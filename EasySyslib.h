/*
 * EasySys.h
 *
 *  Created on: Feb 18, 2024
 *      Author: wang_
 */

#ifndef SRC_EASYSYS_H_
#define SRC_EASYSYS_H_

//#include <Device_V1.h>
#include <stdint.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//mylib
//#include <Device_V1.h>		//HSPY PS, VC DMM, code lib
//#include <EasyPower_V1.h>	//INA226 DCMeter code lib
#include <OLED.h>			//0.9inch/SSD1306/128*32	1.3inch/SH1106/128*64	1.5inch/SH1107/128*128		lib
#include <USBPD.h>			//HUSB238 PD requst code

#include "stm32g0xx_hal.h"
#include "stm32g0xx_hal_crc.h"


#define	REC_LENGTH			64
#define	MIN_REC_LENGTH 		8
#define MAX_REC_LENGTH   	128

#define OLED_I2C_ch		1
#define OLED_type		1306	//	1106	1.3inch		SH1106		128*64

#define OLED1_I2C_ch		1
#define OLED1_type		1306	//	0.9inch		SSD1306		128*32
#define OLED2_I2C_ch		2
#define OLED2_type		1306	//	0.9inch		SSD1306		128*32

#define temp1075_ch		3


#define IO_BEEP_Port	GPIOC

//#define SPI_Flash_NSS_Pin			SPI1_NSS_Pin					//SPI2_NSS_2_Pin
#define SPI_Flash_NSS_Group			GPIOE			//GPIOD

extern SPI_HandleTypeDef hspi2;
extern SPI_HandleTypeDef *Flash_SPI;//TFT_SPI
extern SPI_HandleTypeDef *TFT_SPI;//TFT_SPI

void Order_MinF(uint8_t length, uint8_t * A);


void uprint_byte(UART_HandleTypeDef *huart, uint8_t Data);
void uprint_STR(UART_HandleTypeDef *huart, uint8_t *Data, int length);
void uprint_CRC(int ch, uint8_t *Data, int length);



void button_check();
void button_L_check();

void Sys_LED_update();

void Sys_longbeep();
void Sys_beep();
void Sys_shortbeep();
//void Sys_tune1();
//void Sys_tune2();
void myerror();
void errorANDreset();


//void Ser2CAN(uint8_t *Data);



void md5_process_part1(uint32_t *w, unsigned char *message,	uint32_t *pos, uint32_t mes_len, const unsigned char *mes_bkp);


void md5_process_part2(uint32_t abcd[4], uint32_t *w, const uint32_t k[64], const uint32_t s[64]);

int32_t cal_md5(unsigned char *result, unsigned char *data, int length);



struct TA531_GP_IN_TypeDef{

	uint8_t GP_IN_1_1;
	uint8_t GP_IN_1_2;
	uint8_t GP_IN_1_3;
	uint8_t GP_IN_1_4;
	uint8_t GP_IN_1_5;
	uint8_t GP_IN_1_6;
	uint8_t GP_IN_1_7;
	uint8_t GP_IN_1_8;

	uint8_t GP_IN_2_1;
	uint8_t GP_IN_2_2;
	uint8_t GP_IN_2_3;
	uint8_t GP_IN_2_4;
	uint8_t GP_IN_2_5;
	uint8_t GP_IN_2_6;
	uint8_t GP_IN_2_7;
	uint8_t GP_IN_2_8;

	uint8_t GP_IN_3_1;
	uint8_t GP_IN_3_2;
	uint8_t GP_IN_3_3;
	uint8_t GP_IN_3_4;
	uint8_t GP_IN_3_5;
	uint8_t GP_IN_3_6;
	uint8_t GP_IN_3_7;
	uint8_t GP_IN_3_8;

	uint8_t GP_IN_4_1;
	uint8_t GP_IN_4_2;
	uint8_t GP_IN_4_3;
	uint8_t GP_IN_4_4;
	uint8_t GP_IN_4_5;
	uint8_t GP_IN_4_6;
	uint8_t GP_IN_4_7;
	uint8_t GP_IN_4_8;

};	//TA531_GP_IN


struct TA531_env_TypeDef{

	uint8_t TA531_env_KL15 ;
	uint8_t TA531_env_USB1 ;
	uint8_t TA531_env_KeyLock ;
	uint8_t TA531_env_KeyUnlock ;
	uint8_t TA531_env_KeyRearDoor ;
	uint8_t TA531_env_KeyBeep ;
	uint8_t TA531_env_KeyWindow ;
	uint8_t TA531_env_KeyLeftDoor ;
	uint8_t TA531_env_KeyRightDoor ;
	uint8_t TA531_env_Relay1 ;
	uint8_t TA531_env_Relay2 ;
	uint8_t TA531_env_Relay3 ;
	uint8_t TA531_env_Relay4 ;
	uint8_t TA531_env_Relay5 ;
	uint8_t TA531_env_Relay6 ;

	uint8_t TA531_env_WindowFL ;
	uint8_t TA531_env_WindowFR ;
	uint8_t TA531_env_WindowRL ;
	uint8_t TA531_env_WindowRR ;
	uint8_t TA531_env_DoorSwF ;
	uint8_t TA531_env_DoorSwR ;
	uint8_t TA531_env_DoorSwFL ;
	uint8_t TA531_env_DoorSwFR ;
	uint8_t TA531_env_DoorSwRL ;
	uint8_t TA531_env_DoorSwRR ;

	uint8_t TA531_env_HSD12_1 ;
	uint8_t TA531_env_HSD12_2 ;
	uint8_t TA531_env_HSD12_3 ;
	uint8_t TA531_env_HSD12_4 ;
	uint8_t TA531_env_HSD5_1 ;
	uint8_t TA531_env_HSD5_2 ;

	uint8_t TA531_env_LightA1 ;
	uint8_t TA531_env_LightA2 ;
	uint8_t TA531_env_LightA3 ;
	uint8_t TA531_env_LightA4 ;
	uint8_t TA531_env_LightD1 ;
	uint8_t TA531_env_LightD2 ;
	uint8_t TA531_env_LightD3 ;
	uint8_t TA531_env_LightD4 ;

	uint8_t TA531_env_ADC1 ;
	uint8_t TA531_env_ADC2 ;

	uint8_t TA531_env_PWM_Ag_1 ;
	uint8_t TA531_env_PWM_Ag_2 ;
	uint8_t TA531_env_PWM_Ag_3 ;
	uint8_t TA531_env_PWM_Ag_4 ;
	uint8_t TA531_env_PWM_Ag_5 ;
	uint8_t TA531_env_PWM_Ag_6 ;
	uint8_t TA531_env_PWM_Ag_7 ;
	uint8_t TA531_env_PWM_Ag_8 ;
};


struct TA531_TimCallback_TypeDef{

	uint8_t TA531_Callback_flag[8] ;
//	uint8_t TA531_Callback_key[8] ;		//LOCK 1;	UNLOCK 2;	RearDoor 3;	Beep 4;	Window 5;	LeftDoor 6;	RightDoor 7;
	uint32_t TA531_Callback_tim[8] ;
};	//TA531TimCallback



struct ScreenSize_TypeDef {
	uint8_t	DispX0[4];
	uint8_t DispX1[4];
	uint8_t DispY0[4];
	uint8_t DispY1[4];
	int	DispX0_32b;
	int	DispX1_32b;
	int	DispY0_32b;
	int	DispY1_32b;

};//ScreenSz_1


struct TA531_RobotCtrl_TypeDef {
	int 	TA531_RC_X_trg;
	int 	TA531_RC_Y_trg;

	int 	TA531_RC_X_act;
	int 	TA531_RC_Y_act;
	int			TA531_RC_X_Mov;
	int			TA531_RC_Y_Mov;

	uint8_t		TA531_RC_X_Spd;
	uint8_t		TA531_RC_Y_Spd;
	int 	TA531_RC_Z;
	uint8_t		TA531_RC_Z_code;
	uint8_t		TA531_RC_Z_code2;

	uint8_t	TA531_RC_Reset;

};//TA531_RC1


struct MotorCtrl_TypeDef{

	uint16_t 	MotorCtrl_HostID ;
	uint8_t 	MotorCtrl_FuncType;
	uint8_t 	MotorCtrl_FuncCode;
	uint32_t 	MotorCtrl_DataCode;
	uint8_t 	MotorCtrl_ByteData;

	uint32_t	M_Limit_0;
	uint32_t	M_Limit_1;

	uint32_t	M_Home;

	uint32_t	M_Position;

};	//MotorCtrl_M1


//HAL_GPIO_WritePin(GPIOE, COM_RELAY_1_Pin, 1);
//HAL_GPIO_WritePin(GPIOE, COM_RELAY_2_Pin, 1);
//HAL_GPIO_WritePin(GPIOE, COM_RELAY_3_Pin, 1);
//HAL_GPIO_WritePin(GPIOE, COM_RELAY_4_Pin, 1);
//HAL_GPIO_WritePin(GPIOE, COM_RELAY_5_Pin, 1);
//HAL_GPIO_WritePin(GPIOB, COM_RELAY_6_Pin, 1);
//HAL_GPIO_WritePin(GPIOB, COM_RELAY_7_Pin, 1);
//


struct Ser2CAN_Msg_TypeDef{

	uint8_t MsgNum;
	uint8_t TriggerType;
	uint16_t DataCycle;
	uint8_t DataChannel;
	uint8_t DataType;
	uint16_t DataID;
	uint8_t PDUID;
	uint32_t DataValueLength;
	uint8_t DataValue[8];
	uint8_t FDDataValue[64];

};

struct SerLoCtrl_Msg_TypeDef{

	uint8_t LocalRelay[16];
	uint8_t Local_5VOUT[2];
	uint8_t Local_12VOUT[2];
	uint16_t LocalPSCtrl[2];

};


struct Bench_AckInfo_TypeDef{

	uint8_t Bench_PowerSts;
	uint8_t Bench_PgLevel1;
	uint8_t Bench_PgLevel2;
	uint8_t Bench_PgLevel3;
	uint8_t Bench_PgLevel4;
	uint8_t Bench_TestType;
	uint8_t Bench_UTInfo;

	uint8_t Bench_TestCase;
	uint8_t Bench_TestProgress;
	uint8_t Bench_TestResult;
	uint8_t Bench_NeedEngineer;
	uint8_t Bench_ErrSts;

	uint16_t ATP_TD_ID;
	uint8_t ATP_TD_Model;

};


struct TA531_LIN_GW_TypeDef{

	uint8_t LIN_GW_SysPwrMd_2;
	uint8_t LIN_GW_VehSideLghtSts_GW_LIN2_2 ;
	uint8_t LIN_GW_DimLghtLvl_GW_LIN2_8;

};	//TA531_LIN_GW

struct TA531_LIN_SWS_TypeDef{

	uint8_t LIN_SWS_050ms_PDU00_RC_4 ;
	uint8_t LIN_SWS_050ms_PDU00_Reserve01_1 ;
	uint8_t LIN_SWS_050ms_PDU00_Reserve02_8 ;
	uint8_t LIN_SWS_050ms_PDU00_Reserve03_7 ;
	uint8_t LIN_SWS_050ms_PDU000_CRC_8 ;
	uint8_t LIN_SWS_CCSwStsCanclSwA_1 ;
	uint8_t LIN_SWS_CCSwStsCCASwA_1 ;
	uint8_t LIN_SWS_CCSwStsDistDecSwA_1 ;
	uint8_t LIN_SWS_CCSwStsDistIncSwA_1 ;
	uint8_t LIN_SWS_CCSwStsOnSwA_1 ;
	uint8_t LIN_SWS_CCSwStsPV_8 ;
	uint8_t LIN_SWS_CCSwStsRsmSwA_1 ;
	uint8_t LIN_SWS_CCSwStsSetSwA_1 ;
	uint8_t LIN_SWS_CCSwStsSpdDecSwA_1 ;
	uint8_t LIN_SWS_CCSwStsSpdIncSwA_1 ;
	uint8_t LIN_SWS_CCSwStsSwDataIntgty_2 ;
	uint8_t LIN_SWS_PfTrTapUpDwnSecySwSta_2 ;
	uint8_t LIN_SWS_StrgWhlDrMdSwDtIntgty_1 ;
	uint8_t LIN_SWS_StrgWhlDrvngMdSwA_1 ;
	uint8_t LIN_SWS_StrgWhlEntrtnSwDtIntgty_1;
	uint8_t LIN_SWS_StrgWhlTipcSwDataIntgty_1 ;
	uint8_t LIN_SWS_SWSCnfmSwA_1 ;
	uint8_t LIN_SWS_SWSEntrtnUserSwA_1 ;
	uint8_t LIN_SWS_SWSFastrUserSwA_1 ;
	uint8_t LIN_SWS_SWSFnChngSwA_1 ;
	uint8_t LIN_SWS_SWSLFnChngSwA_1 ;
	uint8_t LIN_SWS_SWSSelDwnSwA_1 ;
	uint8_t LIN_SWS_SWSSelLSwA_1 ;
	uint8_t LIN_SWS_SWSSelRSwA_1 ;
	uint8_t LIN_SWS_SWSSelUpSwA_1 ;
	uint8_t LIN_SWS_SWSSocContSwA_1 ;
	uint8_t LIN_SWS_SWSVcSwA_1 ;
	uint8_t LIN_SWS2_ErrRespSWS_1 ;
	uint8_t LIN_SWS2_RespErSWSF_1 ;

};	//TA531_LIN_SWS


struct TA531_LIN_SWS_G3_TypeDef{
	uint8_t CCSwStsChksm;
	uint8_t SWSPB2SwAL_l;
	uint8_t StrgWhlTipcSwDataIntgty_l;
	uint8_t SWSSelRSwAL_l;
	uint8_t SWSSelLSwStuckL_l;
	uint8_t RespErSWSF_l;
	uint8_t SWSPB1SwAL_l;
	uint8_t PadSSelLSwStuck_l;
	uint8_t SWSSelLSwReq_l;
	uint8_t StrgWhlDrvngMdSwDataIntgty_l;
	uint8_t SWSSelRSwReq_l;
	uint8_t SWSPB2SwStuckL_l;
	uint8_t CCSwStsAlvRC_l;
	uint8_t PfTrTapUpDwnSecySwSta_l;
	uint8_t PadSSelRSwStuck_l;
	uint8_t SWSSelUpSwReq_l;
	uint8_t SWSPB1SwReq_l;
	uint8_t SWSSelRSwStuckL_l;
	uint8_t SWSCnfmSwAL_l;
	uint8_t SWSPB3SwAL_l;
	uint8_t SWSPB2SwReq_l;
	uint8_t StrgWhlDrvngMdSwA_l;
	uint8_t PadSSelRSwA_l;
	uint8_t SWSSelLSwAL_l;
	uint8_t SWSPB3SwReq_l;
	uint8_t SWSPB1SwStuckL_l;
	uint8_t SWSSelDwnSwAL_l;
	uint8_t SWSSelUpSwAL_l;
	uint8_t SWSCnfmSwReq_l;
	uint8_t SWSCnfmSwStuckL_l;
	uint8_t PadSSelLSwA_l;
	uint8_t SWSPB3SwStuckL_l;
	uint8_t SWSSelDwnSwReq_l;
	uint8_t StrgWhlEntrtnSwDataIntgty_l;

};


//////////////////
// W25Q64 FLASH
#define		Flash_Write_Enable_CMD		0x06
#define		Flash_Write_Disable_CMD		0x04
#define		Flash_Write_SR_CMD			0x01
#define		Flash_Read_SR_CMD			0x05
#define		Flash_Read_Data				0x03
#define		Flash_FastRead_Data			0x0b
#define		Flash_Write_Page			0x02
#define		Flash_Erase_Page			0x81
#define		Flash_Erase_Sector			0x20
#define		Flash_Erase_Block			0xd8
#define		Flash_Erase_Chip			0xc7
#define		Flash_Power_Down			0xb9
#define		Flash_Release_Power_Down	0xab
#define		Flash_Read_DeviceID			0x90
#define		Flash_Read_UniqueID			0x4b

#define		SPI_FLASH_SIZE		(8*1024*1024)
#define		PAGE_SIZE			8192
#define		SECTOR_SIZE			512
#define		BLOCK_SIZE			32
#define		PAGE_LENGTH			255



void SPI_Flash_Init(void);
uint16_t SPI_Flash_GetID(void);
uint64_t SPI_Flash_GUID(void);
void SPI_Flash_WtritEnable(void);
void SPI_Flash_WtritDisable(void);
uint8_t SPI_Flash_ReadSR(void);
void SPI_Flash_WriteSR(uint8_t write_cmd);
void SPI_Flash_WaitNoBusy(void);
void SPI_Flash_ReadBytes(uint8_t *Rxpbuffer, uint32_t ReadAddr, uint16_t NumbBytes);
void SPI_Flash_FastReadBytes(uint8_t *Rxpbuffer, uint32_t ReadAddr, uint16_t NumbBytes);
void SPI_Flash_WritePage(uint8_t *Txpbuffer, uint32_t WrtieAddr, uint16_t NumbBytes);
void SPI_Flash_WriteNoCheck(uint8_t *Txpbuffer, uint32_t WrtieAddr, uint16_t NumbBytes);
void SPI_Flash_WriteSomeBytes(uint8_t *Txpbuffer, uint32_t WrtieAddr, uint16_t NumbBytes);
void SPI_Flash_ErasePage(uint32_t pPageAddr);
void SPI_Flash_EraseSector(uint32_t pSectorAddr);
void SPI_Flash_EraseBlock(uint32_t pBlockAddr);
void SPI_Flash_EraseChip(void);
void SPI_Flash_PowerDown(void);
void SPI_Flash_PowerUp(void);





////XL9555

#define	XL9555_1_addr_read		0x41	//	0x20 << 1 + 1
#define	XL9555_1_addr_write		0x40	//	0x20 << 1 + 0
#define	XL9555_2_addr_read		0x43
#define	XL9555_2_addr_write		0x42

void XL9555_Init(uint8_t addr,uint8_t port1,uint8_t port2);
uint8_t XL9555_Read(uint8_t addr,uint8_t port);




/////////TMP1075

#define TempSensor_ADDR_ZXD     0x48<<1
#define TempSensor_ADDR_ZPD     0x49<<1
#define TempSensor_ADDR_LHZCU     0x4A<<1
#define TempSensor_ADDR_RHZCU     0x4B<<1
#define TempSensor_ADDR_RZCU     0x4C<<1

#define TMP1075_TEMP_REG  0x00  // 温度数据寄存器（只读）
#define TMP1075_CONFIG_REG 0x01 // 配置寄存器（可读可写）
#define TMP1075_TLOW_REG  0x02  // 低温阈值寄存器
#define TMP1075_THIGH_REG 0x03  // 高温阈值寄存器


void TMP1075_Init(uint8_t ch, uint8_t addr);
float readTemperature(uint8_t ch, uint8_t addr);


#endif /* SRC_EASYSYS_H_ */
