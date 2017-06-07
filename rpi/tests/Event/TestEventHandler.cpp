/*
 * TestEventHandler.cpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#include <EventQueue.hpp>
#include <EventHandler.hpp>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(TestEventHandler, testNameForEventHandler) {
	event::EventHandler handler;
  EXPECT_EQ(0, 0);

}
