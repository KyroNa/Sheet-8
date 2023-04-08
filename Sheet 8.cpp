

#include <iostream>
#include <string.h>
using namespace std;

void addm(float A[][3], float B[][3], float C[][3],int);
void subm(float A[][3], float B[][3], float C[][3],int);

void printm(float A[][3], int, int);

void multm(float A[][3], float B[][3], float C[][3], int);

void tram(float A[][3], float B[][3], int);

float sumdiag(float A[][3], int);

int nonzero(float A[][3], int);

float proddiag(float A[][3], int);

int main()
{
    /*
    // Problem 1 & 2
    
    const int N = 3;
    const int M = 100;
    char names[N][M];

    cout << "Insert the names of the students\n";
    for (int i = 0; i < N; i++)
    {
        
        cin.getline(names[i], M);
        
    }
    cout << endl;
    cout << "The names inserted are:\n";
    for (int i = 0; i < N; i++)
    {
        cout << names[i] << "\n";
    }
    cout << endl;

    // Sorting names
    char temp[M];
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int n = 0; n < M; n++)
            {
                if(names[i][n] < names[j][n])
                    break;
                if (names[i][n] > names[j][n]) 
                {
                    strcpy_s(temp, names[i]);
                    strcpy_s(names[i], names[j]);
                    strcpy_s(names[j], temp);
                    break;
                }
            }
           
        }
    }

    cout << "The names arranged are:\n";
    for (int i = 0; i < N; i++)
    {
        cout << names[i] << "\n";
    }
    */

    /*
    //Problem 2 & 3 & 4 & 5 & 6 & 7 
    float A [3][3] = {{1,2,3},{1,2,3},{1,2,3}};
    float B [3][3] = {{1,2,3},{1,2,3},{1,2,3}};

    cout << "Array A: \n"; 
    printm(A, 3, 3);
    cout << "Array B: \n";
    printm(B, 3, 3);

    float C[3][3];
    addm(A, B, C, 3);
    cout << "the sum: \n";
    printm(C, 3, 3);

    subm(A, B, C, 3);
    cout << "the sub: \n";
    printm(C, 3, 3);

    multm(A, B, C, 3);
    cout << "the mul: \n";
    printm(C, 3, 3);

    tram(A, C, 3);
    cout << "the tran: \n";
    printm(C, 3, 3);

    
    cout << "\nSum of the diagonals of matrix A: " << sumdiag(A, 3) << "\n";
    cout << "Product of the diagonals of matrix A: " << proddiag(A, 3) << "\n";
    cout << "Number of nonzero elements of matrix A: " << nonzero(A, 3) << "\n";
    */

    //Problem 8
    //I will create a 10 * 10 array to show that the code works 
    const int N = 10;
    const int M = 10;
    float RndArr[N][M];
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            RndArr[i][j] = 1 + rand() % 1000;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << RndArr[i][j] << "\t";
        cout << "\n";
    }

    int count = 0;
    

    for (int i = 1; i < N-1; i++)
    {
        for (int j = 1; j < M-1; j++)
        {
            int around = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (RndArr[k][l] < RndArr[i][j])
                        around++;
                }
            }
            if (around == 8)
                count++;
        }
    }

    cout << "Number of values where All 8 neighbors values are less than the center value are " << count << "\n";

}

void addm(float A[][3], float B[][3], float C[][3],int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
    }
}

void subm(float A[][3], float B[][3], float C[][3], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] - B[i][j];
    }
}

void printm(float A[][3], int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
           cout << A[i][j] << "\t";
        cout << "\n";
    }
}

void multm(float A[][3], float B[][3], float C[][3], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            float sum = 0;
            for(int k = 0; k < 3; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void tram(float A[][3], float B[][3], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
            B[i][j] = A[j][i];
    }
}

float sumdiag(float A[][3], int N)
{
    float sum = 0;
  
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                sum += A[i][j];
        }
    }
    return sum;
}

int nonzero(float A[][3], int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (A[i][j] != 0)
                count++;
        }
    }
    return count;
}

float proddiag(float A[][3], int N)
{
    float product = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                product *= A[i][j];
        }
    }
    return product;
}