#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/drop_command.h"
#include "../../../../src/graphics/drag_and_drop/command/grab_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

TEST(GrabCommandTest, executeShouldCallGrabMethodWithCorrectMousePosition)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    GrabCommand grabCommand(&mockDragAndDrop, &history);
    grabCommand.execute();
    ASSERT_NEAR(85.23, mockDragAndDrop.getGrabX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getGrabY(), 0.001);
}

TEST(GrabCommandTest, executeShouldCopyItselfInMacroCommandInHistory)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    GrabCommand grabCommand(&mockDragAndDrop, &history);
    grabCommand.execute();
    std::stack<Command *> _history =history.getHistory();
    Command *command = _history.top();
    std::vector<Command *> v1 = command->getCommands();
    ASSERT_EQ(1,_history.size());
    ASSERT_EQ(1,v1.size());
}
TEST(GrabCommandTest, theCopiedCommandShouldHaveTheOriginalXY)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    GrabCommand grabCommand1(&mockDragAndDrop, &history);
    MousePosition::getInstance()->setPos(85, 232);
    grabCommand1.execute();
    GrabCommand grabCommand2(grabCommand1);
    ASSERT_NEAR(85, grabCommand2.getX(), 0.001);
    ASSERT_NEAR(232, grabCommand2.getY(), 0.001);
}
TEST(GrabCommandTest, undoShouldCallMoveAndDropWithTheOriginalXY)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    GrabCommand grabCommand(&mockDragAndDrop, &history);
    grabCommand.execute();
    grabCommand.undo();
    ASSERT_NEAR(85.23, mockDragAndDrop.getMoveX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getMoveY(), 0.001);
    ASSERT_NEAR(85.23, mockDragAndDrop.getDropX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getDropY(), 0.001);
}
TEST(GrabCommandTest, addCommandShouldThrowException)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    GrabCommand grabCommand1(&mockDragAndDrop, &history);
    GrabCommand grabCommand2(&mockDragAndDrop, &history);
    EXPECT_ANY_THROW(grabCommand1.addCommand(&grabCommand2));
}
TEST(GrabCommandTest, getCommandsShouldThrowException)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    GrabCommand grabCommand1(&mockDragAndDrop, &history);
    GrabCommand grabCommand2(&mockDragAndDrop, &history);
    EXPECT_ANY_THROW(grabCommand1.getCommands());
}
