//
// Created by littl on 4/2/2023.
//

#include "AirportRecord.h"
#include <string>
#include <sstream>

AirportRecord::AirportRecord(std::string arCode, std::string arName, std::string arCity, std::string arCountry,
    int arLatitudeDegrees, int arLatitudeMinutes, int arLatitudeSeconds, std::string arLatitudeDirection,
    int arLongitudeDegrees, int arLongitudeMinutes, int arLongitudeSeconds, std::string arLongitudeDirection,
    int arAltitude) {
    code = arCode;
    name = arName;
    city = arCity;
    country = arCountry;
    latitudeDegrees = arLatitudeDegrees;
    latitudeMinutes = arLatitudeMinutes;
    latitudeSeconds = arLatitudeSeconds;
    latitudeDirection = arLatitudeDirection;
    longitudeDegrees = arLongitudeDegrees;
    longitudeMinutes = arLongitudeMinutes;
    longitudeSeconds = arLongitudeSeconds;
    longitudeDirection = arLongitudeDirection;
    altitude = arAltitude;
}

std::string AirportRecord::toString() {
    std::stringstream outputStream;

    outputStream << code << ", " << name << ", " << city << ", " << country << ", " << latitudeDegrees << ", " <<
        latitudeMinutes << ", " << latitudeSeconds << ", " << latitudeDirection << ", " << longitudeDegrees << ", " <<
        longitudeMinutes << ", " << longitudeSeconds << ", " << longitudeDirection << ", " << altitude;

    return outputStream.str();
}
