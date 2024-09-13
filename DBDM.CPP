#include<iostream>
using namespace std;

class DB;

class DM {
    int meter, cm;

    public:
        DM(int a, int b) : meter(a), cm(b) {}

        void disp(){
            cout << meter << " meters and " << cm << " centimeters." << endl;
        }

        friend DM addDist(const DM& a, const DB& b);
        friend DB addDist2(const DM& a, const DB& b);
};

class DB {
    int feet;
    double inches;

    public:
        DB(int a, double b) : feet(a), inches(b) {}

        void disp(){
            cout << feet << " feet and " << inches << " inches." << endl;
        }

        friend DM addDist(const DM& a, const DB& b);
        friend DB addDist2(const DM& a, const DB& b);
};

DM addDist(const DM& a, const DB& b) {
    double d1, d2;
    d1 = ((b.feet * 12) + b.inches) * 2.54;  
    d2 = (a.meter * 100) + a.cm; 
    
    double distance = d1 + d2;  

    int totalMeter = static_cast<int>(distance) / 100; 
    int remainingCm = static_cast<int>(distance) % 100;  

    return DM(totalMeter, remainingCm); 
}

DB addDist2(const DM& a, const DB& b) {
    double d1, d2;
    d1 = ((b.feet * 12) + b.inches) * 2.54;
    d2 = (a.meter * 100) + a.cm; 
    
    double totalCm = d1 + d2; 

    double totalInches = totalCm / 2.54; 
    int feet = static_cast<int>(totalInches) / 12;
    double inches = totalInches - (feet * 12);

    return DB(feet, inches);
}

int main() {
    DM dist1(2, 15);  
    DB dist2(6 ,10); 

    DM totalDistanceDM = addDist(dist1, dist2); 
    DB totalDistanceDB = addDist2(dist1, dist2); 

    cout << "Total Distance in Meters and Centimeters: ";
    totalDistanceDM.disp();

    cout << "Total Distance in Feet and Inches: ";
    totalDistanceDB.disp();

    return 0;
}
