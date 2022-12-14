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
    Shape** s1;
    Shape *cir1 ,*cir2;
    Shape *rec;

    void SetUp() override
    {
        p1 = new Point(0, 0);
        p2 = new Point(0, 5);
        p3 = new Point(5, 0);
        p4 = new Point(0, 3);

        vec1 = new TwoDimensionalVector(*p1, *p2);
        vec2 = new TwoDimensionalVector(*p1,*p3);
        vec3 = new TwoDimensionalVector(*p1, *p4);
        s1 =new Shape* {};
        cs2 = new CompoundShape(s1,0);
        cir1 =new Circle(*vec1);
        cir2 =new Circle(*vec3);
        rec =new Rectangle(*vec1,*vec2);
        cs2->addShape(cir1);
        cs2->addShape(rec);
        cs2->addShape(cir2);
        
        it = cs2->createIterator(IteratorFactory::getInstance("List"));
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
        delete s1;
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