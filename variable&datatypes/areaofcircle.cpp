#include <iostream>
#include<iomanip>
#define PI 3.14159265359
using namespace std;
int main() {
  int r;
  cout << "enter the radius of circle:" << endl;
  cin >> r;
  double area = PI * r * r;
  cout <<"area of entered circle is "<< setprecision(area)<< area;
  return 0;
}
