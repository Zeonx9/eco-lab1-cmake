/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoEnumConnections
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoEnumConnections
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

#ifndef __I_ECO_ENUM_CONNECTIONS_1_H__
#define __I_ECO_ENUM_CONNECTIONS_1_H__

#include "IEcoBase1.h"

typedef struct EcoConnectionData {
    IEcoUnknown *pUnk;
    uint32_t cCookie;
} EcoConnectionData;

/* IEcoEnumConnections IID = 00000002-0000-0000-C000-000000000046 */
#ifndef __IID_IEcoEnumConnections
static const UGUID IID_IEcoEnumConnections = { 0x01, 0x10, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46};
#endif /* __IID_IEcoEnumConnections */

typedef struct IEcoEnumConnectionsVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface )(/* in */ struct IEcoEnumConnections* me, /* in */ const UGUID* riid, /* out */ void** ppv);
    uint32_t (ECOCALLMETHOD *AddRef )(/* in */ struct IEcoEnumConnections* me);
    uint32_t (ECOCALLMETHOD *Release )(/* in */ struct IEcoEnumConnections* me);

    int16_t (ECOCALLMETHOD *Next)(/* in */ struct IEcoEnumConnections* me, /* in */ uint32_t cConnections, /* out */ struct EcoConnectionData *rgcd, /* out */ uint32_t *pcFetched);
    int16_t (ECOCALLMETHOD *Skip)(/* in */ struct IEcoEnumConnections* me, /* in */ uint32_t cConnections);
    int16_t (ECOCALLMETHOD *Reset)(/* in */ struct IEcoEnumConnections* me);
    int16_t (ECOCALLMETHOD *Clone)(/* in */ struct IEcoEnumConnections* me, /* out */ struct IEcoEnumConnections **ppEnum);

} IEcoEnumConnectionsVTbl;

interface IEcoEnumConnections {
    struct IEcoEnumConnectionsVTbl *pVTbl;
} IEcoEnumConnections;

#endif /* __I_ECO_ENUM_CONNECTIONS_1_H__ */
