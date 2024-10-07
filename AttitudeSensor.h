#ifndef ATTITUDE_SENSOR_H
#define ATTITUDE_SENSOR_H
#include "ReadInterface.h"
#include <string>

/* @brief Generic Sensor that reads a single axis orientation
 */
class AttitudeSensor
{
public:
   AttitudeSensor(std::string Id, ReadInterface* Control);
   ~AttitudeSensor() = default;

   /* @brief Command Motor to actuate
    *
    * @param Value amount motor should actuate. Supports positive and negative
    */
   void Read(int& Value);

   std::string m_Id;
private:
   ReadInterface* m_Control;

};

#endif /* ATTITUDE_SENSOR_H */
