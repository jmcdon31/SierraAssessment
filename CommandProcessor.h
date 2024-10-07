#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H
#include <string>
#include <unordered_map>
#include <thread>
class CommandAcceptor;
/**
 * @brief The first stop for all ground commands. This class handles accepting commands from the
 * ground and distributing them to the appropriate object.
 */
class CommandProcessor
{
public:

   /**
    * @brief Start the Command Processor Thread for processing commands
    */
   static void Start();

   /**
    * @brief Register a CommandAcceptor with a Command string. When a new message is processed 
    *        with type "Command" then it will be routed to the Acceptor
    *
    * @param Command The string that identifies the command type
    * @param Acceptor The CommandAcceptor Object that will receive the command
    *
    * @return Success or Failed to add
    *
    * @note Current implementation only supports 1 Acceptor per Command type. This could be easily
    *       modified to allow multiple accptors per command type by changing the map to hold a
    *       list instead
    */
   static bool RegisterAcceptor(std::string Command, CommandAcceptor& Acceptor);


   static std::unordered_map<std::string, CommandAcceptor*> m_RegisterdAcceptors;
private:

/**
 * @brief Read commands coming into the spacecraft and route them to the appropriate command
 *        acceptor
 */
   static void ProcessCommands();

/**
 * @brief verify a packet or message has the form of a valid command
 */
   static bool ValidCommand(std::string& Command);

/**
 * @brief Get the Command Type from a valid Command Packet
 */
   static std::string GetCommandType(std::string& Command);


   static std::thread m_ProccessingThread;
};
#endif /* COMMAND_PROCESSOR_H */
