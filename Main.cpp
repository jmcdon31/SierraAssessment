#include <iostream>
#include "CommandProcessor.h"
#include "AttitudeControl.h"

int main()
{
   std::cout << "Sierra Flight Software Assessment" << std::endl;

   //Start the command processor thread
   CommandProcessor::Start();
   AttitudeControl attitudeControl;

   /*Continuous Control Loop */
   while(1)
   {
      attitudeControl.ProcessCommands();
   //SendTelemetry
   }

   return 0;
}
