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

//选择排序 
void selectionSort(int array[], int len)
{
	int k = 0;
	int i = 0;
	int j = 0;
	
	for(i = 0; i < len; i++)
	{
		k = i;
		for(j = k; j < len; j++)
		{
			if(array[j] < array[k])
			{
				k = j;
			}
		}
		
		sweep(array, i, k);
	}
}

int main(int argc, char *argv[])
{
  int array[] = {25,21,25,4,16,12,8};
	
  int len = sizeof(array) / sizeof(*array);
  
  println(array, len);
  
  selectionSort(array, len);
  
  printf("\n");
  println(array, len);
  
  printf("\nPress enter to continue ...");
  getchar();	
  return 0;

}

*/
