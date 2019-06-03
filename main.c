 /*******************************************************************************
 *
 * Copyright (C) 2019 TUSUR, FB, Baranov Dmitriy
 *
 * File              : main.c
 * Compiler          : IAR for ARM
 * Version           : 7.50.2.10505
 * Created File      : 14.03.2019
 * Last modified     : 14.04.2019
 *
 * Support mail      : baranov19972015@gmail.com
 * Target MCU        : MCU: Milandr 1986BE9x
 *
 * Description       : Set\reset the desired bit in various ways.
 *
********************************************************************************/

#include "bit_band.h"
#include <stdlib.h>
#include <stdint.h>


struct bitField{
  int flag_a : 1; 
  int flag_b : 1;
  int flag_c : 1; 
  int flag_d : 1;
  int flag_e : 1; 
  int flag_f : 1;
  int flag_g : 1; 
  int flag_h : 1;
} _bitField;

int main(int argc, char *argv[]) {
  
  //bit-field
  _bitField.flag_a = 1;
  _bitField.flag_a = 0;
  
  static uint32_t a = 0;
  
  //bit-band realization
  BIT_BAND_SRAM(&a, 1) = 1; //set 1-st bit in "a" var
  BIT_BAND_SRAM(&a, 1) = 0; //reset 1-st bit in "a" var
  
  
  //handwork with bits
  a |= (1<<1); //set 1-st bit in "a" var
  a &=~(1<<1); //reset 1-st bit in "a" var
  
  return EXIT_SUCCESS;
}