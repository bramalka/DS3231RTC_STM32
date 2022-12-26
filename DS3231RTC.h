#include "stm32f4xx.h"

#define DS3231_ADDRESS 0xD0

typedef struct{
	uint8_t sec;
	uint8_t min; 
	uint8_t hour; 
	uint8_t dow;
	uint8_t date;
	uint8_t month;
	uint8_t year2digit; 
}TIME;

uint8_t decToBcd(int val);

int bcdToDec(uint8_t val);

void DS3231_Init(I2C_HandleTypeDef *i2chandle);

void Set_Time(uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom, uint8_t month, uint8_t year);
void Get_Time(TIME *time);
