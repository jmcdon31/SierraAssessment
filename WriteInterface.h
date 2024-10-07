#ifndef WRITE_INTERFACE_H
#define WRITE_INTERFACE_H
#include <cstdint>
/* Generic Write interface. Could represent UART, SPI, I2c, SpaceWire, ect*/
class WriteInterface
{
public:
   virtual void Write(uint8_t* buff, uint32_t size) = 0;
};
#endif /* WRITE_INTERFACE_H */
