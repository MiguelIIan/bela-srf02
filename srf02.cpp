#include "srf02.hpp"

SRF02::SRF02(){
	
}

bool SRF02::begin(uint8_t i2caddr){
  i2c_address = i2caddr;
  uint8_t data[2];
  if(!i2c.readBytes(i2caddr,0x00,2,data)) return false;
  if(((data[0] << 8) | data[1]) == 0) return false;
  else return true;
  
}

int SRF02::readDistance(uint8_t i2caddr,Unit unit){
	
	uint8_t command = 0x00;
	if(unit==CENTIMETERS){
		command = 0x51;
	} else if(unit == INCHES){
		command = 0x50;
	} else {
		command = 0x52;
	}
	
	i2c.writeByte(i2caddr,0x00, command);
	
	usleep(70000);
	
	uint8_t reg = 0x02;
	uint8_t data[2];
	
	i2c.writeByte(i2caddr,reg,1);
	i2c.readBytes(i2caddr,reg,2,data);
	
	return (data[0] << 8) | data[1];
}

void SRF02::setAddress(uint8_t newi2caddress,uint8_t i2caddress){
	// For doing the i2c address change, the datasheet tells us to do the next
	// commands sequence: 0xA0 --> 0xAA --> 0xA5 --> New I2C address
	i2c.writeByte(i2caddress,0x00,0xA0);
	i2c.writeByte(i2caddress,0x00,0xAA);
	i2c.writeByte(i2caddress,0x00,0xA5);
	i2c.writeByte(i2caddress,0x00,newi2caddress);
	i2c_address = newi2caddress;
	
	
}

uint8_t SRF02::getAddress(){
	return i2c_address;
}