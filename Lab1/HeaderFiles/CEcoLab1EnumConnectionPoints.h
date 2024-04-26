/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1EnumConnectionPoints
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию интерфейсов CEcoLab1EnumConnectionPoints
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOLAB1_ENUM_CONNECTION_POINTS_H__
#define __C_ECOLAB1_ENUM_CONNECTION_POINTS_H__

#include "IEcoEnumConnectionPoints.h"
#include "IdEcoList1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoLab1EnumConnectionPoints {

    /* Таблица функций интерфейса IEcoEnumConnectionPoints */
    IEcoEnumConnectionPointsVTbl* m_pVTblIECP;

    /* Список */
    IEcoList1* m_List;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

} CEcoLab1EnumConnectionPoints;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoLab1EnumConnectionPoints(/* in */ IEcoUnknown* pIUnkSystem, /* in */ struct IEcoConnectionPoint *pCP, /* out */ IEcoEnumConnectionPoints** ppIEnum);
/* Удаление */
void ECOCALLMETHOD deleteCEcoLab1EnumConnectionPoints(/* in */ IEcoEnumConnectionPoints* pIEnum);

#endif /* __C_ECOLAB1_ENUM_CONNECTION_POINTS_H__ */
