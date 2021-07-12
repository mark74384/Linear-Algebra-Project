#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M_PI 3.14159265358979323846

//Matrix Multiplication
void matrixMultiplyAndSaveInto2ndArray(int row1,int col1,int col2,float arr1[row1][col1],float arr2[][col2]){
    int row2 = col1;
    double arrm[row1][col2];
        for(int i=0;i<row1;i++)
            for(int j=0;j<col2;j++)
            {
                arrm[i][j] = 0;
                for(int p=0;p<col1;p++)
                {
                    arrm[i][j] += arr1[i][p] * arr2[p][j];
                }
            }
    for(int i=0;i<row2;i++)
    {
        for(int j=0;j<col2;j++)
        {
            arr2[i][j]=arrm[i][j];
        }
    }

}

//Translation used in scaling
void translationFunctionWithGiven(int x,int y,int numberOfRows,int numberOfPoints,float arr[][numberOfPoints]){
    float translationarray [3][3] = {{1, 0, x}, {0, 1, y} , {0, 0, 1}};
    matrixMultiplyAndSaveInto2ndArray(3,3,numberOfPoints,translationarray,arr);
}

//Reflection around X-axis and Y-axis
//// triangle reflection in the x axis;
void reflection_x_axis_triangle ( float a[3][3]){
float b[2][3] = {1,0,0,0,-1,0};
float new_array[2][3];
float new_array1[3][2];
int sum=0 , i , j , k ;
for ( i=0 ; i<2 ; i++ ){
    for ( j=0 ; j<3 ; j++ ){
        for ( k=0 ; k<3 ; k++ ){
         sum += b[i][k]*a[k][j];
        }
        new_array[i][j] = sum;
        sum =0;
    }
}
for(i=0;i<2;i++){
    for(j=0;j<3;j++){
        new_array1[j][i]=new_array[i][j];
    }
}
printf("used matrix \n");
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("%0.2f ",b[i][j]);
        if(j==1){
            printf("\n");
        }
    }
}
printf("new matrix \n");
for ( i=0 ; i<3 ; i++){
    for ( j=0 ; j<2 ; j++){
        printf("%0.2f ",new_array1[i][j]);
        if (j==1){
            printf("\n");
        }
    }
}
}
//// triangle reflection in the y axis;
void reflection_y_axis_triangle (float a[3][3]){
float b[2][3]={-1,0,0,0,1,0};
int sum=0 , i , j , k ;
float new_array[2][3];
float new_array1[3][2];
for ( i=0 ; i<2 ; i++ ){
    for ( j=0; j<3 ; j++ ){
        for ( k=0 ; k<3 ; k++ ){
         sum+= b[i][k]*a[k][j];
        }
        new_array[i][j]=sum;
        sum =0;
    }
}
for(i=0;i<2;i++){
    for(j=0;j<3;j++){
        new_array1[j][i]=new_array[i][j];
    }}
    printf("used matrix \n");
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("%0.2f ",b[i][j]);
        if(j==1){
            printf("\n");
        }
    }
}
for ( i=0 ; i<3;i++){
    for ( j=0; j<2;j++){
        printf("%0.2f ",new_array1[i][j]);
        if (j==1){
            printf("\n");
        }
    }
}
}
////reflection in the x axis rectangle;
void reflection_x_axis_rectangle(float a[3][4]){
float b[2][3] = {1,0,0,0,-1,0};
float new_array[2][4];
float new_array1[4][2];
int sum=0,i,j,k;
for ( i=0 ;i<2;i++){
    for ( j=0;j<4;j++){
        for ( k=0;k<3;k++){
         sum+= b[i][k]*a[k][j];
        }
        new_array[i][j]=sum;
        sum =0;
    }
}
for(i=0;i<2;i++){
    for(j=0;j<4;j++){
        new_array1[j][i]=new_array[i][j];
    }}
    printf("used matrix \n");
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("%0.2f ",b[i][j]);
        if(j==1){
            printf("\n");
        }
    }
}
for ( i=0 ; i<4;i++){
    for ( j=0; j<2;j++){
        printf("%0.2f ",new_array1[i][j]);
        if (j==1){
            printf("\n");
        }
    }
}
}
////reflection in the y axis rectangle;
void reflection_y_axis_rectangle(float a[3][4]){
float b[2][3]={-1,0,0,0,1,0};
int sum=0,i,j,k;
float new_array[2][4];
float new_array1[4][2];
for ( i=0 ;i<2;i++){
    for ( j=0 ; j<4 ; j++ ){
        for ( k=0 ; k<3 ; k++ ){
         sum+= b[i][k]*a[k][j];
        }
        new_array[i][j]=sum;
        sum =0;
    }
}
for(i=0;i<2;i++){
    for(j=0;j<4;j++){
        new_array1[j][i]=new_array[i][j];
    }}
    printf("used matrix \n");
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("%0.2f ",b[i][j]);
        if(j==1){
            printf("\n");
        }
    }
}
for ( i=0 ; i<4 ; i++ ){
    for ( j=0 ; j<2 ; j++ ){
        printf("%0.2f ",new_array1[i][j]);
        if (j==1){
            printf("\n");
        }
    }
}
}

//Degree to Radian
float degreeToRad(float x){
    x = x * M_PI / 180;
    return x;
}

//Rotation Function
void rotationTransformation(int row,int numberOfPoints,float array[][numberOfPoints])
{
    //translation to the origin
    int deltaX = 0 - array[0][0];
    int deltaY = 0 - array[1][0];
    if(deltaX != 0 || deltaY != 0)
    {
        translationFunctionWithGiven(deltaX,deltaY,3,numberOfPoints,array);
    }
    float angle,angleRad;
    printf("enter the rotation angle in degrees:");
    scanf("%f",&angle);
    angleRad = degreeToRad(angle);
    float rotationMatrix[3][3] = {{cos(angleRad),sin(angleRad),0}
                                    ,{-sin(angleRad),cos(angleRad),0}
                                    ,{0,0,1}};
    matrixMultiplyAndSaveInto2ndArray(3,3,numberOfPoints,rotationMatrix,array);
    //translation to original position
    if(deltaX != 0 || deltaY != 0)
    {
        translationFunctionWithGiven(-deltaX,-deltaY,3,numberOfPoints,array);
    }
    float arr[numberOfPoints][2];
    for (int i = 0; i < numberOfPoints; ++i) {
            for (int j = 0; j < 2; j++) {
                arr[i][j] = array[j][i];
            }
        }
    printf("\nThe transformation matrix used is:\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            printf("%0.2f ",rotationMatrix[i][j]);
        printf("\n");
    }
    printf("The new coordinates are\n");
    for (int i = 0; i < numberOfPoints; ++i) {
            for (int j = 0; j < 2; ++j) {
                printf("%.2f ", arr[i][j]);
            }
            printf("\n");
        }

}

//Scaling Function
void scalingTransformation(int row,int numberOfPoints, float array[][numberOfPoints]){
    //shift polygon towards the origin
    int deltaX = 0 - array[0][0];
    int deltaY = 0 - array[1][0];
    if(deltaX != 0 || deltaY != 0)
        {
            translationFunctionWithGiven(deltaX,deltaY,3,numberOfPoints,array);
        }
    int xAxisScale, yAxisScale;
    //scan scaling factors
    printf("enter the horizontal scaling factor:");
    scanf("%d",&xAxisScale);
    printf("enter the vertical scaling factor:");
    scanf("%d",&yAxisScale);
    //initializing scaling matrix and multiplying by given array
    float scalingMatrix[3][3] = {{xAxisScale,0,0},{0,yAxisScale,0},{0,0,1}};
    matrixMultiplyAndSaveInto2ndArray(row,row,numberOfPoints,scalingMatrix,array);
    //shift the polygon to it's original origin
    if(deltaX != 0 || deltaY != 0)
    {
        translationFunctionWithGiven(-deltaX,-deltaY,3,numberOfPoints,array);
    }
    float arr[numberOfPoints][2];
    for (int i = 0; i < numberOfPoints; ++i) {
        for (int j = 0; j < 2; j++) {
            arr[i][j] = array[j][i];
        }
    }
    printf("\nThe transformation matrix used is:\n");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            printf("%0.2f ",scalingMatrix[i][j]);
        printf("\n");
    }
    printf("The new coordinates are\n");
    for (int i = 0; i < numberOfPoints; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%.2f ", arr[i][j]);
        }
        printf("\n");
    }
}

//Translation Function
void translation_Function (float arr[][2], int numberOfRows, float deltaX, float deltaY) {
    float translationarray [3][3] = {{1, 0, deltaX}, {0, 1, deltaY} , {0, 0, 1}};
    int common_count = 0;
    int i = 0, j = 0;
    // Triangle Translation
    if (numberOfRows == 3) {
        float tempArray[3][3];
        // Putting Array of Coordinates in a 3*3 array with ones
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 2; ++j) {
                tempArray[j][i] = arr[i][j];
            }
        }
        for (i = 0; i < 3; ++i) {
            tempArray[2][i] = 1;
        }

        // Here we get the array that we need to translate in tempArray
        float result[3][3] = {{0}};
        for(i=0; i < 3; i++) {
            for(j=0; j < 3; j++) {
                common_count = 0;
                while(common_count != 3) {
                    result[i][j] += (translationarray[i][common_count] * tempArray[common_count][j]);
                    common_count++;
                }
            }
        }

        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 2; j++) {
                arr[i][j] = result[j][i];
            }
        }
        printf("The used matrix for translation is \n");
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 3; j++) {
                printf("%.2f ", translationarray[i][j]);
            }
            printf("\n");
        }
        printf("The resulted matrix is \n");
        // Result Array is the array of multiplication
        // now we will put the values of new x's and y's from result to parameter array
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 2; j++) {
                printf("%.2f ", arr[i][j]);
            }
            printf("\n");
        }
    }

    // Rectangle Translation
    else if (numberOfRows == 4) {
        float tempArray[3][4];
        // Putting Array of Coordinates in a 3*4 array with ones
        for (i = 0; i < 4; ++i) {
            for (j = 0; j < 2; ++j) {
                tempArray[j][i] = arr[i][j];
            }
        }
        for (i = 0; i < 4; ++i) {
            tempArray[2][i] = 1;
        }
        // Here we get the array that we need to translate in tempArray
        float result[3][4] = {{0}};
        for(i=0; i < 3; i++) {
            for(j=0; j < 4; j++) {
                common_count = 0;
                while(common_count != 3) {
                    result[i][j] += (translationarray[i][common_count] * tempArray[common_count][j]);
                    common_count++;
                }
            }
        }
        // Result Array is the array of multiplication
        // now we will put the values of new x's and y's from result to parameter array
        for (i = 0; i < 4; ++i) {
            for (j = 0; j < 2; j++) {
                arr[i][j] = result[j][i];
            }
        }
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 3; j++) {
                printf("%.2f ", translationarray[i][j]);
            }
            printf("\n");
        }
        printf("The resulted matrix is \n");
        for (i = 0; i < 4; ++i) {
            for (j = 0; j < 2; ++j) {
                printf("%.2f ", arr[i][j]);
            }
            printf("\n");
        }

    }
}

//Reflection y = x Function
void reflection_yx(float points[][4],int numOfPoints){
int reflection[3][3]={0,1,0,1,0,0,0,0,1};//the reflection array
int i,j,k;
double result[3][4]={0};//initialize the result array elements to zero
if(numOfPoints==3){
    for(i=0;i<3;i++){
        for(k=0;k<3;k++){
            for(j=0;j<3;j++){
                result[i][k]+=reflection[i][j]*points[j][k];
            }
        }
    }
printf("The new coordinates are \n");//print the result points
for(j=0;j<3;j++){
    for(i=0;i<2;i++){
        printf("%lf ",result[i][j]);
    }
    printf("\n");
}
printf("The standard transformation matrix for reflection over y=x is\n");//print the matrix used in the transformation
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("%d ",reflection[i][j]);
    }
    printf("\n");
}
}
else if (numOfPoints==4){
         for(i=0;i<3;i++){
        for(k=0;k<4;k++){
            for(j=0;j<3;j++){
                result[i][k]+=reflection[i][j]*points[j][k];

            }
        }
         }
printf("The new coordinates are \n");//print the result points
for(j=0;j<4;j++){
    for(i=0;i<2;i++){
        printf("%.2lf ",result[i][j]);
    }
    printf("\n");
}
printf("The standard transformation matrix for reflection over y=x is\n");//print the matrix used in the transformation
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("%d ",reflection[i][j]);
    }
    printf("\n");
}
}
}

//Reflection around y = -x Function
void reflection_ymx(float points[][4],int numOfPoints){//reflection around y and minus x
int reflection[3][3]={0,-1,0,-1,0,0,0,0,1};//the reflection array
int i,j,k;
double result[3][4]={0};//initialize the result array elements to zero
if(numOfPoints==3){
    for(i=0;i<3;i++){
        for(k=0;k<3;k++){
            for(j=0;j<3;j++){
                result[i][k]+=reflection[i][j]*points[j][k];
            }
        }
    }
printf("The new coordinates are \n");//print the result points
for(j=0;j<3;j++){
    for(i=0;i<2;i++){
        printf("%0.2lf ",result[i][j]);
    }
    printf("\n");
}
printf("The standard transformation matrix for reflection about y=-x is\n");//print the matrix used in the transformation
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("%d ",reflection[i][j]);
    }
    printf("\n");
}
}
else if (numOfPoints==4){
         for(i=0;i<3;i++){
        for(k=0;k<4;k++){
            for(j=0;j<3;j++){
                result[i][k]+=reflection[i][j]*points[j][k];

            }
        }
         }
printf("The new coordinates are \n");//print the result points
for(j=0;j<4;j++){
    for(i=0;i<2;i++){
        printf("%lf ",result[i][j]);
    }
    printf("\n");
}
printf("The standard transformation matrix for reflection about y=-x is\n");//print the matrix used in the transformation
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("%d ",reflection[i][j]);
    }
    printf("\n");
}
}
}


int main() {
    // Choosing the shape to be translated
    printf("Please choose the shape of the input \n For choosing triangle press t\n For choosing rectangle press r\n");
    char shape;
    int i, j;
    scanf("%c", &shape);
    float deltax;
    float deltay;
    // Checking the shape is Triangle or Rectangle
    if (shape == 't') {
        float arrayOfCoordinates[3][2];
        printf("Co-ordinates of the origin point of the shape\n");
        for (i = 0; i < 3; ++i) {
            printf("Please enter the x coordinate of point %d\n", (i+1));
            scanf("%f", &arrayOfCoordinates[i][0]);
            printf("Please enter the y coordinate of point %d\n", (i+1));
            scanf("%f", &arrayOfCoordinates[i][1]);
        }
        float tempArray[3][3];
        // Putting Array of Coordinates in a 3*3 array with ones
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 2; ++j) {
                tempArray[j][i] = arrayOfCoordinates[i][j];
            }
        }
        for (i = 0; i < 3; ++i) {
            tempArray[2][i] = 1;
        }
        printf("Write down the number of your choice\n");
        printf("(1)Scaling with ratios Alpha and Beta along x-axis and y-axis, respectively\n");
        printf("(2)Reflection in the X-axis\n");
        printf("(3)Reflection in the Y-axis\n");
        printf("(4)Reflection in the straight line y = x\n");
        printf("(5)Reflection in the straight line y = -x\n");
        printf("(6)Rotation about the origin of the polygon by an angle Theta in the clockwise direction\n");
        printf("(7)Translation of the polygon origin to a new point\n");
        int choice;
        scanf ("%d", &choice);
        switch (choice) {
        case 1:
            scalingTransformation(3, 3, tempArray);
            break;
        case 2:
            reflection_x_axis_triangle(tempArray);
            break;
        case 3:
            reflection_y_axis_triangle(tempArray);
            break;
        case 4:
            reflection_yx(tempArray, 3);
            break;
        case 5:
            reflection_ymx(tempArray, 3);
            break;
        case 6:
            rotationTransformation(3, 3, tempArray);
            break;
        case 7:
            printf("Please enter delta x\n");
            scanf("%f", &deltax);
            printf("Please enter delta y\n");
            scanf("%f", &deltay);
            translation_Function(arrayOfCoordinates, 3, deltax, deltay);
            break;
        }
    }
    else if (shape = 'r') {
        float arrayOfCoordinates[4][2];
        printf("Co-ordinates of the origin point of the shape\n");
        for (i = 0; i < 4; ++i) {
            printf("Please enter the x coordinate of point %d\n", (i+1));
            scanf("%f", &arrayOfCoordinates[i][0]);
            printf("Please enter the y coordinate of point %d\n", (i+1));
            scanf("%f", &arrayOfCoordinates[i][1]);
        }
        float tempArray[3][4];
        // Putting Array of Coordinates in a 3*4 array with ones
        for (i = 0; i < 4; ++i) {
            for (j = 0; j < 2; ++j) {
                tempArray[j][i] = arrayOfCoordinates[i][j];
            }
        }
        for (i = 0; i < 4; ++i) {
            tempArray[2][i] = 1;
        }
        printf("Write down the number of your choice\n");
        printf("(1)Scaling with ratios Alpha and Beta along x-axis and y-axis, respectively\n");
        printf("(2)Reflection in the X-axis\n");
        printf("(3)Reflection in the Y-axis\n");
        printf("(4)Reflection in the straight line y = x\n");
        printf("(5)Reflection in the straight line y = -x\n");
        printf("(6)Rotation about the origin of the polygon by an angle Theta in the clockwise direction\n");
        printf("(7)Translation of the polygon origin to a new point\n");
        int choice;
        scanf ("%d", &choice);
        switch (choice) {
            case 1:
                scalingTransformation(3, 4, tempArray);
                break;
            case 2:
                reflection_x_axis_triangle(tempArray);
                break;
            case 3:
                reflection_y_axis_triangle(tempArray);
                break;
            case 4:
                reflection_yx(tempArray, 4);
                break;
            case 5:
                reflection_ymx(tempArray, 4);
                break;
            case 6:
                rotationTransformation(3, 4, tempArray);
                break;
            case 7:
                printf("Please enter delta x\n");
                scanf("%f", &deltax);
                printf("Please enter delta y\n");
                scanf("%f", &deltay);
                translation_Function(arrayOfCoordinates, 4, deltax, deltay);
                break;
        }
    }

}

