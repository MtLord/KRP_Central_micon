/*
 * buzzer.cpp
 *
 *  Created on: 2019/11/18
 *      Author: nabeya11
 */


#include <Libraries/Buzzer/Buzzer.hpp>

/*
 * メロディーを鳴らす（割り込み式）
 */
void Buzzer::Melody_Start(uint8_t value){
	melody_select=value;
	melody_target = 0;
	BuzzerOff();
	HAL_TIM_Base_Stop_IT(&TIM_MELODY_HANDLER);

	__HAL_TIM_SET_COUNTER(&TIM_MELODY_HANDLER, 0);
	__HAL_TIM_SET_AUTORELOAD(&TIM_MELODY_HANDLER, melody[melody_select][melody_target].tim*1000);
	BuzzerOn(melody[melody_select][melody_target].pitch);
	melody_target++;
	HAL_TIM_Base_Start_IT(&TIM_MELODY_HANDLER);
}

/*
 * メロディー更新
 * 割り込み式に必須
 * タイマ割り込み内で実行
 */
uint8_t Buzzer::Melody_Update(void){
	if(melody_target < melodyend[melody_select]){
		BuzzerUpdate(melody[melody_select][melody_target].pitch);
		__HAL_TIM_SET_AUTORELOAD(&TIM_MELODY_HANDLER, melody[melody_select][melody_target].tim*1000);
		melody_target++;
		return 0;
	}
	else{
		BuzzerOff();
		HAL_TIM_Base_Stop_IT(&TIM_MELODY_HANDLER);
		return 1;
	}
}

/*
 * メロディーを鳴らす
 * @param	value : メロディーの種類
 * @return
 */
void Buzzer::Melody(uint8_t value){
	switch(value){
		case 0:
			//愛の挨拶
			BuzzerBeep(BUZZER_FM6,ONE_4);
			BuzzerBeep(BUZZER_A5,ONE_8);
			BuzzerBeep(BUZZER_FM6,ONE_8);
			BuzzerBeep(BUZZER_E6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_CM6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_G6,ONE_4);
			BuzzerBeep(BUZZER_G6,ONE_4);
			BuzzerBeep(BUZZER_G6,ONE_4);
			BuzzerBeep(BUZZER_A5,ONE_4);

			BuzzerBeep(BUZZER_FM6,ONE_4);
			BuzzerBeep(BUZZER_AM5,ONE_8);
			BuzzerBeep(BUZZER_FM6,ONE_8);
			BuzzerBeep(BUZZER_E6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_CM6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_E6,ONE_4);
			BuzzerBeep(BUZZER_E6,ONE_4);
			BuzzerBeep(BUZZER_E6,ONE_4);
			BuzzerBeep(BUZZER_F6,ONE_4);

			BuzzerBeep(BUZZER_FM6,ONE_4);
			BuzzerBeep(BUZZER_A5,ONE_8);
			BuzzerBeep(BUZZER_FM6,ONE_8);
			BuzzerBeep(BUZZER_E6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_CM6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_B6,ONE_4);
			BuzzerBeep(BUZZER_B6,ONE_4);
			BuzzerBeep(BUZZER_B6,ONE_4);

			BuzzerBeep(BUZZER_A6,ONE_8);
			BuzzerBeep(BUZZER_G6,ONE_8);
			BuzzerBeep(BUZZER_FM6,ONE_4);
			BuzzerBeep(BUZZER_E6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_B5,ONE_4);
			BuzzerBeep(BUZZER_CM6,ONE_4);
			BuzzerBeep(BUZZER_D6,ONE_2);
			melend=1;
			break;
		case 1:
			//マクド
			for(int i=0;i<6;i++){
				BuzzerBeep(BUZZER_G5,ONE_16);
				HAL_Delay(ONE_16+ONE_8);
				BuzzerBeep(BUZZER_G5,ONE_8);
				BuzzerBeep(BUZZER_F5,ONE_8);
			}
			melend=1;
			break;
		case 2:
			//運命
			BuzzerBeep(BUZZER_G6,ONE_8);
			BuzzerBeep(BUZZER_G6,ONE_8);
			BuzzerBeep(BUZZER_G6,ONE_8);
			BuzzerBeep(BUZZER_E6,ONE_2+ONE_4);
			BuzzerBeep(BUZZER_F6,ONE_8);
			BuzzerBeep(BUZZER_F6,ONE_8);
			BuzzerBeep(BUZZER_F6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_2+ONE_4);
			melend=1;
			break;
		case 3:
			//フーガ
			BuzzerBeep(BUZZER_A6,ONE_8);
			BuzzerBeep(BUZZER_G6,ONE_8);
			BuzzerBeep(BUZZER_A6,ONE_2+ONE_4);
			BuzzerBeep(BUZZER_G6,ONE_8);
			BuzzerBeep(BUZZER_F6,ONE_8);
			BuzzerBeep(BUZZER_E6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_CM6,ONE_4);
			BuzzerBeep(BUZZER_D6,ONE_2);
			melend=1;
			break;
		case 4:
			//チャルメラ
			BuzzerBeep(BUZZER_C6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_E6,ONE_4+ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_C6,ONE_8);
			HAL_Delay(ONE_8);
			BuzzerBeep(BUZZER_C6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_E6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_C6,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8+ONE_2);
			melend=1;
			break;
		case 5:
			//横断歩道？
			for(int i=0;i<4;i++){
				BuzzerBeep(BUZZER_G6,ONE_16);
				HAL_Delay(ONE_16);
				BuzzerBeep(BUZZER_E6,ONE_8);
				HAL_Delay(ONE_8);
				BuzzerBeep(BUZZER_G6,ONE_32);
				HAL_Delay(ONE_32);
				BuzzerBeep(BUZZER_G6,ONE_32);
				HAL_Delay(ONE_32);
				BuzzerBeep(BUZZER_E6,ONE_8);
				HAL_Delay(ONE_8);
				melend=1;
			}
			break;
		case 255:
		default:
			break;
	}
}

/*
 * アルペジオ
 * @param	value : アルペジオの種類
 * @return
 */
void Buzzer::Arpeggio(uint8_t value){
	switch(value){
		case 0:
			BuzzerBeep(BUZZER_C5,ONE_8);
			BuzzerBeep(BUZZER_E5,ONE_8);
			BuzzerBeep(BUZZER_G5,ONE_8);
			break;
		case 1:
			BuzzerBeep(BUZZER_D5,ONE_8);
			BuzzerBeep(BUZZER_FM5,ONE_8);
			BuzzerBeep(BUZZER_A5,ONE_8);
			break;
		case 2:
			BuzzerBeep(BUZZER_E5,ONE_8);
			BuzzerBeep(BUZZER_GM5,ONE_8);
			BuzzerBeep(BUZZER_B5,ONE_8);
			break;
		case 3:
			BuzzerBeep(BUZZER_F5,ONE_8);
			BuzzerBeep(BUZZER_A5,ONE_8);
			BuzzerBeep(BUZZER_C6,ONE_8);
			break;
		case 4:
			BuzzerBeep(BUZZER_G5,ONE_8);
			BuzzerBeep(BUZZER_B5,ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_8);
			break;
		case 5:
			BuzzerBeep(BUZZER_D6,ONE_16);
			BuzzerBeep(BUZZER_D6,ONE_16);
			HAL_Delay(ONE_8);
			BuzzerBeep(BUZZER_D6,ONE_16);
			BuzzerBeep(BUZZER_D7,ONE_4);
			break;
		case 6:
			BuzzerBeep(BUZZER_D6,ONE_8);
			BuzzerBeep(BUZZER_FM6,ONE_8);
			BuzzerBeep(BUZZER_A6,ONE_8);
			BuzzerBeep(BUZZER_B6,ONE_8);
			HAL_Delay(ONE_8);
			BuzzerBeep(BUZZER_B6,ONE_8);
			BuzzerBeep(BUZZER_CM7,ONE_8);
			BuzzerBeep(BUZZER_B6,ONE_8);
			BuzzerBeep(BUZZER_A6,ONE_8);
			HAL_Delay(ONE_8);
			BuzzerBeep(BUZZER_FM6,ONE_4);
			break;
		case 7:
			BuzzerBeep(BUZZER_E6,ONE_8);
			BuzzerBeep(BUZZER_C6,ONE_8);
			HAL_Delay(ONE_8);
			BuzzerBeep(BUZZER_G6,ONE_8);
			BuzzerBeep(BUZZER_C6,ONE_8);
			break;
		default:
			break;
	}
}

/*
 * ブザーを指定された周波数で指定された時間鳴らす
 * @param	freq : 周波数(Hz)
 * 			time : 時間(ms)
 * 			(ex:BuzzerBeep(BUZZER_A7, 1000))
 * @return
 */
void Buzzer::BuzzerBeep(int16_t freq, int32_t time) {
	BuzzerOn(freq);
	HAL_Delay(time);
	BuzzerOff();
}

/*
 * ブザーを指定された周波数で鳴らす
 * @param
 * @return
 */
void Buzzer::BuzzerOn(int16_t freq) {
//	BUZZER_TIM_HANDLER.Init.Period = (float)BUZZER_TIM_FREQ / (float)freq;
//	HAL_TIM_Base_Init(&BUZZER_TIM_HANDLER);
//	HAL_TIM_PWM_Init(&BUZZER_TIM_HANDLER);
//	__HAL_TIM_SetCompare(&BUZZER_TIM_HANDLER, BUZZER_TIM_CHANNEL, (uint16_t)((float)BUZZER_TIM_FREQ / ((float)freq * 2.0f)));

	//PWMスタート
	BuzzerUpdate(freq);
	HAL_TIM_PWM_Start(&BUZZER_TIM_HANDLER, BUZZER_TIM_CHANNEL);
}

/*
 * ブザー止める
 * @param
 * @return
 */
void Buzzer::BuzzerOff(void)
{
	HAL_TIM_PWM_Stop(&BUZZER_TIM_HANDLER, BUZZER_TIM_CHANNEL);
}

/*
 * ブザーを指定された周波数で更新
 * @param
 * @return
 */
void Buzzer::BuzzerUpdate(int16_t freq) {
	__HAL_TIM_SetCounter(&BUZZER_TIM_HANDLER, 0);
	__HAL_TIM_SET_AUTORELOAD(&BUZZER_TIM_HANDLER, (uint16_t)((float)BUZZER_TIM_FREQ / (float)freq));
	__HAL_TIM_SetCompare(&BUZZER_TIM_HANDLER, BUZZER_TIM_CHANNEL, (uint16_t)((float)BUZZER_TIM_FREQ / ((float)freq * 2.0f)));
}
