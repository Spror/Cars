#include <gtest/gtest.h>
#include <PetrolCar.hpp>
#include <ElectricCar.hpp>
#include <memory>

class Cars : public testing::Test
{
 public: 
  Cars(): CarE(std::make_unique<ElectricEngine>(150, 60)), CarP(std::make_unique<PetrolEngine>(50, 1200, 6)) {}

 protected:
    PetrolCar CarP;
    ElectricCar CarE;
};




TEST_F(Cars, GearChangingTest){
 
 EXPECT_NO_THROW(CarP.SetGear(1));

 // shifting into negative a gear
 EXPECT_THROW(CarP.SetGear(-2), PetrolEngine::InvalidGear);

 // shifting into too high a gear
 EXPECT_THROW(CarP.SetGear(8), PetrolEngine::InvalidGear);

 // shifting into reverse from a forward gear
 EXPECT_THROW(CarP.SetGear(-1), PetrolEngine::InvalidGear);
 
}


TEST_F(Cars, AccelerateTest){
 
 EXPECT_NO_THROW(CarP.SetGear(1));

 // shifting into negative a gear
 EXPECT_THROW(CarP.SetGear(-2), std::logic_error);

 // shifting into too high a gear
 EXPECT_THROW(CarP.SetGear(8), std::logic_error);

 // shifting into reverse from a forward gear
 EXPECT_THROW(CarP.SetGear(-1), std::logic_error);
 
}

int main(int argc, char **argv)
{

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}