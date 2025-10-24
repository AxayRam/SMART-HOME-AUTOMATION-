#define BLYNK_TEMPLATE_ID "TMPL3NxRgCxqj"
#define BLYNK_TEMPLATE_NAME "EMERTXE IOT INTERNSHIP PROJECT"
#define BLYNK_AUTH_TOKEN "0nPoJ_lwB1U_wC62BP_56xi5RWWrhGXG"


#include "ldr.h"
#include "main.h"
#include "temperature_system.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#include "serial_tank.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

bool heater_sw, inlet_sw, outlet_sw, cooler_sw;
char auth[] = BLYNK_AUTH_TOKEN;

BlynkTimer timer;

// Cooler control
BLYNK_WRITE(COOLER_V_PIN)
{
  cooler_sw = param.asInt();               // correct way
  cooler_control(cooler_sw);               // call IO
  if (cooler_sw) {
    lcd.setCursor(3,0);
    lcd.print("CLR_ON");
  } else {
    lcd.setCursor(3,0);
    lcd.print("CLR_OF");
  }
}

// Heater control
BLYNK_WRITE(HEATER_V_PIN)
{
  heater_sw = param.asInt();               // correct way
  heater_control(heater_sw);
  if (heater_sw) {
    lcd.setCursor(10, 0);
    lcd.print("HTR_ON");
  } else {
    lcd.setCursor(10, 0);
    lcd.print("HTR_OF");
  }
}

// Inlet valve control (fixed)
BLYNK_WRITE(INLET_V_PIN)
{
  inlet_sw = param.asInt();                // read virtual pin value
  set_inlet(inlet_sw);                     // single call -> serial_tank
  if (inlet_sw) {
    lcd.setCursor(6, 1);                   // stable slot for IN
    lcd.print("IN_ON");                    // 5 chars
  } else {
    lcd.setCursor(6, 1);
    lcd.print("IN_OF");                    // fixed width
  }
}

// Outlet valve control (fixed)
BLYNK_WRITE(OUTLET_V_PIN)
{
  outlet_sw = param.asInt();               // read virtual pin value
  set_outlet(outlet_sw);                   // single call
  if (outlet_sw) {
    lcd.setCursor(11, 1);                  // stable slot for OT
    lcd.print("OT_ON");                    // 5 chars
  } else {
    lcd.setCursor(11, 1);
    lcd.print("OT_OF");                    // fixed width
  }
}


void handle_temp(void)
{
  if (read_temperature() > (float)35 && heater_sw) {
    heater_sw = 0;
    heater_control(0);
    Blynk.virtualWrite(HEATER_V_PIN, 0);
  }
}
// Gauges
float up_temp;
void update_temperature_reading()
{
  up_temp =read_temperature();
  Blynk.virtualWrite(TEMPERATURE_GAUGE,up_temp);
 
}
float water;
void handle_tank(void)
{
   water = volume();
  Blynk.virtualWrite(TANK_GAUGE, water);
}

void setup(void)
{
  init_ldr();
  init_temperature_system();
  init_serial_tank();                      // IMPORTANT: start tank serial

  Blynk.begin(BLYNK_AUTH_TOKEN);           // Ethernet shield (DHCP)

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.home();
  lcd.setCursor(0, 0);
  lcd.print("HA:");


  timer.setInterval(100,update_temperature_reading);
  timer.setInterval(100,handle_tank);
}

float temp;
void loop(void)
{
  Blynk.run();                             // run once is enough
  timer.run();

  brightness_control();
  temp = read_temperature();
  handle_temp();

  lcd.setCursor(0, 1);
  lcd.print(temp);                         // keep as-is
  
}
