#include <stdio.h>
#include "Hash.h"

typedef struct _tag_Student
{
	//char* id;
	int id;
	char* name;
	int age;
}Student;

int compared(HashKey* key1, HashKey* key2)
{
	return key1 - key2;/*strcmp((char*)key1, (char*)key2);*/
}

int main(int argc, char *argv[])
{
	Student s1 = {1, "iLdak", 24};
	Student s2 = {2, "Linux", 24};
	Student s3 = {3, "c++", 40};
	Student s4 = {4, "c", 50};
	Student s5 = {5, "java", 20};
	Student* ps = NULL;
	
	Hash* hash = Hash_Create();
	
	Hash_Add(hash, s1.id, &s1, compared);
	Hash_Add(hash, s2.id, &s2, compared);
	Hash_Add(hash, s3.id, &s3, compared);
	Hash_Add(hash, s4.id, &s4, compared);
	Hash_Add(hash, s5.id, &s5, compared);
	
	ps = Hash_Get(hash, 1, compared);
	
	if(ps != NULL)
	{
		printf("id=%d, name=%s, age=%d\n", ps->id, ps->name, ps->age);
	}
	
	ps = Hash_Get(hash, 2, compared);
	
	if(ps != NULL)
	{
		printf("id=%d, name=%s, age=%d\n", ps->id, ps->name, ps->age);
	}
	
	ps = Hash_Get(hash, 3, compared);
	
	if(ps != NULL)
	{
		printf("id=%d, name=%s, age=%d\n", ps->id, ps->name, ps->age);
	}	
	
	ps = Hash_Remove(hash, 2, compared);
	
	if(ps != NULL)
	{
		printf("Delete After id = 2\n");
	}
	
	
	Hash_Destroy(hash);
  
  	printf("Press enter to continue ...");
  	getchar();	
  	return 0;

}
