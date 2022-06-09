#include <stdlib.h>  
#include <stdio.h>  
int GetMaxChildArraySum(int * pInput, int nLen, int * pOut)  
{  
    if (!pInput || !pOut)  
        return 0;  
    if (nLen < 0)  
        return 0;  
    int nSum = 0;  
    int nTempSum = 0;  
    int nMax = pInput[0];  
    int i = 0;  
    for (i = 0; i < nLen; i++)  
    {  
        if (nTempSum <= 0)  
        {  
            //如果累加和小于等于0，则表示前面的子数组是拖累，甩掉它们。  
            //从当下的元素重新计算子数组的开始位置。  
            nTempSum = pInput[i];  
        }  
        else  
        {  
            nTempSum += pInput[i];  
        }      
        if (pInput[i] > nMax)  
        {  
            nMax = pInput[i];  
        }  
        if (nTempSum > nSum)  
        {  
            nSum = nTempSum;  
        }  
    }  
    if (nMax < 0)  
    {  
        //如果都是负数，则返回最大值。  
        *pOut = nMax;  
        return 1;  
    }  
    *pOut = nSum;          
    return 1;  
}  
void main()  
{  
    int Array[] = { 1, 2, 3, -10, -4, -7, -2, -5 };  
    int nTemp = 0;  
    GetMaxChildArraySum(Array, 8, &nTemp);  
    printf("数组最大和:%d\n", nTemp);  
    system("pause");  
    return;  
}  
