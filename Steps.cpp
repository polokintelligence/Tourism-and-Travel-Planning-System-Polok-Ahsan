#ifndef STEPS_CPP
#define STEPS_CPP

#include "Database.cpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class TravelSystem {
public:
    void run();

private:
    Database db;
    User     user;
    const Destination* dest = nullptr;
    double   km = 0;

    void planTrip();

    void step1_Profile();
    int  step2_3_ChooseDestination();
    bool step4_Overview();
    void underDevelopment();

    const City& home() const { return db.cities[user.cityIndex]; }
};

static const string EMERGENCY = "999 (Police / Fire / Ambulance), 16263 (Health helpline)";

static string num(long long n) { return util::intToStr(n); }

void TravelSystem::run() {
    util::header("TOURISM & TRAVEL PLANNING SYSTEM - BANGLADESH");
    cout << "\n  Plan a trip to " << db.destinations.size() << " famous places across all 8 divisions.\n";

    while (true) {
        cout << "\n  MAIN MENU\n\n"
             << "  1. Plan a new trip\n"
             << "  2. Exit\n";
        int c = util::readInt("\n  Choose (1-2): ", 1, 2);
        if (c == 1) planTrip();
        else {
            cout << "\n  Thank you for using the Travel Planner. Have a safe journey!\n\n";
            return;
        }
    }
}

void TravelSystem::planTrip() {
    user = User();
    step1_Profile();

    while (true) {
        int idx = step2_3_ChooseDestination();
        if (idx < 0) { cout << "\n  Trip planning cancelled.\n"; return; }
        dest = &db.destinations[idx];
        km = dest->roadKmFrom(home());
        if (step4_Overview()) break;
    }
    underDevelopment();
}

void TravelSystem::step1_Profile() {
    util::section("STEP 1 OF 12 - YOUR DETAILS, LOCATION, BUDGET & TRAVELERS");
    User& u = user;

    u.name = util::readLine("  Your name: ");

    while (true) {
        u.phone = util::readLine("  Phone number (11 digits, e.g. 017XXXXXXXX): ");
        bool ok = u.phone.size() == 11 && u.phone[0] == '0' && u.phone[1] == '1';
        for (size_t i = 0; ok && i < u.phone.size(); ++i)
            if (!isdigit((unsigned char)u.phone[i])) ok = false;
        if (ok) break;
        cout << "  [!] Enter an 11-digit Bangladeshi mobile number starting with 01.\n";
    }

    static const string DIVISIONS[8] = {"Dhaka", "Chattogram", "Sylhet", "Khulna",
                                        "Rajshahi", "Barishal", "Rangpur", "Mymensingh"};
    cout << "\n  Where are you travelling from?\n\n";
    for (int i = 0; i < 8; ++i) {
        cout << "  " << i + 1 << ". " << left << setw(16) << DIVISIONS[i];
        if (i % 4 == 3) cout << "\n";
    }
    string division = DIVISIONS[util::readInt("\n  Choose your division (1-8): ", 1, 8) - 1];

    vector<int> districts;
    for (size_t i = 0; i < db.cities.size(); ++i)
        if (db.cities[i].division == division) districts.push_back((int)i);

    cout << "\n  Districts in " << division << " division:\n\n";
    for (size_t i = 0; i < districts.size(); ++i) {
        cout << "  " << right << setw(2) << i + 1 << ". " << left << setw(19) << db.cities[districts[i]].name;
        if (i % 3 == 2 || i + 1 == districts.size()) cout << "\n";
    }
    int dc = util::readInt("\n  Choose your district (1-" + num((long long)districts.size()) + "): ",
                           1, (int)districts.size());
    u.cityIndex = districts[dc - 1];
    cout << "\n";

    u.travelers = util::readInt("  Number of travelers (1-20): ", 1, 20);
    u.budget = util::readDouble("  Total budget for the whole group in BDT: ", 500, 10000000);

    Date today = util::today();
    while (true) {
        string s = util::readLine("  Travel date (DD/MM/YYYY): ");
        stringstream ss(s);
        Date d = {0, 0, 0};
        char slash1 = 0, slash2 = 0;
        char extra;
        if (!(ss >> d.d >> slash1 >> d.m >> slash2 >> d.y) || slash1 != '/' || slash2 != '/' ||
            (ss >> extra) || !util::isValid(d)) {
            cout << "  [!] Not a valid date. Use DD/MM/YYYY, for example 20/12/2026\n";
            continue;
        }
        int diff = util::daysBetween(today, d);
        if (diff < 1)   { cout << "  [!] Travel date must be after today.\n"; continue; }
        if (diff > 365) { cout << "  [!] Please choose a date within the next 12 months.\n"; continue; }
        u.travelDate = d;
        break;
    }

    cout << "\n  Hello " << u.name << "! Your profile:\n\n";
    util::field(cout, "From", home().name + " district, " + home().division + " division");
    util::field(cout, "Travelers", num(u.travelers));
    util::field(cout, "Budget", util::money(u.budget) + " total (" +
                                util::money(u.budget / u.travelers) + " per person)");
    util::field(cout, "Travel date", util::toString(u.travelDate));
}

int TravelSystem::step2_3_ChooseDestination() {
    static const string TYPES[] = {"Beach", "Heritage", "Nature"};
    const City& h = home();

    struct Row { int idx; double km; double est; };

    while (true) {
        util::section("STEP 2 OF 12 - CHOOSE TOUR AREA");
        cout << "  1. Near me (" << h.division << " division)\n"
             << "  2. Whole Bangladesh\n";
        int scope = util::readInt("\n  Choose area (1-2): ", 1, 2);

        vector<string> types;
        for (int t = 0; t < 3; ++t)
            for (size_t i = 0; i < db.destinations.size(); ++i) {
                const Destination& d = db.destinations[i];
                if (d.type == TYPES[t] && (scope == 2 || d.division == h.division)) {
                    types.push_back(TYPES[t]);
                    break;
                }
            }

        string type = "All";
        if (types.size() > 1) {
            cout << "\n  0. All";
            for (size_t i = 0; i < types.size(); ++i) cout << "   " << i + 1 << ". " << types[i];
            cout << "\n";
            int c = util::readInt("\n  Choose type of place (0-" + num((long long)types.size()) + "): ",
                                  0, (int)types.size());
            if (c > 0) type = types[c - 1];
        }

        vector<Row> ok;
        Row cheapestOver = { -1, 0, 0 };
        int hidden = 0;
        for (size_t i = 0; i < db.destinations.size(); ++i) {
            const Destination& d = db.destinations[i];
            if (scope == 1 && d.division != h.division) continue;
            if (type != "All" && d.type != type) continue;
            Row r = { (int)i, d.roadKmFrom(h), minimumTripCost(d, h, user.travelers) };
            if (r.est <= user.budget) ok.push_back(r);
            else {
                ++hidden;
                if (cheapestOver.idx < 0 || r.est < cheapestOver.est) cheapestOver = r;
            }
        }

        sort(ok.begin(), ok.end(), [](const Row& a, const Row& b) { return a.km < b.km; });

        util::section("STEP 3 OF 12 - DESTINATIONS WITHIN YOUR BUDGET");

        if (ok.empty() && hidden == 0) {
            cout << "  No places match this area and type. Please search again.\n";
            continue;
        }

        if (ok.empty()) {
            cout << "  [!] Your budget of " << util::money(user.budget)
                 << " is insufficient for any place here.\n"
                 << "      Cheapest: " << db.destinations[cheapestOver.idx].name << " needs "
                 << util::money(cheapestOver.est) << " (short by "
                 << util::money(cheapestOver.est - user.budget) << ").\n\n"
                 << "  1. Search again (other area / type)\n"
                 << "  2. Increase my budget\n"
                 << "  3. Cancel trip\n";
            int ch = util::readInt("\n  Choose (1-3): ", 1, 3);
            if (ch == 3) return -1;
            if (ch == 2) user.budget = util::readDouble("  New total budget in BDT: ", user.budget, 10000000);
            continue;
        }

        cout << "  Budget " << util::money(user.budget) << " for " << user.travelers
             << " traveler(s). These places fit your budget:\n\n";
        cout << "  " << left << setw(5) << "No" << setw(26) << "Destination" << setw(13) << "District"
             << setw(10) << "Type" << right << setw(10) << "Distance" << "\n\n";
        for (size_t i = 0; i < ok.size(); ++i) {
            const Destination& d = db.destinations[ok[i].idx];
            cout << "  " << left << setw(5) << (num((long long)i + 1) + ".")
                 << setw(26) << d.name << setw(13) << d.district << setw(10) << d.type
                 << right << setw(10)
                 << (d.district == h.name ? string("Local") : num((long long)(ok[i].km + 0.5)) + " km")
                 << "\n";
        }
        if (hidden > 0)
            cout << "\n  (" << hidden << " more place(s) are over your budget and not shown.)\n";

        int c = util::readInt("\n  Select destination (1-" + num((long long)ok.size()) +
                              ", 0 = search again): ", 0, (int)ok.size());
        if (c == 0) continue;
        return ok[c - 1].idx;
    }
}

bool TravelSystem::step4_Overview() {
    const Destination& d = *dest;
    util::section("STEP 4 OF 12 - DESTINATION OVERVIEW: " + d.name);

    string distance = d.district == home().name
                    ? "in your own district"
                    : num((long long)(km + 0.5)) + " km from " + home().name;
    util::field(cout, "Location", d.district + ", " + d.division + "  |  " + d.type + "  |  " + distance);
    util::field(cout, "About", d.famousFor);
    cout << "\n";
    util::field(cout, "Weather", d.weather);

    int month = user.travelDate.m;
    string monthNote = d.isGoodMonth(month)
                     ? util::monthName(month) + " is a good time"
                     : "[!] " + util::monthName(month) + " is outside the best time";
    util::field(cout, "Best time", d.bestTimeText + " - " + monthNote);
    cout << "\n";
    util::field(cout, "Safety", num(d.safetyStars) + "/5 - " + d.safetyRecord);

    ostringstream rating;
    rating << fixed << setprecision(1) << d.averageRating() << "/5 (sample reviews)";
    util::field(cout, "Reviews", rating.str());
    for (size_t i = 0; i < d.reviews.size(); ++i)
        util::field(cout, "", "\"" + d.reviews[i].text + "\" - " + d.reviews[i].author);
    cout << "\n";
    util::field(cout, "Tip", d.tip);
    if (!d.extraLeg.empty())
        util::field(cout, "Extra journey", d.extraLeg + " (" + util::money(d.extraLegCost) +
                                           " per person each way)");
    cout << "\n";
    util::field(cout, "Hospital", d.hospital);
    util::field(cout, "Emergency", EMERGENCY);

    cout << "\n  1. Continue with " << d.name << "\n"
         << "  2. Choose another destination\n";
    return util::readInt("\n  Choose (1-2): ", 1, 2) == 1;
}

void TravelSystem::underDevelopment() {
    util::section("PROJECT IS UNDER DEVELOPMENT");
    exit(0);
}

#endif
