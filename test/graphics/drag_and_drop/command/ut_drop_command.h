#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/drop_command.h"
#include "../../../../src/graphics/drag_and_drop/command/grab_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

TEST(DropCommandTest, executeShouldCallDropMethodWithCorrectMousePosition)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    DropCommand dropCommand(&mockDragAndDrop, &history);
    dropCommand.execute();
    ASSERT_NEAR(85.23, mockDragAndDrop.getDropX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getDropY(), 0.001);
}
TEST(DropCommandTest, executeShouldCopyItselfInMacroCommandInHistory)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    GrabCommand grabCommand(&mockDragAndDrop, &history);
    MoveCommand moveCommand(&mockDragAndDrop, &history);
    DropCommand dropCommand(&mockDragAndDrop, &history);
    grabCommand.execute();
    moveCommand.execute();
    dropCommand.execute();
    std::stack<Command *> _history =history.getHistory();
    Command *command = _history.top();
    std::vector<Command *> v1 = command->getCommands();
    ASSERT_EQ(1,_history.size());
    ASSERT_EQ(3,v1.size());
}
TEST(DropCommandTest, theCopiedCommandShouldHaveTheOriginalXY)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    DropCommand dropCommand1(&mockDragAndDrop, &history);
    MousePosition::getInstance()->setPos(85, 232);
    dropCommand1.execute();
    DropCommand dropCommand2(dropCommand1);
    ASSERT_NEAR(85, dropCommand2.getX(), 0.001);
    ASSERT_NEAR(232, dropCommand2.getY(), 0.001);
}
TEST(DropCommandTest, undoShouldCallDragWithTheOriginalXY)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    DropCommand dropCommand(&mockDragAndDrop, &history);
    dropCommand.execute();
    dropCommand.undo();
    ASSERT_NEAR(85.23, mockDragAndDrop.getGrabX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getGrabY(), 0.001);
}
TEST(DropCommandTest, addCommandShouldThrowException)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    DropCommand dropCommand1(&mockDragAndDrop, &history);
    GrabCommand grabCommand2(&mockDragAndDrop, &history);
    EXPECT_ANY_THROW(dropCommand1.addCommand(&grabCommand2));
}
TEST(DropCommandTest, getCommandsShouldThrowException)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    DropCommand dropCommand1(&mockDragAndDrop, &history);
    GrabCommand grabCommand2(&mockDragAndDrop, &history);
    EXPECT_ANY_THROW(dropCommand1.getCommands());
}
