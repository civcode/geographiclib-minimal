#include <iostream>
#include <GeographicLib/Geocentric.hpp>
#include <GeographicLib/Constants.hpp>
#include <GeographicLib/LocalCartesian.hpp>

int main() {
    // The WGS84 ellipsoid
    const GeographicLib::Geocentric& earth = GeographicLib::Geocentric::WGS84();
    
    // Latitude and Longitude in degrees, Altitude in meters
    double latitude = 40.7128; // Example latitude
    double longitude = -74.0060; // Example longitude
    double altitude = 0; // Assuming sea level for simplicity
    
    // Variables to hold the ECEF coordinates
    double x, y, z;
    
    // Convert to ECEF coordinates
    earth.Forward(latitude, longitude, altitude, x, y, z);
    
    std::cout << "ECEF Coordinates: X=" << x << ", Y=" << y << ", Z=" << z << std::endl;


    // Define a local reference point in geodetic coordinates (for example, the location of a radar)
    double refLatitude = latitude + 0.002; // Latitude of the reference point
    double refLongitude = longitude + 0.002; // Longitude of the reference point
    double refAltitude = altitude; // Altitude of the reference point

    // Initialize the Local Cartesian converter with the reference point
    GeographicLib::LocalCartesian enu(refLatitude, refLongitude, refAltitude, earth);

    // Convert the geodetic coordinates of the target point to ENU coordinates
    double east, north, up;
    enu.Forward(latitude, longitude, altitude, east, north, up);

    std::cout << "ENU Coordinates: East=" << east << ", North=" << north << ", Up=" << up << std::endl;

    
    return 0;
}

