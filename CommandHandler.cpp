#include "CommandHandler.h"

using namespace std;


void CommandHandler::add_command(vector<string> input_command)
{
    current_command = input_command;
}
    
void CommandHandler::process_command()
{
    string commence = current_command[0];
    string main_command = current_command[1];
    if(commence == POST)
}
    //void get_command(std::string input_command);
private:
    vector<string> current_command;