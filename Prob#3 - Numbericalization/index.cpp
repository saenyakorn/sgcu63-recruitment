#include <iostream>
#include <string>
#include <vector>
#include <utility>

typedef vector<char> vc;

using namespace std;

vector<vc> initialize_canvas(string number, int ver_scale, int hor_scale)
{
  vector<vc> canvas;
  int number_len = number.length();
  int canvas_ver_len = 3 * ver_scale;
  int canvas_hor_len = 3 * hor_scale * number_len;
  for (int i = 0; i < canvas_ver_len; i++)
  {
    vc canvas_hor(canvas_hor_len, NULL);
    canvas.push_back(canvas_hor);
  }
  return canvas;
}

int main()
{
  string number;
  int ver_scale, hor_scale;
  cin >> number >> ver_scale >> hor_scale;

  vector<vc> canvas = initialize_canvas(number, ver_scale, hor_scale);
}