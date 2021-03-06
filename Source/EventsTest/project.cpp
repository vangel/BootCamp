#include "FirstEvent.h"
#include "SecondEvent.h"

#include <iostream>
#include <cassert>

struct Asteroid
{
	std::map<EventID_t, Token_t> _tokens;
	int countOfHandlerResponce = 0;

	void subscribeToEvent(const EventID_t eventID)
	{
		std::map<EventID_t, Token_t>::iterator tokenForCurrentEvent = _tokens.find(eventID);

		if (tokenForCurrentEvent != _tokens.end())
		{
			std::cout << "Failed to subscribe. Already subscribe to this event" << std::endl;
			return;
		}

		Dispatcher& dispatcher = Dispatcher::getInstance();

		std::function<void(const Event&)> handler = [&](const Event &e) 
		{
			countOfHandlerResponce++;
		};

		int token = dispatcher.Connect(eventID, handler);
		_tokens[eventID] = token;
	}

	void unsubscribeToEvent(const EventID_t eventID)
	{
		std::map<EventID_t, Token_t>::iterator tokenForCurrentEvent = _tokens.find(eventID);

		if (tokenForCurrentEvent == _tokens.end())
		{
			std::cout << "Failed to unsubscribe. Already unsubscribed or never have been subscribed." << std::endl;
			return;
		}

		Dispatcher& dispatcher = Dispatcher::getInstance();
		dispatcher.Disconnect(eventID, tokenForCurrentEvent->second);
		_tokens.erase(tokenForCurrentEvent);
	}
};

struct Analytic
{
	std::map<EventID_t, Token_t> _tokens;
	int countOfHandlerResponce = 0;

	void subscribeToEvent(const EventID_t eventID)
	{
		std::map<EventID_t, Token_t>::iterator tokenForCurrentEvent = _tokens.find(eventID);

		if (tokenForCurrentEvent != _tokens.end())
		{
			std::cout << "Failed to subscribe. Already subscribe to this event" << std::endl;
			return;
		}

		Dispatcher& dispatcher = Dispatcher::getInstance();

		std::function<void(const Event&)> handler = [&](const Event &e)
		{
			countOfHandlerResponce++;
		};

		int token = dispatcher.Connect(eventID, handler);
		_tokens[eventID] = token;
	}

	void unsubscribeToEvent(const EventID_t eventID)
	{
		std::map<EventID_t, Token_t>::iterator tokenForCurrentEvent = _tokens.find(eventID);

		if (tokenForCurrentEvent == _tokens.end())
		{
			std::cout << "Failed to unsubscribe. Already unsubscribed or never have been subscribed." << std::endl;
			return;
		}

		Dispatcher& dispatcher = Dispatcher::getInstance();
		dispatcher.Disconnect(eventID, tokenForCurrentEvent->second);
		_tokens.erase(tokenForCurrentEvent);
	}
};


int main()
{
	Dispatcher& dispatcher = Dispatcher::getInstance();
	Asteroid asteroid;
	Analytic analytic;
	FirstEvent firstEvent;
	SecondEvent secondEvent;

	assert(firstEventID != secondEventID);
	std::cout << "Different ID for different Event classes - Done!" << std::endl;

	int beforeRegistrationTokensCount = asteroid._tokens.size();
	asteroid.subscribeToEvent(firstEventID);
	int afterRegistrationTokensCount = asteroid._tokens.size();
	assert(beforeRegistrationTokensCount + 1 == afterRegistrationTokensCount);
	std::cout << "Adding new listener to certain event notification - Done!" << std::endl;
	
	asteroid.unsubscribeToEvent(firstEventID);
	int afterUnregistrationTokensCount = asteroid._tokens.size();
	assert(afterRegistrationTokensCount - 1 == afterUnregistrationTokensCount);
	std::cout << "Removing listener from certain event notification - Done!" << std::endl;

	asteroid.subscribeToEvent(firstEventID);
	dispatcher.Send(firstEvent, firstEventID);
	assert(asteroid.countOfHandlerResponce == 1);
	analytic.subscribeToEvent(firstEventID);
	dispatcher.Send(firstEvent, firstEventID);
	assert(asteroid.countOfHandlerResponce == 2 && analytic.countOfHandlerResponce == 1);
	std::cout << "Dispatcher sends events and listeners handle them  - Done!" << std::endl;

	asteroid.unsubscribeToEvent(firstEventID);
	analytic.unsubscribeToEvent(firstEventID);
	asteroid.subscribeToEvent(firstEventID);
	analytic.subscribeToEvent(firstEventID);
	asteroid.unsubscribeToEvent(firstEventID);
	analytic.unsubscribeToEvent(firstEventID);

	return 0;
}