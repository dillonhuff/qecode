#include "sphere_ellipsoid_opt.h"

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void benchmark_ellipsoid_plane_intersection_code() {

  // Plane variables
  double a = 0.2;
  double b = 2.3;
  double c = 1;
  double d = 1.1;

  //Ellipsoid variables

  // Offsets
  double f = 3;
  double g = -2;
  double h = 1;

  // Major axis lengths
  double l = 3; // x
  double m = 2; // y
  double n = 1; // z

  int num_trials = 30;
  for (int i = 0; i < num_trials; i++) {
    bool intersect = sphere_ellipsoid_opt(  a,  b,  c,  d,  f,  g,  h,  l,  m,  n );
    cout << intersect << endl;
  }
  
}

int main() {
  clock_t begin = clock();

  benchmark_ellipsoid_plane_intersection_code();

  clock_t end = clock();
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

  cout << "Optimized ellipsoid-plane intersection = " << elapsed_secs << " secs" << endl;
}
