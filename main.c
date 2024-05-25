#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    unsigned int flatNum;
    int type;
    char surname[21];
    char name[21];
    char middleName[21];
    unsigned int debtsUtilityBills;
    unsigned int amountResidents;
} flat;

void printArray(flat*, long);
flat* genArray(long);
void insertSort(flat*, long, char);
void mergeSort(flat*, long, char);
void heapSort(flat*, long, char);
void checkSort(const char*,void (*sort)(flat*, long, char), flat*, long, char);

int main() {
    char work;
    do {
        long n;
        printf("Enter array's length: ");
        scanf("%ld", &n);
        flat *a;
        a = genArray(n);
        printf("If you want to print generated arrays enter [1], if don't - [0]: ");
        getchar();
        char p;
        scanf("%c", &p);
        if (p == '1') {
            printf("The generated array:\n");
            printArray(a, n);
        }
        printf("Enter a number for:\n"
               "insert sort - [1]\n"
               "merge sort - [2]\n"
               "heap sort - [3]: ");
        char sw;
        getchar();
        scanf("%c", &sw);
        printf("Enter a number for:\n"
               "sort from min to max - [1]\n"
               "sort from max to min - [2]: ");
        char sw1;
        getchar();
        scanf("%c", &sw1);
        switch (sw) {
            case '1':
                if (sw1 == '1' || sw1 == '2') {
                    checkSort("Insert sort", insertSort, a, n, sw1);
                }
                else {
                    printf("You entered not right number your array wasn't sorted.");
                }
                break;
            case '2':
                if (sw1 == '1' || sw1 == '2') {
                    checkSort("Merge sort", mergeSort, a, n, sw1);
                }
                else {
                    printf("You entered not right number your array wasn't sorted.");
                }
                break;
            case '3' :
                if (sw1 == '1' || sw1 == '2') {
                    checkSort("Heap sort", heapSort, a, n, sw1);
                }
                else {
                    printf("You entered not right number your array wasn't sorted.\n");
                }
                break;
            default:
                printf("You entered wrong letter.\n");
        }
        printf("If you want to print sorted arrays enter [1], if don't - [0]: ");
        getchar();
        scanf("%c", &p);
        if (p == '1') {
            printf("Sorted array:\n");
            printArray(a, n);
        }
        free(a);
        printf("If you want to continue - [1], to end the programme enter - [0]: ");
        getchar();
        scanf("%c", &work);
    } while (work == '1');
    return 0;
}

void printArray(flat *a, long n) {
    for (int i = 0; i < n; ++i) {
        printf("%d\n", i);
        printf("num %u\t", a[i].flatNum);
        printf("t %d\t", a[i].type);
        printf("s %s\t", a[i].surname);
        printf("n %s\t", a[i].name);
        printf("m %s\t", a[i].middleName);
        printf("d %u\t", a[i].debtsUtilityBills);
        printf("a %u\t", a[i].amountResidents);
        printf("\n");
    }
}

flat* genArray(long n) {
    flat *x = (flat*)malloc(n * sizeof(flat));
    if (!x) return NULL;
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        x[i].flatNum = rand()%300;
        x[i].type = rand() % 4;
        for(int j = 0; j < 20; ++j) {
            x[i].surname[j] = rand()%26+'A';
        }
        for(int j = 0; j < 20; ++j) {
            x[i].name[j] = rand()%26+'A';
        }
        for(int j = 0; j < 20; ++j) {
            x[i].middleName[j] = rand()%26+'A';
        }
        x[i].debtsUtilityBills = rand()%10000;
        x[i].amountResidents = rand()%10;
    }
    return x;
}

int cmpFlats1(flat tmp1, flat tmp2) { //if the first is bigger, return 1
    if (tmp1.flatNum > tmp2.flatNum) return 1;
    else if (tmp1.flatNum == tmp2.flatNum) {
        if (tmp1.type > tmp2.type) return 1;
        else if (tmp1.type == tmp2.type) {
            if (strcmp(tmp1.surname, tmp2.surname) > 0) return 1;
            else if (!strcmp(tmp1.surname, tmp2.surname)) {
                if (strcmp(tmp1.name, tmp2.name) > 0) return 1;
                else if (!strcmp(tmp1.name, tmp2.name)) {
                    if (strcmp(tmp1.middleName, tmp2.middleName) > 0) return 1;
                    else if (!strcmp(tmp1.middleName, tmp2.middleName)) {
                        if (tmp1.debtsUtilityBills > tmp2.debtsUtilityBills) return 1;
                        else if (tmp1.debtsUtilityBills == tmp2.debtsUtilityBills) {
                            if (tmp1.amountResidents > tmp2.amountResidents) return 1;
                            else return 0;
                        }
                        else return 0;
                    }
                    else return 0;
                }
                else return 0;
            }
            else return 0;
        }
        else return 0;
    }
    else return 0;
}

int cmpFlats2(flat tmp1, flat tmp2) { //if the first is bigger, return 1
    if (tmp1.flatNum >= tmp2.flatNum) return 1;
    else if (tmp1.flatNum == tmp2.flatNum) {
        if (tmp1.type >= tmp2.type) return 1;
        else if (tmp1.type == tmp2.type) {
            if (strcmp(tmp1.surname, tmp2.surname) >= 0) return 1;
            else if (!strcmp(tmp1.surname, tmp2.surname)) {
                if (strcmp(tmp1.name, tmp2.name) >= 0) return 1;
                else if (!strcmp(tmp1.name, tmp2.name)) {
                    if (strcmp(tmp1.middleName, tmp2.middleName) >= 0) return 1;
                    else if (!strcmp(tmp1.middleName, tmp2.middleName)) {
                        if (tmp1.debtsUtilityBills >= tmp2.debtsUtilityBills) return 1;
                        else if (tmp1.debtsUtilityBills == tmp2.debtsUtilityBills) {
                            if (tmp1.amountResidents >= tmp2.amountResidents) return 1;
                            else return 0;
                        }
                        else return 0;
                    }
                    else return 0;
                }
                else return 0;
            }
            else return 0;
        }
        else return 0;
    }
    else return 0;
}

void insertSort(flat *a, long n, char sw1) {
    int i, j;
    flat tmp;
    switch (sw1) {
        case '1':
            for (i = 0; i < n; ++i) {
                tmp = a[i];
                for (j = i - 1; j >= 0 && cmpFlats1(a[j], tmp); --j) {
                    a[j + 1] = a[j];
                }
                a[j + 1] = tmp;
            }
            break;
        case'2':
            for (i = 0; i < n; ++i) {
                tmp = a[i];
                for (j = i - 1; j >= 0 && !cmpFlats1(a[j], tmp); --j) {
                    a[j + 1] = a[j];
                }
                a[j + 1] = tmp;
            }
    }
}

void merge(flat *a, int low, int mid, int high, char sw1){
    flat *b = (flat*)malloc((high + 1 - low) * sizeof(flat));
    int h, i, j, k;
    h = low;
    i = 0;
    j = mid + 1;
    switch (sw1) {
        case '1':
            while((h <= mid) && (j <= high)) {
                if(cmpFlats2(a[j], a[h])) {
                    b[i] = a[h];
                    h++;
                }
                else {
                    b[i]=a[j];
                    j++;
                }
                i++;
            }
            break;
        case '2':
            while((h <= mid) && (j <= high)) {
                if(cmpFlats2(a[h], a[j])) {
                    b[i] = a[h];
                    h++;
                }
                else {
                    b[i]=a[j];
                    j++;
                }
                i++;
            }
            break;
    }
    if(h > mid) {
        for(k = j; k <= high; k++) {
            b[i] = a[k];
            i++;
        }
    }
    else{
        for(k = h ; k <= mid; k++) {
            b[i] = a[k];
            i++;
        }
    }
    for(k = 0; k <= high - low; k++) {
        a[k + low] = b[k];
    }
    free(b);
}

void mergeSort1(flat *a, long low, long high, char sw1) {
    long mid;
    if(low<high) {
        mid = (low+high)/2;
        mergeSort1(a, low, mid, sw1);
        mergeSort1(a, mid+1,high, sw1);
        merge(a, low, mid, high, sw1);
    }
}

void mergeSort(flat* a, long n, char sw1) {
    long low = 0;
    long high = n - 1;
    mergeSort1(a, low, high, sw1);
}

void downHeap(flat *a, long k, long n, char sw1) {
    long child;
    flat new_elem = a[k];
    switch (sw1) {
        case '1':
            while (k <= n / 2) {
                child = 2 * k;
                if (child < n && cmpFlats2(a[child + 1], a[child])) {
                    child++;
                }
                if (cmpFlats2(new_elem, a[child])) {
                    break;
                }
                a[k] = a[child];
                k = child;
            }
            break;
        case '2':
            while (k <= n / 2) {
                child = 2 * k;
                if (child < n && cmpFlats2(a[child], a[child + 1])) {
                    child++;
                }
                if (cmpFlats2(a[child], new_elem)) {
                    break;
                }
                a[k] = a[child];
                k = child;
            }
            break;
    }
    a[k] = new_elem;
}

void heapSort(flat *a, long size, char sw1) {
    long i;
    flat tmp;
    for(i = size/2; i >= 0; i--)
    {
        downHeap(a, i, size-1, sw1);
    }
    for(i = size-1; i > 0; i--)
    {
        tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;
        downHeap(a, 0, i-1, sw1);
    }
}

void checkSort(const char *algName ,void (*sort)(flat *a, long n, char sw1), flat *a, long n, char sw1) {
    const char *typeSort;
    if (sw1 == '1') {
       typeSort = "from min to max";
    }
    if (sw1 == '2') {
        typeSort = "from max to min";
    }
    clock_t t1 = clock();
    sort(a, n, sw1);
    clock_t t2 = clock();
    double sortTime = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("%s %s time for array of %li elements in seconds %.6lf\n", algName, typeSort, n, sortTime);
}