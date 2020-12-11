/*
 * buzzer.hpp
 *
 *  Created on: 2019/11/18
 *      Author: nabeya11
 */

#ifndef BUZZER_H_
#define BUZZER_H_



#include "main.h"
#include "tim.h"
#include "stm32f4xx_hal.h"

/*-----------------------------------------------
 * Buzzer
 ----------------------------------------------*/
//繝悶じ繝ｼ繧ｿ繧､繝槭�ｼ繝上Φ繝峨Λ
#define BUZZER_TIM_HANDLER		htim3

//繝悶じ繝ｼ繧ｿ繧､繝槭�ｼ繝√Ε繝ｳ繝阪Ν
#define BUZZER_TIM_CHANNEL		TIM_CHANNEL_1

//驛｢譎�縺倡ｸｺ蛟｡�ｽｹ譎｢�ｽｽ�ｽｼ驛｢�ｽｧ�ｿｽ�ｽｽ�ｽｿ驛｢�ｽｧ�ｿｽ�ｽｽ�ｽ､驛｢譎�ｽｧ�ｽｭ�ｿｽ�ｽｿ�ｽｽ�ｿｽ�ｽｽ�ｽｼ髯ｷ�ｽｻ�ｿｽ�ｽｽ�ｽｨ髮主桁�ｽｽ�ｽ｢髫ｰ�ｽｨ�ｿｽ�ｽｽ�ｽｰ�ｿｽ�ｽｿ�ｽｽ�ｿｽ�ｽｽ�ｽｼ闔��ｽ･�ｿｽ�ｽｿ�ｽｽ髯ｷ�ｽｻ�ｿｽ�ｽｽ�ｽｨ髯滓坩�ｽｯ莨夲ｽｽ�ｽｼ�ｿｽ�ｽｿ�ｽｽ
#define BUZZER_TIM_FREQ			1000000.0f

//驛｢譎�縺倡ｸｺ蛟｡�ｽｹ譎｢�ｽｽ�ｽｼ髫ｴ蠑ｱ�ｽ玖将�ｽ｣驛｢�ｽｧ�ｿｽ�ｽｽ�ｽｿ驛｢�ｽｧ�ｿｽ�ｽｽ�ｽ､驛｢譎｢�ｽｿ�ｽｽ
#define TIM_MELODY_HANDLER		htim7

//髻ｳ髫�
enum {
	BUZZER_NO  =    0,
	BUZZER_A4  =  440,
	BUZZER_B4  =  494,
	BUZZER_C5  =  524,
	BUZZER_CM5 =  554,
	BUZZER_D5  =  588,
	BUZZER_Em5 =  622,
	BUZZER_E5  =  660,
	BUZZER_F5  =  699,
	BUZZER_FM5 =  740,
	BUZZER_G5  =  784,
	BUZZER_GM5 =  831,
	BUZZER_Am5 =  831,
	BUZZER_A5  =  880,
	BUZZER_AM5 =  932,
	BUZZER_Bm5 =  932,
	BUZZER_B5  =  988,
	BUZZER_C6  = 1047,
	BUZZER_CM6 = 1109,
	BUZZER_Dm6 = 1109,
	BUZZER_D6  = 1175,
	BUZZER_Em6 = 1245,
	BUZZER_E6  = 1319,
	BUZZER_F6  = 1397,
	BUZZER_FM6 = 1480,
	BUZZER_G6  = 1568,
	BUZZER_GM6 = 1661,
	BUZZER_Am6 = 1661,
	BUZZER_A6  = 1760,
	BUZZER_AM6 = 1865,
	BUZZER_Bm6 = 1865,
	BUZZER_B6  = 1976,
	BUZZER_C7  = 2093,
	BUZZER_CM7 = 2217,
	BUZZER_Dm7 = 2217,
	BUZZER_D7  = 2349,
	BUZZER_Em7 = 2489,
	BUZZER_E7  = 2637,
	BUZZER_F7  = 2794,
	BUZZER_FM7 = 2960,
	BUZZER_G7  = 3136,
	BUZZER_GM7 = 3322,
	BUZZER_Am7 = 3322,
	BUZZER_A7  = 3520,
	BUZZER_Bm7 = 3729,
	BUZZER_B7  = 3951,
	BUZZER_C8  = 4186,
};

enum {
	ONE_2 = 1000,
	ONE_4 = ONE_2/2,
	ONE_8 = ONE_4/2,
	ONE_16 = ONE_8/2,
	ONE_32 = ONE_16/2
};
class Buzzer
{
	void BuzzerOn(int16_t);
	void BuzzerOff(void);
	uint8_t melody_select;
	uint8_t melody_target;
	typedef struct{
		int16_t pitch;
		int32_t tim;
	}struct_melody;

	uint8_t melodyend[25] = {8, 23, 13, 23, 20, 17, 17, 13, 9, 18, 12, 13, 10, 10, 10, 11};
	int melend=0;
	struct_melody melody[25][25] = {
		{
			//0.ハンガリー舞曲
			{BUZZER_D6, ONE_4+ONE_8},
			{BUZZER_G6, ONE_8},
			{BUZZER_Bm6,ONE_4+ONE_8},
			{BUZZER_G6, ONE_8},
			{BUZZER_FM6,ONE_4+ONE_8},
			{BUZZER_G6, ONE_16},
			{BUZZER_A6, ONE_16},
			{BUZZER_G6, ONE_2},
		},
		{
			//1.風呂焚き
			{BUZZER_G6, ONE_8},
			{BUZZER_F6, ONE_8},
			{BUZZER_E6, ONE_4},
			{BUZZER_G6, ONE_8},
			{BUZZER_C7, ONE_8},
			{BUZZER_B6, ONE_4},
			{BUZZER_G6, ONE_8},
			{BUZZER_D7, ONE_8},
			{BUZZER_C7, ONE_4},
			{BUZZER_E7, ONE_4},
			{BUZZER_NO, ONE_4},
			{BUZZER_C7, ONE_8},
			{BUZZER_B6, ONE_8},
			{BUZZER_A6, ONE_4},
			{BUZZER_F7, ONE_8},
			{BUZZER_D7, ONE_8},
			{BUZZER_C7, ONE_4},
			{BUZZER_B6, ONE_4},
			{BUZZER_C7, ONE_8},
			{BUZZER_G6, ONE_8},
			{BUZZER_G6, ONE_8},
			{BUZZER_F6, ONE_8},
			{BUZZER_E6, ONE_4},
		},
		{
			//2.ファミマ
			{BUZZER_FM6,ONE_8},
			{BUZZER_D6, ONE_8},
			{BUZZER_A5, ONE_8},
			{BUZZER_D6, ONE_8},
			{BUZZER_E6, ONE_8},
			{BUZZER_A6, ONE_8},
			{BUZZER_NO, ONE_8},
			{BUZZER_A5, ONE_8},
			{BUZZER_E6, ONE_8},
			{BUZZER_FM6,ONE_8},
			{BUZZER_E6, ONE_8},
			{BUZZER_A5, ONE_8},
			{BUZZER_D6, ONE_8},
		},
		{
			//3.四季　春
			{BUZZER_E6, ONE_8},
			{BUZZER_GM6,ONE_8},
			{BUZZER_GM6,ONE_8},
			{BUZZER_GM6,ONE_8},
			{BUZZER_FM6,ONE_16},
			{BUZZER_E6, ONE_16},
			{BUZZER_B6, ONE_4+ONE_8},

			{BUZZER_B6, ONE_16},
			{BUZZER_A6, ONE_16},
			{BUZZER_GM6,ONE_8},
			{BUZZER_GM6,ONE_8},
			{BUZZER_GM6,ONE_8},
			{BUZZER_FM6,ONE_16},
			{BUZZER_E6, ONE_16},
			{BUZZER_B6, ONE_4+ONE_8},

			{BUZZER_B6, ONE_16},
			{BUZZER_A6, ONE_16},
			{BUZZER_GM6,ONE_8},
			{BUZZER_A6, ONE_16},
			{BUZZER_B6, ONE_16},
			{BUZZER_A6, ONE_8},
			{BUZZER_GM6,ONE_8},
			{BUZZER_FM6,ONE_2},
		},
		{
			//4.「不協和音」
			{BUZZER_D6, ONE_8},
			{BUZZER_E6, ONE_8},
			{BUZZER_F6, ONE_8},
			{BUZZER_E6, ONE_8},
			{BUZZER_D6, ONE_8},
			{BUZZER_E6, ONE_16},
			{BUZZER_F6, ONE_16},
			{BUZZER_NO, ONE_16},
			{BUZZER_F6, ONE_16},
			{BUZZER_E6, ONE_8},
			{BUZZER_D6, ONE_8},
			{BUZZER_E6, ONE_8},
			{BUZZER_F6, ONE_8},
			{BUZZER_D6, ONE_8},
			{BUZZER_G6, ONE_8},
			{BUZZER_G6, ONE_16},
			{BUZZER_G6, ONE_8},
			{BUZZER_F6, ONE_16},
			{BUZZER_E6, ONE_8},
			{BUZZER_D6, ONE_2},
		},
		{
			//5.サイレントマジョリティー
			{BUZZER_Em6, ONE_8},
			{BUZZER_F6, ONE_8},
			{BUZZER_G6, ONE_8},
			{BUZZER_Am6, ONE_8},
			{BUZZER_Am6, ONE_16},
			{BUZZER_Am6, ONE_8},
			{BUZZER_Am6, ONE_16},
			{BUZZER_Em6, ONE_8},
			{BUZZER_NO, ONE_8},
			{BUZZER_Em6, ONE_8},
			{BUZZER_Dm7, ONE_8},
			{BUZZER_C7, ONE_8},
			{BUZZER_Bm6, ONE_8},
			{BUZZER_Bm6, ONE_16},
			{BUZZER_Bm6, ONE_8},
			{BUZZER_Bm6, ONE_16},
			{BUZZER_Am6, ONE_8},
		},
		{
			//6.Chocolate
			{BUZZER_Bm6, ONE_8},
			{BUZZER_G6, ONE_8},
			{BUZZER_Bm6, ONE_8},
			{BUZZER_G6, ONE_8},
			{BUZZER_Bm6, ONE_8},
			{BUZZER_C7, ONE_8},
			{BUZZER_Em6, ONE_8},
			{BUZZER_NO, ONE_8},
			{BUZZER_Em6, ONE_8},
			{BUZZER_C6, ONE_8},
			{BUZZER_Em6, ONE_8},
			{BUZZER_C6, ONE_8},
			{BUZZER_Em6, ONE_8},
			{BUZZER_NO, ONE_8},
			{BUZZER_C7, ONE_8},
			{BUZZER_Bm6, ONE_8},
			{BUZZER_Em6, ONE_8},
		},
		{
			//7.Hankyu
			{BUZZER_Dm6, ONE_16},
			{BUZZER_Am5, ONE_16},
			{BUZZER_C6, ONE_16},
			{BUZZER_Dm6, ONE_16},
			{BUZZER_F6, ONE_16},
			{BUZZER_Em6, ONE_16},
			{BUZZER_F6, ONE_16},
			{BUZZER_G6, ONE_16},
			{BUZZER_Am6, ONE_16},
			{BUZZER_G6, ONE_16},
			{BUZZER_Am6, ONE_16},
			{BUZZER_F6, ONE_16},
			{BUZZER_Em6, ONE_8},
		},
		{
			//8.Subway
			{BUZZER_C5, ONE_8},
			{BUZZER_E5, ONE_8},
			{BUZZER_G5, ONE_8},
			{BUZZER_C6, ONE_8},
			{BUZZER_D6, ONE_8},
			{BUZZER_C6, ONE_8},
			{BUZZER_B5, ONE_8},
			{BUZZER_D6, ONE_8},
			{BUZZER_C6, ONE_8},
		},
		{
			//9.さくらんぼ
			{BUZZER_E6, ONE_8},
			{BUZZER_G6, ONE_8},
			{BUZZER_FM6, ONE_16},
			{BUZZER_G6, ONE_16},
			{BUZZER_A6, ONE_16},
			{BUZZER_D6, ONE_16},
			{BUZZER_B6, ONE_8},
			{BUZZER_C7, ONE_8},
			{BUZZER_B6, ONE_8},
			{BUZZER_A6, ONE_8},
			{BUZZER_E6, ONE_8},
			{BUZZER_FM6, ONE_16},
			{BUZZER_G6, ONE_16},
			{BUZZER_FM6, ONE_16},
			{BUZZER_G6, ONE_16},
			{BUZZER_A6, ONE_16},
			{BUZZER_FM6, ONE_16},
			{BUZZER_G6, ONE_8},
		},
		{
			//10.トトロ
			{BUZZER_F6, ONE_8},
			{BUZZER_G6, ONE_8},
			{BUZZER_A6, ONE_8},
			{BUZZER_Bm6, ONE_8},
			{BUZZER_C7, ONE_4},
			{BUZZER_A6, ONE_8},
			{BUZZER_F6, ONE_8},
			{BUZZER_NO, ONE_8},
			{BUZZER_C7, ONE_8},
			{BUZZER_NO, ONE_8},
			{BUZZER_Bm6, ONE_4},
			{BUZZER_G6, ONE_8},
		},
		{
			//11.KyotoSta.
			{BUZZER_FM6, ONE_4/3},
			{BUZZER_CM6, ONE_4/3},
			{BUZZER_AM5, ONE_4/3},
			{BUZZER_FM6, ONE_4},
			{BUZZER_GM6, ONE_4/3},
			{BUZZER_Em6, ONE_4/3},
			{BUZZER_B5,  ONE_4/3},
			{BUZZER_GM6, ONE_4},
			{BUZZER_AM6, ONE_4/3},
			{BUZZER_E6,  ONE_4/3},
			{BUZZER_CM6, ONE_4/3},
			{BUZZER_AM6, ONE_4},
			{BUZZER_B6,  ONE_2},
		},
		{
			//12.OsakaMetro
			{BUZZER_D6, ONE_8},
			{BUZZER_A5, ONE_8},
			{BUZZER_E6, ONE_8},
			{BUZZER_A5, ONE_8},
			{BUZZER_FM6,ONE_4},
			{BUZZER_D6, ONE_8},
			{BUZZER_A5, ONE_8},
			{BUZZER_E6, ONE_8},
			{BUZZER_A5, ONE_8},
			{BUZZER_D6, ONE_4},
		},
		{
			//13.ProjectX
			{BUZZER_D6, ONE_8+ONE_16},
			{BUZZER_E6, ONE_8+ONE_16},
			{BUZZER_F6, ONE_8},
			{BUZZER_E6, ONE_4},
			{BUZZER_NO, ONE_8},
			{BUZZER_A5, ONE_8},
			{BUZZER_E6, ONE_8+ONE_16},
			{BUZZER_F6, ONE_8+ONE_16},
			{BUZZER_E6, ONE_8},
			{BUZZER_D6, ONE_4},
		},
		{
			//14.もののけ
			{BUZZER_C6, ONE_8},
			{BUZZER_F6, ONE_8},
			{BUZZER_F6, ONE_8},
			{BUZZER_Em6, ONE_8},
			{BUZZER_F6, ONE_4},
			{BUZZER_NO, ONE_8},
			{BUZZER_F6, ONE_8},
			{BUZZER_Am6, ONE_8},
			{BUZZER_Em6, ONE_8},
			{BUZZER_Em6, ONE_4},
		},
		{
			//15.ポニョ
			{BUZZER_C7, ONE_4},
			{BUZZER_A6, ONE_8},
			{BUZZER_F6, ONE_4},
			{BUZZER_C6, ONE_8},
			{BUZZER_C6, ONE_8},
			{BUZZER_C6, ONE_8},
			{BUZZER_D6, ONE_8},
			{BUZZER_F6, ONE_8},
			{BUZZER_Bm6, ONE_8},
			{BUZZER_D7, ONE_8},
			{BUZZER_C7, ONE_8},
		}
	};

public:
	void BuzzerBeep(int16_t, int32_t);
	void BuzzerUpdate(int16_t freq);
	void Melody_Start(uint8_t value);
	uint8_t Melody_Update(void);
	void Melody(uint8_t value);
	void Arpeggio(uint8_t value);

};



#endif /* BUZZER_H_ */
