#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/drop_command.h"
#include "../../../../src/graphics/drag_and_drop/command/grab_command.h"
#include "../../../../src/graphics/drag_and_drop/command/move_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

TEST(CommandHistoryTest, addCommandShouldBeCorrect)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    Command *grabCommand=new GrabCommand(&mockDragAndDrop, &history);
    Command *moveCommand=new MoveCommand(&mockDragAndDrop, &history);
    Command *dropCommand=new DropCommand(&mockDragAndDrop, &history);
    history.addCommand(grabCommand);
    history.addCommand(moveCommand);
    history.addCommand(dropCommand);
    ASSERT_EQ(3,(history.getHistory()).size());
}
TEST(CommandHistoryTest, beginMacroCommandShouldAddAMacroCommand )
{
    CommandHistory history;
    history.beginMacroCommand();
    ASSERT_EQ(1,(history.getHistory()).size());
}
TEST(CommandHistoryTest, commandShouldBeAddedInTheMacroCommandAfterBeginningMacro )
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    Command *grabCommand=new GrabCommand(&mockDragAndDrop, &history);
    history.beginMacroCommand();
    history.addCommand(grabCommand);
    ASSERT_EQ(grabCommand,((history.getHistory()).top())->getCommands().front());
}
TEST(CommandHistoryTest, commandShouldNotBeAddedInTheMacroCommandAfterEndingMacro )
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    Command *grabCommand=new GrabCommand(&mockDragAndDrop, &history);
    history.endMacroCommand();
    history.addCommand(grabCommand);
    ASSERT_EQ(grabCommand,((history.getHistory()).top()));
}
