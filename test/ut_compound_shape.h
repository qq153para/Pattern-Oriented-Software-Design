#include "../src/compound_shape.h"
#include "../src/shape.h"



class CompoundShapeTest : public ::testing::Test
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

        cs1 = new CompoundShape(new Shape* {},0);
        cs1->addShape(new Circle(vec1));
        cs1->addShape(new Rectangle(vec1,vec2));

        cs2 = new CompoundShape(new Shape* {},0);
        cs2->addShape(new Circle(vec3));
        cs2->addShape(cs1);
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

TEST_F(CompoundShapeTest, TestArea)
{
    ASSERT_EQ(3 * 3 * M_PI+5*5* M_PI+25, cs2->area());

}
TEST_F(CompoundShapeTest, TestPerimeter)
{
    ASSERT_EQ(6 * M_PI+10* M_PI+20, cs2->perimeter());

}
TEST_F(CompoundShapeTest, TestInfo)
{
    ASSERT_EQ("CompoundShape (Circle (Vector ((0.00, 0.00), (0.00, 3.00))), CompoundShape (Circle (Vector ((0.00, 0.00), (0.00, 5.00))), Rectangle (Vector ((0.00, 0.00), (0.00, 5.00)), Vector ((0.00, 0.00), (5.00, 0.00)))))", cs2->info());

}
TEST_F(CompoundShapeTest, TestcreateBFSIterator)
{
    Point Point1(-0.5,0.3);
    Point Point2(0.5,0.3);
    Point Pointa(0.9,0.6);
    Point Point3(0.4,0.2);
    Point Point5(0.5,0);

    TwoDimensionalVector t1(&Point1,&Pointa);
    TwoDimensionalVector t2(&Point1,&Point3);
    TwoDimensionalVector t3(&Point1,&Point2);
    TwoDimensionalVector t4(&Point5,&Point2);
    Rectangle* Rec1=new Rectangle(&t3, &t4);
    Circle* Cir1=new Circle(&t3);
    Circle* Cir2=new Circle(&t4);
    Circle* Cir3=new Circle(&t1);
    Circle* Cir4=new Circle(&t2);
    Shape* Tri1= new Triangle(&t1, &t2);

    Shape* cs3 = new CompoundShape(new Shape* {},0);
    cs3->addShape(Cir3);
    cs3->addShape(Cir4);
    Shape* cs4 = new CompoundShape(new Shape* {},0);
    cs4->addShape(Cir2);
    // cs2->addShape(cs3);
    cs4->addShape(Tri1);
    // cs2->addShape(cs3);
    Shape* cs5 = new CompoundShape(new Shape* {},0);
    cs5->addShape(cs4);
    cs5->addShape(Cir1);
    cs5->addShape(cs3);

    Iterator* it = cs5->createBFSIterator();

    ASSERT_EQ(cs4 , it->currentItem());
    it->next();
    ASSERT_EQ(Cir1 , it->currentItem());
    it->next();
    ASSERT_EQ(cs3 , it->currentItem());
    it->next();
    ASSERT_EQ(Cir2 , it->currentItem());
    it->next();
    ASSERT_EQ(Tri1 , it->currentItem());
    it->next();
    ASSERT_EQ(Cir3 , it->currentItem());
    it->next();
    ASSERT_EQ(Cir4 , it->currentItem());
    it->next();
    ASSERT_EQ(true , it->isDone());
   
}
TEST_F(CompoundShapeTest, TestcreateDFSIterator)
{
    Point Point1(-0.5,0.3);
    Point Point2(0.5,0.3);
    Point Pointa(0.9,0.6);
    Point Point3(0.4,0.2);
    Point Point5(0.5,0);

    TwoDimensionalVector t1(&Point1,&Pointa);
    TwoDimensionalVector t2(&Point1,&Point3);
    TwoDimensionalVector t3(&Point1,&Point2);
    TwoDimensionalVector t4(&Point5,&Point2);
    Rectangle* Rec1=new Rectangle(&t3, &t4);
    Circle* Cir1=new Circle(&t3);
    Circle* Cir2=new Circle(&t4);
    Circle* Cir3=new Circle(&t1);
    Circle* Cir4=new Circle(&t2);
    Shape* Tri1= new Triangle(&t1, &t2);

    Shape* cs3 = new CompoundShape(new Shape* {},0);
    cs3->addShape(Cir3);
    cs3->addShape(Cir4);
    Shape* cs4 = new CompoundShape(new Shape* {},0);
    cs4->addShape(Cir2);
    cs4->addShape(Tri1);
    Shape* cs5 = new CompoundShape(new Shape* {},0);
    cs5->addShape(cs4);
    cs5->addShape(Cir1);
    cs5->addShape(cs3);

    Iterator* it = cs5->createDFSIterator();

    ASSERT_EQ(cs4 , it->currentItem());
    it->next();
    ASSERT_EQ(Cir2 , it->currentItem());
    it->next();
    ASSERT_EQ(Tri1 , it->currentItem());
    it->next();
    ASSERT_EQ(Cir1 , it->currentItem());
    it->next();
    ASSERT_EQ(cs3 , it->currentItem());
    it->next();
    ASSERT_EQ(Cir3 , it->currentItem());
    it->next();
    ASSERT_EQ(Cir4 , it->currentItem());
    it->next();
    ASSERT_EQ(true , it->isDone());
}
TEST_F(CompoundShapeTest, TestdeleteShape) {
    CompoundShape* cs3 = new CompoundShape(new Shape* {},0);
    Shape* Cir1 =new Circle(vec1);
    cs3->addShape(Cir1);
    cs3->addShape(new Rectangle(vec1,vec2));

    CompoundShape* cs4 = new CompoundShape(new Shape* {},0);
    cs4->addShape(new Circle(vec3));
    cs4->addShape(cs1);

    cs4->deleteShape( Cir1 );

    Iterator* it = cs4->createBFSIterator();
    for ( it->first(); !it->isDone(); it->next() ) {
        ASSERT_NE( Cir1, it->currentItem() );
    }
    delete cs4;
    delete cs3;
    delete Cir1;

}
TEST_F(CompoundShapeTest, TestaddShape) {
    Point Point1(-0.5,0.3);
    Point Point2(0.5,0.3);
    Point Point5(0.5,0);
    TwoDimensionalVector t3(&Point1,&Point2);
    TwoDimensionalVector t4(&Point5,&Point2);
    Rectangle* Rec1=new Rectangle(&t3, &t4);

    cs2->addShape( Rec1 );

    Iterator* it = cs2->createBFSIterator();
    it->next();
    it->next();
    ASSERT_EQ(Rec1 , it->currentItem());

    delete Rec1;
    delete it;

}
