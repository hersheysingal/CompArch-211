/* 
 * 
 * This code calculates the house price of a house by learing from
 * training data. It uses pseudo inverse of a given matrix to find the 
 * weight of different features.
 * 
 * Predicted Price : Y = W0 + W1*x1 + W2*X2 + W3*X3 + W4*X4
 * Weight Matrix : W = pseudoInv(X)*Y
 * pseudoInv(X) = inverse(transpose(X)*X) * transpose(X)  
 * 
 * weight(w) = pseudoInv(X) * Y
 *          where   X = Input data matrix
 *                  Y = Target vector
 * 
 */
 
#include<stdio.h>
#include<stdlib.h>

// all methods declarations
double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2);
double** transposeMatrix(double** mat, int row, int col);
double** inverseMatrix(double **matA, int dimension);

// main method starts here
int main(int argc, char** argv){

    int k, n;

    FILE *fpTrain = fopen(argv[1], "r");
    if(fpTrain == NULL) {
        printf("File is empty/doesn't exist\n");
        return 0;
    }
    fscanf(fpTrain, "%d\n", &k);
    fscanf(fpTrain, "%d\n", &n);

    double** matX = calloc(n, sizeof(double*));
    for(int i = 0; i < n; i++){
        matX[i] = calloc((k+1), sizeof(double*));
    }
    double** matY = calloc(n, sizeof(double*));
    for(int j = 0; j < n; j++){
        matY[j] = calloc(1, sizeof(double*));
    }

    for(int m = 0; m < n; m++) {
        matX[m][0] = 1;
        for(int v = 0; v < k; v++){
            fscanf(fpTrain, "%lf", &matX[m][v+1]);
        }
        fscanf(fpTrain, "%lf\n", &matY[m][0]);
    }
    
    fclose(fpTrain);

    double** pseudoInv = calloc((k+1), sizeof(double*));
    for(int i = 0; i < n; i++){
        pseudoInv[i] = calloc(n, sizeof(double*));
    }
    pseudoInv = multiplyMatrix((inverseMatrix(multiplyMatrix((transposeMatrix(matX, n, (k+1))), matX, (k+1), n, n, k+1),n)), (transposeMatrix(matX,n,(k+1))), k+1, k+1, k+1, n);

    double** matW = calloc(1, sizeof(double*));
    for(int i = 0; i < n; i++){
        matW[i] = calloc((k+1), sizeof(double*));
    }
    matW = multiplyMatrix(pseudoInv, matY, k+1, n, n, 1);
    
    for(int i = 0; i < n; i++){
        free(matX[i]);
        free(matY[i]);
    }
    free(matX);
    free(matY);
    for(int i = 0; i < n; i++){
        free(pseudoInv[i]);
    }
    free(pseudoInv);

    FILE *fpData = fopen(argv[2], "r");
    if(fpData == NULL) {
        printf("File is empty/doesn't exist\n");
        return 0;
    }

    fscanf(fpData, "%d\n", &n);

    matX = calloc(n, sizeof(double*));
    for(int i = 0; i < n; i++){
        matX[i] = calloc((k+1), sizeof(double*));
    }
    for(int m = 0; m < n; m++) {
        matX[m][0] = 1;
        for(int v = 0; v < k; v++){
            fscanf(fpTrain, "%lf", &matX[m][v+1]);
            if(v != k-1){
                fscanf(fpData, " ");
            }
        }
    }
    fclose(fpData);

    matY = calloc(n, sizeof(double*));
    for(int j = 0; j < n; j++){
        matY[j] = calloc(1, sizeof(double*));
    }

    matY = multiplyMatrix(matX, matW, n, k+1, k+1, 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 1; j++){
            printf("%0.0lf", matX[i][j]);
            if(j != 0){
                printf(" ");
            }
        }
        printf("\n");
    }
    // your code goes here
    
    return 0;
}



double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2)
{
    double** result = calloc(r1, sizeof(double*)); 
    for(int j = 0; j < r1; j++){
        result[j] = calloc(c2, sizeof(double*));
    }
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            for(int k = 0; k < c1; k++){
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }

    }
    // your code goes here
    return result;
}




double** transposeMatrix(double** mat, int row, int col)
{
    double** matTran = calloc(col, sizeof(double*)); 
    int c;
    for(c = 0; c < col; c++)
    {
        matTran[c] = calloc(row, sizeof(double*));
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            matTran[j][i] = mat[i][j];
        }
    }
    // your code goes here
    return matTran;        
}




double** inverseMatrix(double **matA, int dimension)
{

    double** matI=calloc(dimension, sizeof(double*)); 
    int c;
    for(c = 0; c < dimension; c++)   
    {
        matI[c] = calloc(dimension, sizeof(double*));
    }    
    
    for(int i = 1; i <= dimension; i++){
        for(int j = 1; j<= dimension; j++){
            if(i == j){
                matI[i][j + dimension] = 1;
            }
            else{
                matI[i][j + dimension] = 0;
            }
        }
    }

    double f;
    for(int p = 0; p < dimension; p++){
        f = matA[p][p];
        for(int a = 0; a < dimension; a++){
            matA[p][a] = matA[p][a]/f;
            matI[p][a] = matI[p][a]/f;
        }
        for(int i = p + 1; i < dimension; i++){
            f = matA[i][p];
            for(int j = 0; j < dimension; j++){
                matA[i][j] = matA[i][j] - (matA[p][j] *f);
                matI[i][j] = matI[i][j] - (matI[p][j] *f);
            }
        }
    }
    int i;
    for(int p = dimension-1; p < dimension; p++){
        for(i = p - 1; i < dimension; i++){
            f = matA[i][p];
            for(int q = 0; q < dimension; q++){
                matA[i][q] = matA[i][q] - (matA[p][q] *f);
                matI[i][q] = matI[i][q] - (matI[p][q] *f);
            }

        }
    }
    // your code goes here
    
    return matI;
}

