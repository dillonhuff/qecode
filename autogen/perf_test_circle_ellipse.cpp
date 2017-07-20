#include "ellipse_circle.h"

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void benchmark_ellipse_circle_intersection_code() {
  double a = 3.5;
  double b = -4.5;
  double r = sqrt(5);

  double c = 7;
  double d = 23;

  double h = 3.3;
  double k = -4;


  int num_trials = 30;
  for (int i = 0; i < num_trials; i++) {
    bool it = shapes_intersect(a, b, c, d, h, k, r);
    cout << it << endl;
  }
  
}

int main() {
  clock_t begin = clock();

  benchmark_ellipse_circle_intersection_code();

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

  cout << "Unoptimized circle-ellipse intersection = " << elapsed_secs << " secs" << endl;
}
