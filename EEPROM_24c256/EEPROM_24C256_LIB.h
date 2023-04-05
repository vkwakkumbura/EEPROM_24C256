/*
 * EEPROM_24C256_LIB.h
 *
 *	     Author: Vipula Wakkumbura
 *
 *      Description : C library to write and read float values to EEPROM_24C256 using I2C
 */

#ifndef INC_EEPROM_24C256_LIB_H_
#define INC_EEPROM_24C256_LIB_H_

#include "stdint.h"
#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


extern I2C_HandleTypeDef hi2c1;
#define EEPROM_I2C &hi2c1


#define EEPROM_ADDR 0xA0


extern uint8_t Write_array1[4];
extern uint8_t Read_array1[4];

extern uint32_t EEPROM_write_val ;
extern bool EEPROM_write_flag ;

extern uint32_t EEPROM_read_val;
extern bool EEPROM_read_flag;

typedef union FLOAT_2_INT{

	float float_in;
	uint32_t int_out;

}FLOAT_2_INT_CON;

extern union FLOAT_2_INT float2int;

typedef union INT_2_FLOAT{
	uint32_t int_in;
	float float_out;

}INT_2_FLOAT_CON;

extern union INT_2_FLOAT int2float;


float EEPROM_Read_NUM (uint16_t MemAddress);
void EEPROM_Write_NUM(uint16_t MemAddress, float Num);


#endif /* INC_EEPROM_24C256_LIB_H_ */
