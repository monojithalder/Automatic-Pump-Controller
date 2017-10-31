#define F_CPU 16000000UL

#include <avr/myInputOutput.h>
#include <util/delay.h>

int main(void) {
	
	//Define Input Pins
	pinMode('C',5,0); //reserver input
	pinMode('C',4,0); //uppper tank low level
	pinMode('C',3,0); //upper tank high level

	//Define Output pins
	pinMode('B',5,1); //enable transistor
	pinMode('B',4,1); //enable led

	
	
	int reserver_input = 0;
	int tank_low_level_input = 0;
	int tank_high_level_input = 0;
	while(1) {

		//Read Inputs
		reserver_input = digitalRead('C',5); //Read reserver input value
		tank_low_level_input = digitalRead('C',4); //Read upper tank low level input value
		tank_high_level_input = digitalRead('C',4); //Read upper tank high level input value

		if(reserver_input == 1) { //If reserver have enough water
			if(tank_low_level_input == 0) {
				//Pump On Condition Satisfy
				digitalWrite('B',5,1);
				digitalWrite('B',4,0);
			}
			else if(tank_low_level_input == 1 && tank_high_level_input == 1) {
				//Pump off Condition satisfy
				digitalWrite('B',5,0);
				digitalWrite('B',5,1);
			}
		}
	}
	return 0;
}
