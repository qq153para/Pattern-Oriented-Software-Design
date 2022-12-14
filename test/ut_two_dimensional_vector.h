#include "../src/two_dimensional_vector.h"
// vector (5.04,0.88)
TEST(TwoDimensionalVectorTest, testlength) {
    Point p1(-8.42, 3.42);
    Point p2(-3.38, 4.3);
    TwoDimensionalVector  Vector(p1,p2);

    ASSERT_NEAR(Vector.length(),5.11625,0.001);
}
TEST(TwoDimensionalVectorTest, testcross) {
    Point p1(-8.42, 3.42);
    Point p2(-3.38, 4.3);
    Point p3(4, 0);
    Point p4(5, 1);
    TwoDimensionalVector  Vector1(p1,p2);
    TwoDimensionalVector  Vector2(p3,p4);
    ASSERT_NEAR(Vector1.cross(Vector2),4.16,0.001);
}
TEST(TwoDimensionalVectorTest, testdot) {
    Point p1(-8.42, 3.42);
    Point p2(-3.38, 4.3);
    Point p3(4, 0);
    Point p4(5, 1);
    TwoDimensionalVector  Vector1(p1,p2);
    TwoDimensionalVector  Vector2(p3,p4);
    ASSERT_NEAR(Vector1.dot(Vector2),5.92,0.001);
}
TEST(TwoDimensionalVectorTest, testinfo) {
    Point p1(-8.42, 3.42);
    Point p2(-3.38, 4.3);
    TwoDimensionalVector Vector(p1,p2);
    ASSERT_STREQ("Vector ((-8.42, 3.42), (-3.38, 4.30))",Vector.info().c_str());
}