//PoolVolume was derived from the Lab1Bootstrap code provided in class

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>


// Always put the funciton declerations first!
float HotTubVolume(float width, float depth)
{
    
	float radius = width / 2;
	float realDepth = depth - 0.667;
    float volume = M_PI * radius * radius * realDepth;
    return volume;
}
float PoolVolume(float W, float D, float LD, float DS, float LS, float WI, float L)
{
    // Calculate pool volume based on above parameters
    //------------------------------------------------

    // Interval 1 area is a rectangle
    float i1 = D * LD;

    // Interval 2 area is a Rectangle +- Triangle
    // float i2...
	float i2 = (((D-DS)*(L-(LS+WI+LD))/2) + (DS*(L - (LS + WI + LD))));
    // Interval 3 area is a rectangle
    float i3 = DS * LS;

    // Interval 4 area is a triangle
    float i4 = WI * DS / 2;

    // Multiply Width and intervals to get total volume from area (since width is constant)
    return W * (i1 + i2 + i3 + i4);
}
float VolCost(float vol)
{
    float cost = vol*7.481*4*0.07;
    return cost;
}


int main() 
{
    float htWidth;
    float htDepth;
    float htVolume;
    float htCost;
    float htVolumeGallons;
    float poolLength;
    float shallowDepth;
    float WILength;
    float shallowLength;
    float poolDepth;
    float poolWidth;
    float deepLength;
    float poolVol;
    float poolCost;
    int repeat;
    repeat = 1;
    
    int valid = 0;
    while (repeat)
    {
        do
        {
            printf("Please enter the Hot Tub Width: \n");
            scanf("%f", &htWidth);
            if(htWidth >= 6.0 && htWidth <= 12.0)
            {
                valid = 1;
            }
            else
                printf("Please enter a value between 6 and 12\n");
        }
        while(!valid);
        valid = 0;
        do
        {
            printf("Please enter the Hot Tub depth: \n");
            scanf("%f", &htDepth);
            if(htDepth >= 3.0 && htDepth <= 5.0)
            {
                valid = 1;
            }
            else
                printf("Please enter a value between 3 and 5\n");
        }
        while(!valid);
        valid = 0;
        do
        {
            printf("Please enter the Pool Length: \n");
            scanf("%f", &poolLength);
            if(poolLength >= 40.0 && poolLength <= 70.0)
            {
                valid = 1;
            }
            else
                printf("Please enter a value between 40 and 70\n");
        }
        while(!valid);
        valid = 0;
        do
        {
            printf("Please enter the Pool Width: \n");
            scanf("%f", &poolWidth);
            if(poolWidth >= 15.0 && poolWidth <= 30.0)
            {
                valid = 1;
            }
            else
                printf("Please enter a value between 15 and 30\n");
        }
        while(!valid);
        valid=0;
        do
        {
            printf("Please enter the Walk-in Length: \n");
            scanf("%f", &WILength);
            if(WILength >= 5.0 && WILength <= (poolLength/3.0))
            {
                valid = 1;
            }
            else
                printf("Value not in range, please re-enter\n");
        }
        while(!valid);
        valid = 0;
        do
        {
            printf("Please enter the shallow-end depth: \n");
            scanf("%f", &shallowDepth);
            if(shallowDepth >= 0.0 && shallowDepth <= 4.0)
            {
                valid = 1;
            }
            else
                printf("Please enter a value between 0 and 4\n");
        }
        while(!valid);
        valid=0;
        do
        {
            printf("Please enter the shallow-end length: \n");
            scanf("%f", &shallowLength);
            if(shallowLength >= 10.0 && shallowLength <= (poolLength/2.0))
            {
                valid = 1;
            }
            else
                printf("Value not in range. Please re-enter\n");
        }
        while(!valid);
        valid=0;
        do
        {
            printf("Please enter the Depth of the deep end: \n");
            scanf("%f", &poolDepth);
            if(poolDepth >= 8.0 && poolDepth <= 17.0)
            {
                valid = 1;
            }
            else
                printf("Please enter a value between 8 and 17\n");
        }
        while(!valid);
        valid=0;
        do
        {
            printf("Please enter the length of the deep end: \n");
            scanf("%f", &deepLength);
            if(deepLength >= 12.0 && deepLength <= (poolLength/2.0))
            {
                valid = 1;
            }
            else
                printf("Value not in range, please re-enter\n");
        }
        while(!valid);
        htVolume = HotTubVolume(htWidth, htDepth);
        htCost = VolCost(htVolume);
        htVolumeGallons = htVolume * 7.481;
        poolVol = PoolVolume(poolWidth, poolDepth, deepLength, shallowDepth, shallowLength, 
        WILength, poolLength);
        poolCost = VolCost(poolVol);
        printf("The volume of the hot tub is: %.2f, and the cost is: $%.2f\n", htVolume, htCost);
        printf("The amount of gallons is : %.2f\n", htVolumeGallons);
        printf("The volume of the pool is: %.2f, and the cost is: $%.2f\n", poolVol, poolCost);
        printf("Would you like to make another volume calculation? (1 = Yes, 0 = No)\n");
        scanf("%i", &repeat);
        repeat = (int)repeat;
        
    }
    return 0;
    
}

