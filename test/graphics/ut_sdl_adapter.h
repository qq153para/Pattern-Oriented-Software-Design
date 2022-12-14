#include "../../src/shape.h"
#include "../../src/rectangle.h"
#include "../../src/circle.h"
#include "../../src/triangle.h"
#include "../../src/compound_shape.h"
#include "../../src/graphics/sdl_adapter.h"
#include "mock_sdl_renderer.h"

class SDLAdapterTest : public ::testing::Test
{
protected:
    MockSDLRenderer *mockSDLRenderer;

    void SetUp() override
    {
        mockSDLRenderer = new MockSDLRenderer();
    }

    void TearDown() override
    {
        delete mockSDLRenderer;
    }
};

TEST_F(SDLAdapterTest, initShouldBeCalledWhenAdapterIsInitialized)
{
    Canvas *canvas = new SDLAdapter(1024, 768, mockSDLRenderer);
    // SDLAdapter calls the init function of the SDL instance.
    ASSERT_TRUE(mockSDLRenderer->isInitCalled());
    delete canvas;
}

TEST_F(SDLAdapterTest, initCalledArgsShouldBeCorrect)
{
    Canvas *canvas;
    EXPECT_NO_THROW( canvas = new SDLAdapter(1024, 768, mockSDLRenderer));
    delete canvas;
}

TEST_F(SDLAdapterTest, widthAndHeightShouldBeGreaterThanZero)
{
    Canvas *canvas;
    EXPECT_ANY_THROW( canvas = new SDLAdapter(0, 0, mockSDLRenderer));
    delete canvas;
}

TEST_F(SDLAdapterTest, renderDrawCircleCalledArgsShouldBeCorrect)
{

    std::string input = "Circle ( Vector ((0.00, 0.00), (0.00, 5.00)))";
    ShapeParser parser(input);
    // cout << input <<endl;
    parser.parse();
    Point p1(0,0);
    Point p2(0,5);
    TwoDimensionalVector v1(p1,p2);
    Circle *cir =new Circle(v1);
    Canvas *canvas = new SDLAdapter(1024, 768, mockSDLRenderer);
    canvas->drawCircle(cir);
    const double *callpoint = mockSDLRenderer->renderDrawCircleCalledArgs();
    ASSERT_NEAR(0,callpoint[0],0.001);
    ASSERT_NEAR(0,callpoint[1],0.001);
    ASSERT_NEAR(5,callpoint[2],0.001);

    delete cir;
    delete canvas;
}

TEST_F(SDLAdapterTest, renderDrawLinesCalledArgsShouldBeCorrectForNonRotatedRect)
{

    std::string input = "Rectangle (Vector ((2.00, -5.00), (4.00, -5.00)), Vector ((4.00, -5.00), (4.00, -7.00)))";
    ShapeParser parser(input);
    // cout << input <<endl;
    parser.parse();
    Point p1(2,-5);
    Point p2(4,-5);
    Point p3(4,-7);
    TwoDimensionalVector v1(p1,p2);
    TwoDimensionalVector v2(p2,p3);
    Rectangle *rect =new Rectangle(v1,v2);
    Canvas *canvas = new SDLAdapter(1024, 768, mockSDLRenderer);
    canvas->drawRectangle(rect);
    const double *callpoint = mockSDLRenderer->renderDrawLinesCalledPoints();
    double size = mockSDLRenderer->renderDrawLinesCalledSize();
    ASSERT_NEAR(8,size,0.001);
    ASSERT_NEAR(2,callpoint[0],0.001);
    ASSERT_NEAR(-7,callpoint[1],0.001);
    ASSERT_NEAR(2,callpoint[2],0.001);
    ASSERT_NEAR(-5,callpoint[3],0.001);
    ASSERT_NEAR(4,callpoint[4],0.001);
    ASSERT_NEAR(-5,callpoint[5],0.001);
    ASSERT_NEAR(4,callpoint[6],0.001);
    ASSERT_NEAR(-7,callpoint[7],0.001);

    delete rect;
    delete canvas;
}

TEST_F(SDLAdapterTest, renderDrawLinesCalledArgsShouldBeCorrectForTriangle1)
{
    std::string input = "Triangle (Vector ((4.00, -2.00), (6.00, -4.00)),Vector ((6.00, -8.00), (4.00, -2.00)))";
    ShapeParser parser(input);
    // cout << input <<endl;
    parser.parse();
    Point p1(4,-2);
    Point p2(6,-4);
    Point p3(6,-8);
    TwoDimensionalVector v1(p1,p2);
    TwoDimensionalVector v2(p3,p1);
    Triangle *tri =new Triangle(v1,v2);
    Canvas *canvas = new SDLAdapter(1024, 768, mockSDLRenderer);
    canvas->drawTriangle(tri);
    const double *callpoint = mockSDLRenderer->renderDrawLinesCalledPoints();
    double size = mockSDLRenderer->renderDrawLinesCalledSize();
    ASSERT_NEAR(6,size,0.001);
    ASSERT_NEAR(4,callpoint[0],0.001);
    ASSERT_NEAR(-2,callpoint[1],0.001);
    ASSERT_NEAR(6,callpoint[2],0.001);
    ASSERT_NEAR(-8,callpoint[3],0.001);
    ASSERT_NEAR(6,callpoint[4],0.001);
    ASSERT_NEAR(-4,callpoint[5],0.001);

    delete tri;
    delete canvas;
}

TEST_F(SDLAdapterTest, renderPresentShouldBeCalledWhenAdapterIsDisplayed)
{
    Canvas *canvas = new SDLAdapter(1024, 768, mockSDLRenderer);
    canvas->display();
    ASSERT_TRUE(mockSDLRenderer->isRenderPresentCalled());
    delete canvas;
}
