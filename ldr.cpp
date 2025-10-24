#include "ldr.h"
#include "Arduino.h"
#include "main.h"


// LDR (Light Dependent Resistor) Control System


// This module controls the brightness of the garden light
// automatically based on ambient light intensity.

// LDR_SENSOR  → Connected to an analog pin (reads light intensity)
// GARDEN_LIGHT → Connected to a PWM pin (controls light brightness)


// Variable to store light intensity and PWM duty cycle
unsigned int Light_intensity = 0;
unsigned int duty = 0;



// Initialize LDR system

void init_ldr(void)
{
    pinMode(GARDEN_LIGHT, OUTPUT);                                 // Set garden light pin as output
}


// Control brightness using LDR

void brightness_control(void)
{
    // Read LDR sensor value (0–1023)
    Light_intensity = analogRead(LDR_SENSOR);

    // Convert to PWM duty (invert logic → brighter when dark)
    duty = 255 - (Light_intensity / 4);

    // Write PWM output to garden light
    analogWrite(GARDEN_LIGHT, duty);

    // Small delay for stable operation
    delay(100);
}
