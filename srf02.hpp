#pragma once
#ifndef SRF02_H
#define SRF02_H

#include <Bela.h>
#include "I2Cdev.hpp"

#define SRF02_DEFAULT_ADDRESS 0x70

class SRF02 {
	public:
	
		typedef enum {
			CENTIMETERS = 1,
			INCHES=2,
			MICROSECONDS=3,
		} Unit;
		
		SRF02();
		
		bool begin(uint8_t i2caddress = SRF02_DEFAULT_ADDRESS);
		
		int readDistance(uint8_t i2caddress, Unit unit = CENTIMETERS);
		
		void setAddress(uint8_t newi2caddress, uint8_t i2caddress = SRF02_DEFAULT_ADDRESS);
		
		uint8_t i2c_address;
		
		uint8_t getAddress();
	private:
		I2Cdev i2c;
		
};

#endif
