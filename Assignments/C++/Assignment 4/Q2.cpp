#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


// ================= VEHICLE =================

class Vehicle
{
protected:

    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:

    Vehicle(const string& reg,
            const string& owner,
            int year,
            double km)
    {
        registrationNo = reg;
        ownerName = owner;
        yearOfManufacture = year;
        kmDriven = km;

        cout << "[Vehicle Constructor] "
             << registrationNo << " : "
             << ownerName << endl;
    }

    virtual double fuelCost(double kmToTravel) const = 0;

    virtual void describe() const
    {
        cout << "Registration: "
             << registrationNo << endl;

        cout << "Owner: "
             << ownerName << endl;

        cout << "Year: "
             << yearOfManufacture << endl;

        cout << "Km Driven: "
             << kmDriven << endl;
    }

    virtual string vehicleType() const = 0;

    virtual ~Vehicle()
    {
        cout << "[Vehicle Destructor] "
             << registrationNo << endl;
    }

    double getKmDriven() const
    {
        return kmDriven;
    }

    string getRegNo() const
    {
        return registrationNo;
    }

    string getOwnerName() const
    {
        return ownerName;
    }
};


// ================= CAR =================

class Car : public Vehicle
{
private:

    string fuelType;
    double mileageKmpl;

public:

    Car(const string& reg,
        const string& owner,
        int year,
        double km,
        string fuel,
        double mileage)
        : Vehicle(reg, owner, year, km)
    {
        fuelType = fuel;
        mileageKmpl = mileage;

        cout << "[Car Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        double fuelPrice;

        if (fuelType == "Petrol")
            fuelPrice = 106.00;
        else
            fuelPrice = 93.00;

        return (kmToTravel / mileageKmpl) * fuelPrice;
    }

    string vehicleType() const override
    {
        return "Car";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Fuel Type: "
             << fuelType << endl;

        cout << "Mileage: "
             << mileageKmpl << " km/l"
             << endl;
    }

    ~Car()
    {
        cout << "[Car Destructor] "
             << registrationNo << endl;
    }
};


// ================= TRUCK =================

class Truck : public Vehicle
{
protected:

    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:

    Truck(const string& reg,
          const string& owner,
          int year,
          double km,
          double payload,
          double efficiency)
        : Vehicle(reg, owner, year, km)
    {
        payloadCapacityTons = payload;
        fuelEfficiencyKmpl = efficiency;

        cout << "[Truck Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        double efficiency = fuelEfficiencyKmpl;

        efficiency = efficiency *
                     (1 - 0.05 * payloadCapacityTons);

        return (kmToTravel / efficiency) * 93.00;
    }

    string vehicleType() const override
    {
        return "Truck";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Payload: "
             << payloadCapacityTons
             << " tons" << endl;

        cout << "Fuel Efficiency: "
             << fuelEfficiencyKmpl
             << " km/l" << endl;
    }

    ~Truck()
    {
        cout << "[Truck Destructor] "
             << registrationNo << endl;
    }
};


// ================= ELECTRIC TRUCK =================

class ElectricTruck : public Truck
{
private:

    double batteryCapacityKWh;
    double rangePerChargeKm;

public:

    ElectricTruck(const string& reg,
                  const string& owner,
                  int year,
                  double km,
                  double payload,
                  double efficiency,
                  double battery,
                  double range)
        : Truck(reg, owner, year, km,
                payload, efficiency)
    {
        batteryCapacityKWh = battery;
        rangePerChargeKm = range;

        cout << "[ElectricTruck Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        return (kmToTravel / rangePerChargeKm)
               * batteryCapacityKWh
               * 9.50;
    }

    string vehicleType() const override
    {
        return "Electric Truck";
    }

    void describe() const override
    {
        Truck::describe();

        cout << "Battery Capacity: "
             << batteryCapacityKWh
             << " kWh" << endl;

        cout << "Range: "
             << rangePerChargeKm
             << " km" << endl;
    }

    double getBatteryCapacity() const
    {
        return batteryCapacityKWh;
    }

    ~ElectricTruck()
    {
        cout << "[ElectricTruck Destructor] "
             << registrationNo << endl;
    }
};


// ================= VAN =================

class Van : public Vehicle
{
private:

    int seatingCapacity;
    double mileageKmpl;

public:

    Van(const string& reg,
        const string& owner,
        int year,
        double km,
        int seats,
        double mileage)
        : Vehicle(reg, owner, year, km)
    {
        seatingCapacity = seats;
        mileageKmpl = mileage;

        cout << "[Van Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        return (kmToTravel / mileageKmpl) * 106.00;
    }

    string vehicleType() const override
    {
        return "Van";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Seats: "
             << seatingCapacity << endl;

        cout << "Mileage: "
             << mileageKmpl << " km/l"
             << endl;
    }

    ~Van()
    {
        cout << "[Van Destructor] "
             << registrationNo << endl;
    }
};


// ================= FLEET REPORT =================

void printFleetReport(const vector<Vehicle*>& fleet,
                      double tripKm)
{
    cout << endl;
    cout << "===== FLEET REPORT =====" << endl;

    cout << left
         << setw(15) << "Registration"
         << setw(20) << "Type"
         << setw(20) << "Owner"
         << "Km Driven"
         << endl;

    for (int i = 0; i < fleet.size(); i++)
    {
        cout << left
             << setw(15) << fleet[i]->getRegNo()
             << setw(20) << fleet[i]->vehicleType()
             << setw(20) << fleet[i]->getOwnerName()
             << fleet[i]->getKmDriven()
             << endl;
    }


    cout << endl;
    cout << "===== FUEL / CHARGE COST ====="
         << endl;

    double lowestCost = 999999999;
    Vehicle* efficientVehicle = nullptr;

    for (int i = 0; i < fleet.size(); i++)
    {
        double cost = fleet[i]->fuelCost(tripKm);

        cout << fleet[i]->getRegNo()
             << " (" << fleet[i]->vehicleType()
             << ") : Rs. "
             << fixed << setprecision(2)
             << cost
             << endl;

        if (cost < lowestCost)
        {
            lowestCost = cost;
            efficientVehicle = fleet[i];
        }


        ElectricTruck* electric =
            dynamic_cast<ElectricTruck*>(fleet[i]);

        if (electric != nullptr)
        {
            cout << "  Electric Truck detected"
                 << endl;
        }
    }


    cout << endl;

    cout << "Most Efficient Vehicle: "
         << efficientVehicle->getRegNo()
         << " ("
         << efficientVehicle->vehicleType()
         << ") - Rs. "
         << lowestCost
         << endl;
}


// ================= MAIN =================

int main()
{
    // Constructor / Destructor demonstration

    cout << "===== CONSTRUCTOR ORDER ====="
         << endl;

    {
        ElectricTruck electricTruck(
            "V-ET001",
            "Green Logistics",
            2024,
            89000,
            5,
            4.0,
            85,
            300
        );
    }


    cout << endl;
    cout << "===== FLEET ====="
         << endl;

    vector<Vehicle*> fleet;

    fleet.push_back(
        new Car(
            "KA01AA001",
            "Ramesh Kumar",
            2022,
            45200,
            "Petrol",
            18
        )
    );

    fleet.push_back(
        new Truck(
            "MH04BB002",
            "Shyam Logistics",
            2020,
            123500,
            8,
            5
        )
    );

    fleet.push_back(
        new ElectricTruck(
            "GJ07CC003",
            "Green Fleet Co",
            2024,
            89000,
            5,
            4,
            85,
            300
        )
    );

    fleet.push_back(
        new Van(
            "DL08DD004",
            "City Transport",
            2021,
            70000,
            8,
            15
        )
    );

    fleet.push_back(
        new Car(
            "MH12EE005",
            "Amit Sharma",
            2023,
            30000,
            "Diesel",
            20
        )
    );


    printFleetReport(fleet, 200);


    // Delete all vehicles

    for (int i = 0; i < fleet.size(); i++)
    {
        delete fleet[i];
    }

    return 0;
}