#include <iostream>
#include <cmath>

using namespace std;

inline double distanceBetween(double x1, double y1,
                              double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2));
}

inline double toRadians(double degrees)
{
    return degrees * (M_PI / 180.0);
}

inline double clamp(double value,
                    double minVal,
                    double maxVal)
{
    if(value < minVal)
    {
        return minVal;
    }

    if(value > maxVal)
    {
        return maxVal;
    }

    return value;
}

inline bool isInSafeZone(double x, double y,
                         double cx, double cy,
                         double radius)
{
    double distance =
        distanceBetween(x, y, cx, cy);

    if(distance <= radius)
    {
        return true;
    }

    return false;
}


int main()
{
    double homeX = 0.0;
    double homeY = 0.0;

    double radius = 50.0;


    // Waypoint 1
    double x1 = 10.0;
    double y1 = 20.0;

    // Waypoint 2
    double x2 = 30.0;
    double y2 = 40.0;

    // Waypoint 3
    double x3 = 60.0;
    double y3 = 20.0;


    double d1 = distanceBetween(
        homeX, homeY, x1, y1);

    double d2 = distanceBetween(
        homeX, homeY, x2, y2);

    double d3 = distanceBetween(
        homeX, homeY, x3, y3);


    cout << "Waypoint 1" << endl;
    cout << "Distance : " << d1 << endl;

    if(isInSafeZone(x1, y1,
                    homeX, homeY, radius))
    {
        cout << "Safe Zone : Yes" << endl;
    }
    else
    {
        cout << "Safe Zone : No" << endl;
    }


    cout << endl;

    cout << "Waypoint 2" << endl;
    cout << "Distance : " << d2 << endl;

    if(isInSafeZone(x2, y2,
                    homeX, homeY, radius))
    {
        cout << "Safe Zone : Yes" << endl;
    }
    else
    {
        cout << "Safe Zone : No" << endl;
    }


    cout << endl;

    cout << "Waypoint 3" << endl;
    cout << "Distance : " << d3 << endl;

    if(isInSafeZone(x3, y3,
                    homeX, homeY, radius))
    {
        cout << "Safe Zone : Yes" << endl;
    }
    else
    {
        cout << "Safe Zone : No" << endl;
    }


    return 0;
}