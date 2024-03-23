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

// функции сравнения для разных типов

int __cdecl compInts(const void *a_ptr, const void *b_ptr) {
	const int a = *(int *)a_ptr;
	const int b = *(int *)b_ptr;
	return (a > b) - (a < b);
}

int __cdecl compDoubles(const void *a_ptr, const void *b_ptr) {
    double a = *(double *)a_ptr;
    double b = *(double *)b_ptr;
    return (a > b) - (a < b);
}

int __cdecl compFloats(const void *a_ptr, const void *b_ptr) {
    float a = *(float *)a_ptr;
    float b = *(float *)b_ptr;
    return (a > b) - (a < b);
}

int __cdecl compStrings(const void *a_ptr, const void *b_ptr) {
    char *a = *(char **)a_ptr;
    char *b = *(char **)b_ptr;
    return strcmp(a, b);
}

// Функции создания массивов и заполнения элементами

void *createIntArray(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i;
    int *arr = (int *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(int));
    for (i = 0; i < size; i++) {
        arr[i] = rand() %20003 - 10000;
    }
    return arr;
}

void *createFloatArray(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i;
    float *arr = (float *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(float));
    for (i = 0; i < size; i++) {
        arr[i] = ((float) (rand() %20003 - 10000)) / ((float)(rand() % 1000 + 1)) ;
    }
    return arr;
}

void *createDoubleArray(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i;
    double *arr = (double *) pIMem->pVTbl->Alloc(pIMem, size * sizeof(double));
    for (i = 0; i < size; i++) {
        arr[i] = ((double) (rand() %20003 - 10000)) / ((float)(rand() % 1000 + 1)) ;
    }
    return arr;
}

void *createStringArray(IEcoMemoryAllocator1 *pIMem, size_t size) {
    size_t i, j, str_size;
    char **arr = (char **) pIMem->pVTbl->Alloc(pIMem, size * sizeof(char *));
    for (i = 0; i < size; i++) {
        arr[i] = (char *) pIMem->pVTbl->Alloc(pIMem, 20 * sizeof(char));
        str_size = rand() % 14 + 4;
        for (j = 0; j < str_size; ++j) {
            arr[i][j] = (char) (rand() % ('z' - 'a' + 1) + 'a');
        }
        arr[i][str_size] = 0;
    }
    return arr;
}

// Функции удаления массивов

void deleteArray(IEcoMemoryAllocator1 *pIMem, void *arr_ptr, size_t size) {
    pIMem->pVTbl->Free(pIMem, arr_ptr);
}

void deleteStringArray(IEcoMemoryAllocator1 *pIMem, void *arr_ptr, size_t size) {
    size_t i;
    char **arr = (char **) arr_ptr;
    for (i = 0; i < size; ++i) {
        pIMem->pVTbl->Free(pIMem, arr[i]);
    }
    pIMem->pVTbl->Free(pIMem, arr_ptr);
}

// Функции копирования

void *createCopyArray(IEcoMemoryAllocator1 *pIMem, void *src, uint32_t byte_count) {
    void *copy_array = pIMem->pVTbl->Alloc(pIMem, byte_count);
    pIMem->pVTbl->Copy(pIMem, copy_array, src, byte_count);
    return copy_array;
}

void *createCopyStringArray(IEcoMemoryAllocator1 *pIMem, void *src, uint32_t byte_count) {
    char **src_arr = (char **) src;
    char **copy_array = pIMem->pVTbl->Alloc(pIMem, byte_count);
    size_t i, size = byte_count / sizeof(char *);
    for (i = 0; i < size; i++) {
        copy_array[i] = (char *) pIMem->pVTbl->Alloc(pIMem, 20 * sizeof(char));
        pIMem->pVTbl->Copy(pIMem, copy_array[i], src_arr[i], 20);
    }
    return copy_array;
}

// функции вывода массивов на экран

void printIntArray(void *array, size_t size) {
    int *arr = (int *) array;
    size_t i;
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printFloatArray(void *array, size_t size) {
    float *arr = (float *) array;
    size_t i;
    for (i = 0; i < size; ++i) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

void printDoubleArray(void *array, size_t size) {
    double *arr = (double *) array;
    size_t i;
    for (i = 0; i < size; ++i) {
        printf("%lf ", arr[i]);
    }
    printf("\n");
}

void printStringArray(void *array, size_t size) {
    char **arr = (char **) array;
    size_t i;
    for (i = 0; i < size; ++i) {
        printf("'%s' ", arr[i]);
    }
    printf("\n");
}

// Структура для хранения сортировок над разными типами данных

typedef struct sorting {
    void *(*createArray)(IEcoMemoryAllocator1 *pIMem, size_t size);
    int (__cdecl *comp)(const void *a_ptr, const void *b_ptr);
    void (*deleteArray)(IEcoMemoryAllocator1 *pIMem, void *arr_ptr, size_t size);
    void *(*createCopy)(IEcoMemoryAllocator1 *pIMem, void *src, uint32_t byte_count);
    void (*printArray)(void *array_ptr, size_t size);
    size_t elem_size;
    const char *type_name;
} Sorting;

// Сравнение времени работы сортировок

typedef struct sort_result {
    double my_sort;
    double q_sort;
    double my_sort2;
} SortResult;


SortResult testSorting(IEcoMemoryAllocator1 *pIMem, Sorting *sorting, size_t size, IEcoLab1 *lab1rec, IEcoLab1 *lab1iter) {
    uint32_t byte_count = size * sorting->elem_size;
    void *array = sorting->createArray(pIMem, size);
    void *copy_array = sorting->createCopy(pIMem, array, byte_count);
    void *copy2_array = sorting->createCopy(pIMem, array, byte_count);
    clock_t before, after;
    double lab_sort_rec, standard_sort, lab_sort_iter;
    SortResult result;

    before = clock();
    lab1rec->pVTbl->qsort(lab1rec, array, size, sorting->elem_size, sorting->comp);
    after = clock();
    lab_sort_rec = (double)(after - before) / CLOCKS_PER_SEC;
    sorting->deleteArray(pIMem, array, size);

    before = clock();
    qsort(copy_array, size, sorting->elem_size, sorting->comp);
    after = clock();
    standard_sort = (double)(after - before) / CLOCKS_PER_SEC;
    sorting->deleteArray(pIMem, copy_array, size);

    before = clock();
    lab1iter->pVTbl->qsort(lab1iter, copy2_array, size, sorting->elem_size, sorting->comp);
    after = clock();
    lab_sort_iter = (double)(after - before) / CLOCKS_PER_SEC;
    sorting->deleteArray(pIMem, copy2_array, size);


    result.my_sort = lab_sort_rec;
    result.my_sort2 = lab_sort_iter;
    result.q_sort = standard_sort;

    return result;
}

// Вывод сортируемых массивов на экран до и после сортировок

void showSorting(IEcoMemoryAllocator1 *pIMem, Sorting *sorting, IEcoLab1 *lab1Rec, IEcoLab1 *lab1Iter, size_t size) {
    void *array_ptr = sorting->createArray(pIMem, size);
    void *copy_array = sorting->createCopy(pIMem, array_ptr, size * sorting->elem_size);
    void *copy2_array = sorting->createCopy(pIMem, array_ptr, size * sorting->elem_size);

    printf("testing sort for type: %s\n", sorting->type_name);
    printf("array and copies before sort:\n");
    sorting->printArray(array_ptr, size);
    sorting->printArray(copy_array, size);
    sorting->printArray(copy2_array, size);

    lab1Rec->pVTbl->qsort(lab1Rec, array_ptr, size, sorting->elem_size, sorting->comp);
    lab1Iter->pVTbl->qsort(lab1Iter, copy2_array, size, sorting->elem_size, sorting->comp);
    qsort(copy_array, size, sorting->elem_size, sorting->comp);

    printf("array after merge sort(recursive), copy after qsort and another copy after merge sort(iterative):\n");
    sorting->printArray(array_ptr, size);
    sorting->printArray(copy_array, size);
    sorting->printArray(copy2_array, size);
    printf("\n");

    sorting->deleteArray(pIMem, array_ptr, size);
    sorting->deleteArray(pIMem, copy_array, size);
    sorting->deleteArray(pIMem, copy2_array, size);
}

void testAndWriteToFile(FILE *file, IEcoMemoryAllocator1 *pIMem, IEcoLab1 *lab1rec, IEcoLab1 *lab1iter, Sorting *sorting, size_t size) {
    SortResult result = testSorting(pIMem, sorting, size, lab1rec, lab1iter);
    printf("time test:\ttype=%s\tsize=%d done.\n", sorting->type_name, size);
    fprintf(file, "%s,%s,%d,%lf\n", "merge_sort_rec", sorting->type_name, size, result.my_sort);
    fprintf(file, "%s,%s,%d,%lf\n", "merge_sort_iter", sorting->type_name, size, result.my_sort2);
    fprintf(file, "%s,%s,%d,%lf\n", "qsort", sorting->type_name, size, result.q_sort);
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

    Sorting sortByType[4] = {
        {createIntArray, compInts, deleteArray, createCopyArray, printIntArray,sizeof(int), "int"}, // int
        {createFloatArray, compFloats, deleteArray, createCopyArray, printFloatArray, sizeof(float), "float"}, // float
        {createDoubleArray, compDoubles, deleteArray, createCopyArray, printDoubleArray, sizeof(double), "double"}, // double
        {createStringArray, compStrings, deleteStringArray, createCopyStringArray, printStringArray, sizeof(char *), "string"} // string
    };
    FILE * resultFile;
    size_t i, j, sizes[4] = {100000, 500000, 1000000, 3000000};


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

    result = pIEcoLab1Rec->pVTbl->QueryInterface(pIEcoLab1Rec, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result != 0 || pIY == 0) {
        goto Release;
    }

    result = pIEcoLab1Rec->pVTbl->QueryInterface(pIEcoLab1Rec, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result != 0 || pIX == 0) {
        goto Release;
    }

    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1, 0, &IID_IEcoCalculatorY, (void **) &pIY);

    printf("Multiplication test 8 * 8 = %d\n", pIY->pVTbl->Multiplication(pIY, 8, 8));
    printf("Division test 40 / 6 = %d\n", pIY->pVTbl->Division(pIY, 40, 6));

    printf("Addition test 8 + 3 = %d\n", pIX->pVTbl->Addition(pIX, 8, 3));
    printf("Subtraction test 11 - 5 = %d\n", pIX->pVTbl->Subtraction(pIX, 11, 5));

//    // установить начальное состояние для rand()
//    srand(time(0));

//    // Вывести на экран примеры сортировок
//    for (i = 0; i < 4; ++i) {
//        showSorting(pIMem, &sortByType[i], pIEcoLab1Rec, pIEcoLab1Iter, 7);
//    }
//
//    // Измерить время и записать его в файл
//    printf("testing time of algorithms, results in file 'output.csv'\n");
//    fopen_s(&resultFile, "output.csv", "w");
//    fprintf(resultFile, "sort,type,size,time\n");
//    for (i = 0; i < 4; ++i) {
//        for (j = 0; j < 4; j++) {
//            testAndWriteToFile(resultFile, pIMem, pIEcoLab1Rec, pIEcoLab1Iter, &sortByType[j], sizes[i]);
//        }
//    }
//    fclose(resultFile);


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
    
    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

