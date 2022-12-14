#include "../../src/builder/shape_builder.h"

TEST(BuilderTest, BuildCircle){
    ShapeBuilder builder;
    builder.buildCircle(new Point(0,0),new Point(2,0));
    std::vector<Shape*> result  = builder.getResult();
    Shape* circle=result[0];
    

    ASSERT_EQ(2 * 2 * M_PI, circle->area());
}

TEST(BuilderTest, BuildRectangle){
    ShapeBuilder builder;
    builder.buildRectangle(new Point(0,0),new Point(2,0),new Point(0,2));
    std::vector<Shape*> result  = builder.getResult();
    Shape* square=result[0];

    ASSERT_EQ(4, square->area());
}

TEST(BuilderTest, BuildTriangle){
    ShapeBuilder builder;

    builder.buildTriangle(new Point(0,0),new Point(3,0),new Point(0,1));
    std::vector<Shape*> result  = builder.getResult();
    Shape* triangle=result[0];
    
    ASSERT_EQ(1.5, triangle->area());
}

TEST(BuilderTest, BuildCompoundSahape){
    ShapeBuilder builder;

    builder.buildCompoundShape();
    builder.buildRectangle(new Point(0,0),new Point(2,0),new Point(0,2));
    builder.buildCircle(new Point(0,0),new Point(2,0));
    builder.buildCompoundEnd();
    std::vector<Shape*> result  = builder.getResult();
    Shape* cs=result[0];
    
    ASSERT_EQ(2*2*M_PI + 4, cs->area());
}


