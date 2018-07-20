/*
              A Menu based PostOffice Application
              ===================================
		The beauty of this program is that this is not a mere static program.
	i.e., it workds dynamically on different data for any other Post Office
	in India.
		
		Since there is not provision to input data in the question, I have 
	written this program so dynamically that if someone changes data at the
	head of the program, the program reacts accordingly and works very nice
	for any data for any Post Office in India and there _needs_no_change_
	_in_the_code_.
		
		Therefore, this program is _not_limited_upon_any_static_data_ for any
  particular Post Office. It workds dynamically very nice for any change
  data and for any Post Office in India.
  
  	One can very easily change some data at the head of the program and 
  _without_changing_any_code_ the program runs smoothly.
*/

/* The Post Office Program
   Shows all the information about Haridevpur Post Office
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include<windows.h>			
#define   TIMEWID   17       /* Width of time-text to print in Time Chart */
#define   SCRNWD    80       /* Width of the screen */
#define   SCRNHT    25       /* Height of the screen (sometimes it can be 50) */

char JUSTWAIT[] = "Press any key to continue..." ;   /* A waiting prompt */

void clrscr(void)
{
   system("cls") ;	//clear screen.
}

void gotoxy(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);		
}

/* Structure for a service */
typedef struct
{
   char title[20] ;     /* Title of the Service Chart */
   char names[10][30] ; /* List of the service names */
   int  count ;         /* Number of services in the list */
   int  maxLen ;      /* Max length of strings (calculated by code) */
} Service ;


/* Structure of the Rate Chart */
typedef struct
{
   char title[20] ;      /* Name of the Rate Chart */
   char head1[20] ;      /* Item Heading */
   char head2[20] ;      /* Price Heading */
   struct                /* Sub structure for the Items and rates */
   {
      char  item[30] ;    /* Name of the item */
      int   price ;       /* Price of the item */
   } vals[20] ;
   int count ;            /* Number of rates */
   int maxLen ;           /* Max length of strings (calculated by code) */
} RateChart ;



/* Structure of the Time Chart */
typedef struct
{
   char note[60] ;       /* Note about time chart */
   char head1[20] ;      /* Service Heading */
   char head2[20] ;      /* Timing Heading */
   struct                /* Sub structure for the timings and services */
   {
      char  service[20] ; /* Name of the item */
      float fTime ;       /* Time from */
      float tTime ;       /* Time to */
   } vals[20] ;
   int count ;            /* Number of services */
   int maxLen ;           /* Max length of strings (calculated by code) */
} TimeChart ;

/* Structure of the Post Office Information */
typedef struct
{
  struct
  {
     char label[20] ;      /* Info name */
     char value[35] ;      /* Info value */
  } data[20] ;             /* List of maximum of 20 information */
  
  int count ;              /* Number of Infomation */
  int data1cnt ;           /* Number of data in 1st part */
  int data2cnt ;           /* Number of data in 2nd part */

  int maxLen1 ;           /* Max length of 1st column strings */
  int maxLen2 ;           /* Max length of 2nd colunm strings */
  int maxLen3 ;           /* Max length of 3rd colunm strings */
  int maxLen4 ;           /* Max length of 4th colunm strings */
} Info ;

/* Structure of the Notice/Circular Board */
typedef struct
{
   char title[40] ;         /* Heading of the Notice/Circular */
   char lines[20][75] ;     /* Lines in the Notice/Circular */
   int  count ;             /* Number of lines */
   int  maxLen ;            /* Maximum length of the lines */
} Notice ;

/* Structure of one Post Office data */
struct
{
   char name[30] ;          /* Post office name */

   Service serv[10] ;       /* Details of the Services */
   int     servCnt ;        /* Number of services in this PO */

   RateChart rates[10] ;    /* Details of the Rate Charts */
   int       rateCnt ;      /* Number of Rate Charts in this PO */

   TimeChart timeChart ;    /* Details of the Timings */
   Info      info ;         /* Details information about the Post Office */
   Notice    notice ;       /* Lines of the Notice/Cirulation */
} po ; 
	
	     
	     
	     /* -------------------------------------------------------------------
          Here goes the whole data of the post office. 
          New data can be added, existing data can be deleted or modified
          WITHOUT CHANGING ANYTHING IN THE CODE 
       ------------------------------------------------------------------- */
               
       "Kalighat Post Office",   /* Name */

      /* All the Services */
      {
       /* Service 1 */
       {   "Mail Services",
        {   "Mail Products",
            "Registration",
            "Parcel",
            "Insurance",
            "Value Payable Post"
        }, 5,  /* count */
       },

       /* Service 2 */
       {   "Premium Products",
        {   "Speed Post",
            "Business Post",
            "Express Parcel",
            "Media Post",
            "Greetings Post",
            "Logistics Post",
        }, 6,  /* count */
       },

       /* Service 3 */
       {   "Financial Services",
        {   "P. O. Savings Schemes",
            "Postal Life Insurance",
            "Money Remittance Service",
            "Mutual Funds",
            "Forex Services",
        }, 5,  /* count */
       },

       /* Service 4 */
       {   "Retail Services",
        {   "Bill Mail",
            "Direct Post",
            "Retail Post",
            "e-Payment",
        }, 4,  /* count */
       },
      }, /* End of Sevices */
      4, /* Number of Services */

      /* All the Rate charts */
      {
        /* Rate Chart 1 */
        { "Speed Post",     /* Chart title */
          "Weight",         /* Heading1 */
          "Price (Rs.)",    /* Heading2 */
          {
             {"Upto 50 gms", 15},
             {"51 gms - 200 gms", 25},
             {"201 gms - 500 gms", 30},
             {"Above 500 (per gm)", 15},
          }, 4, /* Number of items */
        },

        /* Rate Chart 2 */
        { "Business Post",    /* Chart title */
          "Service",          /* Heading1 */
          "Rate (P.)",         /* Heading2 */
          {
             {"Collection from Premises", 40},
             {"Franking", 30},
             {"Addressing", 10},
             {"Sealing", 10},
             {"Special Heading", 10},
          }, 5, /* Number of items */
        },

        /* Rate Chart 3 */
        { "Express Parcel",    /* Chart title */
          "Distance",          /* Heading1 */
          "Rate (Rs.)",         /* Heading2 */
          {
             {"Local", 30},
             {"Within State", 50},
             {"Neibouring State", 60},
             {"Other State", 80},
             {"Between Capitals", 70},
          }, 5, /* Number of items */
       },
       
      }, /* End of Rate Charts */
      3, /* Number of Rate Charts */

      /* The Time Chart */
      {  "Lunch period should be considered. Sunday full closed",
        "Services",
        "Timings",
        {
           {"Stamps", 10.30, 15},
           {"Parcels", 12, 16.15},
           {"Speed Post", 11, 17},
           {"Registered Post", 11.30, 16.45},
           {"Greetings Post", 14.30, 16},
           {"Bill Payments", 10.15, 15.15},
           {"Lunch", 13, 14},
        }, 6, /* Number of timings */
      },

      /* Information about the Post Office */
      {
        {
          {"Pincode", "700082"},
          {"Office Type", "Sub Post Office"},
          {"District", "Kolkata"},
          {"State", "West Bengal"},
          {"Circle", "West Bengal"},
          {"Division", "Calcutta South"},
          {"Delivery?", "Yes"},
        }, 7, /* Number of data info */
      },

      /* Notice/Circulation */
      {
         "Kolkata Post Office Recruitment 2014",
         {
            "Post Office of Kolkata has released Notification about various",
            "vacancies in terms of Kolkata Post Office Recruitment 2014.",
            "Interested canditates may apply for the post of TC driver, motor",
            "vehicle driver/electrician, tin or copper smith. There is no",
            "procedure to apply online. Last date to submit the application",
            "form is 31/12/2014.",
            "",
            "Interested applicants can check the rest details like",
            "qualifation, selection process, how to apply etc. from the rest",
            "portion of the page prepared for you by the team of recruitments.",
         },  10, /* Number of lines */
      },

} ; /* End of all data about the Post Office */

/* Characters to create a box */
typedef struct
{
   char
   /* top-left, top, top-right, right, */
   tplt,        top, tprt,      rgt,
   /* bottom-right, bottom, bottom-left, left */
   btrt,         bot,    btlt,        lft ;
} Box ;

Box sBox = {'Ú', 'Ä', '¿', '³', 'Ù', 'Ä', 'À', '³'} ;
Box dBox = {'É', 'Í', '»', 'º', '¼', 'Í', 'È', 'º'} ;

/* Draw the Box
   Parameters : box, topX, topY, Width, Height */
void drawBox(Box *b, int x, int y, int wd, int ht)
{
   int i, w, h ;

   w = x+wd-1 ;
   h = y+ht-1 ;
   gotoxy(x, y) ;   putchar(b->tplt) ;  /* top left */

   gotoxy(w, y) ;   putchar(b->tprt) ;  /* top right */

   gotoxy(w, h) ;   putchar(b->btrt) ;  /* bottom right */

   gotoxy(x, h) ;   putchar(b->btlt) ;  /* bottom left */

   /* Draw top and bottom borders */
   for(i = x+1 ; i < w ; i ++)
   {
     gotoxy(i, y) ; putchar(b->top) ;
     gotoxy(i, h) ; putchar(b->bot) ;
   }

   /* Draw left and right borders */
   for(i = y+1 ; i < h ; i ++)
   {
     gotoxy(x, i) ; putchar(b->lft) ;
     gotoxy(w, i) ; putchar(b->rgt) ;
   }
} /* End of drawBox */

/* Convert all the characters of the passing string to uppercase */
void toUpperString(char *str)
{
   for(; *str != '\0' ; str++)
      *str = toupper(*str) ;
} /* End of toUpperString */

/* Show the prompt in the middle of y'th row and input a character */
char promptAndInput(char *prompt, int y)
{   /* Print the prompt at the middle of the screen */
    gotoxy((SCRNWD-strlen(prompt)) / 2 + 1, y) ; printf(prompt) ;

    return getch() ;  /* Wait for a key to be pressed and return it */
} /* End of promptAndInput */

/* Show Post Office name and return total number of lines taken.
   Also, show current page name.
     y = top most line
     str = Name of current page  */
int showPOname(char *str, int y)
{
   char *ch ;
   int  len = 0 ;
   int x, xx ;

   /* Turn to UPPER case and calculate length */
   for(ch = po.name ; *ch != '\0' ; ch++)
   {
     len ++ ;
     *ch = toupper(*ch) ;
   }

   clrscr() ;  /* Clear the screen */
   
   len *= 2 ;  /* For one space between the letters */
   len += 3 ;  /* 2-character margin on both sides minus 1 trailing space */
   x = xx = (SCRNWD - len) / 2 + 1 ; /* To center align */

   x += 2 ;
   /* Print the name with 1 gap after each letter */
   gotoxy(x, y+2) ;
   for(ch = po.name ; *ch != '\0' ; ch++)
      printf("%c ", *ch) ;


   drawBox(&dBox, xx, y, len, 5) ;

   /* Print page name at the center of the screen */
   gotoxy((SCRNWD - (strlen(str) + 2)) / 2 + 1, y+5) ;
   printf("-:%s:-", str) ;

   return 6 ;
} /* End of showPOname */

/* Calculate the Hour and Minute from a 24hr time
   and print in 'HH:MM ap' 12 hr format */
void printHrMin(float time)
{
   int hr, mn ;
   char ampm ;

   hr = (int) time ;
   mn = (int) ((time - hr) * 100) ;

   if(hr > 12)
   {
     hr -= 12 ;
     ampm = 'p' ;
   }
   else
     ampm = 'a' ;

   printf("%d", hr) ;
   if(mn > 0)
      printf(":%d", mn) ;

   printf("%s", ampm=='a' ? "am" : "pm") ;
} /* End of printHrMin */

/* Print the Notice chart and return total number of lines taken */
int printNotice(Notice *t, int y)
{
   int i, x, ht, wd ;

   ht = t->count + 4 ;           /* Height of the chart */
   wd = t->maxLen + 4 ;          /* Chart Width */

   x = (SCRNWD - wd) / 2 + 1 ;  /* Bring chart to the middle of the screen */

   drawBox(&dBox, x, y, wd, ht) ;  /* Draw the outer box */

   /* Print the title of the notice on the top border of the chart */
   gotoxy(x + (wd-strlen(po.notice.title)+2)/2,  y) ;  /* On the center */
   printf(" %s ", po.notice.title) ;


   /* Print all the lines of the notice */
   x += 2 ;
   y += 2 ;
   for(i = 0 ; i < t->count ; i ++)
   {
      gotoxy(x,  y+i) ; printf(po.notice.lines[i]) ;
   }

   promptAndInput(JUSTWAIT, SCRNHT) ;

   return ht ;
} /* End of printNotice */

/* Print one infomation chart and return total number of lines taken */
int printInfo(Info *f, int y)
{
   int i, j, k, x, y2, x1, x2, x3, x4, ht, wd ;

   ht = f->data1cnt * 2 + 1 ;                 /* Height of the chart */
   wd = f->maxLen1 + f->maxLen2 + f->maxLen3 + f->maxLen4 + 7 ; /* Chart Width */

   x = (SCRNWD - wd) / 2 ;   /* Bring chart to the middle of the screen */

   x1 = x  + f->maxLen1 + 1 ;  /* position of first column seperator */
   x2 = x1 + f->maxLen2 + 2 ;  /* position of second column seperator */
   x3 = x2 + f->maxLen3 + 2 ;  /* position of third column seperator */
   x4 = x+wd-1 ;               /* position of rightmost border */

   drawBox(&dBox, x, y, wd, ht) ;  /* Draw the outer box */

   /* Print the colulmn knobs */
   gotoxy(x1, y) ;  putchar('Ñ') ;     /* top - on first col seperator */
   gotoxy(x2, y) ;  putchar('Ë') ;     /* top - on second col seperator */
   gotoxy(x3, y) ;  putchar('Ñ') ;     /* top - on third col seperator */
   y2 = y + ht-1 ;
   gotoxy(x1, y2) ;  putchar('Ï') ;     /* bot - on first col seperator */
   gotoxy(x2, y2) ;  putchar('Ê') ;     /* bot - on second col seperator */
   gotoxy(x3, y2) ;  putchar('Ï') ;     /* bot - on third col seperator */


   /* Print all the labels and values */
   y2 = y+1 ;            /* Row of first item */
   k = f->data1cnt ;     /* start index of second part */
   for(i = 0 ; i < f->data1cnt ; i ++)
   {
     /* The first part */
     gotoxy(x+1, y2) ; printf("%*s", f->maxLen1, f->data[i].label) ;
     gotoxy(x1,  y2) ; printf("³%s", f->data[i].value) ;
     gotoxy(x2,  y2) ; putchar('º') ;
  
     /* The second part */
     gotoxy(x3,  y2) ; putchar('³') ;
     if(k < f->count)
     {
        gotoxy(x2+2, y2) ; printf("%*s", f->maxLen3, f->data[k].label) ;
        gotoxy(x3+1, y2) ; printf(f->data[k].value) ;
     }
  
     y2 ++ ;
     k ++ ;
  
     if(i < f->data1cnt - 1)     /* If it is not the last row */
     {
        /* Row border */
        for(j = 0 ; j < wd ; j++)
        {    gotoxy(x+j, y2) ; putchar('Ä') ;
        }
  
        gotoxy(x,  y2) ;      putchar('Ç') ;
        gotoxy(x1, y2) ;      putchar('Å') ;
        gotoxy(x2, y2) ;      putchar('×');
        gotoxy(x3, y2) ;      putchar('Å') ;
        gotoxy(x4, y2) ;      putchar('¶') ;
  
        y2 ++ ;
     }
   }

   promptAndInput(JUSTWAIT, SCRNHT) ;

   return ht ;
}

/* Print one Time Chart and return total number of lines taken */
int printTimeChart(TimeChart *t, int y)
{
   int i, j, x, y2, x1, x2, hLen2, ht, wd ;
   int fHr, fMn, tHr, tMn ;        /* from and to hour and minutes */

   ht = t->count * 2 + 5 ;
   wd = t->maxLen + 2 ;

   /* If this chart does not fit in the remaining rows, don't print */
   if(y + ht > SCRNHT)
      return 0 ;

   x = (SCRNWD - wd) / 2 + 1 ;  /* Bring chart to the middle of the screenn */

   hLen2 = strlen(t->head2) ;           /* second heading's length */
   x1 = x + 1 ;                         /* start of first column */
   x2 = x1 + t->maxLen - TIMEWID - 1 ;  /* position of column border */

   drawBox(&dBox, x, y, wd, ht) ;  /* Draw the outer box */

   /* Print Note */
   gotoxy(x + (t->maxLen-strlen(t->note))/2+1, y+1) ; /* Align to center */
   printf(t->note) ;

   /* Print the heading border */
   for(i = 0 ; i < t->maxLen+2 ; i++)
   {     gotoxy(x+i, y+2) ; putchar(dBox.top) ;
         gotoxy(x+i, y+4) ; putchar(dBox.top) ;
   }
   gotoxy(x, y+2) ;  putchar('Ì') ;           /* on left border */
   gotoxy(x, y+4) ;  putchar('Ì') ;           /* on left border */
   gotoxy(x2, y+2) ; putchar('Ñ') ;           /* on column border */
   gotoxy(x2, y+3) ; putchar('³') ;           /* on column border */
   gotoxy(x2, y+4) ; putchar('Ø') ;           /* on column border */
   gotoxy(x2+TIMEWID+1, y+2) ; putchar('¹') ;   /* on right border */
   gotoxy(x2+TIMEWID+1, y+4) ; putchar('¹') ;   /* on right border */

   /* Print the headings */
   gotoxy(x1, y+3) ; printf(t->head1) ;
   gotoxy(x2 + (TIMEWID - hLen2)/2+1, y+3) ; printf(t->head2) ;


   /* Print all the items and rates */
   y2 = y+5 ;            /* Row of first item */
   for(i = 0 ; i < t->count ; i ++)
   {
     /* Service and Timing */
     gotoxy(x1, y2) ; printf(t->vals[i].service) ;
     gotoxy(x2, y2) ; printf("³") ;
  
     printHrMin(t->vals[i].fTime) ;
     printf(" to ") ;
     printHrMin(t->vals[i].tTime) ;
     y2 ++ ;
  
     if(i < t->count - 1)
     {
        /* Row border */
        for(j = 0 ; j < t->maxLen+2 ; j++)
        {    gotoxy(x+j, y2) ; putchar('Ä') ;
        }
  
        gotoxy(x, y2) ;            putchar('Ç') ;
        gotoxy(x2, y2) ;           putchar('Å');
        gotoxy(x2+TIMEWID+1, y2) ; putchar('¶') ;
  
        y2 ++ ;
     }
   }

   gotoxy(x2, y2) ;           putchar('Ï');

   promptAndInput(JUSTWAIT, SCRNHT) ;

   return ht ;
} /* End of printTimeChart */

/* Print one Rate Chart and return total number of lines taken */
int printRateChart(RateChart *r, int x, int y)
{
   int i, j, y2, x1, x2, hLen2, ht ;

   ht = r->count * 2 + 4 ;

   /* If this chart does not fit in the remaining rows, don't print */
   if(y + ht > SCRNHT)
      return 0 ;


   hLen2 = strlen(r->head2) ;           /* second heading's length */
   x1 = x + 1 ;                         /* start of first column */
   x2 = x1 + r->maxLen - hLen2 - 1 ;    /* position of column border */

   drawBox(&dBox, x, y, r->maxLen+2, ht) ;  /* Draw the outer box */

   /* Print Rate Title */
   gotoxy(x + (r->maxLen-strlen(r->title))/2, y) ; /* Align to center */
   printf(" %s ", r->title) ;

   /* Print the heading border */
   for(i = 0 ; i < r->maxLen+2 ; i++)
   {     gotoxy(x+i, y+3) ; putchar(dBox.top) ;
   }
   gotoxy(x, y+3) ;  putchar('Ì') ;           /* on left border */
   gotoxy(x2, y+3) ; putchar('Ø') ;           /* on column border */
   gotoxy(x2+hLen2+1, y+3) ; putchar('¹') ;   /* on right border */

   /* Print the headings */
   gotoxy(x1, y+2) ; printf(r->head1) ;
   gotoxy(x2, y+2) ; printf("³%-*s", hLen2, r->head2) ;


   /* Print all the items and rates */
   y2 = y+4 ;            /* Row of first item */
   for(i = 0 ; i < r->count ; i ++)
   {
     /* Item and Price */
     gotoxy(x1, y2) ; printf(r->vals[i].item) ;
     gotoxy(x2, y2) ; printf("³%*d", hLen2, r->vals[i].price) ;
     y2 ++ ;
  
     if(i < r->count-1)
     {
        /* Row border */
        for(j = 0 ; j < r->maxLen+2 ; j++)
        {   gotoxy(x+j, y2) ; putchar('Ä') ;
        }
  
        gotoxy(x, y2) ;          putchar('Ç') ;
        gotoxy(x2, y2) ;         putchar('Å');
        gotoxy(x2+hLen2+1, y2) ; putchar('¶') ;
        y2 ++ ;
     }
   }

   gotoxy(x2, y2) ;         putchar('Ï');

   return ht ;
} /* End of printRateChart */

void printAllRateCharts(int x, int y)
{
   int i, lines, max = 0, col = x, row = y ;

   /* Keep printing all the rate charts side by side */
   for(i = 0 ; i < po.rateCnt ; i ++)
   {  /* Print i'th rate chart */
     lines = printRateChart(po.rates + i, col, row) ;
     if(max < lines)
        max = lines ;
     col += po.rates[i].maxLen+3;
  
     /* if more service(s) to print then no more space on the side */
     if(i<po.rateCnt-1 && col + po.rates[i].maxLen+2 >= SCRNWD)
     {  /* then next service will be printed below */
        row += max + 2 ;
        col = x ;
        max = 0 ;
     }
   }

   promptAndInput(JUSTWAIT, SCRNHT) ;
} /* End of printAllRateCharts */

/* Print one service and return total number of lines taken */
int printService(Service *s, int x, int y)
{
   int i ;

   drawBox(&sBox, x, y, s->maxLen+2, s->count + 3) ;

   /* Print Service Title */
   gotoxy(x+1, y) ; printf(" %s ", s->title) ;

   /* Print all the sub-service names */
   for(i = 0 ; i < s->count ; i ++)
   {
     gotoxy(x+1, y+i+2) ;
     printf(s->names[i]);
   }

   return s->count+2 ;
} /* End of printService */

void printAllServices(int x, int y)
{
   int i, lines, max = 0, col = x, row = y ;

   /* Keep printing all the services side by side */
   for(i = 0 ; i < po.servCnt ; i ++)
   {  /* Print i'th service */
     lines = printService(po.serv + i, col, row) ;
     if(max < lines)
        max = lines ;
     col += po.serv[i].maxLen+3;
  
     /* if more service(s) to print then no more space on the side */
     if(i<po.servCnt-1 && col + po.serv[i].maxLen+2 >= 80)
     {  /* then next service will be printed below */
        row += max + 2 ;
        col = x ;
        max = 0 ;
     }
   }

   promptAndInput(JUSTWAIT, SCRNHT) ;
} /* End of printAllServices */

/* Calculate maximum length of strings for each of the sections to print */
void calcLengths(void)
{
  int i, j, max, max2, len, c, hdLen2 ;


  /* Calculate Maximum length of strings in each service */
  for(i = 0 ; i < po.servCnt ; i ++)
  {
     max = strlen(po.serv[i].title) + 2 ; /* 2 extra spaces on the sides */

     for(j = 0 ; j < po.serv[i].count ; j ++)
     {
       len = strlen(po.serv[i].names[j]) ;
       if(max < len)
          max = len ;
     }
     po.serv[i].maxLen = max ;
  }

  /* Calculate Maximum length of strings in each Rate Chart */
  for(i = 0 ; i < po.rateCnt ; i ++)
  {
     max = strlen(po.rates[i].title)  + 2 ; /* 2 extra spaces on sides */

     /* total length of the headings */
     hdLen2 = strlen(po.rates[i].head2) + 1 ;
     len = strlen(po.rates[i].head1) + hdLen2 ;
     if(max < len)
        max = len ;


     for(j = 0 ; j < po.rates[i].count ; j ++)
     {
       len = strlen(po.rates[i].vals[j].item) + hdLen2 ;
       if(max < len)
          max = len ;
     }
     po.rates[i].maxLen = max ;
  }

  /* Calculate Maximum length of strings in the Time Chart */
  max = strlen(po.timeChart.note) ;

  /* total length of the headings */
  hdLen2 = strlen(po.timeChart.head2) + 1 ;
  if(hdLen2 < TIMEWID)
     hdLen2 = TIMEWID ;
  len = strlen(po.timeChart.head1) + hdLen2 ;
  if(max < len)
     max = len ;

  /* Lengths of the items and times */
  for(j = 0 ; j < po.timeChart.count ; j ++)
  {
     len = strlen(po.timeChart.vals[j].service) + hdLen2 ;
     if(max < len)
     max = len ;
  }
  po.timeChart.maxLen = max ;


  /* Calculate Maximum lengths of strings in the Info page */

  /* First, count number of data for each part */
  po.info.data1cnt = (po.info.count + 1) / 2 ;
  po.info.data2cnt = (po.info.count - po.info.data1cnt) ;

  /* Now, calculate max length of strings */
  max = max2 = 0 ;              /* Initiate */
  for(j = 0 ; j < po.info.count ; j ++)
  {
     len = strlen(po.info.data[j].label) ;
     if(max < len)
        max = len ;

     len = strlen(po.info.data[j].value) ;
     if(max2 < len)
        max2 = len ;

     /* Also the opportunity to turn the label to uppercase */
     toUpperString(po.info.data[j].label) ;

     if(j < po.info.data1cnt)
     {
       po.info.maxLen1 = max ;  /* Max length for the first column */
       po.info.maxLen2 = max2 ; /* Max length for the second column */
     }
     else
     {
       po.info.maxLen3 = max ;  /* Max length for the third column */
       po.info.maxLen4 = max2 ; /* Max length for the fourth column */
     }
  }

  /* Calculate the maximum length of the strings in the Notice */
  max = strlen(po.notice.title) + 2 ; /* 2 extra spaces for the sides */
  for(i = 0 ; i < po.notice.count ; i ++)
  {
     len = strlen(po.notice.lines[i]) ;
     if(max < len)
        max = len ;
  }
  po.notice.maxLen = max ;

} /* End of calcLengths */

/* Print and take inputs for the main menu */
void showMenu(void)
{
   char menu[][50] = {
           "Information",
           "Service details",
           "Rate list",
           "Important Circulars/Notices",
           "Timings",
           "Quit",
         } ;
   char waitPrompt[50] = "Enter your choice [", ch ;
   char opt[] = "  1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9 /" ; /* Also some extra */
   int n = sizeof menu / sizeof menu[0] ; /* Number of options */
   int i, len, maxLen = 0 ;
   int x, y, wd, ht ;

   /* Build the prompt string */
   opt[n * 4 - 1] = '\0' ;     /* Cut after required option */
   strcat(strcat(waitPrompt, opt+2), "] : ")  ;       /* Concat with the main prompt and terminate properly */

   /* Count maximum lenght of the menu items */
   for(i = 0 ; i < n ; i ++)
   {
     len = strlen(menu[i]) ;
     if(maxLen < len)
        maxLen = len ;
   }

   while(1)                /* Set an infinite loop */
   {
     /* Show the menu first */
     y = showPOname("Main Menu", 1) + 2 ;  /* Show Post Office Title */
  
     wd = maxLen + 7 ;
     ht = 4 * n + 1 ;         /* Each line takes 4 lines */
     x = (SCRNWD - wd) / 2 ;  /* Bring the box to the middle of the screen */
  
     drawBox(&dBox, x, y, wd, ht) ;
  
     y ++ ;
     for(i = 0 ; i < n ; i ++)   /* Print the option numbers */
     {
        drawBox(&sBox, x+1, y, 3, 3) ;
        gotoxy(x+2, y+1) ;  putchar('1' + i) ;
        gotoxy(x+5, y+1) ;  printf(menu[i]) ;
  
        y+= 4 ;
     }
  
     ch = promptAndInput(waitPrompt, y+1) ;
     switch(ch)
     {
        case '1' :   /* Information */
           y = showPOname("Post Office Information", 1) + 2 ;
           printInfo(&po.info, y) ;
        break ;
  
        case '2' :   /* Service Details */
           y = showPOname("Service Details", 1) + 2 ;
           printAllServices(1, y) ;
        break ;
  
        case '3' :   /* Rate list */
           y = showPOname("Rate List", 1) + 2 ;
           printAllRateCharts(1, y) ;
        break ;
  
        case '4' :   /* Important Cirular/Notices */
           y = showPOname("Circular/Notice", 1) + 2 ;
           printNotice(&po.notice, y) ;
        break ;
  
        case '5' :  /* Timings */
           y = showPOname("Timings", 1) + 2 ;
           printTimeChart(&po.timeChart, y) ;
        break ;
  
        case '6' :  /* Quit */
           return ;
      }
   } /* End of while */
} /* End of showMenu */


/* The Main function */
int main(void)
{
    calcLengths() ;

    showMenu() ;

    return 0 ;
} /* End of main */
/* ------------------------- END OF PROGRAM ------------------------- */


