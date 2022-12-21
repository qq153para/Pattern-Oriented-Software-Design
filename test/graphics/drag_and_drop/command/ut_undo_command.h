#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/undo_command.h"
#include "../../../../src/graphics/drag_and_drop/command/grab_command.h"
#include "../../../../src/graphics/drag_and_drop/command/move_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

TEST(UndoCommandTest, executeShouldCallCommandHistoryToUndo)
{
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(85.23, 232.7);
    GrabCommand grabCommand(&mockDragAndDrop, &history);
    MoveCommand moveCommand(&mockDragAndDrop, &history);
    DropCommand dropCommand(&mockDragAndDrop, &history);
    UndoCommand undoCommand(&mockDragAndDrop, &history);
    grabCommand.execute();
    moveCommand.execute();
    dropCommand.execute();
    ASSERT_EQ(1,(history.getHistory()).size());
    undoCommand.execute();
    ASSERT_EQ(0,(history.getHistory()).size()); 

}