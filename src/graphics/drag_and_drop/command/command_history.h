#pragma once

#include <stack>
#include "command.h"
#include "macro_command.h"

class CommandHistory
{
private:
    bool inMacro = false;
    std::stack<Command *> _history;
    std::stack<Command *> _undoCommands;

public:
    CommandHistory() {}
    ~CommandHistory() {
        while(!_history.empty()){
           delete _history.top() ;
           _history.pop();
        } 
        while(!_undoCommands.empty()){
            delete _undoCommands.top() ;
            _undoCommands.pop();
        }
    }

    void beginMacroCommand() {  
        MacroCommand *macro = new MacroCommand();
        addCommand(macro);
        inMacro=true;
    }

    void addCommand(Command *command) {
        if (inMacro==false){
            _history.push(command);
        } 
        else{
            _history.top()->addCommand(command);
        }
    }

    void endMacroCommand() {
        inMacro=false;
    }

    void undo() {
        Command *macro = _history.top();
        _history.pop();
        macro -> undo();
        _undoCommands.push(macro);
    }

    std::stack<Command *> getHistory() {
        return _history;
    }
};