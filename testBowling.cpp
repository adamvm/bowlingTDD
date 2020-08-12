#include "bowling.hpp"
#include <gtest/gtest.h>
using namespace std;

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void rollMany(int n, int pins, bowling& game) {
  for (int i = 0; i < n; ++i) {
    game.roll(pins);
  }
}

void rollSpare(bowling& game) {
    game.roll(5);
    game.roll(5);
}

class setup : public ::testing::Test {
public:
  bowling game;
};

TEST_F(setup, gutterGame)
{
  rollMany(20, 0, game);
  ASSERT_EQ(0, game.score());
}

TEST_F(setup, allOnes)
{
  rollMany(20, 1, game);
  ASSERT_EQ(20, game.score());
}

TEST_F(setup, oneSpare)
{
  rollSpare(game);
  game.roll(3);
  rollMany(17, 0, game);
  ASSERT_EQ(16, game.score());
}

TEST_F(setup, oneStrike)
{ game.roll(10); // strike
  game.roll(3);
  game.roll(4);
  rollMany(16, 0, game);
  ASSERT_EQ(24, game.score());
}

TEST_F(setup, perfectGame)
{
  rollMany(12, 10, game);
  ASSERT_EQ(300, game.score());
}

