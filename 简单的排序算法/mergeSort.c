
#include <stdio.h>
#include <malloc.h>

//打印数组内容
void println(int array[], int len)
{
	int i = 0;
	
	for(i = 0; i < len; i++)
	{
		printf("%d ",array[i]);
	} 
} 

//合并排序 
void mergeSort(int src[], int des[], int low, int mid, int high)
{
	int high_mid = mid+1; 
	int low_mid = low;
	int des_subscript = low;
	
	while( (low_mid <= mid) && (high_mid <= high) )
	{
		if( src[low_mid] > src[high_mid] )
		{
			des[des_subscript++] = src[high_mid++];
		}
		else
		{
			des[des_subscript++] = src[low_mid++];
		}
	}
	
	while(low_mid <= mid)
	{
		des[des_subscript++] = src[low_mid++];
	}
	
	while(high_mid <= high)
	{
		des[des_subscript++] = src[high_mid++];
	}	
}

void Msort(int src[], int des[], int low, int high, int max)
{
	if(low == high)
	{
		des[low] = src[low]; 
	}
	else
	{
		int mid = ( low + high ) / 2;
		int* space  = (int*)malloc(sizeof(int) * max);
		
		if(space != NULL)
		{
			Msort(src, space, low, mid, max);
			Msort(src, space, mid+1, high, max);
			
			mergeSort(space, des, low, mid, high);	
		}
		
		free(space);
	}	
}

void sort(int array[],int len)
{
	Msort(array, array, 0, len-1, len);
}

int main(int argc, char *argv[])
{
  int array[] = {25,21,25,4,16,12,8};
	
  int len = sizeof(array) / sizeof(*array);
  
  println(array, len);
  
  sort(array, len);
  
  printf("\n");
  println(array, len);
  
  printf("\nPress enter to continue ...");
  getchar();	
  return 0;

}
