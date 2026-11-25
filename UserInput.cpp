#ifndef USERINPUT_CPP
#define USERINPUT_CPP

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

struct Date {
    int d;
    int m;
    int y;
};

namespace util {

    string readLine(const string& prompt);
    int    readInt(const string& prompt, int lo, int hi);
    double readDouble(const string& prompt, double lo, double hi);

    void   header(const string& title);
    void   section(const string& title);
    const int WIDTH = 106;
    const int RULE  = 90;
    void   rule(ostream& os, char c = '-', int n = RULE);
    void   field(ostream& os, const string& label, const string& text, int labelWidth = 13);
    string money(double amount);
    string intToStr(long long n);

    double haversineKm(double lat1, double lon1, double lat2, double lon2);

    Date   today();
    bool   isValid(Date date);
    int    daysBetween(Date from, Date to);
    int    dayOfWeek(Date date);
    string toString(Date date);
    string monthName(int m);
    bool   monthInRange(int m, int from, int to);
}

namespace util {

static string trim(const string& s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

string readLine(const string& prompt) {
    while (true) {
        cout << prompt;
        string s;
        if (!getline(cin, s)) {
            cout << "\n\nInput closed. Exiting program.\n";
            exit(0);
        }
        s = trim(s);
        if (!s.empty()) return s;
        cout << "  [!] This field cannot be empty.\n";
    }
}

int readInt(const string& prompt, int lo, int hi) {
    while (true) {
        string s = readLine(prompt);
        stringstream ss(s);
        int value;
        char extra;
        if ((ss >> value) && !(ss >> extra) && value >= lo && value <= hi) return value;
        cout << "  [!] Please enter a whole number from " << lo << " to " << hi << ".\n";
    }
}

double readDouble(const string& prompt, double lo, double hi) {
    while (true) {
        string s = readLine(prompt);
        string clean;
        for (size_t i = 0; i < s.size(); ++i)
            if (s[i] != ',') clean += s[i];
        stringstream ss(clean);
        double value;
        char extra;
        if ((ss >> value) && !(ss >> extra) && value >= lo && value <= hi) return value;
        cout << "  [!] Please enter a number from " << lo << " to " << hi << ".\n";
    }
}

void rule(ostream& os, char c, int n) {
    os << string(n, c) << "\n";
}

void header(const string& title) {
    cout << "\n\n";
    rule(cout, '=');
    int pad = (RULE - (int)title.size()) / 2;
    if (pad < 0) pad = 0;
    cout << string(pad, ' ') << title << "\n";
    rule(cout, '=');
}

void section(const string& title) {
    cout << "\n\n\n\n";
    rule(cout, '-');
    cout << "  " << title << "\n";
    rule(cout, '-');
    cout << "\n";
}

void field(ostream& os, const string& label, const string& text, int labelWidth) {
    string indent(2 + labelWidth + 3, ' ');
    int width = WIDTH - (int)indent.size();
    if (label.empty()) os << indent;
    else               os << "  " << left << setw(labelWidth) << label << " : ";
    istringstream words(text);
    string w;
    int col = 0;
    while (words >> w) {
        if (col > 0 && col + 1 + (int)w.size() > width) {
            os << "\n" << indent;
            col = 0;
        } else if (col > 0) {
            os << ' ';
            ++col;
        }
        os << w;
        col += (int)w.size();
    }
    os << "\n";
}

string intToStr(long long n) {
    ostringstream os;
    os << n;
    return os.str();
}

string money(double amount) {
    bool negative = amount < 0;
    long long n = (long long)(fabs(amount) + 0.5);
    string digits = intToStr(n);
    string out;
    int count = 0;
    for (int i = (int)digits.size() - 1; i >= 0; --i) {
        out.insert(out.begin(), digits[i]);
        if (++count % 3 == 0 && i > 0) out.insert(out.begin(), ',');
    }
    return string("BDT ") + (negative ? "-" : "") + out;
}

double haversineKm(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0;
    const double PI = 3.14159265358979323846;
    double dLat = (lat2 - lat1) * PI / 180.0;
    double dLon = (lon2 - lon1) * PI / 180.0;
    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1 * PI / 180.0) * cos(lat2 * PI / 180.0) *
               sin(dLon / 2) * sin(dLon / 2);
    return R * 2 * atan2(sqrt(a), sqrt(1 - a));
}

static tm toTm(Date date) {
    tm t = tm();
    t.tm_mday = date.d;
    t.tm_mon  = date.m - 1;
    t.tm_year = date.y - 1900;
    t.tm_hour = 12;
    mktime(&t);
    return t;
}

static Date fromTm(const tm& t) {
    Date d = { t.tm_mday, t.tm_mon + 1, t.tm_year + 1900 };
    return d;
}

Date today() {
    time_t now = time(0);
    tm* t = localtime(&now);
    return fromTm(*t);
}

bool isValid(Date date) {
    if (date.y < 2000 || date.y > 2100 || date.m < 1 || date.m > 12 || date.d < 1 || date.d > 31)
        return false;
    tm t = toTm(date);
    return t.tm_mday == date.d && t.tm_mon == date.m - 1;
}

int daysBetween(Date from, Date to) {
    tm a = toTm(from), b = toTm(to);
    double sec = difftime(mktime(&b), mktime(&a));
    return (int)floor(sec / 86400.0 + 0.5);
}

int dayOfWeek(Date date) {
    return toTm(date).tm_wday;
}

string monthName(int m) {
    static const char* names[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    if (m < 1 || m > 12) return "?";
    return names[m - 1];
}

string toString(Date date) {
    static const char* days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    ostringstream os;
    os << setfill('0') << setw(2) << date.d << "/" << setw(2) << date.m << "/" << date.y
       << " (" << days[dayOfWeek(date)] << ")";
    return os.str();
}

bool monthInRange(int m, int from, int to) {
    if (from <= to) return m >= from && m <= to;
    return m >= from || m <= to;
}

}

#endif
