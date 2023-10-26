#include <gtest/gtest.h>
#include <PetrolCar.hpp>
#include <ElectricCar.hpp>
#include <memory>

class Cars : public testing::Test
{
public:
  Cars() : CarE(std::make_unique<ElectricEngine>(150, 60)), CarP(std::make_unique<PetrolEngine>(50, 1200, 6)) {}

protected:
  PetrolCar CarP;
  ElectricCar CarE;
};

TEST_F(Cars, GearChangingTest)
{

  EXPECT_NO_THROW(CarP.SetGear(1));

  // shifting into negative a gear
  EXPECT_THROW(CarP.SetGear(-2), PetrolEngine::InvalidGear);

  // shifting into too high a gear
  EXPECT_THROW(CarP.SetGear(8), PetrolEngine::InvalidGear);

  // shifting into reverse from a forward gear
  EXPECT_THROW(CarP.SetGear(-1), PetrolEngine::InvalidGear);
}

TEST_F(Cars, AccelerateTest)
{
  CarP.accelerate(100);
  CarE.accelerate(100);
  EXPECT_EQ(CarP.getSpeed(), 100);
  EXPECT_EQ(CarE.getSpeed(), 100);

  // accelerating of negative value
  EXPECT_THROW(CarP.accelerate(-10), std::out_of_range);
  EXPECT_THROW(CarE.accelerate(-10), std::out_of_range);

  // exceeding maximum speed
  EXPECT_THROW(CarP.accelerate(CarP.getMaxSpeed()+1), std::out_of_range);
  EXPECT_THROW(CarE.accelerate(CarE.getMaxSpeed()+1), std::out_of_range);
}

int main(int argc, char **argv)
{

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}