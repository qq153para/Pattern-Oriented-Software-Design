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
TEST(TriangleTest, testgetPoints) { 
    Point *p1=new Point(0.00, 0.00);
    Point *p2=new Point(2.00, 2.00);
    Point *p3=new Point(-2.00, 2.00);
    Triangle tri(new TwoDimensionalVector (p1 ,p2),new TwoDimensionalVector (p1,p3));
    std::set<const Point*> AllVertices=tri.getPoints(); 
    std::set<const Point*> Except; 
    Except.insert(p1);Except.insert(p2);Except.insert(p3);
    ASSERT_EQ( Except, AllVertices );
}