#ifndef __I_ECOLAB1_H__
#define __I_ECOLAB1_H__

#include "IEcoBase1.h"

/* IEcoLab1 IID = {277FC00C-3562-4096-AFCF-C125B94EEC90} */
#ifndef __IID_IEcoLab1
static const UGUID IID_IEcoLab1 = {0x01, 0x10, 0x27, 0x7F, 0xC0, 0x0C, 0x35, 0x62, 0x40, 0x96, 0xAF, 0xCF, 0xC1, 0x25, 0xB9, 0x4E, 0xEC, 0x90};
#endif /* __IID_IEcoLab1 */

interface IEcoLab1 {
    struct IEcoLab1VTbl *pVTbl;
} IEcoLab1;

typedef struct IEcoLab1VTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ struct IEcoLab1* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ struct IEcoLab1* me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ struct IEcoLab1* me);

    /* IEcoLab1 */
	int16_t (ECOCALLMETHOD *qsort)(
		struct IEcoLab1* me,
		void* pData,
		size_t elem_count,
		size_t elem_size,
		int (*comp)(const void *, const void*)
	);

} IEcoLab1VTbl, *IEcoLab1VTblPtr;


#endif /* __I_ECOLAB1_H__ */
