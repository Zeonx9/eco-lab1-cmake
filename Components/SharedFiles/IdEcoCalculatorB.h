/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoCalculatorB
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoCalculatorB
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

#ifndef __ID_ECO_CALCULATOR_B_H__
#define __ID_ECO_CALCULATOR_B_H__

#include "IEcoBase1.h"
#include "IEcoCalculatorX.h"

/* EcoCalculatorB CID = {AE202E54-3CE5-4550-8996-03BD70C62565} */
#ifndef __CID_EcoCalculatorB
static const UGUID CID_EcoCalculatorB = {0x01, 0x10, 0xAE, 0x20, 0x2E, 0x54, 0x3C, 0xE5, 0x45, 0x50, 0x89, 0x96, 0x03, 0xBD, 0x70, 0xC6, 0x25, 0x65};
#endif /* __CID_EcoCalculatorB */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_AE202E543CE54550899603BD70C62565;
#endif

#endif /* __ID_ECO_CALCULATOR_B_H__ */
