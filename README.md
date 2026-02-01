# SRF02 sonar I2C sensor
Release date: 01/02/2026

### Summary
This repository contains the library that enables the Bela development board to interface with the SRF02 sensor and also a Bela example code. The ```I2Cdev``` library comes from the [giuliomoro/bela-vl53l0x](https://github.com/giuliomoro/bela-vl53l0x/tree/bela) repository.

## Usage
### Hardware
#### Connections
                   Bela   SRF02 Sonar
    -------------------   -------------
     3.3V Power (P9_03) - VIN
            SDA (P9_26) - SDA
            SCL (P9_24) - SCL
         Ground (P9_01) - GND

### Software
#### Installation
Simply add all the ```.cpp``` and ```.hpp``` files to your project and modify your build script to include them.

#### Using the library
* Include ```"srf02.hpp"```
* Create an object of SRF02 class
* Call ```.begin()```
For a distance reading:
* Call ```.readDistance()```

#### Methods
* ```SRF02()``` --> Constructor.
* ```bool begin(uint8_t i2caddress)``` --> Try the i2c connection with the SRF02 and returns false if it is not.
* ```int readDistance(uint8_t i2caddress, Unit unit)``` --> Read distance in centimeters, inches or microseconds.
* ```uint8_t getAddress()``` --> Gets the SRF02 i2c address.
* ```void setAddress(uint8_t newi2caddress, uint8_t i2caddress)``` --> Changes the SRF02 sensor i2c address to a new one.

### Special thanks
Giuliomoro for the ```I2Cdev``` library which let me communicate more easily with the SRF02 using the Bela board.
