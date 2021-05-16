#include <iostream>
#include "gtest/gtest.h"

#include "shmosolver.h"

TEST(BaseCases, CosineWave){
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
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
