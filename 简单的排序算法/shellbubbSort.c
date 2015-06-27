
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
void shellSort(int array[], int len)
{
	int changFlag = 1;
	int i = 0;
	int j = 0;
	int grap = len;
	
	do{
		grap = grap / 3 + 1;
		
		for(i = 0; i < len ; i++)
		{
			for((j = len - 1); j > i; j-=grap)
			{
				if(((j - grap) >= 0) && (array[j - grap] > array[j]))
				{
					sweep(array, j - grap, j);
				}
			}
		}
		printf("\ngrap is %d\n",grap);
		println(array, len);
		
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

