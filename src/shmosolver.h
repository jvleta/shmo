#pragma once

#include <memory>

#include "shmodata.h"

namespace shmo {

ShmoResults solve(const ShmoInput& input);

class ExactSolution;

class ISolver {
 protected:
  virtual void setup(const ShmoInput& input) = 0;
  virtual ShmoResults run() = 0;

 public:
  ISolver(){};
  ShmoResults solve(const ShmoInput& input) {
    setup(input);
    return run();
  }
};

class ExactSolution : public ISolver {
 public:
  ExactSolution(){};
  ~ExactSolution() = default;

 private:
  double mass_ = 0.0;
  double dampening_ = 0.0;
  double stiffness_ = 0.0;
  double natural_frequency_ = 0.0;
  double time_step_size_ = 0.0;
  double start_time_ = 0.0;
  double stop_time_ = 0.0;
  double initial_position_ = 0.0;
  double initial_velocity_ = 0.0;
  ShmoResults results_{};

  void setup(const ShmoInput& input) override;
  ShmoResults run() override;
};

/*
class SecondOrderOdeIntegrator : public ISolver {
 private
  void setup(const ShmoInput& input) override;
  void run() override();
  void print_reuslts() override;
};

class FirstOrderOdeSystemIntegrator : public ISolver {
 private
  void setup(const ShmoInput& input) override;
  void run() override();
  void print_reuslts() override;
};
*/

}  // namespace shmo
