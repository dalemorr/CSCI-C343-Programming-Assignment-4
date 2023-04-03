#ifndef AIRPORTRECORD_H
#define AIRPORTRECORD_H

#include <string>

class AirportRecord {
public:
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    int latitudeDegrees;
    int latitudeMinutes;
    int latitudeSeconds;
    std::string latitudeDirection;
    int longitudeDegrees;
    int longitudeMinutes;
    int longitudeSeconds;
    std::string longitudeDirection;
    int altitude;

    AirportRecord(std::string arCode, std::string arName, std::string arCity, std::string arCountry,
        int arLatitudeDegrees, int arLatitudeMinutes, int arLatitudeSeconds, std::string arLatitudeDirection,
        int arLongitudeDegrees, int arLongitudeMinutes, int arLongitudeSeconds, std::string arLongitudeDirection,
        int arAltitude);

    std::string toString();
};

#endif //AIRPORTRECORD_H
