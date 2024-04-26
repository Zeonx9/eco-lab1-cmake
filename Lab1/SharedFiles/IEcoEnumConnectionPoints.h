/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoEnumConnectionPoints
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoEnumConnectionPoints
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

#ifndef __I_ECO_ENUM_CONNECTION_POINTS_1_H__
#define __I_ECO_ENUM_CONNECTION_POINTS_1_H__

#include "IEcoBase1.h"
#include "IEcoConnectionPoint.h"

/* IEcoEnumConnectionPoints IID = 00000004-0000-0000-C000-000000000046 */
#ifndef __IID_IEcoEnumConnectionPoints
static const UGUID IID_IEcoEnumConnectionPoints = { 0x01, 0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 };
#endif /* __IID_IEcoEnumConnectionPoints */

typedef struct IEcoEnumConnectionPointsVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface )(/* in */ struct IEcoEnumConnectionPoints* me, /* in */ const UGUID* riid, /* out */ void** ppv);
    uint32_t (ECOCALLMETHOD *AddRef )(/* in */ struct IEcoEnumConnectionPoints* me);
    uint32_t (ECOCALLMETHOD *Release )(/* in */ struct IEcoEnumConnectionPoints* me);

    int16_t (ECOCALLMETHOD *Next)(/* in */ struct IEcoEnumConnectionPoints* me, /* in */ uint32_t cConnections, /* out */ struct IEcoConnectionPoint **ppCP, /* out */ uint32_t *pcFetched);
    int16_t (ECOCALLMETHOD *Skip)(/* in */ struct IEcoEnumConnectionPoints* me, /* in */ uint32_t cConnections);
    int16_t (ECOCALLMETHOD *Reset)(/* in */ struct IEcoEnumConnectionPoints* me);
    int16_t (ECOCALLMETHOD *Clone)(/* in */ struct IEcoEnumConnectionPoints* me, /* out */ struct IEcoEnumConnectionPoints **ppEnum);

} IEcoEnumConnectionPointsVTbl;

interface IEcoEnumConnectionPoints {
    struct IEcoEnumConnectionPointsVTbl *pVTbl;
} IEcoEnumConnectionPoints;


#endif /* __I_ECO_ENUM_CONNECTION_POINTS_1_H__ */
