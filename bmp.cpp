#include<stdio.h>
typedef struct
{
	char val1;
	char val2;
	int size;
	short zero1;
	short zero2;
	int start;
	int hsize;
	int width;
	int height;
}str;
int filesize(FILE *fp)
{
	int l,p;
	p=ftell(fp);
	fseek(fp,0,SEEK_END);
	l=ftell(fp);
	fseek(fp,p,SEEK_SET);
	return l;
}
int main()
{
	str bmp;
	FILE *fp;
	fp=fopen("C:\\Users\\Lenovo\\Desktop\\penguin.bmp","r");
	fread(&bmp.val1,sizeof(char),1,fp);
	fread(&bmp.val2,sizeof(char),1,fp);
	fread(&bmp.size,sizeof(int),1,fp);
	fread(&bmp.zero1,sizeof(short),1,fp);
	fread(&bmp.zero2,sizeof(short),1,fp);
	fread(&bmp.start,sizeof(int),1,fp);
	fread(&bmp.hsize,sizeof(int),1,fp);
	fread(&bmp.width,sizeof(int),1,fp);
	fread(&bmp.height,sizeof(int),1,fp);
		
/*	if(bmp.val1==0x42 && bmp.val2==0x4d && bmp.size==filesize(fp) && bmp.zero1==0 && bmp.zero2==0)
	{
		printf("image width is %d in pixels\n",bmp.width);
		printf("image height is %d in pixels\n",bmp.height);
	}
	else
		printf("file corrupt");*/
	printf("%02x\n%2x\n",bmp.val1,bmp.val2);
	printf("%d,%d",bmp.size,filesize(fp));
	printf("\nzero 1=%d\nzero 2=%d\nstart=%d\nhsize=%d\nwidth=%d\nheight=%d",bmp.zero1,bmp.zero2,bmp.start,bmp.hsize,bmp.width,bmp.height);
	
	fclose(fp);
}
