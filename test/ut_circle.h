#include "../src/circle.h"
TEST(CircleTest, testradius) {
    Point p1(-4.284, 0.264); 
    Point p2(-4.827, 0.728);
    TwoDimensionalVector v1(p1,p2);
    Circle circle(v1);
    ASSERT_NEAR(circle.radius(),0.714244,0.001);
}
TEST(CircleTest, testarea) {
    Point p1(-4.284, 0.264); 
    Point p2(-4.827, 0.728);
    TwoDimensionalVector v1(p1,p2);
    Circle circle(v1);
    ASSERT_NEAR(circle.area(),1.60267,0.001);
}
TEST(CircleTest, testperimeter) {
    Point p1(-4.284, 0.264); 
    Point p2(-4.827, 0.728);
    TwoDimensionalVector v1(p1,p2);
    Circle circle(v1);
    ASSERT_NEAR(circle.perimeter(),4.48773,0.001);
}
TEST(CircleTest, testinfo) {
    Point p1(-4.284, 0.264); 
    Point p2(-4.827, 0.728);
    TwoDimensionalVector v1(p1,p2);
    Circle circle(v1);
    ASSERT_STREQ("Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))",circle.info().c_str());
}
TEST(CircleTest, testgetpoints) {
    Point *p1=new Point(0.00, 0.00);
    Point *p2=new Point(2.00, 0);
    Point *p3=new Point(2.00, 2.00);
    Point *p4=new Point(-2.00, -2.00);
    TwoDimensionalVector* v1 =new TwoDimensionalVector (*p1 ,*p2);
    Shape *cir=new Circle(*v1);
    std::set<Point> AllVertices=cir->getPoints(); 
    std::set<Point>::iterator it;
    it=AllVertices.begin();
    ASSERT_TRUE((*it).operator==(*p4));
    it++;
    ASSERT_TRUE((*it).operator==(*p3));
    delete p1;delete p2;delete p3;delete p4;delete v1;delete cir;
}
