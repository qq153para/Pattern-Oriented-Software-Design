#include "../src/shape.h"
#include "../src/bounding_box.h"

#include <iostream>

class CollisionTest : public ::testing::Test
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

        vec1 = new TwoDimensionalVector(p1, p2);
        vec2 = new TwoDimensionalVector(p1, p3);
        vec3 = new TwoDimensionalVector(p1, p4);
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

TEST_F(CollisionTest, CalMaximumPointShouldBeCorrect)
{
    Shape *cir1 = new Circle(vec1);
    Point *max = new Point(5, 5);
    BoundingBox cirAABB(cir1->getPoints());

    ASSERT_TRUE(max->operator==(*(cirAABB.max())));
}

TEST_F(CollisionTest, CalMinimumPointShouldBeCorrect)
{
    Shape *cir1 = new Circle(vec1);
    Point *max = new Point(-5, -5);
    BoundingBox cirAABB(cir1->getPoints());

    ASSERT_TRUE(max->operator==(*(cirAABB.min())));
}

TEST_F(CollisionTest, BoundingBoxOfRectangleShouldBeCorrect)
{
    Shape *rec1 = new Rectangle(vec2,vec1);
    BoundingBox recAABB(rec1->getPoints());
    EXPECT_NO_THROW( BoundingBox recAABB(rec1->getPoints()) );

}

TEST_F(CollisionTest, BoundingBoxOfCircleShouldBeCorrect)
{
    Shape *cir1 = new Circle(vec1);
    BoundingBox cirAABB(cir1->getPoints());
    EXPECT_NO_THROW( BoundingBox cirAABB(cir1->getPoints()) );

}

TEST_F(CollisionTest, BoundingBoxOfTriangleShouldBeCorrect)
{
    Shape *tri1 = new Triangle(vec2,vec1);
    BoundingBox triAABB(tri1->getPoints());
    EXPECT_NO_THROW( BoundingBox triAABB(tri1->getPoints()) );

}

TEST_F(CollisionTest, TwoAdjacentRectanglesShouldCollide)
{
    Shape *rec1 = new Rectangle(vec2,vec1);
    Point *p5 = new Point(0, -2);
    Point *p6 = new Point(2, -2);
    Point *p7 = new Point(2, -2);

    TwoDimensionalVector *vec3 = new TwoDimensionalVector(p5, p6);
    TwoDimensionalVector *vec4 = new TwoDimensionalVector(p5, p4);
    Shape *rec2 = new Rectangle(vec3,vec4);
    BoundingBox rec1AABB(rec1->getPoints());
    BoundingBox rec2AABB(rec2->getPoints());
    ASSERT_TRUE(rec1AABB.collide(&rec2AABB));
}

TEST_F(CollisionTest, TwoNonAdjacentRectanglesShouldNotCollide)
{
    Shape *rec1 = new Rectangle(vec2,vec1);
    Point *p5 = new Point(0, -2);
    Point *p6 = new Point(2, -2);
    Point *p7 = new Point(2, -4);

    TwoDimensionalVector *vec3 = new TwoDimensionalVector(p5, p6);
    TwoDimensionalVector *vec4 = new TwoDimensionalVector(p6, p7);
    Shape *rec2 = new Rectangle(vec3,vec4);
    BoundingBox rec1AABB(rec1->getPoints());
    BoundingBox rec2AABB(rec2->getPoints());
    ASSERT_FALSE(rec1AABB.collide(&rec2AABB));
}

TEST_F(CollisionTest, TwoAdjacentTrianglesShouldCollide)
{
    Shape *rec1 = new Triangle(vec2,vec1);
    Point *p5 = new Point(0, -2);
    Point *p6 = new Point(2, -2);

    TwoDimensionalVector *vec3 = new TwoDimensionalVector(p5, p6);
    TwoDimensionalVector *vec4 = new TwoDimensionalVector(p5, p4);
    Shape *rec2 = new Triangle(vec3,vec4);
    BoundingBox tri1AABB(rec1->getPoints());
    BoundingBox tri2AABB(rec2->getPoints());
    ASSERT_TRUE(tri1AABB.collide(&tri2AABB));
}

TEST_F(CollisionTest, TwoAdjacentTrianglesShouldNotCollide)
{
    Shape *rec1 = new Triangle(vec2,vec1);
    Point *p5 = new Point(0, -2);
    Point *p6 = new Point(2, -2);
    Point *p7 = new Point(2, -4);

    TwoDimensionalVector *vec3 = new TwoDimensionalVector(p5, p6);
    TwoDimensionalVector *vec4 = new TwoDimensionalVector(p6, p7);
    Shape *rec2 = new Triangle(vec3,vec4);
    BoundingBox tri1AABB(rec1->getPoints());
    BoundingBox tri2AABB(rec2->getPoints());
    ASSERT_FALSE(tri1AABB.collide(&tri2AABB));
}

TEST_F(CollisionTest, TwoAdjacentCirclesShouldCollide)
{
    Shape *cir1 = new Circle(vec1);
    Point *p5 = new Point(0, -2);
    Point *p6 = new Point(2, -2);

    TwoDimensionalVector *vec3 = new TwoDimensionalVector(p5, p6);
    Shape *cir2 = new Circle(vec3);
    BoundingBox cir1AABB(cir1->getPoints());
    BoundingBox cir2AABB(cir2->getPoints());
    ASSERT_TRUE(cir1AABB.collide(&cir2AABB));
}

TEST_F(CollisionTest, TwoAdjacentCirclesShouldNotCollide)
{
    Shape *cir1 = new Circle(vec1);
    Point *p5 = new Point(8, -2);
    Point *p6 = new Point(9, -2);
    TwoDimensionalVector *vec3 = new TwoDimensionalVector(p5, p6);

    Shape *cir2 = new Circle(vec3);
    BoundingBox cir1AABB(cir1->getPoints());
    BoundingBox cir2AABB(cir2->getPoints());
    ASSERT_FALSE(cir1AABB.collide(&cir2AABB));
}
