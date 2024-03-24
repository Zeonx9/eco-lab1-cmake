/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"

#include "IdEcoLab1.h"
#include "IdEcoLab1Iterative.h"

#include "IEcoCalculatorY.h"
#include "IEcoCalculatorX.h"

#include "IdEcoLab2.h"

#include <stdio.h>

int __cdecl compInts(const void *a_ptr, const void *b_ptr) {
    const int a = *(int *)a_ptr;
    const int b = *(int *)b_ptr;
    return (a > b) - (a < b);
}


void *createIntArray(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i;
    int *arr = (int *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(int));
    for (i = 0; i < size; i++) {
        arr[i] = rand() %20003 - 10000;
    }
    return arr;
}

void printIntArray(void *array, size_t size) {
    int * arr = (int *) array;
    size_t i;
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// Функция EcoMain - точка входа
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoLab1* pIEcoLab1Rec = 0;
    IEcoLab1* pIEcoLab1Iter = 0;
    IEcoCalculatorY* pIY = 0;
    IEcoCalculatorX* pIX = 0;

    IEcoLab1* pIEcoLab2 = 0;
    void *testArr = 0;
    size_t testSize = 10;

    /* Проверка и создание системного интерфейса */
    result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
    if (result != 0 && pISys == 0) {
        goto Release;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        goto Release;
    }

    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);
    if (result != 0 || pIMem == 0) {
        goto Release;
    }

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1, 0, &IID_IEcoLab1, (void**) &pIEcoLab1Rec);
    if (result != 0 || pIEcoLab1Rec == 0) {
        goto Release;
    }
    printf("queried IEcoLab1 component\n");

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1Iterative, 0, &IID_IEcoLab1, (void**) &pIEcoLab1Iter);
    if (result != 0 || pIEcoLab1Iter == 0) {
        goto Release;
    }
    printf("queried IEcoLab1Iterative component\n\n");

    /* запрос интерфейса IEcoCalculatorY через IEcoLab1 */
    result = pIEcoLab1Rec->pVTbl->QueryInterface(pIEcoLab1Rec, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result != 0 || pIY == 0) {
        goto Release;
    }

    /* запрос интерфейса IEcoCalculatorX через IEcoLab1 */
    result = pIEcoLab1Rec->pVTbl->QueryInterface(pIEcoLab1Rec, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result != 0 || pIX == 0) {
        goto Release;
    }

    printf("Multiplication test 8 * 8 = %d\n", pIY->pVTbl->Multiplication(pIY, 8, 8));
    printf("Division test 40 / 6 = %d\n", pIY->pVTbl->Division(pIY, 40, 6));
    pIY->pVTbl->Release(pIY);

    printf("Addition test 8 + 3 = %d\n", pIX->pVTbl->Addition(pIX, 8, 3));
    printf("Subtraction test 11 - 5 = %d\n", pIX->pVTbl->Subtraction(pIX, 11, 5));
    pIX->pVTbl->Release(pIX);

    printf("\nCheck Interface properties:\n");

    result = pIEcoLab1Rec->pVTbl->QueryInterface(pIEcoLab1Rec, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result == 0) {
        printf("Able to Query IX from ILab1\n");
        pIX->pVTbl->Release(pIX);
    }
    result = pIEcoLab1Rec->pVTbl->QueryInterface(pIEcoLab1Rec, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result == 0) {
        printf("Able to Query IY from ILab1\n");
        pIY->pVTbl->Release(pIY);
    }
    result = pIEcoLab1Rec->pVTbl->QueryInterface(pIEcoLab1Rec, &IID_IEcoLab1, (void **) &pIEcoLab1Rec);
    if (result == 0) {
        printf("Able to Query ILab1 from ILab1\n");
        pIEcoLab1Rec->pVTbl->Release(pIEcoLab1Rec);
    }

    result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result == 0) {
        printf("Able to Query IX from IX\n");
        pIX->pVTbl->Release(pIX);
    }
    result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result == 0) {
        printf("Able to Query IY from IX\n");
        pIY->pVTbl->Release(pIY);
    }
    result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoLab1, (void **) &pIEcoLab1Rec);
    if (result == 0) {
        printf("Able to Query ILab1 from IX\n");
        pIEcoLab1Rec->pVTbl->Release(pIEcoLab1Rec);
    }

    result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result == 0) {
        printf("Able to Query IX from IY\n");
        pIX->pVTbl->Release(pIX);
    }
    result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result == 0) {
        printf("Able to Query IY from IY\n");
        pIY->pVTbl->Release(pIY);
    }
    result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoLab1, (void **) &pIEcoLab1Rec);
    if (result == 0) {
        printf("Able to Query ILab1 from IY\n");
        pIEcoLab1Rec->pVTbl->Release(pIEcoLab1Rec);
    }

    printf("\nTest sorting interface queried from aggregated component:\n");
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab2, 0, &IID_IEcoLab1, (void**) &pIEcoLab2);
    if (result == 0) {
        printf("queried IEcoLab1 interface aggregated by CEcoLab2\n");
    }

    testArr = createIntArray(pIMem, testSize);
    printIntArray(testArr, testSize);

    pIEcoLab2->pVTbl->qsort(pIEcoLab2, testArr, testSize, sizeof(int), compInts);

    printIntArray(testArr, testSize);

    pIMem->pVTbl->Free(pIMem, testArr);


Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIEcoLab1Rec != 0) {
        pIEcoLab1Rec->pVTbl->Release(pIEcoLab1Rec);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIEcoLab1Iter != 0) {
        pIEcoLab1Iter->pVTbl->Release(pIEcoLab1Iter);
    }

    if (pIEcoLab2 != 0) {
        pIEcoLab2->pVTbl->Release(pIEcoLab2);
    }
    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

