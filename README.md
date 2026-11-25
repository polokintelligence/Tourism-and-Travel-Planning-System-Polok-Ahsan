# Tourism & Travel Planning System (Bangladesh)
**Made by:** Polok and Ahsan

A C++ console application that helps plan a trip to famous places across all 8 divisions of Bangladesh.

## Features
- Traveller profile: name, phone (validated), home division and district, group size, budget, travel date
- Choose a tour area (near me / whole Bangladesh) and type of place (Beach, Heritage, Nature)
- Lists only destinations that fit the budget, sorted by distance (haversine distance x 1.3 for roads)
- Destination overview: weather, best time to visit, safety, sample reviews, tips, nearest hospital and emergency numbers
- Transport cost options (bus, AC bus, train, launch, air, local ride, rickshaw) using C++ classes and inheritance

## Files
| File | Contents |
|---|---|
| `main.cpp` | Program entry point |
| `Steps.cpp` | `TravelSystem` class: menu and the trip-planning steps |
| `Database.cpp` | Districts and destination data |
| `PlaceInfo.cpp` | `City`, `Destination`, `Transport` classes, cost estimate |
| `UserInput.cpp` | Input validation, formatting, date and distance helpers |

## Build and run
```
g++ -std=c++11 main.cpp -o main
./main
```
