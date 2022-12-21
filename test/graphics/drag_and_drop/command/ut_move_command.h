#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/drop_command.h"
#include "../../../../src/graphics/drag_and_drop/command/grab_command.h"
#include "../../../../src/graphics/drag_and_drop/command/move_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

TEST(MoveCommandTest, executeShouldCallMoveMethodWithCorrectMousePosition)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    MoveCommand moveCommand(&mockDragAndDrop, &history);
    moveCommand.execute();
    ASSERT_NEAR(85.23, mockDragAndDrop.getMoveX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getMoveY(), 0.001);
}
TEST(MoveCommandTest, undoShouldCallMoveWithTheOriginalXY)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    MoveCommand moveCommand(&mockDragAndDrop, &history);
    moveCommand.execute();
    moveCommand.undo();
    ASSERT_NEAR(85.23, mockDragAndDrop.getMoveX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getMoveY(), 0.001);
}
TEST(MoveCommandTest, addCommandShouldThrowException)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    MoveCommand moveCommand(&mockDragAndDrop, &history);
    GrabCommand grabCommand2(&mockDragAndDrop, &history);
    EXPECT_ANY_THROW(moveCommand.addCommand(&grabCommand2));
}
TEST(MoveCommandTest, getCommandsShouldThrowException)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    MoveCommand moveCommand(&mockDragAndDrop, &history);
    GrabCommand grabCommand2(&mockDragAndDrop, &history);
    EXPECT_ANY_THROW(moveCommand.getCommands());
}