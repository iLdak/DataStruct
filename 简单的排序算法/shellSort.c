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
void shellSort(int array[], int len)
{
	int k = 0;
	int i = 0;
	int j = 0;
	int tmp = 0;
	int grap = len;
	
	do{
		grap = grap / 3 + 1;
		
		for(i = grap; i < len; i += grap)
		{
			k = i;
			tmp = array[k];
		
			for(j = i - grap; (j >= 0) && array[j] > tmp; j -= grap)
			{
				array[j+grap] = array[j];
				k = j;
			}
		
			array[k] = tmp;
		}
		
	}while(grap > 1);
}

int main(int argc, char *argv[])
{
  int array[] = {25,21,25,4,16,12,8,49,3};
	
  int len = sizeof(array) / sizeof(*array);
  
  println(array, len);
  
  shellSort(array, len);
  
  printf("\n");
  println(array, len);
  
  printf("\nPress enter to continue ...");
  getchar();	
  return 0;

}
*/
