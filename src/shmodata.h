#pragma one

#include <math.h>
#include <fstream>
#include <iostream>
#include <vector>

namespace shmo {

constexpr double kPi = M_PI;

struct ShmoInput {
  double mass = 0.0;
  double dampening = 0.0;
  double stiffness = 0.0;
  double initial_velocity = 0.0;
  double initial_position = 0.0;
  double start_time = 0.0;
  double stop_time = 0.0;
  int num_points = 0;
};

struct ShmoResults {
  std::vector<double> time;
  std::vector<double> position;
  friend std::ostream& operator<<(std::ostream& o, const ShmoResults&);
};

}  // namespace shmo
