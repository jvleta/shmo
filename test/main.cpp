#include <iostream>
#include <fstream>

#include "gtest/gtest.h"

#include "shmosolver.h"

TEST(BaseCases, CosineWave){
    shmo::ShmoInput input{};
    input.mass = 1.0;
    input.stiffness = 1.0;
    input.dampening = 0.0;
    input.num_points = 20;
    input.initial_position = 1.0;
    input.initial_velocity = 0.0;
    input.stop_time = 6.28;
    shmo::ShmoResults results = shmo::solve(input);
    for (int i = 0; i < input.num_points; ++i) {
        EXPECT_EQ(results.position[i], std::cos(results.time[i]));
    }
}

TEST(BaseCases, SineWave){
    shmo::ShmoInput input{};
    input.mass = 1.0;
    input.stiffness = 1.0;
    input.dampening = 0.0;
    input.num_points = 20;
    input.initial_position = 0.0;
    input.initial_velocity = 1.0;
    input.stop_time = 6.28;
    shmo::ShmoResults results = shmo::solve(input);
    for (int i = 0; i < input.num_points; ++i) {
        EXPECT_EQ(results.position[i], std::sin(results.time[i]));
    }
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
