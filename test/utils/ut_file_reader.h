#include "../../src/utils/file_reader.h"

TEST(FileReaderTest, ReadShouldBeCorrect)
{
    FileReader reader("test/utils/test_input.txt");
    std::string result = reader.read();
    ASSERT_EQ(
        "CompoundShape (\r\n    CompoundShape (\r\n        Circle (\r\n            Vector ((0.00, 0.00), (0.00, 5.00))\r\n        ), Rectangle (\r\n            Vector ((0.00, 0.00), (0.00, 5.00)),\r\n            Vector ((0.00, 0.00), (5.00, 0.00))\r\n        )\r\n    ), CompoundShape (\r\n        Circle (\r\n            Vector ((0.00, 0.00), (0.00, 3.00))\r\n        )\r\n    )\r\n)",
        result
    );
}
