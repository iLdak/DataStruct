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
	int j = 0;
	int i = 0;
	int changFlag = 1;
	
	for(i = 0; i < len && changFlag; i++)
	{
		changFlag = 0;
		
		for(j = len -1; j > i; j--)
		{
			if(array[j - 1] > array[j])
			{
				sweep(array, j - 1, j);
				changFlag = 1;
			}
		}
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
