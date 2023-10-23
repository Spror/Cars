#include <gtest/gtest.h>
#include <PetrolCar.hpp>
#include <ElectricCar.hpp>
#include <memory>

class Cars : public testing::Test
{

 protected:
    PetrolCar CarP;
    ElectricCar CarE;
 
    void SetUp() override
    {
      CarP.changeEngine(std::make_unique<PetrolEngine>(1202, 1800,7));
      CarE.changeEngine(std::make_unique<ElectricEngine>(1202, 7));
    }

};



// Demonstrate some basic assertions.
TEST_F(Cars, GearChanging) {
 
 EXPECT_THROW(CarP.SetGear(-2), std::logic_error);
CarP.SetGear(-2);
 EXPECT_EQ(1,1);

}

int main(int argc, char **argv)
{

  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}