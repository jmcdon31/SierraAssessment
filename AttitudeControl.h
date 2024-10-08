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

   /**
    * @brief Calculate the current spacecraft attitude by reading sensors 
    * @note: If the current attitude was not converging on the expected commanded attitude, we
    *        could start to detect that here and maybe trigger fault protection*/
   void CalculatePosition();
private:

   /**
    * @brief Command handler for ATTITUDE command */
   void AttitudeCommand(std::vector<std::string>& Args);

   /**
    * @brief Given x, y , and z coordinates, return the planet that is being pointed at */
   std::string const GetPlanet();

   AttitudeXYZ                        m_Attitude;       //Current spacecraft Attitude
   bool                               m_ReportAttitude; //Flag to print out Attitude

   std::vector<AttitudeControlMotor*> m_AttControlMotors;
   std::vector<AttitudeSensor*>       m_AttSensors;

   //Note: Ideally these Mocks would be only added in for testing via build system or
   //configuration setup. For this example they have been hard coded.
   std::vector<MockSpaceAxis*>        m_Mocks;

};

#endif /* ATTITUDE_CONTROL_H */
