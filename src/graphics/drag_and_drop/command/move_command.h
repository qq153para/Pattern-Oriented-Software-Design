#pragma once

#include "command.h"
#include "command_history.h"
#include "../drag_and_drop.h"
#include "../mouse_position.h"

class MoveCommand : public Command
{
private:
    DragAndDrop *_dragAndDrop;
    CommandHistory *_commandHistory;
    MousePosition *instance;
    double _x, _y;

public:
    MoveCommand(DragAndDrop *dragAndDrop, CommandHistory *commandHistory) 
    : _dragAndDrop(dragAndDrop),_commandHistory(commandHistory){
    }
    MoveCommand(const MoveCommand &moveCommand) {
        _dragAndDrop = moveCommand._dragAndDrop;
        _commandHistory = moveCommand._commandHistory;
        _x = moveCommand._x;
        _y = moveCommand._y;
    } // copy constructor

    void execute() override {
        _x = MousePosition::getInstance() -> getX();
        _y = MousePosition::getInstance() -> getY();
        _dragAndDrop -> move(_x,_y);
        Command *copy = new MoveCommand(*this);
        _commandHistory -> addCommand(copy);
    }

    void undo() override {
        _dragAndDrop -> move(_x,_y);
    }

    double getX() const {
        return _x;
    }

    double getY() const {
        return _y;
    }
};
