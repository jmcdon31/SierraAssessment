#ifndef ATTITUDE_CONTROL_H
#define ATTITUDE_CONTROL_H
#include "CommandAcceptor.h"
#include "AttitudeControlMotor.h"
#include "AttitudeSensor.h"
#include "MockSpaceAxis.h"

/**
 * @brief High level Attitude Control class
 */
class AttitudeControl : public CommandAcceptor
{
public:
   struct AttitudeXYZ
   {
      int x = 0;
      int y = 0;
      int z = 0;
   };

   AttitudeControl();
   ~AttitudeControl();

   //Overwritten Command Acceptor call
   void ProcessCommands() override;

   /* @brief Calculate the current spacecraft attitude
    */
   void CalculatePosition();
private:

   /*@brief Command handler for ATTITUDE command
    */
   void AttitudeCommand(std::vector<std::string>& Args);

   /* @brief Given x, y , and z coordinates, return the planet that is being pointed at
    */
   std::string const GetPlanet();

   AttitudeXYZ                        m_Attitude; //Current spacecraft Attitude
   bool                               m_ReportPosition; //Flag to print out Position

   std::vector<AttitudeControlMotor*> m_AttControlMotors;
   std::vector<AttitudeSensor*>       m_AttSensors;
   std::vector<MockSpaceAxis*>        m_Mocks;

};

#endif /* ATTITUDE_CONTROL_H */
