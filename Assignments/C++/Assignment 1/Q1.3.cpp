#include <iostream>

using namespace std;

int main()
{
    double temperature[3][3];

    // Input
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << "Enter temperature for Floor "
                 << i + 1
                 << " Room "
                 << j + 1 << " : ";

            cin >> temperature[i][j];
        }
    }

    // Display table
    cout << endl;

    cout << "        Room1 Room2 Room3" << endl;

    for(int i = 0; i < 3; i++)
    {
        cout << "Floor " << i + 1 << " : ";

        for(int j = 0; j < 3; j++)
        {
            cout << temperature[i][j] << " ";
        }

        cout << endl;
    }

    // Find hottest room
    double hottest = temperature[0][0];

    int hottestFloor = 0;
    int hottestRoom = 0;

    int warningRooms = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(temperature[i][j] > hottest)
            {
                hottest = temperature[i][j];

                hottestFloor = i;
                hottestRoom = j;
            }

            if(temperature[i][j] >= 30)
            {
                warningRooms++;
            }
        }
    }

    // Find hottest floor
    double highestAverage = 0;
    int hottestFloorNumber = 0;

    for(int i = 0; i < 3; i++)
    {
        double sum = 0;

        for(int j = 0; j < 3; j++)
        {
            sum = sum + temperature[i][j];
        }

        double average = sum / 3;

        if(average > highestAverage)
        {
            highestAverage = average;
            hottestFloorNumber = i;
        }
    }

    cout << endl;

    cout << "Hottest Room : Floor "
         << hottestFloor + 1
         << ", Room "
         << hottestRoom + 1
         << " -> "
         << hottest << "C" << endl;

    cout << "Hottest Floor : Floor "
         << hottestFloorNumber + 1
         << " (avg "
         << highestAverage
         << "C)" << endl;

    cout << "Rooms at WARNING or above : "
         << warningRooms << endl;

    return 0;
}