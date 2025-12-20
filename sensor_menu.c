#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#include "sensor_menu.h"
#include "tools.h"



void LDR_conv(void);
void print_sensor_menu(void);
int select_sensor(int input);
void thermistor_conv(void);
void pressure_conv(void);


int select_sensor(int input) 
{
    switch (input) {
        case 1:
            LDR_conv();
            go_back_to_main();
            return false;
        case 2:
            thermistor_conv();
            go_back_to_main();
            return false;
        case 3:
            pressure_conv();
            go_back_to_main();
            return false;
        default:
            return true;
    }

}


void print_sensor_menu(void) 
{
    printf("\n----------- Help menu -----------\n");
    printf("\n"
           "\t\t\t\t\t\t\n"
           "\t1. LDR\t\t\n"
           "\t2. Thermistor\t\t\n"
           "\t3. Pressure Sensor\t\t\n"
           "\t5. Exit to main menu\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");

}

void LDR_conv(void) 
{
    const double LOW = 0.3, MEDIUM = 0.7, MIN_V = 0, MAX_V = 4.99, V_IN = 5;
    
    printf("\n>> LDR converter\n\n\nPlease enter the voltage reading");
    double vReading = get_float_input(MIN_V, MAX_V);
    double ratio = vReading / V_IN;

    const char *lightLevel;
    if (ratio < LOW) {lightLevel = "low";}
    else if (ratio < MEDIUM) {lightLevel = "medium";}
    else {lightLevel = "high";}

    printf("\nThe light Level is: %s", lightLevel);

}

void thermistor_conv(void) /* using an NTC 100k 3950 */
{
    const double REF_TEMP_C = 25.0, REF_RES = 10000.0, THERM_CON = 3950.0, FIX_RES = 10000.0, MIN_V = 0.01, MAX_V = 4.99, V_IN = 5;
    
    printf("\n>> Thermistor converter\n\n\nPlease enter the voltage reading");
    double vReading = get_float_input(MIN_V, MAX_V); //offset so can't divide by 0
    double refTempK = REF_TEMP_C + 273.15;

    double thermRes = FIX_RES * vReading / (MAX_V - vReading);
    double kelvinTemp = 1.0 / ((1.0 / THERM_CON) * log(thermRes / REF_RES) + (1.0 / refTempK));

    double celsiusTemp = kelvinTemp - 273.15;
    double fahrenTemp = (celsiusTemp * (9.0/5.0)) + 32.0;

    printf("\nThe temperature is %.2f degrees celcius or %.2f degrees fahrenheit", 
    celsiusTemp, fahrenTemp);
    
}

void pressure_conv(void)
{
    /* Pressure sensor characteristics */
    const double V_MIN = 0.5, V_MAX = 4.5, P_MAX = 100.0;   

    printf("\n>> Pressure sensor converter\n\nPlease enter the voltage reading: ");
    double vReading = get_float_input(V_MIN,V_MAX);

    /* Linear pressure conversion */
    double kPa_pressure = (vReading - V_MIN) * P_MAX / (V_MAX - V_MIN);
    double barPressure = kPa_pressure / 100.0;
    double psiPressure = kPa_pressure * 0.145038;

    printf("\nPressure is %.2f kPa", kPa_pressure);
    printf("\nPressure is %.2f bar", barPressure);
    printf("\nPressure is %.2f psi", psiPressure);
}
