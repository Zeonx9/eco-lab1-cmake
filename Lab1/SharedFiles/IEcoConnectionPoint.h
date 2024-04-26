/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoConnectionPoint
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoConnectionPoint
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

#ifndef __I_ECO_CONNECTION_POINT_1_H__
#define __I_ECO_CONNECTION_POINT_1_H__

#include "IEcoBase1.h"

/* IEcoConnectionPoint IID = 00000003-0000-0000-C000-000000000046 */
#ifndef __IID_IEcoConnectionPoint
static const UGUID IID_IEcoConnectionPoint = { 0x01, 0x10, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 };
#endif /* __IID_IEcoConnectionPoint */

struct IEcoConnectionPointContainer;

typedef struct IEcoConnectionPointVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface )(/* in */ struct IEcoConnectionPoint* me, /* in */ const UGUID* riid, /* out */ void** ppv);
    uint32_t (ECOCALLMETHOD *AddRef )(/* in */ struct IEcoConnectionPoint* me);
    uint32_t (ECOCALLMETHOD *Release )(/* in */ struct IEcoConnectionPoint* me);

    int16_t (ECOCALLMETHOD *GetConnectionInterface )(/* in */ struct IEcoConnectionPoint* me, /* out */ UGUID *pIID);
    int16_t (ECOCALLMETHOD *GetConnectionPointContainer )(/* in */ struct IEcoConnectionPoint* me, /* out */ struct IEcoConnectionPointContainer **ppCPC);
    int16_t (ECOCALLMETHOD *Advise)(/* in */ struct IEcoConnectionPoint* me, /* in */ struct IEcoUnknown *pUnkSink, /* out */ uint32_t *pcCookie);
    int16_t (ECOCALLMETHOD *Unadvise)(/* in */ struct IEcoConnectionPoint* me, /* in */ uint32_t cCookie);
    int16_t (ECOCALLMETHOD *EnumConnections)(/* in */ struct IEcoConnectionPoint* me, /* out */ struct IEcoEnumConnections **ppEnum);

} IEcoConnectionPointVTbl;

interface IEcoConnectionPoint {
    struct IEcoConnectionPointVTbl *pVTbl;
} IEcoConnectionPoint;

#endif /* __I_ECO_CONNECTION_POINT_1_H__ */
