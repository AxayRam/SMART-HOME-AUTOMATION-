#ifndef TEMPERATURE_SYSTEM_H
#define TEMPERATURE_SYSTEM_H

#define HEATER                4
#define COOLER                5

#define TEMPERATURE_SENSOR    A0

float read_temperature(void);
void init_temperature_system(void);

// Specify int type for control (0 = OFF, 1 = ON)
void cooler_control(int control);
void heater_control(int control);

#endif
