#include "ellipse_circle.h"

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void benchmark_ellipsoid_plane_intersection_code() {


  int num_trials = 30;
  for (int i = 0; i < num_trials; i++) {
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
