#include "DS3231RTC.h"
#include "main.h"

I2C_HandleTypeDef i2c;

uint8_t decToBcd(int val){// Convert binary coded decimal to normal decimal numbers
  return (uint8_t)( (val/10*16) + (val%10) );
}

int bcdToDec(uint8_t val){
  return (int)( (val/16*10) + (val%16) );
}

void DS3231_Init(I2C_HandleTypeDef *i2chandle){
	i2c = *i2chandle;
}

void Set_Time (uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom, uint8_t month, uint8_t year){
	uint8_t set_time[7];
	set_time[0] = decToBcd(sec);
	set_time[1] = decToBcd(min);
	set_time[2] = decToBcd(hour);
	set_time[3] = decToBcd(dow);
	set_time[4] = decToBcd(dom);
	set_time[5] = decToBcd(month);
	set_time[6] = decToBcd(year);

	HAL_I2C_Mem_Write(&i2c, DS3231_ADDRESS, 0x00, 1, set_time, 7, 1000);
}
void Get_Time(TIME *time){
	uint8_t get_time[7];
	HAL_I2C_Mem_Read(&i2c, DS3231_ADDRESS, 0x00, 1, get_time, 7, 1000);
	time->sec = bcdToDec(get_time[0]);
	time->min = bcdToDec(get_time[1]);
	time->hour = bcdToDec(get_time[2]);
	time->dow = bcdToDec(get_time[3]);
	time->date = bcdToDec(get_time[4]);
	time->month = bcdToDec(get_time[5]);
	time->year2digit = bcdToDec(get_time[6]);
}
