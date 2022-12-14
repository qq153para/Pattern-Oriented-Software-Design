#include "../src/triangle.h"
TEST(TriangleTest, testarea) {
    Triangle tri(new TwoDimensionalVector ( new Point(0.00, 0.00), new Point(3.00, 0.00)),new TwoDimensionalVector (new Point(3.00, 4.00), new Point(3.00, 0.00)));
    ASSERT_NEAR(tri.area(),6,0.001);
}
TEST(TriangleTest, testperimeter) {
    Triangle tri(new TwoDimensionalVector ( new Point(0.00, 0.00), new Point(3.00, 0.00)),new TwoDimensionalVector (new Point(3.00, 4.00), new Point(3.00, 0.00)));
    ASSERT_NEAR(tri.perimeter(),12,0.001);
}
TEST(TriangleTest, testinfo) {
    Triangle tri(new TwoDimensionalVector ( new Point(0.00, 0.00), new Point(3.00, 0.00)),new TwoDimensionalVector (new Point(3.00, 4.00), new Point(3.00, 0.00)));
    ASSERT_STREQ("Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))",tri.info().c_str());
}
//  statement throws an exception of any type
TEST(TriangleTest, testexception1) {
    EXPECT_ANY_THROW(Triangle tri(new TwoDimensionalVector ( new Point(0.00, 0.00), new Point(3.01, 0.00)),new TwoDimensionalVector (new Point(3.00, 4.00), new Point(3.00, 0.00))));
}
//	statement throws an exception of the given type
TEST(TriangleTest, testexception2) { 
    EXPECT_THROW(Triangle tri(new TwoDimensionalVector ( new Point(3.00, 4.00), new Point(3.00, 0.00)),new TwoDimensionalVector (new Point(3.00, 4.00), new Point(3.00, 0.00))),const  char*);
}