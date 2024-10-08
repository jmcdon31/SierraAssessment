#ifndef MOCK_SPACE_H
#define MOCK_SPACE_H
#include "WriteInterface.h"
#include "ReadInterface.h"

/*Mock a Space Axis environment. Take a actuator input and spit out a sensor output*/
class MockSpaceAxis : public WriteInterface, public ReadInterface
{
public:
   MockSpaceAxis();

   //Overwritten Interfaces
   void Write(uint8_t* buff, uint32_t size)  override;
   void Read(uint8_t* buff, uint32_t size)  override;

private:
   int m_SimulatedPosition; //Simulated environment value
};
#endif /* MOCK_SPACE_H */
