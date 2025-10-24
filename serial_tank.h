#ifndef SERIAL_TANK_H
#define SERIAL_TANK_H

#define INLET_VALVE  0x00
#define OUTLET_VALVE 0x01

#define HIGH_FLOAT 0x10
#define LOW_FLOAT  0x11

#define VOLUME 0x30

#define ENABLE  0x01
#define DISABLE 0x00

extern unsigned int tank_volume;
extern bool inlet_state;
extern bool outlet_state;

void init_serial_tank(void);
void enable_inlet(void);
void disable_inlet(void);
void enable_outlet(void);
void disable_outlet(void);
unsigned int volume(void);

// Single-call helpers for Blynk virtual pin
void set_inlet(int control);
void set_outlet(int control);

#endif
