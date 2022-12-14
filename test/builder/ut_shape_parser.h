#include "../../src/builder/shape_parser.h"


TEST(ShapeParserrTest, ParseCompoundShapeShouldBeCorrect) {
    std::string input = "CompoundShape (Circle (Vector ((0.00, 0.00), (0.00, 5.00))), Rectangle (Vector ((0.00, 0.00), (0.00, 5.00)), Vector ((0.00, 0.00), (5.00, 0.00))))";
    ShapeParser parser(input);
    parser.parse();
    std::vector<Shape*> result = parser.getResult();
    ASSERT_EQ(25+5*5*M_PI, (result[0])->area());
}

TEST(ShapeParserrTest, ParseCircleShouldBeCorrect) {
    std::string input = "Circle (Vector ((0, 0), (5, 0)))";
    ShapeParser parser(input);
    parser.parse();
    std::vector<Shape*> result = parser.getResult();
    ASSERT_EQ(5*5*M_PI, (result[0])->area());
}

TEST(ShapeParserrTest, ParseTriangleShouldBeCorrect) {
    std::string input = "Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))";
    ShapeParser parser(input);
    parser.parse();
    std::vector<Shape*> result = parser.getResult();
    ASSERT_EQ(6, (result[0])->area());
}

TEST(ShapeParserrTest, ParseRectangleShouldBeCorrect) {
    std::string input = "Rectangle (Vector ((0, 0), (2, 0)), Vector ((0, 0), (0,2)))";
    ShapeParser parser(input);
    parser.parse();
    std::vector<Shape*> result = parser.getResult();
    ASSERT_EQ(2*2, (result[0])->area());
}

