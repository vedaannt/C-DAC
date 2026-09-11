#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// ================= ABSTRACT CLASS =================

class DataProcessor
{
public:

    virtual void loadData(const string& source) = 0;

    virtual void processData() = 0;

    virtual void exportResult(
        const string& destination) = 0;

    virtual string processorType() const = 0;

    virtual int recordCount() const = 0;

    virtual void printSummary() const
    {
        cout << "Processor: "
             << processorType()
             << endl;

        cout << "Records: "
             << recordCount()
             << endl;
    }

    virtual ~DataProcessor() = default;
};


// ================= CSV PROCESSOR =================

class CSVProcessor : public DataProcessor
{
private:

    vector<string> records;

public:

    void loadData(const string& source) override
    {
        records.clear();

        records.push_back("name,age");
        records.push_back("vedant,22");
        records.push_back("rahul,23");
        records.push_back("amit,21");
        records.push_back("rohan,24");

        cout << "CSV data loaded from "
             << source << endl;
    }

    void processData() override
    {
        for (int i = 0; i < records.size(); i++)
        {
            for (int j = 0; j < records[i].length(); j++)
            {
                records[i][j] =
                    toupper(records[i][j]);
            }
        }
    }

    void exportResult(
        const string& destination) override
    {
        cout << "[CSV EXPORT -> "
             << destination << "]"
             << endl;

        for (int i = 0; i < records.size(); i++)
        {
            cout << records[i] << endl;
        }
    }

    string processorType() const override
    {
        return "CSV Processor";
    }

    int recordCount() const override
    {
        return records.size();
    }
};


// ================= SENSOR PROCESSOR =================

class SensorStreamProcessor : public DataProcessor
{
private:

    vector<double> readings;

    double mean;
    double minimum;
    double maximum;

public:

    SensorStreamProcessor()
    {
        mean = 0;
        minimum = 0;
        maximum = 0;
    }

    void loadData(const string& source) override
    {
        readings.clear();

        readings.push_back(23.4);
        readings.push_back(21.8);
        readings.push_back(25.1);
        readings.push_back(24.5);
        readings.push_back(22.9);
        readings.push_back(26.2);
        readings.push_back(23.7);
        readings.push_back(24.1);

        cout << "Sensor data loaded from "
             << source << endl;
    }

    void processData() override
    {
        minimum = readings[0];
        maximum = readings[0];

        double sum = 0;

        for (int i = 0; i < readings.size(); i++)
        {
            sum += readings[i];

            if (readings[i] < minimum)
                minimum = readings[i];

            if (readings[i] > maximum)
                maximum = readings[i];
        }

        mean = sum / readings.size();
    }

    void exportResult(
        const string& destination) override
    {
        cout << "[SENSOR EXPORT -> "
             << destination << "]"
             << endl;

        cout << "Mean: "
             << mean << endl;

        cout << "Minimum: "
             << minimum << endl;

        cout << "Maximum: "
             << maximum << endl;
    }

    string processorType() const override
    {
        return "Sensor Stream Processor";
    }

    int recordCount() const override
    {
        return readings.size();
    }

    double getMean() const
    {
        return mean;
    }
};


// ================= MAIN =================

int main()
{
    vector<DataProcessor*> pipeline;

    pipeline.push_back(
        new CSVProcessor()
    );

    pipeline.push_back(
        new SensorStreamProcessor()
    );


    for (auto* p : pipeline)
    {
        p->loadData("source_data");

        p->processData();

        p->printSummary();

        p->exportResult("output_dir");

        cout << "---" << endl;
    }


    // DataProcessor dp;
    // ERROR:
    // DataProcessor is an abstract class because
    // it contains pure virtual functions.


    // Bonus dynamic_cast

    for (auto* p : pipeline)
    {
        CSVProcessor* csv =
            dynamic_cast<CSVProcessor*>(p);

        if (csv != nullptr)
        {
            cout << "Found CSV Processor with "
                 << csv->recordCount()
                 << " records."
                 << endl;
        }

        SensorStreamProcessor* sensor =
            dynamic_cast<SensorStreamProcessor*>(p);

        if (sensor != nullptr)
        {
            cout << "Found Sensor Processor - Mean: "
                 << sensor->getMean()
                 << endl;
        }
    }


    // Cleanup

    for (auto* p : pipeline)
    {
        delete p;
    }

    return 0;
}