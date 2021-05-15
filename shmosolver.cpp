#include "shmosolver.h"

namespace shmo {

void ExactSolution::setup(const ShmoInput& input) {
  mass_ = input.mass;
  dampening_ = input.dampening;
  stiffness_ = input.stiffness;
  natural_frequency_ = 1.0 / (2.0 * kPi) * std::sqrt(stiffness_ / mass_);
  start_time_ = input.start_time;
  stop_time_ = input.stop_time;
  time_step_size_ = (stop_time_ - start_time_) / (input.num_points - 1);
  initial_position_ = input.initial_position;
  initial_velocity_ = input.initial_velocity;
  results_.time.resize(input.num_points, 0.0);
  results_.position.resize(input.num_points, 0.0);
}

ShmoResults ExactSolution::run() {
  auto& t = results_.time;
  auto& x = results_.position;
  auto x0 = initial_position_;
  auto v0 = initial_velocity_;
  auto omega_n = natural_frequency_ * 2.0 * kPi;
  for (int i = 0; i < results_.time.size(); ++i) {
    t[i] = i * time_step_size_;
    x[i] =
        x0 * std::cos(omega_n * t[i]) + v0 / omega_n * std::sin(omega_n * t[i]);
  }
  return results_;
}

ShmoResults solve(const ShmoInput& input) {
  auto solver = std::make_unique<ExactSolution>();
  return solver->solve(input);
}

}  // namespace shmo
