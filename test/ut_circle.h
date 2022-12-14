#include "../src/circle.h"
TEST(CircleTest, testradius) {
    Circle circle(new TwoDimensionalVector(new Point(-4.284, 0.264),new Point(-4.827, 0.728)));
    ASSERT_NEAR(circle.radius(),0.714244,0.001);
}
TEST(CircleTest, testarea) {
    Circle circle(new TwoDimensionalVector(new Point(-4.284, 0.264),new Point(-4.827, 0.728)));
    ASSERT_NEAR(circle.area(),1.60267,0.001);
}
TEST(CircleTest, testperimeter) {
    Circle circle(new TwoDimensionalVector(new Point(-4.284, 0.264),new Point(-4.827, 0.728)));
    ASSERT_NEAR(circle.perimeter(),4.48773,0.001);
}
TEST(CircleTest, testinfo) {
    Circle circle(new TwoDimensionalVector(new Point(-4.284, 0.264),new Point(-4.827, 0.728)));
    ASSERT_STREQ("Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))",circle.info().c_str());
}