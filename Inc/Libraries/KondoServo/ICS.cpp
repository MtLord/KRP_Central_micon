/*
 * ICS.cpp
 *
 *  Created on: 2019/08/07
 *      Author: �T��
 */

#include "Libraries/KondoServo/ICS.hpp"
#define ENPIN(STATE) (STATE==1)? HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET): HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET)

int ICS::Synchronize(uint8_t *txBuff, size_t txLength, uint8_t *rxBuff, size_t rxLength)
{

	 int size=0; //��M����byte��
	 	 ENPIN(1);
	  HAL_UART_Transmit(&huart1,(uint8_t*)txBuff, txLength,0xf);
	  while(HAL_UART_GetState(&huart1)==HAL_UART_STATE_BUSY_TX){}
	  	  ENPIN(0);
	  size= HAL_UART_Receive(&huart1,(uint8_t*)rxBuff, rxLength,0xF);
	  while(HAL_UART_GetState(&huart1)==HAL_UART_STATE_BUSY_RX){}
	  if (size != HAL_OK) //�w�肵����M�����ǂ����m�F
	  {
	    return 0;
	  }
	  return 1;
}

int ICS::SetPosition(uint8_t id, unsigned short pos)
{
	 uint8_t tx_data[3];
		  uint8_t rx_data[3];
		  int flag;
		  int rAngle;   //��M�����p�x�f�[�^
		  /// ���M�R�}���h���쐬
		  tx_data[0] = ICS_POS_CMD + id;
		  tx_data[1] = (uint8_t)((pos & 0x3F80) >> 7);
		  tx_data[2] = (uint8_t)(pos & 0x007F);

		  //����M���s��
		  flag = Synchronize(tx_data,3,rx_data,3);

		  if(flag == 0) //���s�����ꍇ��-1��Ԃ�
		  {
		    return -1;
		  }

		  rAngle = ((rx_data[1] << 7) & 0x3F80) + (rx_data[2] & 0x007F);

		  return rAngle;
}

int ICS::SetSpeed(uint8_t id,uint8_t spData)
{
	uint8_t tx_data[3];
	  uint8_t rx_data[3];
	  int flag;
	  /// ���M�R�}���h���쐬
	  tx_data[0] = ICS_PARA_WRITE_COMMND + id;
	  tx_data[1] = SUB_SP_COMMND;
	  tx_data[2] = spData;

	  //����M���s��
	  flag = Synchronize(tx_data,3,rx_data,3);

	  if(flag == 0) //���s�����ꍇ��-1��Ԃ�
	    {
	      return -1;
	    }

	  return flag;
}

int ICS::SetStretch(uint8_t id,uint8_t stData)
{
	uint8_t tx_data[3];
	  uint8_t rx_data[3];
	  int flag;
	  /// ���M�R�}���h���쐬
	  tx_data[0] = ICS_PARA_WRITE_COMMND + id;
	  tx_data[1] = SUB_ST_COMMND;
	  tx_data[2] = stData;

	  //����M���s��
	  flag = Synchronize(tx_data,3,rx_data,3);

	  if(flag == 0) //���s�����ꍇ��-1��Ԃ�
	   {
	     return -1;
	   }

	  return flag;
}
