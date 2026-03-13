/*
 * FlashAddr.h
 *
 *  Created on: Sep 24, 2025
 *      Author: wch
 */

#ifndef INC_FLASHADDR_H_
#define INC_FLASHADDR_H_

///////////////////////////////////////////////////////////

#define FLASH_INDEX_START    0x000000
#define FLASH_INDEX_SIZE     0x008000  // 32KB	flash索引区

//////////////////////////////////////////////////////////

#define BENCH_CONFIG_START    0x008000
#define BENCH_CONFIG_SIZE     0x008000  // 32KB	台架配置区

//////////////////////////////////////////////////////////

#define SYS_CONFIG_START    0x010000

#define Sys_Addr_DispTest 	SYS_CONFIG_START + 0x000000  // 0x010000
#define Sys_Addr_DispX0 	SYS_CONFIG_START + 0x000010  // 0x010010 ⬅️ 间隔16字节
#define Sys_Addr_DispX1 	SYS_CONFIG_START + 0x000020  // 0x010020 ⬅️ 间隔16字节
#define Sys_Addr_DispY0 	SYS_CONFIG_START + 0x000030  // 0x010030 ⬅️ 间隔16字节
#define Sys_Addr_DispY1 	SYS_CONFIG_START + 0x000040  // 0x010040 ⬅️ 间隔16字节

#define SYS_CONFIG_SIZE     0x010000  // 64KB	系统状态区

//////////////////////////////////////////////////////////

#define DATA_AREA_START      0x020000

//float
#define TemperAddr_ZXD		DATA_AREA_START + 0x000010 +0*4
#define TemperAddr_IPD		DATA_AREA_START + 0x000010 +1*4
#define TemperAddr_LHZCU	DATA_AREA_START + 0x000010 +2*4
#define TemperAddr_RHZCU	DATA_AREA_START + 0x000010 +3*4
#define TemperAddr_RZCU		DATA_AREA_START + 0x000010 +4*4
#define TemperAddr_Bk1		DATA_AREA_START + 0x000010 +5*4
#define TemperAddr_Bk2		DATA_AREA_START + 0x000010 +6*4
#define TemperAddr_Bk3		DATA_AREA_START + 0x2C

#define DATA_AREA_SIZE       0x700000  // 7MB的数据区

//////////////////////////////////////////////////////////

#define Reserve_AREA_START      0x720000
#define Reserve_AREA_SIZE       0x0E0000  // 约896KB的预留区

#endif /* INC_FLASHADDR_H_ */
