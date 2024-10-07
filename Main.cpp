#include <iostream>
#include "CommandProcessor.h"
#include "AttitudeControl.h"

int main()
{
   AttitudeControl attitudeControl;
   std::cout << "Sierra Flight Software Assessment\n   Waiting for Input" << std::endl;

   //Start the command processor thread
   CommandProcessor::Start();

   /*Continuous Control Loop */
   while(1)
   {
      attitudeControl.ProcessCommands();
      attitudeControl.CalculatePosition();
   //SendTelemetry
   }

   return 0;
}
