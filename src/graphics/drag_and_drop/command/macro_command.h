#pragma once

#include "command.h"
#include <vector>

class MacroCommand : public Command
{
private:
    std::vector<Command *> _commands;
    std::stack<Command *> _undoCommands;

public:
    MacroCommand() {}
    ~MacroCommand() {
        for (std::vector<Command *>::iterator it = _commands.begin(); it != _commands.end(); ++it)
        {
            delete *it;
        }
        _commands.clear();
        while(!_undoCommands.empty()){
            delete _undoCommands.top() ;
            _undoCommands.pop();
        }
    }

    void execute() override {
        for (auto v : _commands){
            v->execute();
        }
    }

    void addCommand(Command *command) override {
        _commands.push_back(command);
    }

    void undo() override {
        while(!_commands.empty()){
            (_commands.back())->undo();
            _undoCommands.push(_commands.back());
            _commands.pop_back();
        }
    }

    std::vector<Command *> getCommands() override {
        return _commands;
    }
};
