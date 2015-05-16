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

//选择排序 
void selectionSort(int array[], int len)
{
	int k = 0;
	int i = 0;
	int j = 0;
	int tmp = 0;
	for(i = 1; i < len; i++)
	{
		k = i;
		tmp = array[k];
		
		for(j = i - 1; (j >= 0) && array[j] > tmp; j--)
		{
			array[j+1] = array[j];
			k = j;
		}
		
		array[k] = tmp;
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
