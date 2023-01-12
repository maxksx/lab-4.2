#include <stdio.h>
#include <stdlib.h>
// Прототипи
void fill_int_array( unsigned int * uiptr, unsigned int size_of_array );
void fill_float_array( float * fptr, unsigned int size_of_array );

void fill_int_array_new( unsigned int * uiptr, unsigned int size_of_array );
void fill_float_array_new( float * fptr, unsigned int size_of_array );


void print_int_array( const unsigned int * uiptr, unsigned int size_of_array );
void print_float_array( const float * fptr, unsigned int size_of_array);

void print_int_array( const unsigned int * A2, unsigned int size_of_array );
void print_float_array_new( const float * B2, unsigned int size_of_array );

unsigned int sum ( const unsigned int * uiptr, unsigned int size_of_array );
double product( const float * fptr, unsigned int size_of_array );

double mean_value(const unsigned int * A, unsigned int Size );

unsigned int find_min(const unsigned int * A, unsigned int Size );

float find_max(const float * B, unsigned int Size );

// Опис функції main()
int main()
{
 unsigned int * A;
 float * B;
 unsigned int * A2;
 float * B2;
 unsigned int Size; // Змінна для збережння розміру динамічного масиву
 unsigned int amount; // змінна для збереження суми елементів масиву А
 double mult; // змінна для збереження добутку елементів масиву В
 double average_value;
 unsigned int min_value;
 float max_value;
 printf("Enter size of array: ");
 scanf("%u", &Size);
 A = (unsigned int *) calloc (Size, sizeof(unsigned int) );
 B = (float *) malloc (Size * sizeof(float) );
 A2 = (unsigned int *) calloc (Size, sizeof(unsigned int) );
 B2 = (float *) malloc (Size * sizeof(float) );
 if( A == NULL || B == NULL ){
 printf("Memory has not been allocated");
 exit(0);
 }

 fill_int_array( A, Size );
 fill_float_array( B, Size );
 print_int_array( A, Size );
 print_float_array( B, Size );
 printf("\n\n");
 amount = sum( A, Size );
 mult = product( B, Size );
 average_value = mean_value( A, Size );
 min_value = find_min( A, Size );
 max_value = find_max( B, Size );
 printf("\nSum for A= %u", amount);
 printf("\nProduct for B= %.3lf", mult);
 printf("\nAverage value for A = %.3lf", average_value);
 printf("\nMin value for A = %u", min_value);
 printf("\nMax value for B = %f \n", max_value);
 printf("\n\n");
 printf("\nEnter size of array for A2 and B2 via our formulas: ");
 scanf("%u", &Size);
 printf("\n");
 fill_int_array_new( A2, Size );
 printf("\n");
 fill_float_array_new( B2, Size );
 print_int_array_new( A2, Size );
 printf("\n");
 printf("\n\n");
 print_float_array_new( B2, Size );
 printf("\n");
 free(A);
 free(B);
 free(A2);
 free(B2);
 return 0;
}

//----------------- Опис Функцій ------------------------
//--------------------------------------------------------
void fill_int_array( unsigned int * A, unsigned int Size )
{
 unsigned int j;
 unsigned int temp;
 printf("\n\nEnter values of UNSIGNED INT elements of array.\n");
 for( j = 0; j <= Size-1; j++ ){
 printf("A[%u]= ", j);
 scanf("%u", &temp);
 A[j] = temp;
 }
}
//---------------------------------------------------------
void fill_float_array( float * B, unsigned int Size )
{
 unsigned int j;
 float temp;
 printf("\n\nEnter values of FLOAT elements of array.\n");
 for( j = 0; j <= Size-1; j++ ){
 printf("B[%u]= ", j);
 scanf("%f", &temp);
 B[j] = temp;
 }
}
//-------------------------------------------------------------
void print_int_array( const unsigned int * A, unsigned int Size )
{
 unsigned int j;
 printf("\n\nArray of UNSIGNED INT values:\n");
 for( j = 0; j < Size; j++ )
 printf("%5d", A[j] );
}
//-------------------------------------------------------------
void print_float_array( const float * B, unsigned int Size )
{
 unsigned int j;
 printf("\n\nArray of FLOAT values:\n");
 for( j = 0; j < Size; j++ )
 printf("%7.2f", B[j] );
}
//---------------------------------------------------------------
unsigned int sum (const unsigned int * A, unsigned int Size )
{
 unsigned int j, S;
 S = 0; // змінна, яка використовується для обрахунку значення
// суми елементів масиву
 for( j = 0; j < Size; j++ )
 S += A[j];
 return S;
}
//---------------------------------------------------------------
double product(const float * B, unsigned int Size )
{
 unsigned int j;
 double M;
 M = 1.0; //змінна, яка використовується для обрахунку значення
// добутку елементів масиву
 for( j = 0; j < Size; j++ )
 M *= B[j];
 return M;
}
//---------------------------------------------------------------
double mean_value(const unsigned int * A, unsigned int Size ) {
 unsigned int j;
 double S;
 S = 0; // змінна, яка використовується для обрахунку значення
 // суми елементів масиву
 for( j = 0; j < Size; j++ ) {
 S += A[j];
 }

 return S/Size;
}
//---------------------------------------------------------------
unsigned int find_min(const unsigned int * A, unsigned int Size ) {
 int min = A[0];
 int minIndex = 0;
 for (int i = 0; i < Size; i++)
 {
	if (min > A[i])
	{
		min = A[i];
		minIndex = i;
	}
}
 return min;
}
//---------------------------------------------------------------
float find_max(const float * B, unsigned int Size ) {
 int max = B[0];
 int maxIndex = 0;
 for (int i = 0; i < Size; i++)
 {
	if (max < B[i])
	{
		max = B[i];
		maxIndex = i;
	}
}
 return max;
}
//------------------------------------------------------------------------------
void fill_int_array_new( unsigned int * A2, unsigned int Size )
{
 unsigned int j;
 unsigned int temp;
 for( j = 0; j < Size; j++ ){
 A2[j] = Size - (j + 1);
 }
}
//---------------------------------------------------------
void print_int_array_new( const unsigned int * A2, unsigned int Size )
{
 unsigned int j;
 printf("\nArray of UNSIGNED INT values of matrix A2:\n");
 for( j = 0; j < Size; j++ )
 printf("%5d", A2[j] );
}
//-------------------------------------------------------------
void fill_float_array_new( float * B2, unsigned int Size )
{
 unsigned int j;
 float temp;
 for( j = 0; j < Size; j++ ){
 B2[j] = 5.0 * j + 5.0;
 }
}
//-------------------------------------------------------------
void print_float_array_new( const float * B2, unsigned int Size )
{
 unsigned int j;
 printf("\nArray of FLOAT values of matrix B2:\n");
 for( j = 0; j < Size; j++ )
 printf("%7.2f", B2[j] );
}
//---------------------------------------------------------------

