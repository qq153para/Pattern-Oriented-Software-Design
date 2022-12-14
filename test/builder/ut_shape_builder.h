#include "../../src/builder/shape_builder.h"

TEST(BuilderTest, BuildCircle){
    ShapeBuilder builder;
    Point* p1 =new Point(0,0);
    Point* p2 =new Point(2,0);
    builder.buildCircle(*p1,*p2);
    std::vector<Shape*> result  = builder.getResult();
    Shape* circle=result[0];
    

    ASSERT_EQ(2 * 2 * M_PI, circle->area());
    delete circle;
    delete p1;
    delete p2;
}

TEST(BuilderTest, BuildRectangle){
    ShapeBuilder builder;
    Point* p1 =new Point(0,0);
    Point* p2 =new Point(2,0);
    Point* p3 =new Point(0,2);
    builder.buildRectangle(*p1,*p2,*p3);
    std::vector<Shape*> result  = builder.getResult();
    Shape* square=result[0];

    ASSERT_EQ(4, square->area());
    delete square;
    delete p1;
    delete p2;
    delete p3;
}

TEST(BuilderTest, BuildTriangle){
    ShapeBuilder builder;
    Point* p1 =new Point(0,0);
    Point* p2 =new Point(3,0);
    Point* p3 =new Point(0,1);
    builder.buildTriangle(*p1,*p2,*p3);
    std::vector<Shape*> result  = builder.getResult();
    Shape* triangle=result[0];
    
    ASSERT_EQ(1.5, triangle->area());
    delete triangle;
    delete p1;
    delete p2;
    delete p3;
}

TEST(BuilderTest, BuildCompoundSahape){
    ShapeBuilder builder;
    Point* p1 =new Point(0,0);
    Point* p2 =new Point(2,0);
    Point* p3 =new Point(0,2);
    builder.buildCompoundShape();
    builder.buildRectangle(*p1,*p2,*p3);
    builder.buildCircle(*p1,*p2);
    builder.buildCompoundEnd();
    std::vector<Shape*> result  = builder.getResult();
    Shape* cs=result[0];
    
    ASSERT_EQ(2*2*M_PI + 4, cs->area());
    delete cs;
    delete p1;
    delete p2;
    delete p3;
}


