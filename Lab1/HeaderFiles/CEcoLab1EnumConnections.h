/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1EnumConnections
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию интерфейсов CEcoLab1EnumConnections
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECOLAB1_ENUM_CONNECTIONS_H__
#define __C_ECOLAB1_ENUM_CONNECTIONS_H__

#include "IEcoEnumConnections.h"
#include "IdEcoList1.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoLab1EnumConnections {

    /* Таблица функций интерфейса IEcoEnumConnections */
    IEcoEnumConnectionsVTbl* m_pVTblIEC;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Список подключений */
    IEcoList1* m_pSinkList;
    uint32_t m_cIndex;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

} CEcoLab1EnumConnections;

/* Создание экземпляра */
int16_t ECOCALLMETHOD createCEcoLab1EnumConnections(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoList1* pIList, /* out */ IEcoEnumConnections** ppIEnum);
/* Удаление */
void ECOCALLMETHOD deleteCEcoLab1EnumConnections(/* in */ IEcoEnumConnections* pIEnum);

#endif /* __C_ECOLAB1_1_ENUM_CONNECTIONS_H__ */
