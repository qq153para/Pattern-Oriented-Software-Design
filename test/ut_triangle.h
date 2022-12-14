#include "../src/triangle.h"
TEST(TriangleTest, testarea) {
    Point p1(0.00, 0.00);
    Point p2(3.00, 0.00);
    Point p3(3.00, 4.00);
    Point p4(3.00, 0.00);
    TwoDimensionalVector* v1 = new TwoDimensionalVector (p1,p2);
    TwoDimensionalVector* v2 =new TwoDimensionalVector (p3,p4);
    Triangle tri(*v1,*v2);
    delete v1;
    delete v2;
    ASSERT_NEAR(tri.area(),6,0.001);
}
TEST(TriangleTest, testperimeter) {
    Point p1(0.00, 0.00);
    Point p2(3.00, 0.00);
    Point p3(3.00, 4.00);
    Point p4(3.00, 0.00);
    TwoDimensionalVector* v1 = new TwoDimensionalVector ( p1 , p2);
    TwoDimensionalVector* v2 =new TwoDimensionalVector ( p3 , p4);
    Triangle tri(*v1 ,*v2);
    delete v1;
    delete v2;
    ASSERT_NEAR(tri.perimeter(),12,0.001);
}
TEST(TriangleTest, testinfo) {
    Point p1(0.00, 0.00);
    Point p2(3.00, 0.00);
    Point p3(3.00, 4.00);
    Point p4(3.00, 0.00);
    TwoDimensionalVector* v1 =new TwoDimensionalVector ( p1 , p2);
    TwoDimensionalVector* v2 =new TwoDimensionalVector ( p3 , p4);
    Triangle tri(*v1 ,*v2);
    delete v1;
    delete v2;
    ASSERT_STREQ("Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))",tri.info().c_str());

}
//  statement throws an exception of any type
TEST(TriangleTest, testexception1) {
    Point p1(0.00, 0.00);
    Point p2(3.01, 0.00);
    Point p3(3.00, 4.00);
    Point p4(3.00, 0.00);
    TwoDimensionalVector* v1 = new TwoDimensionalVector ( p1 , p2);
    TwoDimensionalVector* v2 = new TwoDimensionalVector ( p3 , p4);
    
    EXPECT_ANY_THROW(Triangle tri(*v1,*v2));
    delete v1;
    delete v2;
}
//	statement throws an exception of the given type
TEST(TriangleTest, testgetPoints) { 
    Point* p1=new Point(0.00, 0.00);
    Point* p2=new Point(2.00, 2.00);
    Point* p3=new Point(-2.00, 2.00);
    TwoDimensionalVector* v1 = new TwoDimensionalVector (*p1 ,*p2);
    TwoDimensionalVector* v2 = new TwoDimensionalVector (*p1 ,*p3);
    Triangle tri(*v1,*v2);
    std::set<Point> AllVertices=tri.getPoints();
    std::set<Point> Except;
    Except.insert(*p1);Except.insert(*p2);Except.insert(*p3);
    ASSERT_EQ( Except, AllVertices );
    delete p1;delete p2;delete p3;delete v1;delete v2;
}