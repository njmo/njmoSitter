#include "ChainEventController.hpp"

namespace app {


ChainEvent::~ChainEvent()
{

}

ChainEvent::ChainEvent(json _ce, u8 id)
  : chainEvent(_ce),
    clientId(_ce["id"]),
    temporaryChainEventId(id)
{
  nannyLogInfo("Craeted ChainEvent");
  waiterId = 99;
	event::EventQueue::getInstance().registerAsWaiter(waiterId,*this);
  sendInternalEvent(chainEvent["action"],waiterId);
}

void ChainEvent::sendReactions()
{
  json &reactions = chainEvent["reaction"];
  for (json::iterator it = reactions.begin(); it != reactions.end(); ++it) {
      sendInternalEvent(*it,clientId);
  }
}
void ChainEvent::notify(void *response)
{
  json *resp = reinterpret_cast<json*>(response);
  if (resp->operator[]("notifyType").get<u8>() != chainEvent["action"]["nannyType"])
    return;
  nannyLogInfo("Received notification " + std::to_string(resp->operator[]("notifyType").get<u8>()));
  sendReactions();

  delete resp; 
}

void ChainEvent::sendInternalEvent(json &j,u8 idToSend)
{
	event::Event* internalResponseEvent= reinterpret_cast<event::Event*>(allocate(5));
	internalResponseEvent->type = event::EventType::InternalResponse;
  internalResponseEvent->senderId = NANNY_ID;

  json *internalJson = new json(j);
  internalJson->operator[]("id") = idToSend;
  internalJson->operator[]("isChainedEvent") = true;

  *reinterpret_cast<u32*>(internalResponseEvent->payload) = (u32)internalJson;
	event::EventQueue::getInstance().push(internalResponseEvent);

}

ChainEventController::~ChainEventController()
{

}

ChainEventController::ChainEventController()
{

}

void ChainEventController::ChainEventController::storeChain(json *chainEvent)
{
  static u8 generatedId = 0;
  ChainEvent* ev = new ChainEvent(*chainEvent,generatedId++);
  chainedEvents.emplace(generatedId,ev);
}

void ChainEventController::removeChain(u8 idToBeRemoved)
{
	auto chainedEvent = chainedEvents.find(idToBeRemoved);
  delete chainedEvent->second;
  chainedEvents.erase(idToBeRemoved);
}

} // namespace app
