#include "../mock_drag_and_drop.h"
#include "./mock_command.h"
#include "../../../../src/graphics/drag_and_drop/command/drop_command.h"
#include "../../../../src/graphics/drag_and_drop/command/grab_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

TEST(MacroCommandTest, addCommandShouldBeCorrect)
{
    MousePosition::getInstance()->setPos(85.23, 232.7);
    MacroCommand macroCommand;
    MockCommand *mockCommand1=new MockCommand();
    MockCommand *mockCommand2=new MockCommand();
    MockCommand *mockCommand3=new MockCommand();
    macroCommand.addCommand(mockCommand1);
    macroCommand.addCommand(mockCommand2);
    macroCommand.addCommand(mockCommand3);
    std::vector<Command *> v1 = macroCommand.getCommands();
    ASSERT_EQ(v1[0],mockCommand1);
    ASSERT_EQ(v1[1],mockCommand2);
    ASSERT_EQ(v1[2],mockCommand3);

}
TEST(MacroCommandTest, executeShouldExecuteAllCommands)
{
    MousePosition::getInstance()->setPos(85.23, 232.7);
    MacroCommand macroCommand;
    MockCommand *mockCommand1=new MockCommand();
    MockCommand *mockCommand2=new MockCommand();
    MockCommand *mockCommand3=new MockCommand();
    macroCommand.addCommand(mockCommand1);
    macroCommand.addCommand(mockCommand2);
    macroCommand.addCommand(mockCommand3);
    macroCommand.execute();
    ASSERT_TRUE(mockCommand1->isExecuteCalled());
    ASSERT_TRUE(mockCommand2->isExecuteCalled());
    ASSERT_TRUE(mockCommand3->isExecuteCalled());
}
TEST(MacroCommandTest, undoShouldUndoAllCommands)
{
    MousePosition::getInstance()->setPos(85.23, 232.7);
    MacroCommand macroCommand;
    MockCommand *mockCommand1=new MockCommand();
    MockCommand *mockCommand2=new MockCommand();
    MockCommand *mockCommand3=new MockCommand();
    macroCommand.addCommand(mockCommand1);
    macroCommand.addCommand(mockCommand2);
    macroCommand.addCommand(mockCommand3);
    macroCommand.undo();
    ASSERT_TRUE(mockCommand1->isUndoCalled());
    ASSERT_TRUE(mockCommand2->isUndoCalled());
    ASSERT_TRUE(mockCommand3->isUndoCalled());
}