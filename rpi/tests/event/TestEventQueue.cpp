/*
 * TestEventQueue.cpp
 *
 *  Created on: Jun 8, 2017
 *      Author: njmo
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <EventQueue.hpp>
#include <Event.hpp>

class TestEventQueue : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}

};

TEST_F(TestEventQueue, shouldReturnLastAddedEvent) {
	event::Event tempEvent;
	tempEvent.type=static_cast<event::EEventType>(4);
	event::EventQueue::getInstance().push(&tempEvent);
	EXPECT_EQ(4, static_cast<u32>(event::EventQueue::getInstance().pop()->type));
}

TEST_F(TestEventQueue, shouldReturnMostImportantEvent) {
	event::Event tempEvent;
	tempEvent.type=static_cast<event::EEventType>(4);

	event::Event mostImportantTempEvent;
	mostImportantTempEvent.type=static_cast<event::EEventType>(9);

	event::EventQueue::getInstance().push(&tempEvent);
	event::EventQueue::getInstance().pushImportant(&mostImportantTempEvent);

	EXPECT_EQ(9, static_cast<u32>(event::EventQueue::getInstance().pop()->type));
}
