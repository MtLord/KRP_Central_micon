/*
 * scanf.c
 *
 *  Created on: 2019/07/12
 *      Author: —T‘¿
 */
#include "usart.h"
#include "main.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#ifdef  __GNUC__
#define GETCHAR_PROTOTYPE int __io_getchar(FILE *f)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#endif /* __GNUC__ */

#ifdef __cplusplus
 extern "C" {
#endif

GETCHAR_PROTOTYPE
{
  uint8_t ch = 0;
  HAL_UART_Receive(&huart2,(uint8_t *)&ch, 1, 0xFFFF);

  if (ch == '\r')
  {
      __io_putchar('\r');
      ch = '\n';
  }

  return __io_putchar(ch);
//  return ch;
}
#ifdef __cplusplus
}
#endif

