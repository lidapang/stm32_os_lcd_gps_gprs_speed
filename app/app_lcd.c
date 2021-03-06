#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "core.h"

#include "driv_lcd.h"
#include "app_lcd.h"
#include "app_rtc.h"
#include "app_speed.h"
#include "app_key.h"
#include "app_gprs.h"

#include "app_lcd_memu.h"
#include "app_network_data.h"

#if defined (CAR_DB44_V1_0_20130315_)

static uint8_t status_lcd = 0;
static uint8_t cnt_lcd = 0;
static uint8_t status_main = 0;
static uint8_t cnt_main = 0;
static uint8_t status_l1 = 0;
static uint8_t cnt_l1 = 0;

#if 0
uint8_t tab32[]={
/*--  调入了一幅图像：F:\梁\画图\HOCO12832.bmp  --*/
/*--  宽度x高度=128x32  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x07,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x7F,0x80,0x00,0x00,0x00,0x00,0x18,0x0C,0x00,0x00,0x01,0x00,0x00,0x00,0x00,
0x01,0xFF,0x80,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x13,0x10,0x03,0xFE,0x00,
0x03,0xFF,0xC0,0x00,0x00,0x00,0x00,0x58,0x00,0x00,0x00,0x3F,0x30,0x1F,0xFF,0xC0,
0x03,0xFF,0xE0,0x00,0x00,0x00,0x00,0x8C,0x03,0xF0,0x00,0x7F,0xE0,0x7C,0x01,0xE0,
0x03,0xFF,0xF0,0x00,0x00,0x00,0x01,0x36,0x06,0xC0,0x00,0x5F,0xC0,0xFF,0xFC,0x60,
0x01,0xFF,0xF0,0x00,0x00,0x00,0x02,0x1B,0x0F,0x80,0x00,0xFF,0x01,0xFE,0x0F,0x30,
0x00,0xEF,0xF0,0x00,0x00,0x00,0x02,0x6D,0x9F,0x00,0x00,0x3E,0x03,0xFF,0xF1,0x90,
0x00,0xFF,0xF8,0x00,0x00,0x00,0x04,0x36,0xFE,0x00,0x01,0xFF,0x07,0xFF,0xFC,0x90,
0x00,0xEF,0xFF,0xFF,0x80,0x00,0x04,0xDB,0x7E,0x00,0x03,0xFF,0x87,0xFF,0xFC,0xD0,
0x00,0x0F,0xFF,0xFF,0xC0,0x00,0x04,0x6D,0xFC,0x00,0x07,0xFF,0x8F,0xFF,0xFE,0x50,
0x00,0x0F,0xFF,0xFF,0xE0,0x00,0x04,0x36,0xFC,0x10,0x07,0xFF,0x8F,0xFF,0xFE,0x90,
0x00,0x0F,0xFF,0xFF,0xE0,0x00,0x04,0x1B,0xF8,0x10,0x07,0xFF,0xCF,0xFF,0xFE,0x80,
0x00,0x0F,0xFF,0xFF,0xF0,0x00,0x04,0x0F,0xF8,0x10,0x07,0xFF,0xFF,0xFF,0xFA,0x00,
0x00,0x07,0xFF,0xFF,0xF0,0x00,0x04,0x07,0xF0,0x10,0x07,0xFF,0xFF,0xFF,0xFA,0x00,
0x00,0xFF,0xFF,0xFF,0xF8,0x00,0x02,0x03,0xF0,0x20,0x07,0xFF,0xFF,0xFF,0xBA,0x00,
0x00,0xFD,0xFF,0xFF,0xFC,0x00,0x02,0x03,0xF0,0x20,0x03,0xFF,0xFF,0xDF,0xB8,0x00,
0x00,0xC1,0xC0,0x3F,0xFC,0x00,0x01,0x01,0xE0,0x40,0x00,0xFF,0xFF,0xDF,0xB0,0x00,
0x00,0x81,0xC0,0x3F,0xCE,0x00,0x00,0x81,0xE0,0x80,0x00,0x7F,0xFF,0xDF,0xA0,0x00,
0x00,0x81,0x80,0x1D,0xCF,0x00,0x00,0x41,0xE1,0x00,0x00,0x3F,0xFF,0x9B,0x00,0x00,
0x01,0x83,0x80,0x1F,0xC7,0x80,0x00,0x21,0xE2,0x00,0x00,0x1F,0xFD,0xB6,0x00,0x00,
0x01,0xC3,0x00,0x0E,0xE6,0x80,0x00,0x19,0xEC,0x00,0x00,0x07,0xFE,0x20,0x00,0x00,
0x00,0xC3,0x00,0x07,0x67,0x40,0x00,0x07,0xF0,0x00,0x00,0x03,0x3E,0x00,0x00,0x00,
0x00,0x02,0x00,0x03,0xE7,0xA0,0x00,0x00,0x00,0x00,0x00,0x02,0x8E,0x00,0x00,0x00,
0x00,0x06,0x00,0x03,0x83,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x03,0x00,0x00,0x00,
0x00,0x06,0x00,0x07,0x03,0x00,0x77,0x46,0x74,0x24,0x80,0x06,0x04,0x00,0x00,0x00,
0x00,0x1C,0x00,0x06,0x00,0x00,0x55,0x45,0x54,0x57,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x1C,0x00,0x0E,0x00,0x00,0x45,0x45,0x74,0x57,0x80,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1C,0x00,0x00,0x55,0x45,0x44,0x74,0x80,0xF0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x38,0x00,0x00,0x77,0x76,0x47,0x54,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
#endif

#if 0
uint8_t tab5[]={
/*--  调入了一幅图像：F:\梁\画图\COCK.bmp  --*/
/*--  宽度x高度=128x64  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x80,0x00,0x0F,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0C,0x43,0x01,0x80,0x00,0x7F,0xFF,0xF0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x19,0xFF,0x07,0x00,0x07,0xFF,0xFF,0xFE,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0x3F,0xFC,0x1E,0x00,0x1F,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0xBF,0xFF,0xFC,0x00,0x7F,0xFC,0x00,0x7F,0xC0,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0xFF,0xFF,0xF0,0x00,0xFF,0xC0,0x00,0x0F,0xE0,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0xFF,0xFF,0xE0,0x03,0xFF,0xFF,0xFC,0x01,0xF0,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0xDF,0xFF,0xC0,0x07,0xFF,0xFF,0xFF,0x80,0xF0,0x00,0x00,0x00,
0x00,0x00,0x00,0x03,0xFF,0xFF,0x00,0x0F,0xFF,0xFF,0xFF,0xE0,0x38,0x00,0x00,0x00,
0x00,0x00,0x00,0x07,0xFF,0xF8,0x00,0x1F,0xFF,0xF0,0x03,0xF8,0x38,0x00,0x00,0x00,
0x00,0x00,0x00,0x07,0xFF,0xE0,0x00,0x3F,0xFF,0xFF,0xC0,0x7C,0x18,0x00,0x00,0x00,
0x00,0x00,0x00,0x04,0x7F,0xF0,0x00,0x3F,0xFF,0xFF,0xF8,0x1E,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0xFF,0xF8,0x00,0x7F,0xFF,0xFF,0xFE,0x0F,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x0F,0xFF,0xFC,0x00,0xFF,0xFF,0xFF,0xFF,0x87,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x1F,0xFF,0xFE,0x00,0xFF,0xFF,0xFF,0xFF,0x83,0x88,0x00,0x00,0x00,
0x00,0x00,0x00,0x3F,0xFF,0xFE,0x01,0xFF,0xFF,0xFF,0xFF,0xC3,0x88,0x00,0x00,0x00,
0x00,0x00,0x00,0x7F,0xFF,0xFE,0x01,0xFF,0xFF,0xFF,0xFF,0xE1,0x88,0x00,0x00,0x00,
0x00,0x00,0x00,0xFF,0xFF,0xFE,0x03,0xFF,0xFF,0xFF,0xFF,0xE1,0x88,0x00,0x00,0x00,
0x00,0x00,0x01,0xFF,0xFF,0xFE,0x03,0xFF,0xFF,0xFF,0xFF,0xF1,0x88,0x00,0x00,0x00,
0x00,0x00,0x01,0xFF,0xFF,0xFE,0x03,0xFF,0xFF,0xFF,0xFF,0xF3,0x08,0x00,0x00,0x00,
0x00,0x00,0x01,0xFF,0xFF,0xFF,0x07,0xFF,0xFF,0xFF,0xFF,0xF2,0x10,0x00,0x00,0x00,
0x00,0x00,0x01,0xFF,0xFF,0xFF,0x8F,0xFF,0xFF,0xFF,0xFF,0xF0,0x20,0x00,0x00,0x00,
0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,
0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x70,0x00,0x00,0x00,0x00,
0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0x70,0x00,0x00,0x00,0x00,
0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0x70,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0x7F,0x20,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xBF,0xFF,0x7F,0x20,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,0xDF,0xFF,0x7E,0x20,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xDF,0xFF,0x3E,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xCF,0xFF,0x3C,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xCF,0xFE,0x38,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0x8F,0xFE,0x38,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0x8F,0xFE,0x30,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x1F,0x7C,0x20,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x7F,0xFF,0xFF,0xFE,0x1E,0x78,0x00,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFE,0x1E,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xDA,0x3C,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xF2,0x30,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xF1,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xFE,0x7F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x7C,0x3F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x78,0x1F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x72,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x70,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xC0,0x03,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x40,0x04,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x02,0x0C,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x02,0x40,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0C,0x48,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x38,0x41,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x0F,0xE2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
#endif

void app_lcd_init(void)
{
	driv_lcd_init();

	app_lcd_menu_init();

	app_network_data_init();
}

static void app_lcd_main_menu(void)
{
	#define FLASH_CNT 50

	struct app_key ak;

	switch (status_main) {
	case 0:
/*		if (cnt_main == 0) {
			driv_lcd_clrram_dma();
			driv_lcd_clean_all_dots_dma();
			app_lcd_main_menu_1();
		}
		else {
			app_lcd_main_menu_1_flash();
		}
		if (cnt_main++ > FLASH_CNT) {
			status_main = 1;
			cnt_main = 0;
		}

		app_key_get_status(&ak);
		break;*/
	case 1:
/*		if (cnt_main == 0) {
			driv_lcd_clrram_dma();
			driv_lcd_clean_all_dots_dma();
			app_lcd_main_menu_2();
		}
		else {
			app_lcd_main_menu_2_flash();
		}
		if (cnt_main++ > FLASH_CNT) {
			status_main = 2;
			cnt_main = 0;
		}

		app_key_get_status(&ak);
		break;*/
	case 2:
		if (cnt_main == 0) {
			driv_lcd_clrram_dma();
			driv_lcd_clean_all_dots_dma();
			app_lcd_main_menu_3();
		}
		else {
			//app_lcd_main_menu_3_flash();
		}
		if (cnt_main++ > FLASH_CNT) {
			status_main = 0;
			cnt_main = 0;
		}

		app_key_get_status(&ak);
		break;
	default:
		break;

	}
}

/*
	返回值:
				true:	退出该界面
				false:	无动作
*/
static bool app_lcd_menu_l1(void)
{
	bool flag;
	struct app_key ak;

	flag = false;
	
	switch (status_l1) {
	case 0:
		if (cnt_l1 == 0) {
			driv_lcd_clrram_dma();
			driv_lcd_clean_all_dots_dma();
			app_lcd_menu_l1_yn_question();
			cnt_l1++;
		}

		app_key_get_status(&ak);
		if (ak.name == E_KEY_NAME_OK || ak.name == E_KEY_NAME_BACK) {
			flag = true;
			sprintf((void *)g_key_send_gprs_msg, "Z:,KEY,%d,CLICK#", ak.name);
		}
		break;
	default:
		break;
	}

	return flag;
}

void app_lcd_disp(void)
{
	static uint8_t c = 0;
	static uint8_t index = 0;

	char buf[24];
	
	switch (status_lcd) {
	case 0:
		app_lcd_main_menu();
		
		if (app_lcd_menu_is_have_yn_question()) {
			status_lcd = 1;
			cnt_lcd = 0;

			status_l1 = 0;
			cnt_l1 = 0;

			c = 0;
		}
		/*if (c++ >= 55) {
			sprintf((void *)buf, "%s%d", "测试问答式", index);
			app_lcd_menu_insert_yn_question(buf, index);
			index++;
		}*/
		break;
	case 1:
		if (app_lcd_menu_l1()) {
			status_lcd = 0;
			cnt_lcd = 0;

			status_main = 0;
			cnt_main = 0;
		}
		break;
	default:
		break;
	}
}

#if 0
void app_lcd_disp(void)
{	

	static bool f = false;
	uint8_t name[25] = "广州联物网络科技有限公司";
	uint8_t addr[64] = "ADDR:West DaSha road GZ China";
	uint8_t addr_c[64] = "ADDR: 广州大沙地西路123号";
	uint8_t gImage_s[64] = { /* 0X10,0X01,0X00,0X19,0X00,0X10, */
0X7F,0XFF,0X00,0X00,0X03,0XFF,0X00,0X00,0X03,0XFF,0X04,0X80,0X03,0XFF,0X04,0X80,
0X3F,0XFF,0X0F,0X80,0X3F,0XFF,0X0F,0X80,0X3F,0XFF,0X0F,0X80,0X3F,0XF8,0X0F,0X80,
0X3F,0XF8,0X0C,0X80,0X3F,0XFE,0X06,0X80,0X3F,0XFE,0X03,0X80,0X00,0XFF,0X03,0X00,
0X0F,0XA0,0X03,0X00,0X3F,0XE0,0X1F,0X00,0X3F,0XF0,0X1F,0X00,0X00,0X00,0X00,0X00,
};
	uint8_t logo_gps[32] = {
		0x00, 0x00, 0x70, 0x08, 0x54, 0x14, 0x7A, 0x22, 0x11, 0x44, 0x20, 0x88, 0x10, 0x50, 0x08, 0x20, 
		0x04, 0x10, 0x0A, 0x08, 0x11, 0x08, 0x22, 0x88, 0x44, 0x78, 0x28, 0x04, 0x10, 0x02, 0x00, 0x00
	};
	uint8_t logo_gprs_y[32] = {
		0x00, 0x00, 0x03, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x7F, 0xC2, 0x40, 0x42, 0x4E, 0x42, 0x4E, 0x7E, 
		0x4E, 0x60, 0x40, 0x60, 0x7F, 0xF8, 0x04, 0x00, 0x04, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	uint8_t logo_gprs_n[32] = {
		0x00, 0x00, 0x03, 0xFE, 0x02, 0x02, 0x12, 0x12, 0x7F, 0xE2, 0x44, 0x42, 0x42, 0xC2, 0x41, 0x7E, 
		0x42, 0xE0, 0x44, 0x60, 0x7F, 0xF8, 0x14, 0x10, 0x04, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	uint8_t logo_gprs_level_0[32] = {
		0x00, 0x00, 0x7F, 0xC0, 0x20, 0x80, 0x11, 0x00, 0x0A, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 
		0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	uint8_t speed_disp[16];
	static bool lcd_clear = false;
	static uint8_t a1=0, a2=16;
	uint8_t *p;
	
#if 1
	if (false == lcd_clear) {
		driv_lcd_clrram_dma();
		driv_lcd_clean_all_dots_dma();
		lcd_clear = true;
	}

	if (a1 == 0) {
		a1 = 16;
		a2 = 0;
	}
	else {
		a1 = 0;
		a2 = 16;
	}
	
	sprintf(addr, "%.4d/%.2d/%.2d %.2d:%.2d:%.2d", calendar.year, calendar.month, calendar.mday, calendar.hour, calendar.min, calendar.sec);
	driv_lcd_disp_dma(addr, strlen(addr), 1, 0);
	driv_lcd_disp_dots_dma(logo_gps, 16, 16, 0, a1);
	driv_lcd_disp_dots_dma(logo_gprs_y, 16, 16, 0, a2);
	driv_lcd_disp_dots_dma(logo_gprs_n, 16, 16, 0, 32);
	driv_lcd_disp_dots_dma(logo_gprs_level_0, 16, 16, 0, 48);
	p =app_key_process();
	if (NULL != p) {
		driv_lcd_disp_dma(p, strlen((void *)p), 0, 4);
	}
	sprintf((void *)speed_disp, " %d.%.1d", g_speed_info.total_km, g_speed_info.total_r*10/g_speed_info.VSC);
	driv_lcd_disp_dma(speed_disp, strlen((void *)speed_disp), 0, 5);
	sprintf((void *)speed_disp, " %dkm/h", g_speed_info.speed_curr);
	driv_lcd_disp_dma(speed_disp, strlen((void *)speed_disp), 0, 8);
	driv_lcd_tx_reload_dma();
#endif
	//chn_disp_ ();
#if 0
	driv_lcd_clrram();
	driv_lcd_clean_all_dots();
	//os_task_delayms(1000);
	//driv_lcd_disp_addr(name, 24, 0, 3);
	sprintf(addr, "%.4d/%.2d/%.2d %.2d:%.2d:%.2d", calendar.year, calendar.month, calendar.mday, calendar.hour, calendar.min, calendar.sec);
	driv_lcd_disp_addr(addr, strlen(addr), 1, 0);
	//os_task_delayms(5000);
	//driv_lcd_disp_dots_addr(gImage_s, 32, 16, 0, 16);
	driv_lcd_disp_dots_addr(logo_gps, 16, 16, 0, 0);
	driv_lcd_disp_dots_addr(logo_gprs_y, 16, 16, 0, 16);
	driv_lcd_disp_dots_addr(logo_gprs_n, 16, 16, 0, 32);
	driv_lcd_disp_dots_addr(logo_gprs_level_0, 16, 16, 0, 48);
	//driv_lcd_disp_dots_addr(gImage_s, 32, 16, 16, 32);
	sprintf((void *)speed_disp, " %dkm/h", speed_curr);
	driv_lcd_disp_addr(speed_disp, strlen((void *)speed_disp), 0, 7);
	//driv_lcd_disp_addr(speed_disp, strlen((void *)speed_disp), 1, 5);
	//os_task_delayms(5000);
	
#endif	

	/*driv_lcd_clrram();
	os_task_delayms(1000);
	driv_lcd_disp_addr(name, 24, 0, 0);
	os_task_delayms(5000);
	driv_lcd_clrram();
	os_task_delayms(1000);
	driv_lcd_disp_addr(addr_c, 22, 1, 0);*/
	//driv_lcd_disp_img(tab32);
	//driv_lcd_disp_img_a(tab5);
}
#endif

#endif
