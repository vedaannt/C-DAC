#include <iostream>
#include <cmath>

using namespace std;

double computeRMS(double* signal, int n)
{
    double sum = 0;

    double* ptr = signal;

    for(int i = 0; i < n; i++)
    {
        sum = sum + (*ptr * *ptr);

        ptr++;
    }

    return sqrt(sum / n);
}

void normalise(double* signal, int n)
{
    double max = 0;

    double* ptr = signal;

    for(int i = 0; i < n; i++)
    {
        if(fabs(*ptr) > max)
        {
            max = fabs(*ptr);
        }

        ptr++;
    }

    ptr = signal;

    for(int i = 0; i < n; i++)
    {
        *ptr = *ptr / max;

        ptr++;
    }
}

int countZeroCrossings(double* signal, int n)
{
    int count = 0;

    double* ptr = signal;

    for(int i = 0; i < n - 1; i++)
    {
        if((*ptr > 0 && *(ptr + 1) < 0) ||
           (*ptr < 0 && *(ptr + 1) > 0))
        {
            count++;
        }

        ptr++;
    }

    return count;
}

void applyGain(double* signal, int n, double gainFactor)
{
    double* ptr = signal;

    for(int i = 0; i < n; i++)
    {
        *ptr = *ptr * gainFactor;

        ptr++;
    }
}

int main()
{
    double signal[] =
    {
        0.5, -1.2, 0.8, -0.3,
        1.0, -0.9, 0.1
    };

    int n = 7;

    cout << "Before : ";

    for(int i = 0; i < n; i++)
    {
        cout << signal[i] << " ";
    }

    cout << endl;

    double rms = computeRMS(signal, n);

    int crossings = countZeroCrossings(signal, n);

    normalise(signal, n);

    cout << "After normalise : ";

    for(int i = 0; i < n; i++)
    {
        cout << signal[i] << " ";
    }

    cout << endl;

    applyGain(signal, n, 2);

    cout << "After gain : ";

    for(int i = 0; i < n; i++)
    {
        cout << signal[i] << " ";
    }

    cout << endl;

    cout << "RMS : " << rms << endl;

    cout << "Zero Crossings : "
         << crossings << endl;

    return 0;
}