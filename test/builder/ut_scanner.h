#include "../../src/builder/scanner.h"


TEST(ScannerTest, ScanCircleShouldBeCorrect) {
    std::string input = "Circle (Vector ((-4.28, -0.27 ), (-4.28, 0.26)))";
    // std::cout << input << std::endl;
    Scanner scanner(input);
    ASSERT_EQ("Circle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(-4.28, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(-0.27, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(-4.28, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0.26, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_TRUE(scanner.isDone());
}
TEST(ScannerTest, ScanTriangleShouldBeCorrect) {
    std::string input = "Triangle (Vector ((0.00, 0.00), (3.00, 0.00)), Vector ((3.00, 4.00), (3.00, 0.00)))";
    // std::cout << input << std::endl;
    Scanner scanner(input);
    ASSERT_EQ("Triangle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(3, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(3, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(4, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(3, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_TRUE(scanner.isDone());
}
TEST(ScannerTest, ScanRectangleShouldBeCorrect) {
    std::string input = "Rectangle (Vector ((0, 0), (2, 0)), Vector ((0, 0), (0,2)))";
    // std::cout << input << std::endl;
    Scanner scanner(input);
    ASSERT_EQ("Rectangle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(2, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(2, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_TRUE(scanner.isDone());
}
TEST(ScannerTest, ScanCompoundShapeShouldBeCorrect ) {
    std::string input = "CompoundShape (Circle (Vector ((0.00, 0.00), (0.00, 5.00))))";
    // std::cout << input << std::endl;
    Scanner scanner(input);
    ASSERT_EQ("CompoundShape", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Circle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(0, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(5, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_TRUE(scanner.isDone());
}
TEST(ScannerTest, NextShouldThrowExceptionWhenIsDone) {
    std::string input = "Circle (Vector ((-4.28, -0.27 ), (-4.28, 0.26)))";
    Scanner scanner(input);
    ASSERT_EQ("Circle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(-4.28, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(-0.27, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(-4.28, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0.26, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_TRUE(scanner.isDone());
    ASSERT_ANY_THROW(scanner.next());
}
TEST(ScannerTest, NextDoubleShouldThrowExceptionWhenIsDone) {
    std::string input = "Circle (Vector ((-4.28, -0.27 ), (-4.28, 0.26)))";
    Scanner scanner(input);
    ASSERT_EQ("Circle", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("Vector", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(-4.28, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(-0.27, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ("(", scanner.next());
    ASSERT_EQ(-4.28, scanner.nextDouble());
    ASSERT_EQ(",", scanner.next());
    ASSERT_EQ(0.26, scanner.nextDouble());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_EQ(")", scanner.next());
    ASSERT_TRUE(scanner.isDone());
    ASSERT_ANY_THROW(scanner.nextDouble());
}