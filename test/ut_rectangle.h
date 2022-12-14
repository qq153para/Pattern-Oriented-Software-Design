#include "../src/rectangle.h"
TEST(RectangleTest, testarea) {
    Point p1(-2, 1);
    Point p2(1.5, 0.47);
    Point p3(-2, 1);
    Point p4(-1.47, 4.5);
    TwoDimensionalVector* v1 = new TwoDimensionalVector (p1,p2);
    TwoDimensionalVector* v2 = new TwoDimensionalVector (p3,p4);
    Rectangle rec(*v1,*v2);
    ASSERT_NEAR(rec.area(),12.53089201,0.001);
    delete v1;
    delete v2;
}

TEST(RectangleTest, testperimeter) {
    Point p1(-2, 1);
    Point p2(1.5, 0.47);
    Point p3(-2, 1);
    Point p4(-1.47, 4.5);
    TwoDimensionalVector* v1 = new TwoDimensionalVector (p1,p2);
    TwoDimensionalVector* v2 = new TwoDimensionalVector (p3,p4);
    Rectangle rec(*v1,*v2);
    ASSERT_NEAR(rec.perimeter(),14.1596,0.001);
    delete v1;
    delete v2;
}
TEST(RectangleTest, testinfo) {
    Point p1(-2, 1);
    Point p2(1.5, 0.47);
    Point p3(-2, 1);
    Point p4(-1.47, 4.5);
    TwoDimensionalVector* v1 = new TwoDimensionalVector (p1,p2);
    TwoDimensionalVector* v2 = new TwoDimensionalVector (p3,p4);
    Rectangle rec(*v1,*v2);
    ASSERT_STREQ("Rectangle (Vector ((-2.00, 1.00), (1.50, 0.47)), Vector ((-2.00, 1.00), (-1.47, 4.50)))",rec.info().c_str());
    delete v1;
    delete v2;
}
//  statement throws an exception of any type
TEST(RectangleTest, testexception1) {
    Point p1(-1, 1);  
    Point p2(1.5, 0.47);
    Point p3(-2, 1);  
    Point p4(-1.47, 4.5);
    TwoDimensionalVector* v1 = new TwoDimensionalVector (p1,p2);
    TwoDimensionalVector* v2 = new TwoDimensionalVector (p3,p4);
    EXPECT_ANY_THROW( Rectangle rec(*v1,*v2));
    delete v1;
    delete v2;
}
//	statement throws an exception of the given type
TEST(RectangleTest, testexception2) { 
    Point p1(-1, 1);  
    Point p2(1.5, 0.47);
    Point p3(-2, 1);  
    Point p4(-1.47, 4.5);
    TwoDimensionalVector* v1 = new TwoDimensionalVector (p1,p2);
    TwoDimensionalVector* v2 = new TwoDimensionalVector (p3,p4);
    EXPECT_THROW(  Rectangle rec(*v1,*v2),const  char*);
    delete v1;
    delete v2;
}
TEST(RectangleTest, testgetPoints) { 
    Point *p1=new Point(0.00, 0.00);
    Point *p2=new Point(2.00, 2.00);
    Point *p3=new Point(-2.00, 2.00);
    Point *p4=new Point(0.00, 4.00);
    TwoDimensionalVector* v1 = new TwoDimensionalVector (*p1 ,*p2);
    TwoDimensionalVector* v2 = new TwoDimensionalVector (*p1 ,*p3);
    Shape *rec=new Rectangle(*v1,*v2);
    std::set<Point> AllVertices=rec->getPoints(); 
    std::set<Point>::iterator it;
    AllVertices.erase (AllVertices.find(*p1));
    AllVertices.erase (AllVertices.find(*p2));
    AllVertices.erase (AllVertices.find(*p3));
    for (auto v: AllVertices)
        ASSERT_TRUE(v.operator==(*p4));
    delete p1;delete p2;delete p3;delete p4;delete v1;delete v2;delete rec;
}