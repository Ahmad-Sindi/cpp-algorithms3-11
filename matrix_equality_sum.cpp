#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 * Algorithm Challenge – Level 3 | #11 Matrix Equality Check Using Sum Comparison
 *
 * This program generates two 3×3 matrices filled with random numbers, prints both matrices in a formatted layout, then checks whether the two matrices are equal based on the sum of their elements.
 *
 * Instead of comparing each cell individually, the algorithm compares the total sum of elements in both matrices.
 *
 * This challenge reinforces:
 * - Matrix traversal (rows & columns)
 * - Function decomposition
 * - Random number generation
 * - Logical comparison between data structures
 * - Clean and readable C++ code
 */

// Function to generate a random number within a specific range
int RandNumbr(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Fills a 3x3 matrix with random numbers
void FillMatrxWithRandNums(int arr[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++) // Loop through rows
    {
        for (short j = 0; j < Colms; j++) // Loop through columns
        {
            arr[i][j] = RandNumbr(1, 9); // Assign random value to each cell
        }
    }
}

// Prints the matrix in a formatted way (two-digit format)
void PrintMatrix(int arr[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
        {
            printf(" %0*d ", 2, arr[i][j]);
        }
        cout << endl;
    }
}

// Calculates the sum of all elements in a matrix
int SumOfMatrix(int arr[3][3], short Rows, short Colms)
{
    int Sum = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
        {
            Sum += arr[i][j]; // Accumulate the value of each cell
        }
    }

    return Sum;
}

// Checks if two matrices are equal based on the sum of their elements
bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Colms)
{
    return (SumOfMatrix(Matrix1, Rows, Colms) ==
            SumOfMatrix(Matrix2, Rows, Colms));
}

int main()
{
    srand((unsigned)time(NULL)); // Seed random number generator (run once)

    int Matrix1[3][3], Matrix2[3][3];

    FillMatrxWithRandNums(Matrix1, 3, 3);
    cout << "Matrix 1:\n";
    PrintMatrix(Matrix1, 3, 3);

    FillMatrxWithRandNums(Matrix2, 3, 3);
    cout << "\nMatrix 2:\n";
    PrintMatrix(Matrix2, 3, 3);

    if (AreEqualMatrices(Matrix1, Matrix2, 3, 3))
        cout << "\nYes, Both Matrices are Equal.";
    else
        cout << "\nNo, Matrices are Not Equal.";

    return 0;
}
