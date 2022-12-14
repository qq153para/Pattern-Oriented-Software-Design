#include "../src/rectangle.h"
TEST(RectangleTest, testarea) {
    Rectangle rec(new TwoDimensionalVector ( new Point(-2, 1), new Point(1.5, 0.47)),new TwoDimensionalVector (new Point(-2, 1), new Point(-1.47, 4.5)));
    ASSERT_NEAR(rec.area(),12.53089201,0.001);
}
//distance between (-2, 1) and (1.5, 0.47)=3.5399
//distance between (-2, 1) and (1.5, 0.47)=3.5399
TEST(RectangleTest, testperimeter) {
    Rectangle rec(new TwoDimensionalVector ( new Point(-2, 1), new Point(1.5, 0.47)),new TwoDimensionalVector (new Point(-2, 1), new Point(-1.47, 4.5)));
    ASSERT_NEAR(rec.perimeter(),14.1596,0.001);
}
TEST(RectangleTest, testinfo) {
    Rectangle rec(new TwoDimensionalVector ( new Point(-2, 1), new Point(1.5, 0.47)),new TwoDimensionalVector (new Point(-2, 1), new Point(-1.47, 4.5)));
    ASSERT_STREQ("Rectangle (Vector ((-2.00, 1.00), (1.50, 0.47)), Vector ((-2.00, 1.00), (-1.47, 4.50)))",rec.info().c_str());
}
//  statement throws an exception of any type
TEST(RectangleTest, testexception1) {
    EXPECT_ANY_THROW(   Rectangle rec(new TwoDimensionalVector ( new Point(-1, 1), new Point(1.5, 0.47)),new TwoDimensionalVector (new Point(-2, 1), new Point(-1.47, 4.5))));
}
//	statement throws an exception of the given type
TEST(RectangleTest, testexception2) { 
    EXPECT_THROW(   Rectangle rec(new TwoDimensionalVector ( new Point(-1, 1), new Point(1.5, 0.47)),new TwoDimensionalVector (new Point(-2, 1), new Point(-1.47, 4.5))),const  char*);
}