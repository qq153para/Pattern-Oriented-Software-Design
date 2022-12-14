#include "../src/two_dimensional_vector.h"
// vector (5.04,0.88)
TEST(TwoDimensionalVectorTest, testlength) {
    TwoDimensionalVector  Vector(
    new Point(-8.42, 3.42),
    new Point(-3.38, 4.3));
    ASSERT_NEAR(Vector.length(),5.11625,0.001);
}
TEST(TwoDimensionalVectorTest, testcross) {
    TwoDimensionalVector  Vector1(
    new Point(-8.42, 3.42),
    new Point(-3.38, 4.3));
    TwoDimensionalVector  Vector2(
    new Point(4, 0),
    new Point(5, 1));
    ASSERT_NEAR(Vector1.cross(&Vector2),4.16,0.001);
}
TEST(TwoDimensionalVectorTest, testdot) {
    TwoDimensionalVector  Vector1(
    new Point(-8.42, 3.42),
    new Point(-3.38, 4.3));
    TwoDimensionalVector  Vector2(
    new Point(4, 0),
    new Point(5, 1));
    ASSERT_NEAR(Vector1.dot(&Vector2),5.92,0.001);
}
TEST(TwoDimensionalVectorTest, testinfo) {
    TwoDimensionalVector Vector(new Point(-8.42, 3.42),new Point(-3.38, 4.3));
    ASSERT_STREQ("Vector ((-8.42, 3.42), (-3.38, 4.30))",Vector.info().c_str());
}