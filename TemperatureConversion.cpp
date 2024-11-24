#include <iostream>
using namespace std;

class Temperature {
    double celsius;

public:
    Temperature(double c) : celsius(c) {}

    double toFahrenheit() {
        return (celsius * 9 / 5) + 32;
    }

    double toKelvin() {
        return celsius + 273.15;
    }
};

int main() {
    double c;
    cout << "Enter temperature in Celsius: ";
    cin >> c;

    Temperature temp(c);
    cout << "Temperature in Fahrenheit: " << temp.toFahrenheit() << endl;
    cout << "Temperature in Kelvin: " << temp.toKelvin() << endl;

    return 0;
}
