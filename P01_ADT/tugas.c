#include <stdio.h>
#define MAX_SIZE 100
#define EMPTY_VALUE -9999

typedef struct {
    float elements[MAX_SIZE];
    int size;
} TabReal;

// Prosedur createTable
void createTable(TabReal *T) {
    for (int i = 0; i < MAX_SIZE; i++) {
        T->elements[i] = EMPTY_VALUE;
    }
    T->size = 0;
}

// Prosedur AddXTable
void AddXTable(TabReal *T, float X) {
    if (T->size < MAX_SIZE) {
        T->elements[T->size] = X;
        T->size++;
    }
}

// Prosedur searchXTable
int searchXTable(TabReal T, float X) {
    for (int i = 0; i < T.size; i++) {
        if (T.elements[i] == X) {
            return i; // Mengembalikan indeks terkecil
        }
    }
    return -1; // Mengembalikan -1 jika X tidak ditemukan
}

// Prosedur delXTable
void delXTable(TabReal *T, float X) {
    int idx = searchXTable(*T, X);
    if (idx != -1) {
        for (int i = idx; i < T->size - 1; i++) {
            T->elements[i] = T->elements[i + 1];
        }
        T->elements[T->size - 1] = EMPTY_VALUE;
        T->size--;
    }
}

// Prosedur editElmtTable
void editElmtTable(TabReal *T, int idx, float X) {
    if (idx >= 0 && idx < T->size) {
        T->elements[idx] = X;
    }
}

// Fungsi getAverageTable
float getAverageTable(TabReal T) {
    float sum = 0;
    for (int i = 0; i < T.size; i++) {
        sum += T.elements[i];
    }
    return (T.size > 0) ? sum / T.size : 0;
}

// Fungsi getMaxTable
float getMaxTable(TabReal T) {
    float max = T.elements[0];
    for (int i = 1; i < T.size; i++) {
        if (T.elements[i] > max) {
            max = T.elements[i];
        }
    }
    return max;
}

// Fungsi getIdxMaxTable
int getIdxMaxTable(TabReal T) {
    int idxMax = 0;
    for (int i = 1; i < T.size; i++) {
        if (T.elements[i] > T.elements[idxMax]) {
            idxMax = i;
        }
    }
    return idxMax;
}

// Fungsi inverseTable
TabReal inverseTable(TabReal T) {
    TabReal T_inv;
    createTable(&T_inv);
    for (int i = 0; i < T.size; i++) {
        T_inv.elements[i] = T.elements[T.size - 1 - i];
    }
    T_inv.size = T.size;
    return T_inv;
}

// Fungsi countXTable
int countXTable(TabReal T, float X) {
    int count = 0;
    for (int i = 0; i < T.size; i++) {
        if (T.elements[i] == X) {
            count++;
        }
    }
    return count;
}

int main() {
    TabReal T;
    createTable(&T);

    AddXTable(&T, 3.5);
    AddXTable(&T, 7.2);
    AddXTable(&T, 3.5);
    AddXTable(&T, 9.1);

    printf("Rata-rata: %.2f\n", getAverageTable(T));
    printf("Nilai maksimum: %.2f\n", getMaxTable(T));
    printf("Indeks nilai maksimum: %d\n", getIdxMaxTable(T));

    int idx = searchXTable(T, 7.2);
    if (idx != -1) {
        printf("7.2 ditemukan di indeks: %d\n", idx);
    } else {
        printf("7.2 tidak ditemukan\n");
    }

    delXTable(&T, 3.5);
    printf("Setelah menghapus 3.5, rata-rata: %.2f\n", getAverageTable(T));

    TabReal T_inv = inverseTable(T);
    printf("Tabel terbalik: \n");
    for (int i = 0; i < T_inv.size; i++) {
        printf("%.2f ", T_inv.elements[i]);
    }
    printf("\n");

    printf("Jumlah elemen 3.5: %d\n", countXTable(T, 3.5));

    return 0;
}
