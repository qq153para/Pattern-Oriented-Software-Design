#include "../src/compound_shape.h"
#include "../src/shape.h"

TEST(ShapeTest, TestRectangleAddshapesShouldbeFail) {
    Point Point1(-0.5,0.3);
    Point Point2(0.5,0.3);
    Point Pointa(0.9,0.6);
    Point Point3(0.4,0.2);
    Point Point5(0.5,0);

    TwoDimensionalVector t1(Point1,Pointa);
    TwoDimensionalVector t2(Point1,Point3);
    TwoDimensionalVector t3(Point1,Point2);
    TwoDimensionalVector t4(Point5,Point2);
    
    Shape* Rec =new Rectangle(t3, t4);
    Shape* Cir =new Circle(t3);
    Shape* Tri= new Triangle(t1, t2);

   EXPECT_ANY_THROW( Rec -> addShape(Cir));
   EXPECT_ANY_THROW( Rec -> deleteShape(Tri));
   delete Rec ; delete Cir ; delete Tri;
}
TEST(ShapeTest, TestCircleAddshapesShouldbBeFail) {
    Point Point1(-0.5,0.3);
    Point Point2(0.5,0.3);
    Point Pointa(0.9,0.6);
    Point Point3(0.4,0.2);
    Point Point5(0.5,0);

    TwoDimensionalVector t1(Point1,Pointa);
    TwoDimensionalVector t2(Point1,Point3);
    TwoDimensionalVector t3(Point1,Point2);
    TwoDimensionalVector t4(Point5,Point2);
    
    Shape* Rec =new Rectangle(t3, t4);
    Shape* Cir =new Circle(t3);
    Shape* Tri= new Triangle(t1, t2);

   EXPECT_ANY_THROW( Cir -> addShape(Rec));
   EXPECT_ANY_THROW( Cir -> deleteShape(Tri));
   delete Rec ; delete Cir ; delete Tri;
}
TEST(ShapeTest, TestTriangleAddshapesShouldbBeFail) {
    Point Point1(-0.5,0.3);
    Point Point2(0.5,0.3);
    Point Pointa(0.9,0.6);
    Point Point3(0.4,0.2);
    Point Point5(0.5,0);

    TwoDimensionalVector t1(Point1,Pointa);
    TwoDimensionalVector t2(Point1,Point3);
    TwoDimensionalVector t3(Point1,Point2);
    TwoDimensionalVector t4(Point5,Point2);
    
    Shape* Rec =new Rectangle(t3, t4);
    Shape* Cir =new Circle(t3);
    Shape* Tri= new Triangle(t1, t2);

   EXPECT_ANY_THROW( Tri -> addShape(Rec));
   EXPECT_ANY_THROW( Tri -> deleteShape(Cir));
   delete Rec ; delete Cir ; delete Tri;
}
