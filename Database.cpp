#ifndef DATABASE_CPP
#define DATABASE_CPP

#include "PlaceInfo.cpp"
#include <vector>

using namespace std;

class Database {
public:
    vector<City>        cities;
    vector<Destination> destinations;

    Database();

private:
    void seedCities();
    void seedDhaka();
    void seedChattogram();
    void seedSylhet();
    void seedKhulna();
    void seedRajshahi();
    void seedBarishal();
    void seedRangpur();
    void seedMymensingh();
    void seedMorePlaces();

    Destination& add(const string& name, const string& district,
                     const string& division, const string& type, double lat, double lon);
};

Database::Database() {
    destinations.reserve(32);
    seedCities();
    seedDhaka();
    seedChattogram();
    seedSylhet();
    seedKhulna();
    seedRajshahi();
    seedBarishal();
    seedRangpur();
    seedMymensingh();
    seedMorePlaces();
}

Destination& Database::add(const string& name, const string& district,
                           const string& division, const string& type, double lat, double lon) {
    Destination d;
    d.name = name; d.district = district; d.division = division; d.type = type;
    d.lat = lat; d.lon = lon;
    destinations.push_back(d);
    return destinations.back();
}

void Database::seedCities() {

    cities = {

        {"Dhaka",            "Dhaka",      23.8103, 90.4125, true,  true },
        {"Gazipur",          "Dhaka",      23.9999, 90.4203, true,  true },
        {"Narayanganj",      "Dhaka",      23.6238, 90.5000, true,  true },
        {"Narsingdi",        "Dhaka",      23.9322, 90.7151, true,  true },
        {"Munshiganj",       "Dhaka",      23.5422, 90.5305, false, true },
        {"Manikganj",        "Dhaka",      23.8617, 90.0003, false, true },
        {"Tangail",          "Dhaka",      24.2513, 89.9167, true,  false},
        {"Kishoreganj",      "Dhaka",      24.4449, 90.7766, true,  false},
        {"Faridpur",         "Dhaka",      23.6071, 89.8429, true,  false},
        {"Rajbari",          "Dhaka",      23.7574, 89.6445, true,  false},
        {"Madaripur",        "Dhaka",      23.1641, 90.1897, true,  false},
        {"Shariatpur",       "Dhaka",      23.2423, 90.4348, false, false},
        {"Gopalganj",        "Dhaka",      23.0050, 89.8266, true,  false},

        {"Chattogram",       "Chattogram", 22.3569, 91.7832, true,  true },
        {"Cox's Bazar",      "Chattogram", 21.4272, 92.0058, true,  true },
        {"Cumilla",          "Chattogram", 23.4607, 91.1809, true,  false},
        {"Brahmanbaria",     "Chattogram", 23.9571, 91.1119, true,  false},
        {"Chandpur",         "Chattogram", 23.2333, 90.6713, true,  false},
        {"Noakhali",         "Chattogram", 22.8696, 91.0995, true,  false},
        {"Feni",             "Chattogram", 23.0159, 91.3976, true,  false},
        {"Lakshmipur",       "Chattogram", 22.9447, 90.8282, false, false},
        {"Rangamati",        "Chattogram", 22.6533, 92.1789, false, false},
        {"Bandarban",        "Chattogram", 22.1953, 92.2184, false, false},
        {"Khagrachhari",     "Chattogram", 23.1193, 91.9847, false, false},

        {"Sylhet",           "Sylhet",     24.8949, 91.8687, true,  true },
        {"Moulvibazar",      "Sylhet",     24.4829, 91.7774, true,  false},
        {"Habiganj",         "Sylhet",     24.3745, 91.4155, true,  false},
        {"Sunamganj",        "Sylhet",     25.0658, 91.3950, false, false},

        {"Khulna",           "Khulna",     22.8456, 89.5403, true,  true },
        {"Jashore",          "Khulna",     23.1664, 89.2081, true,  true },
        {"Satkhira",         "Khulna",     22.7185, 89.0705, false, false},
        {"Bagerhat",         "Khulna",     22.6516, 89.7859, false, false},
        {"Narail",           "Khulna",     23.1725, 89.5127, true,  true },
        {"Magura",           "Khulna",     23.4873, 89.4199, false, true },
        {"Jhenaidah",        "Khulna",     23.5450, 89.1726, true,  true },
        {"Chuadanga",        "Khulna",     23.6402, 88.8418, true,  false},
        {"Kushtia",          "Khulna",     23.9013, 89.1204, true,  false},
        {"Meherpur",         "Khulna",     23.7622, 88.6318, false, false},

        {"Rajshahi",         "Rajshahi",   24.3745, 88.6042, true,  true },
        {"Bogura",           "Rajshahi",   24.8466, 89.3776, true,  false},
        {"Naogaon",          "Rajshahi",   24.7936, 88.9318, true,  false},
        {"Natore",           "Rajshahi",   24.4206, 89.0003, true,  true },
        {"Chapainawabganj",  "Rajshahi",   24.5965, 88.2776, true,  false},
        {"Pabna",            "Rajshahi",   24.0064, 89.2372, true,  false},
        {"Sirajganj",        "Rajshahi",   24.4534, 89.7007, true,  false},
        {"Joypurhat",        "Rajshahi",   25.0968, 89.0227, true,  false},

        {"Barishal",         "Barishal",   22.7010, 90.3535, false, true },
        {"Patuakhali",       "Barishal",   22.3596, 90.3299, false, true },
        {"Bhola",            "Barishal",   22.6859, 90.6482, false, false},
        {"Pirojpur",         "Barishal",   22.5841, 89.9720, false, false},
        {"Jhalokathi",       "Barishal",   22.6406, 90.1987, false, true },
        {"Barguna",          "Barishal",   22.0953, 90.1121, false, false},

        {"Rangpur",          "Rangpur",    25.7439, 89.2752, true,  true },
        {"Dinajpur",         "Rangpur",    25.6217, 88.6354, true,  true },
        {"Thakurgaon",       "Rangpur",    26.0336, 88.4616, true,  false},
        {"Panchagarh",       "Rangpur",    26.3411, 88.5542, true,  false},
        {"Nilphamari",       "Rangpur",    25.9310, 88.8560, true,  true },
        {"Lalmonirhat",      "Rangpur",    25.9923, 89.2847, true,  false},
        {"Kurigram",         "Rangpur",    25.8072, 89.6295, true,  false},
        {"Gaibandha",        "Rangpur",    25.3297, 89.5430, true,  false},

        {"Mymensingh",       "Mymensingh", 24.7471, 90.4203, true,  false},
        {"Jamalpur",         "Mymensingh", 24.9375, 89.9378, true,  false},
        {"Sherpur",          "Mymensingh", 25.0205, 90.0153, false, false},
        {"Netrokona",        "Mymensingh", 24.8709, 90.7279, true,  false}
    };
}

void Database::seedDhaka() {
    const string dhakaWeather = "Hot and humid summer (30-36C), heavy rain Jun-Sep, mild winter (12-25C)";
    const string dhakaHospital = "Dhaka Medical College Hospital, Bakshibazar";

    Destination& d1 = add("Lalbagh Fort", "Dhaka", "Dhaka", "Heritage", 23.7190, 90.3882);
    d1.famousFor = "Unfinished Mughal fort from 1678 with the tomb of Pari Bibi, gardens and a museum.";
    d1.weather = dhakaWeather;
    d1.bestFrom = 11; d1.bestTo = 2; d1.bestTimeText = "Nov-Feb (cool, dry, good for walking)";
    d1.safetyStars = 4;
    d1.safetyRecord = "Safe inside. Pickpockets in the crowded Old Dhaka lanes outside.";
    d1.hospital = dhakaHospital;
    d1.tip = "Go early morning to avoid crowds; check the weekly closing day before you go.";
    d1.hasRail = true; d1.hasAirport = true; d1.recommendedNights = 0;
    d1.hotelPrice = 1800;
    d1.reviews = {{"Rafi H.", 5, "Beautiful Mughal architecture, garden is very well kept."},
                  {"Nusrat J.", 4, "Lovely place but very crowded on holidays."}};

    Destination& d2 = add("Ahsan Manzil", "Dhaka", "Dhaka", "Heritage", 23.7086, 90.4061);
    d2.famousFor = "The 'Pink Palace' on the Buriganga - former home of the Nawabs of Dhaka, now a museum.";
    d2.weather = dhakaWeather;
    d2.bestFrom = 11; d2.bestTo = 2; d2.bestTimeText = "Nov-Feb";
    d2.safetyStars = 4;
    d2.safetyRecord = "Safe inside. Sadarghat nearby is very crowded - watch your bags.";
    d2.hospital = dhakaHospital;
    d2.tip = "Combine with a short boat ride on the Buriganga for the best view of the palace.";
    d2.hasRail = true; d2.hasAirport = true;
    d2.hotelPrice = 1800;
    d2.reviews = {{"Tanvir A.", 5, "Great museum about the Nawab family, must see."},
                  {"Mitu S.", 4, "Nice palace, roads to reach it are jammed."}};

    Destination& d3 = add("Hatirjheel", "Dhaka", "Dhaka", "Nature", 23.7639, 90.4064);
    d3.famousFor = "Lakeside area in central Dhaka with curved bridges, water taxis and night lights.";
    d3.weather = dhakaWeather;
    d3.bestFrom = 10; d3.bestTo = 3; d3.bestTimeText = "Oct-Mar, best in the evening";
    d3.safetyStars = 4;
    d3.safetyRecord = "Well lit and patrolled. Avoid empty stretches late at night.";
    d3.hospital = "Kurmitola General Hospital / Dhaka Medical College Hospital";
    d3.tip = "Take the water taxi at sunset and stay for the bridge lights.";
    d3.hasRail = true; d3.hasAirport = true;
    d3.hotelPrice = 1800;
    d3.reviews = {{"Sabbir R.", 4, "Beautiful at night, water taxi is fun."},
                  {"Farhana K.", 4, "Good place to relax after work."}};

    Destination& d4 = add("Star Mosque", "Dhaka", "Dhaka", "Heritage", 23.7149, 90.4010);
    d4.famousFor = "18th-century mosque in Armanitola decorated with star-shaped mosaic tiles (chini-tikri).";
    d4.weather = dhakaWeather;
    d4.bestFrom = 11; d4.bestTo = 2; d4.bestTimeText = "Nov-Feb";
    d4.safetyStars = 4;
    d4.safetyRecord = "Safe. Dress modestly and avoid prayer times when visiting.";
    d4.hospital = dhakaHospital;
    d4.tip = "Visit between prayer times; women should carry a scarf.";
    d4.hasRail = true; d4.hasAirport = true;
    d4.hotelPrice = 1800;
    d4.reviews = {{"Imran H.", 5, "The tile work is stunning up close."},
                  {"Priya D.", 4, "Small but very beautiful."}};

    Destination& d5 = add("Dhakeshwari Temple", "Dhaka", "Dhaka", "Heritage", 23.7232, 90.3895);
    d5.famousFor = "National temple of Bangladesh; Dhaka is said to be named after goddess Dhakeshwari.";
    d5.weather = dhakaWeather;
    d5.bestFrom = 10; d5.bestTo = 2; d5.bestTimeText = "Oct-Feb (Durga Puja in Oct is very festive)";
    d5.safetyStars = 4;
    d5.safetyRecord = "Safe, with security during festivals. Very crowded during Durga Puja.";
    d5.hospital = dhakaHospital;
    d5.tip = "Remove shoes before entering; photography may be limited inside.";
    d5.hasRail = true; d5.hasAirport = true;
    d5.hotelPrice = 1800;
    d5.reviews = {{"Ananya P.", 5, "Peaceful and very important place."},
                  {"Shakil M.", 4, "Go during Puja to see the celebration."}};

    Destination& d6 = add("Panam City (Sonargaon)", "Narayanganj", "Dhaka", "Heritage", 23.6513, 90.6105);
    d6.famousFor = "Ghost town of 19th-century merchant houses in Sonargaon, the old capital of Bengal.";
    d6.weather = dhakaWeather;
    d6.bestFrom = 10; d6.bestTo = 3; d6.bestTimeText = "Oct-Mar";
    d6.safetyStars = 5;
    d6.safetyRecord = "Very safe. Old buildings are fragile - do not climb walls.";
    d6.hospital = "Sonargaon Upazila Health Complex";
    d6.tip = "Visit the Folk Art Museum nearby; check its weekly closing days.";
    d6.hasRail = true; d6.hasAirport = true;
    d6.hotelPrice = 1500;
    d6.reviews = {{"Arif K.", 5, "Feels like walking back in time."},
                  {"Lamia T.", 4, "Great for photography, go on a weekday."}};
}

void Database::seedChattogram() {
    Destination& c1 = add("Cox's Bazar", "Cox's Bazar", "Chattogram", "Beach", 21.4272, 92.0058);
    c1.famousFor = "World's longest natural unbroken sea beach - about 120 km along the Bay of Bengal.";
    c1.weather = "Warm and humid (22-32C); heavy monsoon and rough sea Jun-Sep";
    c1.bestFrom = 11; c1.bestTo = 3; c1.bestTimeText = "Nov-Mar (calm sea, dry weather)";
    c1.safetyStars = 4;
    c1.safetyRecord = "Rip currents cause drownings - swim only near lifeguard flags.";
    c1.hospital = "Cox's Bazar District Sadar Hospital";
    c1.tip = "Book hotels early for Dec-Jan; Marine Drive at sunset is a must.";
    c1.hasRail = true; c1.hasAirport = true; c1.recommendedNights = 2;
    c1.hotelPrice = 2000;
    c1.reviews = {{"Sadia R.", 5, "Endless beach, sunset is magical."},
                  {"Mahmud H.", 4, "Beautiful but very crowded in December."}};

    Destination& c2 = add("Saint Martin's Island", "Cox's Bazar", "Chattogram", "Beach", 20.6237, 92.3234);
    c2.famousFor = "Bangladesh's only coral island, with clear blue water, coconut palms and coral reefs.";
    c2.weather = "Warm (22-32C); sea crossing is closed or unsafe in the monsoon";
    c2.bestFrom = 11; c2.bestTo = 2; c2.bestTimeText = "Nov-Feb (ships run only in season)";
    c2.safetyStars = 3;
    c2.safetyRecord = "Visits limited by government rules. Sea crossing can be rough.";
    c2.hospital = "Teknaf Upazila Health Complex (small clinic on the island)";
    c2.tip = "Carry cash, there are almost no ATMs. Do not collect or step on coral.";
    c2.hasRail = false; c2.hasAirport = false; c2.recommendedNights = 1;
    c2.hotelPrice = 2000;
    c2.extraLeg = "Ship Teknaf <-> Saint Martin's"; c2.extraLegCost = 900;
    c2.reviews = {{"Rumana A.", 5, "Clearest water I have seen in Bangladesh."},
                  {"Fahim S.", 3, "Ship tickets were hard to get, plan early."}};
}

void Database::seedSylhet() {
    Destination& s1 = add("Ratargul Swamp Forest", "Sylhet", "Sylhet", "Nature", 25.0068, 91.9744);
    s1.famousFor = "A rare freshwater swamp forest - trees stand in water during the monsoon.";
    s1.weather = "Mild (18-32C), very rainy Jun-Sep";
    s1.bestFrom = 7; s1.bestTo = 10; s1.bestTimeText = "Jul-Oct (forest is flooded, boats can go inside)";
    s1.safetyStars = 4;
    s1.safetyRecord = "Boat only - wear a life jacket. Snakes are seen in the monsoon.";
    s1.hospital = "Sylhet MAG Osmani Medical College Hospital";
    s1.tip = "Bargain the boat price before you start; keep silent to see birds.";
    s1.hasRail = true; s1.hasAirport = true; s1.recommendedNights = 1;
    s1.hotelPrice = 1500;
    s1.extraLeg = "CNG Sylhet city <-> Ratargul"; s1.extraLegCost = 200;
    s1.reviews = {{"Tasnim H.", 5, "Like the Amazon in Bangladesh, amazing in rain."},
                  {"Ridwan C.", 4, "Dry season is not worth it, go in monsoon."}};

    Destination& s2 = add("Jaflong", "Sylhet", "Sylhet", "Nature", 25.1636, 92.0177);
    s2.famousFor = "Clear, stony Piyain river with views of the Meghalaya hills at the border.";
    s2.weather = "Mild (18-32C), very rainy Jun-Sep";
    s2.bestFrom = 6; s2.bestTo = 10; s2.bestTimeText = "Jun-Oct (green hills and waterfalls)";
    s2.safetyStars = 3;
    s2.safetyRecord = "Strong river currents have caused drownings. Do not cross the border line.";
    s2.hospital = "Gowainghat Upazila Health Complex / Sylhet MAG Osmani MCH";
    s2.tip = "Stay in Sylhet city and do Jaflong as a day trip.";
    s2.hasRail = true; s2.hasAirport = true; s2.recommendedNights = 1;
    s2.hotelPrice = 1500;
    s2.reviews = {{"Nabila F.", 5, "Hills and river together, beautiful."},
                  {"Asif Z.", 3, "Too many stone-collecting boats in some parts."}};
}

void Database::seedKhulna() {
    Destination& k1 = add("Sundarbans (Karamjal)", "Bagerhat", "Khulna", "Nature", 22.4300, 89.5900);
    k1.famousFor = "World's largest mangrove forest (UNESCO), home of the Royal Bengal Tiger and deer.";
    k1.weather = "Humid (20-34C); cyclone risk in May and Oct-Nov";
    k1.bestFrom = 11; k1.bestTo = 2; k1.bestTimeText = "Nov-Feb (calm rivers, cool weather)";
    k1.safetyStars = 3;
    k1.safetyRecord = "Go only with licensed guides and forest guards. Permit needed.";
    k1.hospital = "Mongla Upazila Health Complex / Khulna Medical College Hospital";
    k1.tip = "For a 2-3 day cruise, book through a licensed tour operator.";
    k1.hasRail = true; k1.hasAirport = true; k1.recommendedNights = 2;
    k1.hotelPrice = 1500;
    k1.extraLeg = "Trawler boat Mongla <-> Karamjal"; k1.extraLegCost = 200;
    k1.reviews = {{"Shuvo D.", 5, "Saw deer and crocodiles, unforgettable."},
                  {"Ishrat L.", 4, "Mosquitoes everywhere, carry repellent."}};

    Destination& k2 = add("Sixty Dome Mosque", "Bagerhat", "Khulna", "Heritage", 22.6747, 89.7417);
    k2.famousFor = "15th-century mosque by Khan Jahan Ali, part of UNESCO's 'Mosque City of Bagerhat'.";
    k2.weather = "Hot and humid summer, mild winter (12-26C)";
    k2.bestFrom = 11; k2.bestTo = 2; k2.bestTimeText = "Nov-Feb";
    k2.safetyStars = 5;
    k2.safetyRecord = "Calm and safe heritage site.";
    k2.hospital = "Bagerhat District Sadar Hospital";
    k2.tip = "Combine with Khan Jahan Ali's tomb, 2 km away.";
    k2.hasRail = true; k2.hasAirport = true;
    k2.hotelPrice = 1200;
    k2.reviews = {{"Kamrul I.", 5, "Peaceful and historic, well maintained."},
                  {"Joya B.", 4, "Small museum is informative."}};
}

void Database::seedRajshahi() {
    Destination& r1 = add("Paharpur Buddhist Vihara", "Naogaon", "Rajshahi", "Heritage", 25.0313, 88.9769);
    r1.famousFor = "Ruins of Somapura Mahavihara, an 8th-century Buddhist monastery (UNESCO site).";
    r1.weather = "Very hot dry summer (up to 40C), cool winter (8-25C)";
    r1.bestFrom = 11; r1.bestTo = 2; r1.bestTimeText = "Nov-Feb";
    r1.safetyStars = 5;
    r1.safetyRecord = "Safe and quiet rural site.";
    r1.hospital = "Badalgachhi Upazila Health Complex / Naogaon Sadar Hospital";
    r1.tip = "Carry water and a hat - there is little shade on the site.";
    r1.hasRail = true; r1.hasAirport = true;
    r1.hotelPrice = 1000;
    r1.reviews = {{"Mehedi H.", 5, "Huge site, history lovers will love it."},
                  {"Sumaiya N.", 4, "Go in winter, summer is too hot."}};

    Destination& r2 = add("Puthia Temple Complex", "Rajshahi", "Rajshahi", "Heritage", 24.3633, 88.8411);
    r2.famousFor = "The largest group of historic Hindu temples in Bangladesh, with fine terracotta work.";
    r2.weather = "Very hot dry summer (up to 40C), cool winter (8-25C)";
    r2.bestFrom = 11; r2.bestTo = 2; r2.bestTimeText = "Nov-Feb";
    r2.safetyStars = 5;
    r2.safetyRecord = "Safe and peaceful.";
    r2.hospital = "Puthia Upazila Health Complex / Rajshahi Medical College Hospital";
    r2.tip = "Visit Rajshahi city's Padma riverside in the evening.";
    r2.hasRail = true; r2.hasAirport = true;
    r2.hotelPrice = 1200;
    r2.reviews = {{"Anik S.", 5, "Terracotta details are incredible."},
                  {"Rima P.", 4, "Needs better signboards but worth it."}};
}

void Database::seedBarishal() {
    Destination& b1 = add("Kuakata", "Patuakhali", "Barishal", "Beach", 21.8167, 90.1200);
    b1.famousFor = "'Daughter of the Sea' - watch both sunrise and sunset over the sea from one beach.";
    b1.weather = "Warm and humid (20-32C); cyclone risk in the monsoon";
    b1.bestFrom = 11; b1.bestTo = 2; b1.bestTimeText = "Nov-Feb";
    b1.safetyStars = 4;
    b1.safetyRecord = "Tourist police present. Strong monsoon waves - follow warning flags.";
    b1.hospital = "Kalapara Upazila Health Complex";
    b1.tip = "Hire a motorbike guide for sunrise at Gangamati and sunset at the main beach.";
    b1.hasRail = false; b1.hasAirport = false; b1.hasLaunch = true; b1.recommendedNights = 2;
    b1.hotelPrice = 1500;
    b1.reviews = {{"Rakib U.", 5, "Sunrise and sunset in one place, loved it."},
                  {"Shirin A.", 4, "Less crowded than Cox's Bazar."}};

    Destination& b2 = add("Durga Sagar", "Barishal", "Barishal", "Nature", 22.7456, 90.2730);
    b2.famousFor = "Historic pond from 1780 with a central island, famous for winter migratory birds.";
    b2.weather = "Humid (20-33C), mild winter";
    b2.bestFrom = 12; b2.bestTo = 2; b2.bestTimeText = "Dec-Feb (migratory birds)";
    b2.safetyStars = 5;
    b2.safetyRecord = "Safe family picnic spot.";
    b2.hospital = "Sher-e-Bangla Medical College Hospital, Barishal";
    b2.tip = "Come early morning to see the birds.";
    b2.hasRail = false; b2.hasAirport = true; b2.hasLaunch = true;
    b2.hotelPrice = 1200;
    b2.reviews = {{"Tanzila M.", 4, "Quiet and green, good for families."},
                  {"Hasib R.", 4, "Birds in winter are lovely."}};
}

void Database::seedRangpur() {
    Destination& g1 = add("Tajhat Palace", "Rangpur", "Rangpur", "Heritage", 25.7177, 89.2647);
    g1.famousFor = "Early-20th-century white palace of a Rangpur zamindar, now the Rangpur Museum.";
    g1.weather = "Hot summer, cold foggy winter (8-24C)";
    g1.bestFrom = 11; g1.bestTo = 2; g1.bestTimeText = "Nov-Feb";
    g1.safetyStars = 5;
    g1.safetyRecord = "Safe.";
    g1.hospital = "Rangpur Medical College Hospital";
    g1.tip = "Check the museum's closing day before visiting.";
    g1.hasRail = true; g1.hasAirport = true;
    g1.hotelPrice = 1200;
    g1.reviews = {{"Sohel K.", 5, "Grand building, nice small museum."},
                  {"Moumita R.", 4, "Clean and calm."}};

    Destination& g2 = add("Kantajew Temple", "Dinajpur", "Rangpur", "Heritage", 25.7905, 88.6680);
    g2.famousFor = "18th-century Hindu temple covered with detailed terracotta panels showing epic stories.";
    g2.weather = "Hot summer, cold foggy winter (8-24C)";
    g2.bestFrom = 11; g2.bestTo = 2; g2.bestTimeText = "Nov-Feb";
    g2.safetyStars = 5;
    g2.safetyRecord = "Safe rural site.";
    g2.hospital = "Dinajpur M Abdur Rahim Medical College Hospital";
    g2.tip = "Bring binoculars or a zoom lens to see the terracotta stories.";
    g2.hasRail = true; g2.hasAirport = true;
    g2.hotelPrice = 1000;
    g2.reviews = {{"Bappy S.", 5, "Best terracotta temple in the country."},
                  {"Lipi D.", 4, "Roads are a bit rough, temple is worth it."}};
}

void Database::seedMymensingh() {
    Destination& m1 = add("Birishiri", "Netrokona", "Mymensingh", "Nature", 25.0400, 90.6500);
    m1.famousFor = "Blue Someshwari river and white clay hills, home of Garo and Hajong communities.";
    m1.weather = "Mild (15-32C), rainy Jun-Sep";
    m1.bestFrom = 10; m1.bestTo = 2; m1.bestTimeText = "Oct-Feb (clear blue river)";
    m1.safetyStars = 4;
    m1.safetyRecord = "Remote area near the border. Return before dark; few ATMs.";
    m1.hospital = "Durgapur Upazila Health Complex";
    m1.tip = "Stay at a local guest house and hire a bike to see the clay hills.";
    m1.hasRail = false; m1.hasAirport = false; m1.recommendedNights = 1;
    m1.hotelPrice = 1000;
    m1.reviews = {{"Jannat F.", 5, "The blue lake in the clay hills is unreal."},
                  {"Nayeem A.", 4, "Simple hotels but friendly people."}};

    Destination& m2 = add("Shashi Lodge", "Mymensingh", "Mymensingh", "Heritage", 24.7563, 90.4065);
    m2.famousFor = "Mymensingh Rajbari - a zamindar palace with a garden and a famous Venus statue.";
    m2.weather = "Mild (15-32C), rainy Jun-Sep";
    m2.bestFrom = 11; m2.bestTo = 2; m2.bestTimeText = "Nov-Feb";
    m2.safetyStars = 5;
    m2.safetyRecord = "Safe. It is now a college campus - follow visiting hours.";
    m2.hospital = "Mymensingh Medical College Hospital";
    m2.tip = "Walk to the Brahmaputra riverside park in the afternoon.";
    m2.hasRail = true; m2.hasAirport = false;
    m2.hotelPrice = 1000;
    m2.reviews = {{"Abir H.", 4, "Beautiful old palace and garden."},
                  {"Puja S.", 4, "Only some areas are open to visitors."}};
}

void Database::seedMorePlaces() {
    const string hillWeather = "Pleasant (15-30C); heavy rain and landslide risk Jun-Sep";

    Destination& p1 = add("Bandarban (Nilgiri)", "Bandarban", "Chattogram", "Nature", 21.9300, 92.3300);
    p1.famousFor = "Hills with Nilgiri peak above the clouds, waterfalls and Marma and Bawm villages.";
    p1.weather = hillWeather;
    p1.bestFrom = 10; p1.bestTo = 3; p1.bestTimeText = "Oct-Mar (clear views, cool weather)";
    p1.safetyStars = 4;
    p1.safetyRecord = "Carry your NID for army checkpoints. Avoid hill roads in heavy rain.";
    p1.hospital = "Bandarban Sadar Hospital";
    p1.tip = "Hire a chander gari (jeep) from Bandarban town to Nilgiri.";
    p1.hasRail = false; p1.hasAirport = false; p1.recommendedNights = 1;
    p1.hotelPrice = 1500;
    p1.extraLeg = "Jeep Bandarban town <-> Nilgiri"; p1.extraLegCost = 400;
    p1.reviews = {{"Tahmid R.", 5, "Standing above the clouds at sunrise was unreal."},
                  {"Sharmin A.", 4, "Roads are steep, keep motion sickness tablets."}};

    Destination& p2 = add("Rangamati (Kaptai Lake)", "Rangamati", "Chattogram", "Nature", 22.6533, 92.1789);
    p2.famousFor = "Huge Kaptai Lake among green hills, with the hanging bridge and Chakma culture.";
    p2.weather = hillWeather;
    p2.bestFrom = 9; p2.bestTo = 2; p2.bestTimeText = "Sep-Feb (lake is full, cool weather)";
    p2.safetyStars = 4;
    p2.safetyRecord = "Generally safe. Always wear a life jacket on lake boats.";
    p2.hospital = "Rangamati General Hospital";
    p2.tip = "Share an engine boat to Shuvolong waterfall to save money.";
    p2.hasRail = false; p2.hasAirport = false; p2.recommendedNights = 1;
    p2.hotelPrice = 1500;
    p2.reviews = {{"Nadia K.", 5, "The lake and hills together are breathtaking."},
                  {"Rifat H.", 4, "Boat ride was long but worth it."}};

    Destination& p3 = add("Chattogram War Cemetery", "Chattogram", "Chattogram", "Heritage", 22.3594, 91.8291);
    p3.famousFor = "Peaceful WWII Commonwealth cemetery with about 700 graves, kept like a garden.";
    p3.weather = "Warm and humid (20-33C); heavy rain Jun-Sep";
    p3.bestFrom = 11; p3.bestTo = 2; p3.bestTimeText = "Nov-Feb";
    p3.safetyStars = 5;
    p3.safetyRecord = "Safe and quiet. Respect the rules - no picnics or loud noise.";
    p3.hospital = "Chattogram Medical College Hospital";
    p3.tip = "Combine with Foy's Lake and Patenga beach on the same day.";
    p3.hasRail = true; p3.hasAirport = true;
    p3.hotelPrice = 2000;
    p3.reviews = {{"Imtiaz C.", 5, "Very calm and beautifully maintained."},
                  {"Ruma S.", 4, "Moving place, a short visit is enough."}};

    Destination& p4 = add("Hazrat Shah Jalal Shrine", "Sylhet", "Sylhet", "Heritage", 24.8983, 91.8697);
    p4.famousFor = "Shrine of 14th-century Sufi saint Hazrat Shah Jalal, Sylhet's most visited holy place.";
    p4.weather = "Mild (18-32C), very rainy Jun-Sep";
    p4.bestFrom = 10; p4.bestTo = 3; p4.bestTimeText = "Oct-Mar";
    p4.safetyStars = 4;
    p4.safetyRecord = "Safe but crowded. Dress modestly and watch your belongings.";
    p4.hospital = "Sylhet MAG Osmani Medical College Hospital";
    p4.tip = "Remove shoes at the entrance; women visit from a separate area.";
    p4.hasRail = true; p4.hasAirport = true;
    p4.hotelPrice = 1500;
    p4.reviews = {{"Fahad A.", 5, "Peaceful and spiritual, a must in Sylhet."},
                  {"Mousumi D.", 4, "Very crowded on Thursdays."}};

    Destination& p5 = add("Sreemangal (Lawachara)", "Moulvibazar", "Sylhet", "Nature", 24.3200, 91.7840);
    p5.famousFor = "Tea capital of Bangladesh - tea gardens and Lawachara rainforest with hoolock gibbons.";
    p5.weather = "Mild (15-32C), rainy Jun-Sep";
    p5.bestFrom = 10; p5.bestTo = 3; p5.bestTimeText = "Oct-Mar (cool, easy forest trails)";
    p5.safetyStars = 4;
    p5.safetyRecord = "Stay on marked trails with a guide. Leeches in the rainy season.";
    p5.hospital = "Sreemangal Upazila Health Complex";
    p5.tip = "Try the famous seven-layer tea in Sreemangal town.";
    p5.hasRail = true; p5.hasAirport = false; p5.recommendedNights = 1;
    p5.hotelPrice = 1500;
    p5.reviews = {{"Rashed M.", 5, "Green everywhere, we heard gibbons in the forest."},
                  {"Lubna F.", 4, "Book a guide, the trails are confusing."}};

    Destination& p6 = add("Padma Riverside (T-Bandh)", "Rajshahi", "Rajshahi", "Nature", 24.3600, 88.5940);
    p6.famousFor = "Wide Padma river promenade in clean, green Rajshahi city - sunsets and boat rides.";
    p6.weather = "Very hot dry summer (up to 40C), cool winter (8-25C)";
    p6.bestFrom = 10; p6.bestTo = 3; p6.bestTimeText = "Oct-Mar";
    p6.safetyStars = 5;
    p6.safetyRecord = "Safe and family friendly. Do not swim in the river.";
    p6.hospital = "Rajshahi Medical College Hospital";
    p6.tip = "Go at sunset and try Rajshahi's famous kalai roti.";
    p6.hasRail = true; p6.hasAirport = true;
    p6.hotelPrice = 1200;
    p6.reviews = {{"Sakib H.", 5, "Best sunset spot in the north."},
                  {"Tania B.", 4, "Clean and calm, great for evening walks."}};

    Destination& p7 = add("Tetulia", "Panchagarh", "Rangpur", "Nature", 26.4833, 88.3500);
    p7.famousFor = "Northernmost tip of Bangladesh - see snowy Kanchenjunga on clear days.";
    p7.weather = "Cold winter (5-24C), hot and rainy summer";
    p7.bestFrom = 10; p7.bestTo = 12; p7.bestTimeText = "Oct-Dec (clear skies for Kanchenjunga)";
    p7.safetyStars = 5;
    p7.safetyRecord = "Safe and quiet. It is next to the border - do not cross it.";
    p7.hospital = "Tetulia Upazila Health Complex / Panchagarh Sadar Hospital";
    p7.tip = "Stay overnight to see Kanchenjunga at sunrise.";
    p7.hasRail = true; p7.hasAirport = false; p7.recommendedNights = 1;
    p7.hotelPrice = 1000;
    p7.reviews = {{"Jahid K.", 5, "Saw Kanchenjunga in November, amazing."},
                  {"Sumi R.", 4, "Very cold in December, bring warm clothes."}};
}

#endif
