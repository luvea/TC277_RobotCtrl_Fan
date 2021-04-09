/*
 * TLE9180_Callout.h
 *
 *  Created on: 2019-11-11
 *      Author: Light
 */

#ifndef TLE9180_CALLOUT_H_
#define TLE9180_CALLOUT_H_

#include "Dio.h"


extern void TLE9180_WriteENA(Dio_LevelType Level);
extern void TLE9180_WriteINH_N(Dio_LevelType Level);
extern void TLE9180_WriteSOFF_N(Dio_LevelType Level);



//extern void TLE_WriteENA(Dio_LevelType Level);
//extern void TLE_Write_INH_N(Dio_LevelType Level);
//extern void TLE_Write_SOFF_N(Dio_LevelType Level);
extern Dio_LevelType TLE9180_ReadERR_N(void);

#endif /* TLE9180_CALLOUT_H_ */
