void populateMatriks(Matriks *M, int x, int y){
    (*M).nbaris = x;
    (*M).nkolom = y;
    for (int i = 0; i <= x; i++){
        for (int j = 0; j <= y; j++){
            printf("Masukkan elemen ke [%d][%d]: ",i,j);
            scanf("%d", &(*M).cell[i][j]);
        }
    }
}