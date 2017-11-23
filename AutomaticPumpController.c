#define F_CPU 16000000UL

#include <avr/myInputOutput.h>
#include <util/delay.h>

int main(void) {
	
	//Define Input Pins
	pinMode('D',6,0); //reserver input
	pinMode('B',0,0); //uppper tank low level
	pinMode('D',7,0); //upper tank high level

	//Define Output pins
	pinMode('C',5,1); //enable transistor
	pinMode('D',2,1); //enable led

	
	
	int reserver_input = 0;
	int tank_low_level_input = 0;
	int tank_high_level_input = 0;
	int pump_on = 0;
	int reccived = 0;
	while(1) {

		//Read Inputs
		reserver_input = digitalRead('D',6); //Read reserver input value
		tank_low_level_input = digitalRead('B',0); //Read upper tank low level input value
		tank_high_level_input = digitalRead('D',7); //Read upper tank high level input value

		if(reserver_input == 1) { //If reserver have enough water
		   if(tank_low_level_input == 0 && tank_high_level_input == 1) {
				//Pump off Condition satisfy
				reccived = 0;
				digitalWrite('C',5,0);
				digitalWrite('D',2,1);
				pump_on = 0;
			}
			else if(tank_low_level_input == 0 && tank_high_level_input == 0 && pump_on == 0) {
				//Pump off Condition satisfy
				reccived = 0;
				digitalWrite('C',5,0);
				digitalWrite('D',2,1);
				pump_on = 0;
			}
			else if(tank_low_level_input == 1 || pump_on == 1) {
				//Pump On Condition Satisfy
				reccived++;
				if(reccived > 500) {
					digitalWrite('C',5,1);
					digitalWrite('D',2,0);
					pump_on = 1;
				}
			}
		}
		else {
			digitalWrite('C',5,0);
			digitalWrite('D',2,1);
			pump_on = 0;
		}
	}
	return 0;
}
