#include "AttitudeControl.h"
#include "CommandProcessor.h"
#include <iostream>
#include <sstream>

AttitudeControl::AttitudeControl()
{
   //Note: Other command types can be register here
   CommandProcessor::RegisterAcceptor("ATTITUDE", *this);
}

void AttitudeControl::ProcessCommands()
{
   while (!m_Commands.empty())
   {
      //Get Command from queue
      m_mutex.lock();
      std::string command = m_Commands.front();
      m_Commands.pop();
      m_mutex.unlock();

      //split command based on spaces
      std::stringstream ss(command);
      std::vector<std::string> commandParsed;
      std::string arg;
      while (ss >> arg)
      {
         commandParsed.push_back(arg);
      }

      if (commandParsed.size() > 0)
      {
         //NOTE: Other command types can be handled here
         if (commandParsed[0] == "ATTITUDE")
         {
            AttitudeCommand(commandParsed);
         }
         else
         {
            std::cout << "WARNING: Unknown Attitude Control Command" << std::endl;
         }
      }
   }

}

void AttitudeControl::AttitudeCommand(std::vector<std::string>& Args)
{
   if (Args.size() != 4)
   {
      std::cout << "ERROR: Attitude Control Command - Invalid Number of Arguments" << std::endl;
      std::cout << "      Please input: x y z" << std::endl;
      return;
   }

   try
   {
      int x = std::stoi(Args[1]);
      int y = std::stoi(Args[2]);
      int z = std::stoi(Args[3]);
      std::cout << "x: " << x << std::endl;
      std::cout << "y: " << y << std::endl;
      std::cout << "z: " << z << std::endl;
   }
   catch (std::invalid_argument const& ex)
   {
      std::cout << "Invalid arguments for Attitude Control Command. Must use Integer values"
         << std::endl;
   }

}
