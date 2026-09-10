#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of readings : ";
    cin >> n;

    double readings[100];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter reading " << i << " : ";
        cin >> readings[i];
    }

    double min = 0;
    double max = 0;
    double sum = 0;

    int valid = 0;
    int skipped = 0;

    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    cout << "Valid readings : ";

    for(int i = 0; i < n; i++)
    {
        if(readings[i] < 0)
        {
            skipped++;
            continue;
        }

        cout << readings[i] << " ";

        if(valid == 0)
        {
            min = readings[i];
            max = readings[i];
        }

        if(readings[i] < min)
        {
            min = readings[i];
        }

        if(readings[i] > max)
        {
            max = readings[i];
        }

        sum = sum + readings[i];
        valid++;

        if(readings[i] < 30)
        {
            normal++;
        }
        else if(readings[i] < 45)
        {
            warning++;
        }
        else if(readings[i] < 60)
        {
            critical++;
        }
        else
        {
            shutdown++;
        }
    }

    cout << endl;

    for(int i = 0; i < n; i++)
    {
        if(readings[i] < 0)
        {
            continue;
        }

        if(readings[i] >= 45)
        {
            cout << "First CRITICAL : Index "
                 << i << " -> "
                 << readings[i] << "C" << endl;

            break;
        }
    }

    double average = sum / valid;

    cout << "Skipped (errors) : "
         << skipped << endl;

    cout << "Min : " << min << "C" << endl;
    cout << "Max : " << max << "C" << endl;
    cout << "Avg : " << average << "C" << endl;

    cout << "Normal : " << normal << endl;
    cout << "Warning : " << warning << endl;
    cout << "Critical : " << critical << endl;
    cout << "Shutdown : " << shutdown << endl;

    return 0;
}