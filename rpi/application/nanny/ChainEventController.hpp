#ifndef APLICATION_NANNY_CHAINEVENTCONTROLLER_HPP_
#define APLICATION_NANNY_CHAINEVENTCONTROLLER_HPP_
#include <event/queue/Waiter.hpp>
#include <event/queue/EventQueue.hpp>
#include <map>
#include <inc/Messages.hpp>

// downloaded from https://github.com/nlohmann/json
#include <utils/json.hpp>
using nlohmann::json;

namespace app {

class ChainEvent : public queue::IWaiter
{
public:
  ChainEvent(json,u8);
  virtual ~ChainEvent();

  void notify(void *);
  void sendReactions();

private:
  void sendInternalEvent(json &,u8);
  u32 clientId;
  u32 temporaryChainEventId;
  u32 waiterId;

  json chainEvent;
};

class ChainEventController
{
public:
  ChainEventController();
  virtual ~ChainEventController();

  void storeChain(json *);
  void removeChain(u8);
private:
  std::map<u8,ChainEvent*> chainedEvents;
};

} // namespace app

#endif /* APLICATION_NANNY_CHAINEVENTCONTROLLER_HPP_ */
