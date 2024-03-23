/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoLab1.h"
#include "IdEcoLab1Iterative.h"
#include "IEcoCalculatorY.h"
#include "IdEcoCalculatorD.h"
#include "IEcoCalculatorX.h"
#include "IdEcoCalculatorE.h"
#include <stdio.h>
#include <stdlib.h>


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

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1Iterative, 0, &IID_IEcoLab1, (void**) &pIEcoLab1Iter);
    if (result != 0 || pIEcoLab1Iter == 0) {
        goto Release;
    }

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

    printf("Addition test 8 + 3 = %d\n", pIX->pVTbl->Addition(pIX, 8, 3));
    printf("Subtraction test 11 - 5 = %d\n", pIX->pVTbl->Subtraction(pIX, 11, 5));

    printf("\nCheck Interface properties:\n");

    result = pIEcoLab1Rec->pVTbl->QueryInterface(pIEcoLab1Rec, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result == 0) {
        printf("Able to Query IX from ILab1\n");
    }
    result = pIEcoLab1Rec->pVTbl->QueryInterface(pIEcoLab1Rec, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result == 0) {
        printf("Able to Query IY from ILab1\n");
    }
    result = pIEcoLab1Rec->pVTbl->QueryInterface(pIEcoLab1Rec, &IID_IEcoLab1, (void **) &pIEcoLab1Rec);
    if (result == 0) {
        printf("Able to Query ILab1 from ILab1\n");
    }

    result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result == 0) {
        printf("Able to Query IX from IX\n");
    }
    result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result == 0) {
        printf("Able to Query IY from IX\n");
    }
    result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoLab1, (void **) &pIEcoLab1Rec);
    if (result == 0) {
        printf("Able to Query ILab1 from IX\n");
    }

    result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result == 0) {
        printf("Able to Query IX from IY\n");
    }
    result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result == 0) {
        printf("Able to Query IY from IY\n");
    }
    result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoLab1, (void **) &pIEcoLab1Rec);
    if (result == 0) {
        printf("Able to Query ILab1 from IY\n");
    }

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
    if (pIEcoLab1Rec != 0) {
        pIEcoLab1Rec->pVTbl->Release(pIEcoLab1Iter);
    }
    
    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

