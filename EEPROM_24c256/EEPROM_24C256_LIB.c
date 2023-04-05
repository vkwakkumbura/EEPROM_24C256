/*
 * EEPROM_24C256_LIB.c
 *
 *
 *      Author: Vipula Wakkumbura
 *
 *      Description : C library to write and read float values to EEPROM_24C256 using I2C
 *
 *
 */

#include "EEPROM_24C256_LIB.h"
#include "math.h"
#include "string.h"



uint8_t Write_array1[4] = { 0, 0, 0, 0 };
uint8_t Read_array1[4] = { 0, 0, 0, 0 };

uint32_t EEPROM_write_val = 0;
uint32_t EEPROM_read_val = 0;


bool EEPROM_write_flag = false;
bool EEPROM_read_flag = false;


union FLOAT_2_INT float2int;
union INT_2_FLOAT int2float;


float EEPROM_Read_NUM(uint16_t MemAddress){

	uint8_t Read_buffer[4] = { 0, 0, 0, 0 };
	float value;



	EEPROM_read_flag = true;
	HAL_I2C_Mem_Read(&hi2c1, EEPROM_ADDR, (5 << 6), 2, Read_buffer, 4, 1000);
	int2float.int_in = (Read_buffer[3] | (Read_buffer[2] << 8)
			| (Read_buffer[1] << 16) | (Read_buffer[0] << 24));


	EEPROM_read_val = int2float.int_in;
	EEPROM_read_flag = false;



	return value = int2float.float_out;

}



void EEPROM_Write_NUM(uint16_t MemAddress, float Num) {

	uint8_t Write_buffer[4] = { 0, 0, 0, 0 };

	float2int.float_in = Num;
	EEPROM_write_val = float2int.int_out;



	EEPROM_write_flag = true;
	Write_buffer[3] = (float2int.int_out & 0xFF);
	Write_buffer[2] = ((float2int.int_out >> 8));
	Write_buffer[1] = ((float2int.int_out >> 16));
	Write_buffer[0] = ((float2int.int_out >> 24));

	HAL_I2C_Mem_Write(&hi2c1, EEPROM_ADDR, (5 << 6), 2, Write_buffer, 4, 1000);

	EEPROM_write_flag = false;

}

