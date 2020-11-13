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
#include "i2c.h"

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

int8_t percent =100;
uint16_t count = 0;
bool up = false;

void run() {
	if(count==0) {
		apa102c.setBrightness(up ? percent++ : percent--);
		apa102c.send();
		if(percent<1) {
			up = true;
		} else if (percent>99) {
			up = false;
		}
	}
	++count;
	if(10000==count) count = 0;
}
