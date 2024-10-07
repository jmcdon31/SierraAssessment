#ifndef READ_INTERFACE_H
#define READ_INTERFACE_H
#include <cstdint>
/* Generic Read interface. Could represent UART, SPI, I2c, SpaceWire, ect*/
class ReadInterface
{
public:
   virtual void Read(uint8_t* buff, uint32_t size) = 0;
};
#endif /* READ_INTERFACE_H */
