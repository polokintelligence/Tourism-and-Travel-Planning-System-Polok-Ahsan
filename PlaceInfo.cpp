#ifndef PLACEINFO_CPP
#define PLACEINFO_CPP

#include "UserInput.cpp"
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct City {
    string name;
    string division;
    double lat;
    double lon;
    bool   hasRail;
    bool   hasAirport;
};

struct Review {
    string author;
    int    stars;
    string text;
};

class Destination {
public:
    string name, district, division, type;
    double lat = 0, lon = 0;

    string famousFor;
    string weather;
    string bestTimeText;
    int    bestFrom = 1;
    int    bestTo = 12;

    int    safetyStars = 3;
    string safetyRecord;
    string hospital;
    string tip;

    bool   hasRail = false, hasAirport = false, hasLaunch = false;
    int    recommendedNights = 0;

    double hotelPrice = 0;

    string extraLeg;
    double extraLegCost = 0;

    vector<Review> reviews;

    double roadKmFrom(const City& c) const;
    bool   isGoodMonth(int month) const;
    double averageRating() const;
    int    suggestedNights(double roadKm) const;
};

double Destination::roadKmFrom(const City& c) const {
    double km = util::haversineKm(c.lat, c.lon, lat, lon) * 1.3;
    return km < 5 ? 5 : km;
}

bool Destination::isGoodMonth(int month) const {
    return util::monthInRange(month, bestFrom, bestTo);
}

double Destination::averageRating() const {
    if (reviews.empty()) return 0;
    double sum = 0;
    for (size_t i = 0; i < reviews.size(); ++i) sum += reviews[i].stars;
    return sum / reviews.size();
}

int Destination::suggestedNights(double roadKm) const {
    int n = recommendedNights;
    if (roadKm > 150 && n < 1) n = 1;
    return n;
}

class Transport {
public:
    virtual ~Transport() {}
    virtual double oneWayCost(int travelers, double km) const = 0;
};

class Bus : public Transport {
    bool ac_;
public:
    explicit Bus(bool ac) : ac_(ac) {}
    double oneWayCost(int travelers, double km) const override {
        double perPerson = ac_ ? 200 + 3.0 * km : 100 + 1.8 * km;
        return perPerson * travelers;
    }
};

class Train : public Transport {
public:
    double oneWayCost(int travelers, double km) const override {
        return (60 + 1.5 * km) * travelers;
    }
};

class Air : public Transport {
public:
    double oneWayCost(int travelers, double km) const override {
        return (3200 + 4.5 * km) * travelers;
    }
};

class Launch : public Transport {
public:
    double oneWayCost(int travelers, double km) const override {
        return (500 + 4.0 * km) * travelers;
    }
};

class LocalRide : public Transport {
public:
    double oneWayCost(int travelers, double km) const override {
        int vehicles = (travelers + 2) / 3;
        return vehicles * (80 + 22.0 * km);
    }
};

class LocalBus : public Transport {
public:
    double oneWayCost(int travelers, double km) const override {
        return (10 + 2.0 * km) * travelers;
    }
};

class Rickshaw : public Transport {
public:
    double oneWayCost(int travelers, double km) const override {
        int rickshaws = (travelers + 1) / 2;
        return rickshaws * (30 + 18.0 * km);
    }
};

vector<shared_ptr<Transport> > buildTransportOptions(const Destination& d, const City& home, double km) {
    vector<shared_ptr<Transport> > v;
    if (km <= 8)                                         v.push_back(make_shared<Rickshaw>());
    if (km <= 60)                                        v.push_back(make_shared<LocalBus>());
    if (km <= 60)                                        v.push_back(make_shared<LocalRide>());
    if (km > 60)                                         v.push_back(make_shared<Bus>(false));
    if (km > 100)                                        v.push_back(make_shared<Bus>(true));
    if (km > 80 && d.hasRail && home.hasRail)            v.push_back(make_shared<Train>());
    if (km > 80 && d.hasLaunch && home.division == "Dhaka") v.push_back(make_shared<Launch>());
    if (km > 250 && d.hasAirport && home.hasAirport)     v.push_back(make_shared<Air>());
    if (v.empty())                                       v.push_back(make_shared<LocalRide>());
    return v;
}

const double RESTAURANT_RATE = 450;

struct User {
    string name;
    string phone;
    int    cityIndex = 0;
    double budget = 0;
    int    travelers = 1;
    Date   travelDate = {1, 1, 2026};
};

double minimumTripCost(const Destination& d, const City& home, int travelers) {
    double km = d.roadKmFrom(home);
    vector<shared_ptr<Transport> > opts = buildTransportOptions(d, home, km);
    double cheapest = opts[0]->oneWayCost(travelers, km);
    for (size_t i = 1; i < opts.size(); ++i)
        if (opts[i]->oneWayCost(travelers, km) < cheapest) cheapest = opts[i]->oneWayCost(travelers, km);

    int nights = d.suggestedNights(km) > 0 ? 1 : 0;
    int rooms = (travelers + 1) / 2;
    double food = nights == 0 ? 0 : RESTAURANT_RATE * travelers * (nights + 1);
    return cheapest * 2
         + d.extraLegCost * travelers * 2
         + d.hotelPrice * rooms * nights
         + food;
}

#endif
