/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoCalculatorC
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoCalculatorC
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

#ifndef __ID_ECO_CALCULATOR_C_H__
#define __ID_ECO_CALCULATOR_C_H__

#include "IEcoBase1.h"
#include "IEcoCalculatorX.h"
#include "IEcoCalculatorY.h"

/* EcoCalculatorC CID = {4828F655-2E45-40E7-8121-EBD220DC360E} */
#ifndef __CID_EcoCalculatorC
static const UGUID CID_EcoCalculatorC = {0x01, 0x10, 0x48, 0x28, 0xF6, 0x55, 0x2E, 0x45, 0x40, 0xE7, 0x81, 0x21, 0xEB, 0xD2, 0x20, 0xDC, 0x36, 0x0E};
#endif /* __CID_EcoCalculatorC */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_4828F6552E4540E78121EBD220DC360E;
#endif

#endif /* __ID_ECO_CALCULATOR_C_H__ */
