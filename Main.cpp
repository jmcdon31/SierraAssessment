#include <iostream>
#include "CommandProcessor.h"
#include "AttitudeControl.h"

int main()
{
   AttitudeControl attitudeControl;
   std::cout << "Sierra Flight Software Assessment" << std::endl;
   std::cout << "   waiting for input" << std::endl;

   //Start the command processor thread
   CommandProcessor::Start();

   /*Continuous Control Loop */
   while(true)
   {
      attitudeControl.ProcessCommands();
      attitudeControl.CalculatePosition();
      //TODO: SendTelemetry to ground
   }

   return 0;
}
