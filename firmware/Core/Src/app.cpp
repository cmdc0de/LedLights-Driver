/*
 * app.cpp
 *
 *  Created on: Apr 5, 2020
 *      Author: dcomes
 */

#include "config.h"
#include "app.h"
#include "spibus.h"
#include "spidevice.h"
#include "leds/apa102c.h"
#include "rgbcolor.h"
#include "main.h"

using namespace cmdc0de;

SPIBus myBus(getSPI());
APA102c apa102c(myBus.createMasterDevice());
const int NUM_LEDS = 9;
cmdc0de::RGB ledBuf[NUM_LEDS] = {RGB::BLUE};

I2CMaster I2CM(getI2C());

void initApp() {
  for(int i=0;i<NUM_LEDS;i++) {
	ledBuf[i] = cmdc0de::RGB::BLUE;
  }
  apa102c.init(NUM_LEDS,&ledBuf[0]);
  I2CM.scan();
}


void run() {
	apa102c.send();
}
