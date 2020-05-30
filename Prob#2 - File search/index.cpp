#include <iostream>
#include <string>
#include <vector>

// customize class
#include "./digital_number.cpp"

using namespace std;

int main() {
    string number;
    int ver_scale, hor_scale;
    cout << "wowza";
    cin >> number >> ver_scale >> hor_scale;

    // Construct digital number named "digitalNumber"
    DigitalNumber digitalNumber(number, ver_scale, hor_scale);

    // Draw the number to canvas
    digitalNumber.draw_canvas();

    // Output
    digitalNumber.print_canvas();
}