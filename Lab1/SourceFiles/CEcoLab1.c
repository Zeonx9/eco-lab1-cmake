﻿#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoLab1.h"
#include "IdEcoCalculatorD.h"
#include "IdEcoCalculatorE.h"
#include "IdEcoCalculatorB.h"
#include "IdEcoCalculatorA.h"
#include "CEcoLab1EnumConnectionPoints.h"
#include "IEcoConnectionPointContainer.h"
#include "IEcoLab1Events.h"

int16_t ECOCALLMETHOD CEcoLab1_QueryInterface(/* in */ struct IEcoLab1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    IEcoUnknown * nonDelegating = (IEcoUnknown *)&pCMe->m_pVTblINondelegatingUnk;
    int16_t result;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    result = nonDelegating->pVTbl->QueryInterface(nonDelegating, riid, ppv);
    if (result != 0 && pCMe->m_pIUnkOuter != 0) {
        result = pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
    }
    return result;
}

uint32_t ECOCALLMETHOD CEcoLab1_AddRef(/* in */ struct IEcoLab1* me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return pCMe->m_pVTblINondelegatingUnk->AddRef((IEcoUnknown *)&pCMe->m_pVTblINondelegatingUnk);
}

uint32_t ECOCALLMETHOD CEcoLab1_Release(/* in */ struct IEcoLab1* me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return pCMe->m_pVTblINondelegatingUnk->Release((IEcoUnknown *)&pCMe->m_pVTblINondelegatingUnk);
}

// callback function
int16_t ECOCALLMETHOD CEcoLab1_Fire_OnMergeSortCalled(/* in */ struct IEcoLab1* me, const void * start_ptr, size_t elem_count) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t result = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->OnMergeSortCalled(pIEvents, start_ptr, elem_count);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

// callback function
int16_t ECOCALLMETHOD CEcoLab1_Fire_OnRecursiveCall(/* in */ struct IEcoLab1* me, bool_t isFirstHalf) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t result = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->OnRecursiveCall(pIEvents, isFirstHalf);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

int16_t ECOCALLMETHOD CEcoLab1_Fire_OnRecursiveCallReturn(/* in */ struct IEcoLab1* me, bool_t isFirstHalf) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t result = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->OnRecursiveCallReturn(pIEvents, isFirstHalf);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

// callback function
int16_t ECOCALLMETHOD CEcoLab1_Fire_BeforeMerge(/* in */ struct IEcoLab1* me, const void * start_ptr, size_t elem_count) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t result = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->BeforeMerge(pIEvents, start_ptr, elem_count);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

// callback function
int16_t ECOCALLMETHOD CEcoLab1_Fire_AfterMerge(/* in */ struct IEcoLab1* me, const void * start_ptr, size_t elem_count) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t result = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->AfterMerge(pIEvents, start_ptr, elem_count);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

// callback function
int16_t ECOCALLMETHOD CEcoLab1_Fire_OnMergeElementSelected(/* in */ struct IEcoLab1* me, const void * element_ptr, bool_t isFromFirstHalf) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    int16_t result = 0;
    IEcoEnumConnections* pEnum = 0;
    IEcoLab1Events* pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = ((IEcoConnectionPoint*)pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint*)pCMe->m_pISinkCP, &pEnum);
        if ( (result == 0) && (pEnum != 0) ) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void**)&pIEvents);
                if ( (result == 0) && (pIEvents != 0) ) {
                    result = pIEvents->pVTbl->OnMergeElementSelected(pIEvents, element_ptr, isFromFirstHalf);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}


// Копирует заданное число байт
void copy_bytes(char *src, char *dst, size_t count) {
	char *end = src + count;
    while (src < end) {
        *(dst++) = *(src++);
    }
}

// реализация сортировки слиянием с использованием внешнего буфера для организации слияния
void merge_sort(
    IEcoLab1 *me,
	char *start_ptr,
	size_t elem_count,
	size_t elem_size,
	int (__cdecl *comp)(const void *, const void*),
	char *buffer
) {
    // локальные переменные
    size_t byte_count = elem_size * elem_count;
    size_t left_count = elem_count / 2;
    size_t right_count = elem_count - left_count;
    char *middle_ptr = start_ptr + (left_count * elem_size);
    char *end_ptr = start_ptr + byte_count;
    char *current_ptr = buffer;
    char *left_ptr = start_ptr;
    char *right_ptr = middle_ptr;

    // function called elem count
    CEcoLab1_Fire_OnMergeSortCalled(me, start_ptr, elem_count);

	// 0. base recursive case;
    if (elem_count < 2) {
        return;
    }

    // 1. sort each half recursively
    CEcoLab1_Fire_OnRecursiveCall(me, TRUE);
    merge_sort(me, start_ptr, left_count, elem_size, comp, buffer);
    CEcoLab1_Fire_OnRecursiveCallReturn(me, TRUE);

    CEcoLab1_Fire_OnRecursiveCall(me, FALSE);
    merge_sort(me, middle_ptr, right_count, elem_size, comp, buffer);
    CEcoLab1_Fire_OnRecursiveCallReturn(me, FALSE);


    CEcoLab1_Fire_BeforeMerge(me, start_ptr, elem_count);
	// 2. merge sorted parts using buffer
    while (left_ptr < middle_ptr && right_ptr < end_ptr) {
        int comp_result = comp(left_ptr, right_ptr);
        if (comp_result <= 0) {
            CEcoLab1_Fire_OnMergeElementSelected(me, left_ptr, TRUE);
            copy_bytes(left_ptr, current_ptr, elem_size);
            left_ptr += elem_size;
        } else {
            CEcoLab1_Fire_OnMergeElementSelected(me, right_ptr, FALSE);
            copy_bytes(right_ptr, current_ptr, elem_size);
            right_ptr += elem_size;
        }
        current_ptr += elem_size;
    }
    while (left_ptr < middle_ptr) {
        CEcoLab1_Fire_OnMergeElementSelected(me, left_ptr, TRUE);
        copy_bytes(left_ptr, current_ptr, elem_size);
        left_ptr += elem_size;
        current_ptr += elem_size;
    }
    while (right_ptr < end_ptr) {
        CEcoLab1_Fire_OnMergeElementSelected(me, right_ptr, FALSE);
        copy_bytes(right_ptr, current_ptr, elem_size);
        right_ptr += elem_size;
        current_ptr += elem_size;
    }

	// 3. copy sorted values from buffer
    copy_bytes(buffer, start_ptr, byte_count);

    CEcoLab1_Fire_AfterMerge(me, start_ptr, elem_count);
}

// Функция сортировка слиянием, использует сигнатуру qsort.
// Выделяет буфер памяти через интерфейс IEcoMemoryAllocator1
int16_t ECOCALLMETHOD CEcoLab1_qsort(
	struct IEcoLab1* me,
	void* pData,
	size_t elem_count,
	size_t elem_size,
	int (__cdecl *comp)(const void *, const void*)
) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
	void *buffer = 0;
    int16_t index = 0;

    /* Проверка указателей */
    if (me == 0 || pData == 0 || comp == 0) {
        return -1;
    }

	// 1. allocate memory for buffer
	buffer = pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, elem_count * elem_size);
	
	// 2. sort with buffer
	merge_sort(me, pData, elem_count, elem_size, comp, buffer);

	// 3. free buffer memory
	pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, buffer);

    return 0;
}

int16_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_QueryInterface(/* in */ struct IEcoCalculatorY* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*));
    IEcoUnknown * nonDelegating = (IEcoUnknown *)&pCMe->m_pVTblINondelegatingUnk;
    int16_t result;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    result = nonDelegating->pVTbl->QueryInterface(nonDelegating, riid, ppv);
    if (result != 0 && pCMe->m_pIUnkOuter != 0) {
        result = pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
    }
    return result;
}

uint32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_AddRef(/* in */ struct IEcoCalculatorY* me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(struct IEcoLab1*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return pCMe->m_pVTblINondelegatingUnk->AddRef((IEcoUnknown *)&pCMe->m_pVTblINondelegatingUnk);
}

uint32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorY_Release(/* in */ struct IEcoCalculatorY* me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(struct IEcoLab1*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return pCMe->m_pVTblINondelegatingUnk->Release((IEcoUnknown *)&pCMe->m_pVTblINondelegatingUnk);
}

int32_t ECOCALLMETHOD CEcoLab1_Multiplication(/* in */ struct IEcoCalculatorY* me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(struct IEcoLab1*));
    int32_t result = 0;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pIY != 0) {
        result = pCMe->m_pIY->pVTbl->Multiplication(pCMe->m_pIY, a, b);
    }

    return result;
}

int16_t ECOCALLMETHOD CEcoLab1_Division(/* in */ struct IEcoCalculatorY* me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(struct IEcoLab1*));
    int16_t result = 0;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pIY != 0) {
        result = pCMe->m_pIY->pVTbl->Division(pCMe->m_pIY, a, b);
    }

    return result;
}


int16_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_QueryInterface(/* in */ struct IEcoCalculatorX* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));
    IEcoUnknown * nonDelegating = (IEcoUnknown *)&pCMe->m_pVTblINondelegatingUnk;
    int16_t result;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    result = nonDelegating->pVTbl->QueryInterface(nonDelegating, riid, ppv);
    if (result != 0 && pCMe->m_pIUnkOuter != 0) {
        result = pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
    }
    return result;
}

uint32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_AddRef(/* in */ struct IEcoCalculatorX* me) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return pCMe->m_pVTblINondelegatingUnk->AddRef((IEcoUnknown *)&pCMe->m_pVTblINondelegatingUnk);
}

uint32_t ECOCALLMETHOD CEcoLab1_IEcoCalculatorX_Release(/* in */ struct IEcoCalculatorX* me) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    return pCMe->m_pVTblINondelegatingUnk->Release((IEcoUnknown *)&pCMe->m_pVTblINondelegatingUnk);
}

int32_t ECOCALLMETHOD CEcoLab1_Addition(/* in */ struct IEcoCalculatorX* me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));
    int32_t result = 0;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pIX != 0) {
        result = pCMe->m_pIX->pVTbl->Addition(pCMe->m_pIX, a, b);
    }

    return result;
}

int16_t ECOCALLMETHOD CEcoLab1_Subtraction(/* in */ struct IEcoCalculatorX* me, /* in */ int16_t a, /* in */ int16_t b) {
    CEcoLab1* pCMe = (CEcoLab1 *)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*));
    int16_t result = 0;

    /* Проверка указателей */
    if (me == 0 ) {
        return -1;
    }

    if (pCMe->m_pIX != 0) {
        result = pCMe->m_pIX->pVTbl->Subtraction(pCMe->m_pIX, a, b);
    }

    return result;
}


// Функция QueryInterface для интерфейса IEcoLab1
int16_t ECOCALLMETHOD CEcoLab1_NondelegatingQueryInterface(/* in */ struct IEcoUnknown * me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*) - sizeof(struct IEcoCalculatorX*));
    int16_t result;
    if (me == 0 || ppv == 0) {
        return -1;
    }
    if ( IsEqualUGUID(riid, &IID_IEcoLab1) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        ++pCMe->m_cRef;
    }
    else if (IsEqualGUID(riid, &IID_IEcoCalculatorY)) {
        *ppv = &pCMe->m_pVTblIY;
        ++pCMe->m_cRef;
    }
    else if (IsEqualGUID(riid, &IID_IEcoCalculatorX)) {
        // передать запрос агрегируемому компоненту B
        if (pCMe->m_pInnerUnknown != 0) {
            // это неделигирующий unknown агрегируемого компонента
            result = pCMe->m_pInnerUnknown->pVTbl->QueryInterface(pCMe->m_pInnerUnknown, riid, ppv);
            return result;
        }
        else {
            *ppv = &pCMe->m_pVTblIX;
            ++pCMe->m_cRef;
        }
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer) ) {
        *ppv = &pCMe->m_pVTblICPC;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblINondelegatingUnk;
        ++pCMe->m_cRef;
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

// Функция AddRef для интерфейса IEcoLab1
uint32_t ECOCALLMETHOD CEcoLab1_NondelegatingAddRef(/* in */ struct IEcoUnknown* me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*) - sizeof(struct IEcoCalculatorX*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

// Функция Release для интерфейса IEcoLab1
uint32_t ECOCALLMETHOD CEcoLab1_NondelegatingRelease(/* in */ struct IEcoUnknown* me) {
    CEcoLab1* pCMe = (CEcoLab1*)((uint64_t)me - sizeof(struct IEcoLab1*) - sizeof(struct IEcoCalculatorY*) - sizeof(struct IEcoCalculatorX*));

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        if (pCMe->m_pInnerUnknown != 0) {
            if (pCMe->m_pInnerUnknown->pVTbl->Release(pCMe->m_pInnerUnknown) == 0) {
                pCMe->m_pInnerUnknown = 0;
            } else {
                pCMe->m_cRef = 1;
            }
        }
        if (pCMe->m_cRef == 0) {
            deleteCEcoLab1((IEcoLab1*)pCMe);
        }
        return 0;
    }
    return pCMe->m_cRef;
}

int16_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_QueryInterface(/* in */ struct IEcoConnectionPointContainer* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1 *pCMe = (CEcoLab1 *) ((uint64_t) me - sizeof(struct IEcoLab1 *) - sizeof(struct IEcoCalculatorY *) -
                                   sizeof(struct IEcoCalculatorX *) - sizeof(struct IEcoUnknown *));
    IEcoUnknown *nonDelegating = (IEcoUnknown *) &pCMe->m_pVTblINondelegatingUnk;
    int16_t result;
    if (me == 0 || ppv == 0) {
        return -1;
    }
    result = nonDelegating->pVTbl->QueryInterface(nonDelegating, riid, ppv);
    if (result != 0 && pCMe->m_pIUnkOuter != 0) {
        result = pCMe->m_pIUnkOuter->pVTbl->QueryInterface(pCMe->m_pIUnkOuter, riid, ppv);
    }
    return result;
}

uint32_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_AddRef(/* in */ struct IEcoConnectionPointContainer* me) {
    CEcoLab1 *pCMe = (CEcoLab1 *) ((uint64_t) me - sizeof(struct IEcoLab1 *) - sizeof(struct IEcoCalculatorY *) -
                                   sizeof(struct IEcoCalculatorX *) - sizeof(struct IEcoUnknown *));
    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return pCMe->m_pVTblINondelegatingUnk->AddRef((IEcoUnknown *)&pCMe->m_pVTblINondelegatingUnk);
}

uint32_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_Release(/* in */ struct IEcoConnectionPointContainer* me) {
    CEcoLab1 *pCMe = (CEcoLab1 *) ((uint64_t) me - sizeof(struct IEcoLab1 *) - sizeof(struct IEcoCalculatorY *) -
                                   sizeof(struct IEcoCalculatorX *) - sizeof(struct IEcoUnknown *));
    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    return pCMe->m_pVTblINondelegatingUnk->Release((IEcoUnknown *)&pCMe->m_pVTblINondelegatingUnk);
}

int16_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_EnumConnectionPoints(/* in */ struct IEcoConnectionPointContainer* me, /* out */ struct IEcoEnumConnectionPoints **ppEnum) {
    CEcoLab1 *pCMe = (CEcoLab1 *) ((uint64_t) me - sizeof(struct IEcoLab1 *) - sizeof(struct IEcoCalculatorY *) -
                                   sizeof(struct IEcoCalculatorX *) - sizeof(struct IEcoUnknown *));
    int16_t result = 0;

    if (me == 0 || ppEnum == 0 ) {
        return -1;
    }

    result = createCEcoLab1EnumConnectionPoints((IEcoUnknown*)pCMe->m_pISys,
                                                (struct IEcoConnectionPoint *) &pCMe->m_pISinkCP->m_pVTblICP, ppEnum);

    return result;
}

int16_t ECOCALLMETHOD CEcoLab1_IEcoConnectionPointContainer_FindConnectionPoint(/* in */ struct IEcoConnectionPointContainer* me, /* in */ const UGUID* riid, /* out */ struct IEcoConnectionPoint **ppCP) {
    CEcoLab1 *pCMe = (CEcoLab1 *) ((uint64_t) me - sizeof(struct IEcoLab1 *) - sizeof(struct IEcoCalculatorY *) -
                                   sizeof(struct IEcoCalculatorX *) - sizeof(struct IEcoUnknown *));
    int16_t result = 0;

    if (me == 0 || ppCP == 0 ) {
        return -1;
    }

    if ( !IsEqualUGUID(riid, &IID_IEcoLab1Events ) ) {
        *ppCP = 0;
        /* CONNECT_E_NOCONNECTION */
        return -1;
    }

    if (pCMe->m_pISinkCP == 0) {
        /* E_FAIL */
        return -1;
    }

    pCMe->m_pISinkCP->m_pVTblICP->AddRef((struct IEcoConnectionPoint *) &pCMe->m_pISinkCP->m_pVTblICP);
    *ppCP = (struct IEcoConnectionPoint *) &pCMe->m_pISinkCP->m_pVTblICP;

    return 0;
}


// Виртуальная таблица методов для IEcoLab1
IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl = {
    CEcoLab1_QueryInterface,
    CEcoLab1_AddRef,
    CEcoLab1_Release,
    CEcoLab1_qsort
};

IEcoCalculatorYVTbl g_xBD6414C29096423EA90C04D77AFD1CADVTblLab1 = {
    CEcoLab1_IEcoCalculatorY_QueryInterface,
    CEcoLab1_IEcoCalculatorY_AddRef,
    CEcoLab1_IEcoCalculatorY_Release,
    CEcoLab1_Multiplication,
    CEcoLab1_Division
};

IEcoCalculatorXVTbl g_x9322111622484742AE0682819447843DVTblLab1 = {
        CEcoLab1_IEcoCalculatorX_QueryInterface,
        CEcoLab1_IEcoCalculatorX_AddRef,
        CEcoLab1_IEcoCalculatorX_Release,
        CEcoLab1_Addition,
        CEcoLab1_Subtraction
};

IEcoUnknownVTbl g_x000000000000000000000000000000AAVTblLab1 = {
        CEcoLab1_NondelegatingQueryInterface,
        CEcoLab1_NondelegatingAddRef,
        CEcoLab1_NondelegatingRelease
};

/* Create Virtual Table IEcoConnectionPointContainer */
IEcoConnectionPointContainerVTbl g_x0000000500000000C000000000000046VTblCPC = {
        CEcoLab1_IEcoConnectionPointContainer_QueryInterface,
        CEcoLab1_IEcoConnectionPointContainer_AddRef,
        CEcoLab1_IEcoConnectionPointContainer_Release,
        CEcoLab1_IEcoConnectionPointContainer_EnumConnectionPoints,
        CEcoLab1_IEcoConnectionPointContainer_FindConnectionPoint
};


// Функция инициализации экземпляра
int16_t ECOCALLMETHOD initCEcoLab1(/*in*/ struct IEcoLab1 * me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoUnknown *pOuterUnknown = (IEcoUnknown *)me;
    int16_t result = -1;

    if (me == 0 ) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    // Пытаемся включить IEcoCalculatorY из CEcoCalculatorD
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorD, 0, &IID_IEcoCalculatorY, (void**) &pCMe->m_pIY);
    if (result != 0 || pCMe->m_pIY == 0) {
        // Если не получилось, то включаем IEcoCalculatorY из CEcoCalculatorE
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorE, 0, &IID_IEcoCalculatorY, (void**) &pCMe->m_pIY);
    }

    // Пытаемся агрегировать CEcoCalculatorB, чтобы иметь доступ к IEcoCalculatorX
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorB, pOuterUnknown, &IID_IEcoUnknown, (void**) &pCMe->m_pInnerUnknown);
    if (result != 0 || pCMe->m_pInnerUnknown == 0) {
        // Если не получилось, то включаем IEcoCalculatorX из CEcoCalculatorA
        result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoCalculatorA, 0, &IID_IEcoCalculatorX, (void**) &pCMe->m_pIX);
    }

    /* Создание точки подключения */
    result = createCEcoLab1ConnectionPoint((IEcoUnknown*)pCMe->m_pISys,
                                           (IEcoConnectionPointContainer *) &pCMe->m_pVTblICPC, &IID_IEcoLab1Events, (IEcoConnectionPoint**)&(pCMe->m_pISinkCP));
    if (result == 0 && pCMe->m_pISinkCP != 0) {
        result = 0;
    }

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
	
    return result;
}

//  Функция создания экземпляра
int16_t ECOCALLMETHOD createCEcoLab1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoLab1 ** ppIEcoLab1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoLab1* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoLab1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoLab1 */
    pCMe->m_pVTblIEcoLab1 = &g_x277FC00C35624096AFCFC125B94EEC90VTbl;

    /* Создание таблицы функций интерфейса IEcoCalculatorY */
    pCMe->m_pVTblIY = &g_xBD6414C29096423EA90C04D77AFD1CADVTblLab1;

    /* Создание таблицы функций интерфейса IEcoCalculatorX */
    pCMe->m_pVTblIX = &g_x9322111622484742AE0682819447843DVTblLab1;

    /* Неделигирующий интерфейс IEcoUnknown */
    pCMe->m_pVTblINondelegatingUnk = &g_x000000000000000000000000000000AAVTblLab1;

    /* Создание таблицы функций интерфейса IEcoConnectionPointContainer */
    pCMe->m_pVTblICPC = &g_x0000000500000000C000000000000046VTblCPC;


    pCMe->m_pIUnkOuter = 0;
    /* Если не агрегируется, использовать неделигирующий интерфейс IEcoUnknown */
    if (pIUnkOuter != 0) {
        pCMe->m_pIUnkOuter = pIUnkOuter;
    } else {
        pCMe->m_pIUnkOuter = (IEcoUnknown*)&pCMe->m_pVTblINondelegatingUnk;
    }

    /* Инициализация данных */
    pCMe->m_Name = 0;

    pCMe->m_pIY = 0;

    pCMe->m_pIX = 0;

    pCMe->m_pInnerUnknown = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoLab1 = (IEcoLab1 *)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

//  Функция освобождения экземпляра
void ECOCALLMETHOD deleteCEcoLab1(/* in */ IEcoLab1* pIEcoLab1) {
    CEcoLab1* pCMe = (CEcoLab1*)pIEcoLab1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoLab1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pIY != 0) {
            pCMe->m_pIY->pVTbl->Release(pCMe->m_pIY);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}