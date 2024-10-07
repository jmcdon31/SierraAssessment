#ifndef COMMAND_ACCEPTOR_H
#define COMMAND_ACCEPTOR_H
#include <queue>
#include <mutex>

/**
 * @brief A Abstract base class for objects which will accept Commands
 */
class CommandAcceptor
{
public:

   virtual void ProcessCommands() = 0;

   void AddCommand(std::string Command)
   {
      m_mutex.lock();
      m_Commands.push(Command);
      m_mutex.unlock();
   };

protected:
   std::queue<std::string> m_Commands;
   std::mutex              m_mutex;
};
#endif /* COMMAND_ACCEPTOR_H */
