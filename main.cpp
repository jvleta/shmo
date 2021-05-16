#include <iostream>

#include "matplotlibcpp.h"
#include "shmosolver.h"

namespace plt = matplotlibcpp;

int main() {
  std::cout << "SHMO!\n";

  shmo::ShmoInput input{};

  input.mass = 1.0;
  input.stiffness = 1.0;
  input.dampening = 0.0;
  input.num_points = 25;
  input.initial_position = 1.0;
  input.initial_velocity = 10.0;
  input.stop_time = 10.0;
  shmo::ShmoResults results = shmo::solve(input);

  std::cout << results;
  plt::plot(results.time, results.position);
  plt::show();
}
