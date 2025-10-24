

#include "serial_tank.h"
#include "Arduino.h"
#include "main.h"

unsigned int vol;
bool inlet_state = false;
bool outlet_state = false;

void init_serial_tank(void) 
{
    Serial.begin(19200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
}
 unsigned int value_h, value_l;
unsigned int volume(void)
{
   
    Serial.write(VOLUME);
    while (!Serial.available());
    value_h = Serial.read();
    while (!Serial.available());
    value_l = Serial.read();
    vol= (value_h << 8) | value_l;
   return vol;
}

void enable_inlet(void) { 
  Serial.write(INLET_VALVE); 
  Serial.write(ENABLE); 
  }
  
void disable_inlet(void) { 
  Serial.write(INLET_VALVE); 
  Serial.write(DISABLE); 
  }
  
void enable_outlet(void) { 
  Serial.write(OUTLET_VALVE); 
  Serial.write(ENABLE); 
   }
  
void disable_outlet(void) {
  Serial.write(OUTLET_VALVE); 
  Serial.write(DISABLE); 
   }

void set_inlet(int control)
{
    if (control ) {
      enable_inlet();
      }
    else {
      disable_inlet();
      }
}

void set_outlet(int control)
{
    if (control){
      enable_outlet();
      
    }
    else{ disable_outlet();}
    
}
