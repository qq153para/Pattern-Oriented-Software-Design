#include "../../src/iterator/factory/list_iterator_factory.h"
#include "../../src/compound_shape.h"
#include "../../src/shape.h"

#include <iostream>

class ListCompoundIteratorTest : public ::testing::Test
{
protected:
    Point *p1, *p2, *p3, *p4;
    TwoDimensionalVector *vec1, *vec2, *vec3;
    CompoundShape *cs1, *cs2;
    Iterator* it;

    void SetUp() override
    {
        p1 = new Point(0, 0);
        p2 = new Point(0, 5);
        p3 = new Point(5, 0);
        p4 = new Point(0, 3);

        vec1 = new TwoDimensionalVector(p1, p2);
        vec2 = new TwoDimensionalVector(p1, p3);
        vec3 = new TwoDimensionalVector(p1, p4);

        cs2 = new CompoundShape(new Shape* {},0);
        cs2->addShape(new Circle(vec1));
        cs2->addShape(new Rectangle(vec1,vec2));
        cs2->addShape(new Circle(vec3));

        it = cs2->createIterator(new ListIteratorFactory());
    }

    void TearDown() override
    {
        delete cs2;
        delete p1;
        delete p2;
        delete p3;
        delete p4;
        delete vec1;
        delete vec2;
        delete vec3;
        delete it;
    }
};

TEST_F(ListCompoundIteratorTest, CurrentItemShouldBeCorrect)
{
    ASSERT_EQ(5 * 5 * M_PI, it->currentItem()->area());
}

TEST_F(ListCompoundIteratorTest, NextShouldBeCorrect)
{
    it->next();
    ASSERT_EQ( 25, it->currentItem()->area());
}

TEST_F(ListCompoundIteratorTest, IsDoneShouldBeCorrect)
{
    it->next();
    it->next();
    it->next();

    ASSERT_TRUE(it->isDone());
}

TEST_F(ListCompoundIteratorTest, CurrentItemShouldThrowExceptionWhenIsDone)
{
    it->next();
    it->next();
    it->next();

    ASSERT_ANY_THROW(it->next());
}

TEST_F(ListCompoundIteratorTest, NextShouldThrowExceptionWhenIsDone)
{
    it->next();
    it->next();
    it->next();
    
    ASSERT_ANY_THROW(it->currentItem());
}