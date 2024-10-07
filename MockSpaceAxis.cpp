#include "MockSpaceAxis.h"
#include <iostream>

MockSpaceAxis::MockSpaceAxis():
m_SimulatedPosition(0)
{
}

void MockSpaceAxis::Write(uint8_t* Buff, uint32_t Size)
{
   (void)Size;
   m_SimulatedPosition +=  *reinterpret_cast<int*>(Buff);
}

void MockSpaceAxis::Read(uint8_t* Buff, uint32_t Size)
{
   (void)Size;
   *reinterpret_cast<int*>(Buff) = m_SimulatedPosition;
}

