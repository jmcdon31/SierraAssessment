#ifndef ATTITUDE_CONTROL_MOTOR_H
#define ATTITUDE_CONTROL_MOTOR_H
#include "WriteInterface.h"
#include <string>

/* @brief Generic Motor that effects attitude on a single axis */
class AttitudeControlMotor
{
public:
   AttitudeControlMotor(std::string Id, WriteInterface* Control);
   ~AttitudeControlMotor() = default;

   /* @brief Command Motor to actuate
    *
    * @param Value amount motor should actuate. Supports positive and negative
    */
   void Write(int Value);

   std::string m_Id;
private:
   WriteInterface* m_Control;

};

#endif /* ATTITUDE_CONTROL_MOTOR_H */
