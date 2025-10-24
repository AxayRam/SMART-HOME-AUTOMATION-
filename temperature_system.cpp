#include "temperature_system.h"
#include "Arduino.h"
#include "main.h"

float temperature = 0;

void init_temperature_system(void)
{
    pinMode(HEATER, OUTPUT);
    pinMode(COOLER, OUTPUT);
}

float read_temperature(void)
{
    // LM35 sensor: 10 mV/°C
    temperature = (((analogRead(TEMPERATURE_SENSOR) * 5.0) / 1024.0) / 0.01);
  return temperature;
}

// Control cooler ON/OFF
void cooler_control(int control)
{
    if (control != 0)
        digitalWrite(COOLER, HIGH);
    else
        digitalWrite(COOLER, LOW);
}

// Control heater ON/OFF
void heater_control(int control)
{
    if (control != 0)
        digitalWrite(HEATER, HIGH);
    else
        digitalWrite(HEATER, LOW);
}
