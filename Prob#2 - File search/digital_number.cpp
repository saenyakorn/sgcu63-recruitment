#include <iostream>
#include <string>
#include <vector>

// 5x5 template for 0-9 number
#include "./number_template.cpp"

using namespace std;

typedef vector<char> vc;

class DigitalNumber {
   public:
    DigitalNumber(string number, int ver_scale, int hor_scale);
    void set_number(string number);
    void set_ver_scale(int ver_scale);
    void set_hor_scale(int hor_scale);
    void print_canvas();
    void draw_canvas();

   private:
    string number;
    vector<vc> canvas;
    int ver_scale, hor_scale;
};

DigitalNumber::DigitalNumber(string number, int ver_scale, int hor_scale) {
    // initialize canvas (set all place with space)
    int number_len = number.size();
    int canvas_ver_len = 3 * ver_scale;
    int canvas_hor_len = 3 * hor_scale * number_len + (number_len * hor_scale);
    for (int i = 0; i < canvas_ver_len; i++) {
        vc canvas_hor(canvas_hor_len, ' ');
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
    for (int i = 0; i < canvas.size(); i++) {
        for (int j = 0; j < canvas[i].size(); i++) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}

void DigitalNumber::draw_canvas() {
    int def_scale = 5;
    for (int i = 0; i < canvas.size(); i++) {
        for (int j = 0; i < canvas[i].size(); j++) {
            int cur_number = number[j % (def_scale * hor_scale + hor_scale)] - '0';
            int pos_i = i / ver_scale;
            int pos_j = j / hor_scale;
            canvas[i][j] = pos_j >= 5 ? ' ' : number_template[cur_number][pos_i][pos_j];
        }
    }
}