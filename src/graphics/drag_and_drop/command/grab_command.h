#pragma once

#include "command.h"
#include "command_history.h"
#include "../drag_and_drop.h"
#include "../mouse_position.h"

class GrabCommand : public Command
{
private:
    DragAndDrop *_dragAndDrop;
    CommandHistory *_commandHistory;
    double _x, _y;

public:
    GrabCommand(DragAndDrop *dragAndDrop, CommandHistory *commandHistory) 
    : _dragAndDrop(dragAndDrop),_commandHistory(commandHistory){
    }
    GrabCommand(const GrabCommand &grabCommand) {
        _dragAndDrop = grabCommand._dragAndDrop;
        _commandHistory = grabCommand._commandHistory;
        _x = grabCommand._x;
        _y = grabCommand._y;
    } // copy constructor

    void execute() override {
        _x = MousePosition::getInstance() ->getX();
        _y = MousePosition::getInstance() ->getY();
        _dragAndDrop -> grab(_x,_y);
        _commandHistory ->beginMacroCommand();
        Command *copy = new GrabCommand(*this);
        _commandHistory -> addCommand(copy);
    }

    void undo() override {
        _dragAndDrop -> move(_x,_y);
        _dragAndDrop -> drop(_x,_y);
    }

    double getX() const {
        return _x;
    }

    double getY() const {
        return _y;
    }
};
