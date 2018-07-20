/*void addDays(Date *dt, int n) ;  // Adds n days with the specified date
void subDays(Date *dt, int n) ;  // Subtracts n days with the specified date
int diffDates(Date *dt1, Date *dt2) ; // Returns number of days between given days, assuming dt2 is earlier to dt1
case 3: addDays(date *dt, int n);
		 		break;
		 	case 4: subDays(Date *dt, int n);
		 		break;
			case 5: diffDates(Date *dt1, Date *dt2) ;
			 		break;*/
#include<stdio.h>
typedef struct 
{
	int dd;
	int mm;
	int yy;
}date ;
void printDate(date *dt)    	// Prints like 15/08/1947
{
	printf("the date is %02d/%02d/%0d\n",dt->dd,dt->mm,dt->yy);
} 
void longPrintDate(date *dt)   // Prints like 15th August, 1947
{
	char a[][50]={"January","Febuary","March","April","May","June","July","August","September","October","November","December"};
	if(dt->dd==1 || dt->dd==21 || dt->dd==31)
		printf("the date is %dst ",dt->dd);
	else if(dt->dd==2 || dt->dd==22 )
			printf("the date is %dnd ",dt->dd);
	else if(dt->dd==3 || dt->dd==23)
			printf("the date is %drd ",dt->dd);
	else
		printf("the date is %dth ",dt->dd);
	printf("%s, ",a[(dt->mm)-1]);		
	printf("%d.",dt->yy);							
}

int main()
{
	date dt;
	char ans;
	int c;
	printf("enter day:");
	scanf("%d",&dt.dd);
	printf("enter month:");
	scanf("%d",&dt.mm);
	printf("enter year:");
	scanf("%d",&dt.yy);
	
	while(1)
	{
		printf("enter choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printDate(&dt);
				break;
			case 2: longPrintDate(&dt);
				break;
			
			default:("invalid choice");
		}
		printf("\ndo you want to continue?(y/n)?:");
		fflush(stdin);
		scanf("%c",&ans);
		if(ans!='Y' && ans!='y')
			break;
	}
}

