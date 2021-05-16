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
  input.num_points = 100;
  input.initial_position = 1.0;
  input.initial_velocity = 0.0;
  input.stop_time = 6.28;
  shmo::ShmoResults results = shmo::solve(input);

  std::cout << results;
  plt::plot(results.time, results.position);
  plt::xlabel("time (seconds)");
  plt::ylabel("position (inches)");
  plt::grid(true);
  plt::show();
}
