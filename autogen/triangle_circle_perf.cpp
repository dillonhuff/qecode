#include "triangle_circle.h"

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void benchmark_triangle_circle_intersection_code() {
  double a = 0.1;
  double b = 0.3;
  double r = 3;;

  double v1x = 8 + -0.2;
  double v1y = 8 + -0.1;

  double v2x = 20 + 1.0;
  double v2y = 16 + 2.3;

  double v3x = 10 + 1.0;
  double v3y = 10 + 0.2;

  int num_trials = 30;
  for (int i = 0; i < num_trials; i++) {
    bool intersect = triangle_circle(  a,  b,  r,  v1x,  v1y,  v2x,  v2y,  v3x, v3y );

    cout << intersect << endl;
  }
}

int main() {

  clock_t begin = clock();

  benchmark_triangle_circle_intersection_code();

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

  cout << "Unoptimized triangle-circle intersection = " << elapsed_secs << " secs" << endl;

}
