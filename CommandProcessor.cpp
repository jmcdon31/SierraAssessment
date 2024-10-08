#include "CommandProcessor.h"
#include "CommandAcceptor.h"
#include <iostream>
#include <sstream>

std::unordered_map<std::string, CommandAcceptor*> CommandProcessor::m_RegisterdAcceptors;
std::thread CommandProcessor::m_ProccessingThread;

void CommandProcessor::Start()
{
   //TODO: need to add some safety checks to verify this start call cant be called twice
   m_ProccessingThread = std::thread(ProcessCommands);
}

/*NOTE: In real flight software this implementation would be reading from some Rx Buffer from the 
 * Communication Hardware, or maybe a SpaceWire message, Or IP packet. For this example, we are 
 * just reading from standard In*/
void CommandProcessor::ProcessCommands()
{
   while(1)
   {
      //NOTE: in order to fit the prompt and not force users to write a specific comand type,
      //hard code the command type here for now.
      std::string FAKE_COMMAND = "ATTITUDE ";

      std::string input;
      std::getline(std::cin, input);

      //NOTE:adding a hard coded command here for the example
      input = FAKE_COMMAND + input;
      if (ValidCommand(input))
      {
         std::string command = GetCommandType(input);

         //Note: this could be modified easily to permit multiple acceptors for a single command
         //Check for Command Acceptors for this type
         auto acceptor = m_RegisterdAcceptors.find(command);
         if ( acceptor != m_RegisterdAcceptors.end())
         {
            acceptor->second->AddCommand(input);
         }
         else
         {
            std::cout << "WARNING: No acceptor for command type: " << command << std::endl;
         }
      }
      else
      {
         std::cout << "ERROR: Invalid Command " << input << std::endl;
      }
   }

}

bool CommandProcessor::RegisterAcceptor(std::string Command, CommandAcceptor& Acceptor)
{
   if (m_RegisterdAcceptors.count(Command) > 0)
   {
      return false;
   }

   m_RegisterdAcceptors[Command] = &Acceptor;
   return true;
}

bool CommandProcessor::ValidCommand(std::string& Command)
{

   (void)Command;
   //NOTE: This would normally do some more robust checking to verify the header, size, and format
   //For this example it is hard coded to be true as we assume the command packets structure is 
   //valid
   return true;
}

std::string CommandProcessor::GetCommandType(std::string& Command)
{
   std::stringstream ss(Command);
   std::string command;
   //NOTE: This would normally parse out the command type from a valid packet and return it.
   //for this implementation the first word is the command type.
   getline(ss, command, ' ');
   return command;
}

