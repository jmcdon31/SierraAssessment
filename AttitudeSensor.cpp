#include "AttitudeSensor.h"
AttitudeSensor::AttitudeSensor(std::string Id, ReadInterface* Control):
   m_Id(Id),
   m_Control(Control)
{
}

void AttitudeSensor::Read(int& Value)
{

   if (m_Control)
   {
      m_Control->Read(reinterpret_cast<uint8_t*>(&Value), sizeof(Value));
   }
}
