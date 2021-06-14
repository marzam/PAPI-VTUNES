#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <climits>
#include <cstring>
#include <string>
#include <cstdint>
#include <System.hpp>
#define EPSILON 1E-15
#define ERROR 1E-20
using namespace std;

struct stMatrix{
    double *A;
    double *B;
    double *X0;
    double *X1;
    int64_t mn;
};

void JacobiMethod(stMatrix *matrix){

   double aux, 
         div, 
         err = 0.0;
   int inter = 0;
   
   do{
         for (int j = 0; j < matrix->mn; j++){
            aux    = 0.0;
            div    = 0.0;
            
            for (int i = 0; i < matrix->mn; i++){
              if (j != i)
//                  aux += ((matrix->A[matrix->mn * j + i] * matrix->X0[i]) * -1.0);
                  aux += (matrix->A[matrix->mn * j + i] * matrix->X0[i]);
               else
                  div =  matrix->A[matrix->mn * j + i];
            }
            matrix->X1[j] = ((matrix->B[j] - aux) / div );
         }

         err = fabs((matrix->X1[0] - matrix->X0[0]) / (matrix->X1[0] + EPSILON));
         for (int j = 1; j < matrix->mn; j++){
            double b = fabs((matrix->X1[j] - matrix->X0[j]) / (matrix->X1[j] + EPSILON));
             err = max(err, b);   
         }

         double *swap = matrix->X0;
         matrix->X0 = matrix->X1;
         matrix->X1 = swap; 
         inter++;
   
       
   }while (err > ERROR);
   cout << err << "\t" << inter << endl;
   

}


void printMatrix(stMatrix matrix){
  cout << setfill(' ') << setw(16) << left << fixed << setprecision(6) << endl;
  for (int j = 0; j < matrix.mn; j++){
    for (int i = 0; i < matrix.mn; i++){
      int p = j * matrix.mn + i;
      cout << " " <<  matrix.A[p];
    }
    cout << "\t|"<< matrix.B[j] << "\t|"<< matrix.X0[j];
    cout << endl;
    
  }
}

int main (int ac, char **av){
    stMatrix matrix;
    int64_t mAlign = 64;
    matrix.mn = 10;
    posix_memalign(reinterpret_cast <void**>(&matrix.A), mAlign, sizeof(int64_t) * matrix.mn * matrix.mn);
    posix_memalign(reinterpret_cast <void**>(&matrix.B), mAlign, sizeof(int64_t) * matrix.mn);
    posix_memalign(reinterpret_cast <void**>(&matrix.X0), mAlign, sizeof(int64_t) * matrix.mn);
    posix_memalign(reinterpret_cast <void**>(&matrix.X1), mAlign, sizeof(int64_t) * matrix.mn);
    for (int i = 1; i < matrix.mn - 1; i++){
    int p = i *  matrix.mn + i;
        matrix.A[i *  matrix.mn + i]   = 7.283034000000000;
        matrix.A[i *  matrix.mn + i-1] = -3.141517000000000;
        matrix.A[i *  matrix.mn + i+1] = -3.141517000000000;
        matrix.B[i] = 150.00;
    
    }
    matrix.B[0] = 200.0;
    matrix.B[matrix.mn - 1] = 0.0;
    matrix.A[0] =   7.283034000000000;
    matrix.A[1] = -3.141517000000000;
    matrix.A[matrix.mn * matrix.mn - 1] =  7.283034000000000;
    matrix.A[matrix.mn * matrix.mn - 2] = -3.141517000000000;
    memset(matrix.X0, 0x00, sizeof(int64_t) * matrix.mn);
    memset(matrix.X1, 0x00, sizeof(int64_t) * matrix.mn);
    
    printMatrix(matrix);
    JacobiMethod(&matrix);
    printMatrix(matrix);
    
    
    cout << "   Alinhamento: " << mAlign << endl;
    cout << "Bytes alocados: "<< (sizeof(int64_t) * matrix.mn * matrix.mn) + (3 * sizeof(int64_t) * matrix.mn) << endl;

    free(matrix.A);
    free(matrix.B);
    free(matrix.X0);
    free(matrix.X1);
    return EXIT_SUCCESS;
}
