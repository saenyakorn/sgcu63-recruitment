#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<char> vc;

class DigitalNumber {
   public:
    DigitalNumber(string number, int ver_scale, int hor_scale);
    void set_number(string number);
    void set_ver_scale(int ver_scale);
    void set_hor_scale(int hor_scale);
    void print_canvas();

   private:
    string number;
    vector<vc> canvas;
    int ver_scale, hor_scale;
};

DigitalNumber::DigitalNumber(string number, int ver_scale, int hor_scal) {
    // initialize canvas (set all place with NULL)
    int number_len = number.length();
    int canvas_ver_len = 3 * ver_scale;
    int canvas_hor_len = 3 * hor_scale * number_len;
    for (int i = 0; i < canvas_ver_len; i++) {
        vc canvas_hor(canvas_hor_len, NULL);
        canvas.push_back(canvas_hor);
    }

    // set number, ver_scale and hor_scale with user input
    set_number(number);
    set_ver_scale(ver_scale);
    set_hor_scale(hor_scale);
}

void DigitalNumber::set_number(string number) {
    this->number = number;
}

void DigitalNumber::set_ver_scale(int ver_scale) {
    this->ver_scale = ver_scale;
}

void DigitalNumber::set_hor_scale(int hor_scale) {
    this->hor_scale = hor_scale;
}

void DigitalNumber::print_canvas() {
    for (vc canvas_hor : canvas) {
        for (char c : canvas_hor) {
            cout << c;
        }
        cout << endl;
    }
}