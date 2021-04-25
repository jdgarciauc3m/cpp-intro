#include <iostream>
using namespace std;

struct punto1 {
  double x, y;
};

class punto2 {
public:
  punto2() : x_{0}, y_{0} {}
  punto2(double x, double y) : x_{x}, y_{y} {}
  
  void x(double x) { x_ = x; }
  double x() const { return x_; }
  void y(double y) { y_ = y; }
  double y() const { return y_; }

private:
  double x_, y_;
};

void f() {
  punto2 p{1.5, 2.5};
  p.x(2.0);
  cout << p.x() << " , " << p.y() << endl;
}

int main() {
  f();
}
