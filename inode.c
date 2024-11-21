#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
	char fname[20];
	struct stat buffer;
	int flag;
	for(int i=1;i<argc;i++)
	{
		flag=stat(argv[i],&buffer);
		if(flag==0)
		{
			printf("\nFile Exist");
			printf("inode:%ld",buffer.st_ino);
			printf("\nFile size:%ld",buffer.st_size);
			printf("\nNumber of links to the file:%ld",buffer.st_nlink);
			printf("\nLast access time:%s",ctime(&buffer.st_atime));
			printf("\nLast modified time:%s",ctime(&buffer.st_mtime));
			printf("\nPermission for file\n");
			if(buffer.st_mode && W_OK)
			printf("\tWrite");
			if(buffer.st_mode && R_OK)
			printf("\tRead");
			if(buffer.st_mode && X_OK)
			printf("\tExecute");
		}
		else
		{
			printf("\nFile does not exist");
		}
	}
}
			
			
		

