#include <iostream>
#include <cmath>

using namespace std;


// Distance
inline double distanceBetween(double x1,
                              double y1,
                              double x2,
                              double y2)
{
    return sqrt(
        pow(x2 - x1, 2) +
        pow(y2 - y1, 2)
    );
}


// Degree to radians
inline double toRadians(double degrees)
{
    return degrees * 3.14159 / 180;
}


// Clamp
inline double clamp(double value,
                    double min,
                    double max)
{
    if(value < min)
    {
        return min;
    }
    else if(value > max)
    {
        return max;
    }
    else
    {
        return value;
    }
}


// Safe zone
inline bool isInSafeZone(double x,
                         double y,
                         double cx,
                         double cy,
                         double radius)
{
    double distance =
        distanceBetween(x, y, cx, cy);

    if(distance <= radius)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    double homeX = 0;
    double homeY = 0;

    double radius = 50;


    double x1 = 10;
    double y1 = 20;

    double x2 = 30;
    double y2 = 40;

    double x3 = 60;
    double y3 = 20;


    cout << "Waypoint 1" << endl;

    cout << "Distance : "
         << distanceBetween(
                homeX, homeY,
                x1, y1)
         << endl;


    if(isInSafeZone(x1, y1,
                    homeX, homeY,
                    radius))
    {
        cout << "Safe Zone : Yes"
             << endl;
    }
    else
    {
        cout << "Safe Zone : No"
             << endl;
    }


    cout << endl;


    cout << "Waypoint 2" << endl;

    cout << "Distance : "
         << distanceBetween(
                homeX, homeY,
                x2, y2)
         << endl;


    if(isInSafeZone(x2, y2,
                    homeX, homeY,
                    radius))
    {
        cout << "Safe Zone : Yes"
             << endl;
    }
    else
    {
        cout << "Safe Zone : No"
             << endl;
    }


    cout << endl;


    cout << "Waypoint 3" << endl;

    cout << "Distance : "
         << distanceBetween(
                homeX, homeY,
                x3, y3)
         << endl;


    if(isInSafeZone(x3, y3,
                    homeX, homeY,
                    radius))
    {
        cout << "Safe Zone : Yes"
             << endl;
    }
    else
    {
        cout << "Safe Zone : No"
             << endl;
    }


    return 0;
}