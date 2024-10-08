#include "AttitudeControl.h"
#include "CommandProcessor.h"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <map>

AttitudeControl::AttitudeControl():
   m_ReportAttitude(false)
{
   //Note: Other command types can be register here
   CommandProcessor::RegisterAcceptor("ATTITUDE", *this);

   //Create simulated axis for x, y and z
   m_Mocks.push_back(new MockSpaceAxis());
   m_Mocks.push_back(new MockSpaceAxis());
   m_Mocks.push_back(new MockSpaceAxis());

   //Register Motors for each axis
   m_AttControlMotors.push_back( new AttitudeControlMotor("X", m_Mocks[0]));
   m_AttControlMotors.push_back( new AttitudeControlMotor("Y", m_Mocks[1]));
   m_AttControlMotors.push_back( new AttitudeControlMotor("Z", m_Mocks[2]));

   //Register Sensor for each axis
   m_AttSensors.push_back( new AttitudeSensor("X", m_Mocks[0]));
   m_AttSensors.push_back( new AttitudeSensor("Y", m_Mocks[1]));
   m_AttSensors.push_back( new AttitudeSensor("Z", m_Mocks[2]));
}

AttitudeControl::~AttitudeControl()
{
   for (auto i = 0U; i < m_Mocks.size(); i++)
   {
      delete &m_Mocks[i];
      delete &m_AttControlMotors[i];
      delete &m_AttSensors[i];
   }
}

void AttitudeControl::CalculatePosition()
{
   m_AttSensors[0]->Read(m_Attitude.x);
   m_AttSensors[1]->Read(m_Attitude.y);
   m_AttSensors[2]->Read(m_Attitude.z);

   //Only report position if flag has been set when attitude changed
   if (m_ReportAttitude)
   {
      printf("Pointing Towards: %s at %d, %d, %d\n",
              GetPlanet().c_str(),
              m_Attitude.x,
              m_Attitude.y,
              m_Attitude.z);

      m_ReportAttitude = false;
   }
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
   if (m_AttControlMotors.size() != 3)
   {
      std::cout << "ERROR: Attitude Control Command not setup with 3 axis" << std::endl;
   }

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
      m_AttControlMotors[0]->Write(x);
      m_AttControlMotors[1]->Write(y);
      m_AttControlMotors[2]->Write(z);

      //After issuing a change in attitude, make sure to report the new position
      m_ReportAttitude = true;
   }
   catch (std::invalid_argument const& ex)
   {
      std::cout << "Invalid arguments for Attitude Control Command. Must use Integer values"
         << std::endl;
   }

}

std::string const AttitudeControl::GetPlanet()
{
   static const std::map<std::tuple<bool, bool, bool>, std::string> planets = {
        {{1, 1, 1}, "GRACE"},
        {{1, 0, 1}, "BRAY"},
        {{1, 1, 0}, "PRICE"},
        {{1, 0, 0}, "MIG"},
        {{0, 1, 1}, "WIEM"},
        {{0, 0, 1}, "TURK"},
        {{0, 1, 0}, "MROW"},
        {{0, 0, 0}, "SEBAS"}};

   bool x =  m_Attitude.x >= 0 ? true : false;
   bool y =  m_Attitude.y >= 0 ? true : false;
   bool z =  m_Attitude.z >= 0 ? true : false;
   return planets.at({x, y, z});

}

