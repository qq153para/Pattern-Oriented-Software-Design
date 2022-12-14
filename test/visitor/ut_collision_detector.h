#include "../../src/compound_shape.h"
#include "../../src/shape.h"
#include "../../src/visitor/collision_detector.h"

#include <iostream>

class CollisionDetectorTest : public ::testing::Test
{
protected:
    Point *p1, *p2, *p3, *p4;
    TwoDimensionalVector *vec1, *vec2, *vec3;

    void SetUp() override
    {
        p1 = new Point(0, 0);
        p2 = new Point(0, 5);
        p3 = new Point(5, 0);
        p4 = new Point(0, 3);

        vec1 = new TwoDimensionalVector(*p1, *p2);
        vec2 = new TwoDimensionalVector(*p1, *p3);
        vec3 = new TwoDimensionalVector(*p1, *p4);
    }

    void TearDown() override
    {
        delete p1;
        delete p2;
        delete p3;
        delete p4;
        delete vec1;
        delete vec2;
        delete vec3;
    }
};

TEST_F(CollisionDetectorTest, visitCircleShouldBeCorrect)
{
    Shape *cir1 = new Circle(*vec1);
    Shape *cir2 = new Circle(*vec2);
    CollisionDetector visitor(cir2);
    cir1->accept(&visitor);

    for (auto v : visitor.collidedShapes() ){
        ASSERT_EQ(cir1,v);
    }
    delete cir1;delete cir2;
}

TEST_F(CollisionDetectorTest, visitTriangleShouldBeCorrect)
{
    Shape *cir1 = new Circle(*vec1);
    Shape *tri1 = new Triangle(*vec2,*vec1);
    CollisionDetector visitor(cir1);
    tri1->accept(&visitor);

    for (auto v : visitor.collidedShapes() ){
        ASSERT_EQ(tri1,v);
    }
    delete cir1;delete tri1;
}

TEST_F(CollisionDetectorTest, visitRectangleShouldBeCorrect)
{
    Shape *cir1 = new Circle(*vec1);
    Shape *rec1 = new Rectangle(*vec2,*vec1);
    CollisionDetector visitor(cir1);
    rec1->accept(&visitor);

    for (auto v : visitor.collidedShapes() ){
        ASSERT_EQ(rec1,v);
    }
    delete cir1;delete rec1;
}

TEST_F(CollisionDetectorTest, visitCompoundShapeShouldBeCorrect1)
{
    Shape** s1 =new Shape* {};
    Shape** s2 =new Shape* {};
    Shape *cs1 = new CompoundShape(s1,0);
    Shape *cir1 = new Circle(*vec1);
    Shape *rec1 = new Rectangle(*vec1,*vec2);
    Shape *cir2 = new Circle(*vec3);
    Shape *tri1 = new Triangle(*vec2,*vec1);
    cs1->addShape(cir1);
    cs1->addShape(rec1);

    Shape *cs2 = new CompoundShape(s2,0);
    cs2->addShape(cir2);
    cs2->addShape(cs1); 
    CollisionDetector visitor(tri1);
    cs2->accept(&visitor);
    int i=0;
    for (auto v : visitor.collidedShapes() ){
        if(i==0){
            ASSERT_EQ(cir2,v);
        }
        else if(i==1){
            ASSERT_EQ(cir1,v);
        }
        else if(i==2){
            ASSERT_EQ(rec1,v);
        }
        i++;
    }
    delete cs2;delete s2;delete s1;delete tri1;
}
