/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoCalculatorD
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoCalculatorD
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __ID_ECO_CALCULATOR_D_H__
#define __ID_ECO_CALCULATOR_D_H__

#include "IEcoBase1.h"
#include "IEcoCalculatorY.h"

/* EcoCalculatorD CID = {3A8E4467-7E82-475C-B4A3-719ED8397E61} */
#ifndef __CID_EcoCalculatorD
static const UGUID CID_EcoCalculatorD = {0x01, 0x10, 0x3A, 0x8E, 0x44, 0x67, 0x7E, 0x82, 0x47, 0x5C, 0xB4, 0xA3, 0x71, 0x9E, 0xD8, 0x39, 0x7E, 0x61};
#endif /* __CID_EcoCalculatorD */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_3A8E44677E82475CB4A3719ED8397E61;
#endif

#endif /* __ID_ECO_CALCULATOR_D_H__ */
