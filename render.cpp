/*
This bela example just shows the distance measured by the SRF02 distance sensor.
Implement this in any bela project you want to.
*/

#include <Bela.h>
#include "srf02.hpp"
#include <cmath>

// SRF02 I2C address (7 bits)
const uint8_t kSrf02Address = 0x70;

// Srf02 class instance
SRF02 sensor;
/*
SRF02 physical pins:
--------------------------
|· Vcc (+5V)           O |
|· SDA                   |
|· SCL                   |
|· Mode                  |
|· Ground                |
|                        |
| O                      |
--------------------------
*/

// Global variables
int gDistance = 0; 

void readDistance(void*) {
	
	while(!Bela_stopRequested())
	{
		// There are three measurements options: Centimeters(default), Inches, Microseconds of flight.
		// For using them, there have to be an additional argument. This argument has to be one of the 
		// next three: "SRF02::CENTIMETERS", "SRF02::INCHES", "SRF02::MICROSECONDS".
	    gDistance = sensor.readDistance(kSrf02Address);
	    rt_printf("DistanciaReal: %d cm\n", gDistance);
	}
}

bool setup(BelaContext *context, void *userData) {
	
    // Looks if the SRF02 is connected and stops the code if it's not.
    if(!sensor.begin(kSrf02Address)){
    	rt_printf("Error initialising SRF02\n");
    	return false;
    }
    
    // With this next command you can change the SRF02 i2c address, but 
    // you have to know that the bits of the i2c address move one bit to the 
    // right. To clarify --> the address 0xE0(1110 0000) in the "setAddress" function,
    // for the "readDistance" function is 0x70(0111 0000), the address 0xE2(1110 0010)
    // is the 0x71(0111 0001) for communicating with it and so on.
    sensor.setAddress(0xe0);
    
    // Lets create the auxiliary task
    Bela_runAuxiliaryTask(readDistance);

    return true;
}

void render(BelaContext *context, void *userData) {
   
}

void cleanup(BelaContext *context, void *userData) {
    
}