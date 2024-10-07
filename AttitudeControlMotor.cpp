#include "AttitudeControlMotor.h"

AttitudeControlMotor::AttitudeControlMotor(std::string Id, WriteInterface* Control):
   m_Id(Id),
   m_Control(Control)
{
}

void AttitudeControlMotor::Write(int Value)
{
   if (m_Control)
   {
      m_Control->Write(reinterpret_cast<uint8_t*>(&Value), sizeof(Value));
   }
}
