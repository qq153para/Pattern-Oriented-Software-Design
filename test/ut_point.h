#include "../src/point.h"
TEST(PointTest, testOperator1) {
    Point Point1(0.1, 0.1);
    Point Point2(0.1, 0.1);
    ASSERT_TRUE(Point1.operator==(Point2));
}
TEST(PointTest, testOperator2) {
    Point Point1(0.1, 0.1);
    Point Point2(0.1, 0.3);
    ASSERT_FALSE(Point1.operator==(Point2));
}
TEST(PointTest, testinfo) {
    Point Point(-4.586, -3.471);
    ASSERT_STREQ("(-4.59, -3.47)",Point.info().c_str());
}
