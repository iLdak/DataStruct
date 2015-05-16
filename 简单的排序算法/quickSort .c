/*
#include <stdio.h>

//打印数组内容
void println(int array[], int len)
{
	int i = 0;
	
	for(i = 0; i < len; i++)
	{
		printf("%d ",array[i]);
	} 
} 

//交换数据 
void sweep(int array[], int i, int k)
{
	int temp = array[i];
	
	array[i] = array[k];
	
	array[k] = temp;
}

int quickSort(int *array, int low, int heigh)
{
	int pv = array[low];

	while(low < heigh)
	{
		while((low < heigh) && array[heigh] >= pv)
		{
			heigh--;
		}
		
		sweep(array, low, heigh);
		
		while((low < heigh) && array[low] < pv)
		{
			low++;
		}
		
		sweep(array, low, heigh);
	}
	
	return low;
}

void recursiveQuickSort(int *array, int low, int heigh)
{
	if(low < heigh)
	{
		int pv_location = quickSort(array, low, heigh);
		
		recursiveQuickSort(array, low, pv_location-1);
		recursiveQuickSort(array, pv_location+1, heigh);
	}
}

int main(int argc, char *argv[])
{
  int array[] = {25,21,25,4,16,12,8};
	
  int len = sizeof(array) / sizeof(*array);
  
  println(array, len);
  
  recursiveQuickSort(array, 0, len-1);
  
  printf("\n");
  println(array, len);
  
  printf("\nPress enter to continue ...");
  getchar();	
  return 0;

}
*/
