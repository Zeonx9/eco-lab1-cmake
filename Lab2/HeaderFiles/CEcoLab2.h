/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoLab1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOLAB2_H__
#define __C_ECOLAB2_H__

#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IEcoLab1.h"
#include "IEcoCalculatorY.h"
#include "IEcoCalculatorX.h"

typedef struct CEcoLab2 {

    /* Таблица функций интерфейса IEcoCalculatorY */
    IEcoCalculatorYVTbl* m_pVTblIY;

    /* Таблица функций интерфейса IEcoCalculatorX */
    IEcoCalculatorXVTbl* m_pVTblIX;

    /* Неделигирующий интерфейс IEcoNondelegatingUnknown */
    IEcoUnknownVTbl* m_pVTblINondelegatingUnk;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    char_t* m_Name;

    /* Ссылка на внутренний компонент для включения, может быть получен из D или E */
    IEcoCalculatorY* m_pIY;

    /* Ссылка на интерфейс IEcoUnknown внутреннего агрегируемого компонента Lab1 */
    IEcoUnknown* m_pInnerUnknownLab1;

    /* Ссылка на интерфейс IEcoUnknown внутреннего агрегируемого компонента B */
    IEcoUnknown* m_pInnerUnknownB;

    /* Ссылка на внутренний компонент для включения, может быть получен из A*/
    IEcoCalculatorX* m_pIX;

    /* Делегирующий IEcoUnknown, указывает на внешний или неделегирующий IEcoUnknown */
    IEcoUnknown* m_pIUnkOuter;

} CEcoLab2, *CEcoLab2Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoLab2(/*in*/ struct IEcoCalculatorY * me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoLab2(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoCalculatorY** ppIEcoLab2);
/* Удаление */
void ECOCALLMETHOD deleteCEcoLab2(/* in */ IEcoCalculatorY* pIEcoLab2);

#endif /* __C_ECOLAB2_H__ */
