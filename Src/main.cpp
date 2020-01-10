/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "can.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Libraries/LowlayerHandel.hpp"
#include "Libraries/InterruptIvent/TimerInterruptCallback.hpp"
#include "stm32f4xx_hal.h"
#include "stdio.h"

#include "Libraries/DefineOrder.h"
#include <stdio.h>

#include "dma_printf.hpp"
#include "dma_scanf.hpp"
extern int cunt;
//#include "Libraries/Buzzer/buzzer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
extern bool IntFlag;
extern void FilterConfig();
extern uint8_t con_data[8];
#ifdef __cplusplus
 extern "C" {
#endif
int __io_putchar(int ch)
{
      dma_printf_putc(ch&0xFF);
        return ch;
}

int __io_getchar(void)
{
      return dma_scanf_getc_blocking();
}

#ifdef __cplusplus
}
#endif
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
      dma_printf_send_it(huart);
}

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
LowlayerHandelTypedef *plow;

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
CAN_TxHeaderTypeDef Txmsg;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//#define USEOLCD
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

	  dma_printf_init(&huart2);   //printfを使いたいUARTポートの構造体のポインタ
	  dma_scanf_init(&huart2);    //scanfを使いたいUARTポートの構造体のポインタ

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_CAN1_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_TIM6_Init();
  MX_TIM7_Init();
  MX_I2C2_Init();
  MX_TIM3_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

  LowlayerHandelTypedef hlow;
  plow=&hlow;
#ifdef USEOLCD
hlow.Lcd.oled_puts((char *)"CAN OK");
#endif
// Print a message to the LCD.



/************Loop config here**************/
    Timer1 LoopInt(&htim6);
    LoopInt.SetLoopTime(5);//Loop period set up by ms
    LoopInt.Start();
    FilterConfig();
/***Motor System initialization. you have to write "begin" before "SetVelocity" ****/
#ifdef MOTERSYSTEM
hlow.M1.SetVcc(24);//Set battery voltage
hlow.M2.SetVcc(24);
hlow.M3.SetVcc(24);
hlow.M4.SetVcc(24);

hlow.M1.begin();
hlow.M2.begin();
hlow.M2.begin();
hlow.M4.begin();
//hlow.M5.begin();
//hlow.M6.begin();
//hlow.M7.begin();
/*************************************/
#endif
#ifdef USEOLCD
hlow.Lcd.oled_setcursor(1, 0);
hlow.Lcd.oled_puts((char *)"Timer OK");
#endif
#ifdef USEI2C
    HAL_I2C_Master_Receive_IT(&hi2c2,CON_ADDRESEE,con_data,8);
#endif
/*************************************/
  /* USER CODE END 2 */
float t=0;
//hlow.EmagenceStop();
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if(IntFlag)
	  {
		//Melody_Update();
/*********write Send Request so that other boards return requested data*************/
	 hlow.loca.SendReqest();
	// hlow.Ad1.SendRequest();
	//hlow.encoder1.Sendreqest();
	 //hlow.PS3.SendRequest();
	// hlow.Msw1.SendRequest();
/*****************************************************************************/
/************write your application code******************************************************/






/******************************************************************************************************/
/*********example code*************************************************************************/
	 //hlow.M1.SetVelocity(30);
	 // printf("x:%f y:%f yaw:%f\n\r",hlow.loca.GetX(),hlow.loca.GetY(),hlow.loca.GetYaw());
	 //printf("3:%f 4:%f\n\r",hlow.encoder3.GetDistance(0.03, 2048),hlow.encoder4.GetDistance(0.03, 2048));
	 //printf("%d \n\r",hlow.Ad1.GetValue());
	 //printf("%d \n\r",hlow.Ad1.GetValue());
	 	// printf("1:%d 2:%d 3:%d 4:%d 5:%d 6:%d\n\r",hlow.Msw1.GetPush(),hlow.Msw2.GetPush(),hlow.Msw3.GetPush(),hlow.Msw4.GetPush(),hlow.Msw5.GetPush(),hlow.Msw6.GetPush());
	 //printf("data:%x\n\r",hlow.Msw1.Data[0]);
	 //printf("maru:%d batu:%d sankaku:%d sikaku:%d count:%d\n\r",hlow.PS3.MARU(),hlow.PS3.BATSU(),hlow.PS3.SANKAKU(),hlow.PS3.SHIKAKU(),cunt);
	 //printf("rightX:%d rightY:%d leftX:%d leftY:%d L2:%d R2:%d count:%d\n\r",hlow.PS3.ANALOG_RIGHT_X(),
	 	//	hlow.PS3.ANALOG_RIGHT_Y(),hlow.PS3.ANALOG_LEFT_X(),hlow.PS3.ANALOG_LEFT_Y(),hlow.PS3.L2(),hlow.PS3.R2(),cunt);
	 	 //printf("R1%d\n\r",hlow.PS3.R1());
		  IntFlag=false;
	  }

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 160;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  setbuf(stdin, NULL);
 	  setbuf(stdout, NULL);
 	  setbuf(stderr, NULL);
}

/* USER CODE BEGIN 4 */


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
	plow->Lcd.oled_puts((char*)"Init Error");
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
