/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1ConnectionPoint
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию интерфейсов CEcoLab1ConnectionPoint
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOLAB1_CONNECTION_POINT_H__
#define __C_ECOLAB1_CONNECTION_POINT_H__

#include "IEcoConnectionPoint.h"
#include "IEcoConnectionPointContainer.h"
#include "IdEcoList1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoLab1ConnectionPoint {

    /* Таблица функций интерфейса IEcoConnectionPoint */
    IEcoConnectionPointVTbl* m_pVTblICP;

    /* Интерфейс контейнера точки подключения */
    IEcoConnectionPointContainer* m_pICPC;

    /* Идентификатор точки подключения */
    UGUID* m_piid;

    /* Cookie */
    uint32_t m_cNextCookie;

    /* Список подключений */
    IEcoList1* m_pSinkList;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

} CEcoLab1ConnectionPoint;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoLab1ConnectionPoint(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoConnectionPointContainer* pICPC, /* in */ const UGUID* riid, /* out */ IEcoConnectionPoint** ppICP);
/* Удаление */
void ECOCALLMETHOD deleteCEcoLab1ConnectionPoint(/* in */ IEcoConnectionPoint* pICP);

#endif /* __C_ECOLAB1_CONNECTION_POINT_H__ */
