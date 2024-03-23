#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoLab1Iterative.h"


// Функция QueryInterface для интерфейса IEcoLab1
int16_t ECOCALLMETHOD CEcoLab1Iterative_QueryInterface(/* in */ struct IEcoLab1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1Iterative* pCMe = (CEcoLab1Iterative*)me;
    if (me == 0 || ppv == 0) {
        return -1;
    }
    if ( IsEqualUGUID(riid, &IID_IEcoLab1) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

// Функция AddRef для интерфейса IEcoLab1
uint32_t ECOCALLMETHOD CEcoLab1Iterative_AddRef(/* in */ struct IEcoLab1* me) {
    CEcoLab1Iterative* pCMe = (CEcoLab1Iterative*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

// Функция Release для интерфейса IEcoLab1
uint32_t ECOCALLMETHOD CEcoLab1Iterative_Release(/* in */ struct IEcoLab1* me) {
    CEcoLab1Iterative* pCMe = (CEcoLab1Iterative*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoLab1Iterative((IEcoLab1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

// Копирует заданное число байт
void copy_bytes(const char *src, char *dst, size_t count) {
    const char *end = src + count;
    while (src < end) {
        *(dst++) = *(src++);
    }
}

char *min_ptr(char *a_ptr, char *b_ptr) {
    if (a_ptr < b_ptr) {
        return a_ptr;
    } else {
        return b_ptr;
    }
}

// реализация сортировки слиянием с использованием внешнего буфера для организации слияния

void merge_sort(
        char *data_ptr,
        size_t elem_count,
        size_t elem_size,
        int (__cdecl *comp)(const void *, const void *),
        char *buffer
) {
    size_t cur_part_size = elem_size;
    size_t byte_count = elem_size * elem_count;
    size_t diff;
    char *left_ptr, *middle_ptr, *right_ptr, *end_ptr, *start_ptr;
    char *data_end_ptr = data_ptr + byte_count;
    char *cur_buffer;

    // while one part is smaller than whole array keep merging
    while (cur_part_size < byte_count) {
        left_ptr = data_ptr;
        while (left_ptr + cur_part_size < data_end_ptr) {
            // define current parts
            start_ptr = left_ptr;
            right_ptr = left_ptr + cur_part_size;
            middle_ptr = right_ptr;
            end_ptr = min_ptr(right_ptr + cur_part_size, data_end_ptr);

            // merge using buffer
            cur_buffer = buffer;
            while (left_ptr < middle_ptr && right_ptr < end_ptr) {
                int comp_res = comp(left_ptr, right_ptr);
                if (comp_res <= 0) {
                    copy_bytes(left_ptr, cur_buffer, elem_size);
                    left_ptr += elem_size;
                } else {
                    copy_bytes(right_ptr, cur_buffer, elem_size);
                    right_ptr += elem_size;
                }
                cur_buffer += elem_size;
            }

            diff = middle_ptr - left_ptr;
            copy_bytes(left_ptr, cur_buffer, diff);
            cur_buffer += diff;

            diff = end_ptr - right_ptr;
            copy_bytes(right_ptr, cur_buffer, diff);
            cur_buffer += diff;

            // copy sorted part back form buffer
            diff = end_ptr - start_ptr;
            copy_bytes(buffer, start_ptr, diff);

            // go to next parts to merge
            left_ptr = end_ptr;
        }
        // merge larger parts
        cur_part_size *= 2;
    }
}


// Функция сортировка слиянием, использует сигнатуру qsort.
// Выделяет буфер памяти через интерфейс IEcoMemoryAllocator1
int16_t ECOCALLMETHOD CEcoLab1Iterative_qsort(
        struct IEcoLab1* me,
        void* pData,
        size_t elem_count,
        size_t elem_size,
        int (__cdecl *comp)(const void *, const void*)
) {
    CEcoLab1Iterative* pCMe = (CEcoLab1Iterative*)me;
    void *buffer;

    /* Проверка указателей */
    if (me == 0 || pData == 0 || comp == 0) {
        return -1;
    }

    // 1. allocate memory for buffer
    buffer = pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, elem_count * elem_size);

    // 2. sort with buffer
    merge_sort(pData, elem_count, elem_size, comp, buffer);

    // 3. free buffer memory
    pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, buffer);

    return 0;
}

// Виртуальная таблица методов для IEcoLab1
IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl = {
        CEcoLab1Iterative_QueryInterface,
        CEcoLab1Iterative_AddRef,
        CEcoLab1Iterative_Release,
        CEcoLab1Iterative_qsort
};


// Функция инициализации экземпляра
int16_t ECOCALLMETHOD initCEcoLab1Iterative(/*in*/ struct IEcoLab1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoLab1Iterative* pCMe = (CEcoLab1Iterative*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return result;
}

//  Функция создания экземпляра
int16_t ECOCALLMETHOD createCEcoLab1Iterative(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoLab1** ppIEcoLab1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoLab1Iterative* pCMe = 0;
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
    pCMe = (CEcoLab1Iterative*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1Iterative));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoLab1 */
    pCMe->m_pVTblIEcoLab1 = &g_x277FC00C35624096AFCFC125B94EEC90VTbl;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoLab1 = (IEcoLab1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

//  Функция освобождения экземпляра
void ECOCALLMETHOD deleteCEcoLab1Iterative(/* in */ IEcoLab1* pIEcoLab1) {
    CEcoLab1Iterative* pCMe = (CEcoLab1Iterative*)pIEcoLab1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoLab1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}