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

#ifndef __C_ECOLAB1_H__
#define __C_ECOLAB1_H__

#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IEcoLab1.h"
#include "IEcoCalculatorY.h"
#include "IEcoCalculatorX.h"
#include "IEcoEnumConnections.h"
#include "IEcoConnectionPointContainer.h"
#include "CEcoLab1ConnectionPoint.h"

typedef struct CEcoLab1 {

    /* Таблица функций интерфейса IEcoLab1 */
    IEcoLab1VTbl* m_pVTblIEcoLab1;

    /* Таблица функций интерфейса IEcoCalculatorY */
    IEcoCalculatorYVTbl* m_pVTblIY;

    /* Таблица функций интерфейса IEcoCalculatorX */
    IEcoCalculatorXVTbl* m_pVTblIX;

    /* Неделигирующий интерфейс IEcoNondelegatingUnknown */
    IEcoUnknownVTbl* m_pVTblINondelegatingUnk;

    /* Таблица функций интерфейса IEcoConnectionPointContainer */
    IEcoConnectionPointContainerVTbl* m_pVTblICPC;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Точка подключения */
    CEcoLab1ConnectionPoint* m_pISinkCP;

    /* Данные экземпляра */
    char_t* m_Name;

    /* Ссылка на внутренний компонент для включения, может быть получен из D или E */
    IEcoCalculatorY* m_pIY;

    /* Ссылка на интерфейс IEcoUnknown внутреннего агрегируемого компонента B */
    IEcoUnknown* m_pInnerUnknown;

    /* Ссылка на внутренний компонент для включения, может быть получен из A*/
    IEcoCalculatorX* m_pIX;

    /* Делегирующий IEcoUnknown, указывает на внешний или неделегирующий IEcoUnknown */
    IEcoUnknown* m_pIUnkOuter;

} CEcoLab1, *CEcoLab1Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCEcoLab1(/*in*/ struct IEcoLab1 * me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoLab1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoLab1 ** ppIEcoLab1);
/* Удаление */
void ECOCALLMETHOD deleteCEcoLab1(/* in */ IEcoLab1* pIEcoLab1);

#endif /* __C_ECOLAB1_H__ */
