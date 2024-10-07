#ifndef ATTITUDE_CONTROL_H
#define ATTITUDE_CONTROL_H
#include "CommandAcceptor.h"

/**
 * @brief High level Attitude Control class
 */
class AttitudeControl : public CommandAcceptor
{
public:

   AttitudeControl();
   ~AttitudeControl() = default;

   void ProcessCommands() override;
private:
   void AttitudeCommand(std::vector<std::string>& Args);

};

#endif /* ATTITUDE_CONTROL_H */
