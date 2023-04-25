#include "Header.h"
user* construct (char* x,char*fn,char*ln,char*email,char*adr,date *birthd)
{
    user *s=malloc(sizeof(user));
    s->fname=malloc(strlen(fn)+1);
    s->dob=malloc(sizeof(date));
    s->lname=malloc(strlen(ln)+1);
    s->email=malloc(strlen(email)+1);
    s->address=malloc(strlen(adr)+1);
    s->phone=malloc(strlen(x)+1);;
    *(s->dob)=*birthd;
    strcpy(s->phone,x);
    strcpy(s->fname,fn);
    strcpy(s->lname,ln);
    strcpy(s->email,email);
    strcpy(s->address,adr);
    return s;
}
void printtoscreen(user *s)
{
    printf("Name :%-8s %-8s | DOB :%.2d-%.2d-%.4d | Address :%-30s | Email :%-22s | Number :%s\n",s->fname,s->lname,s->dob->day,s->dob->month,s->dob->year,s->address,s->email,s->phone);
}
void printalltoscreen (user **ps,int n)
{
    int i;
    for(i=0; i<n; i++)
        printtoscreen(ps[i]);
}
int entry ()
{
    int option;
    char op[20];
    printf("Choose An Option : \n1)Load\t 2)Search\n3)Add\t 4)Delete\n5)Modify 6)Sort\n7)Save   8)Exit\n");
    printf("Option:");
    fflush(stdin);
    fgets(op,20,stdin);
    op[strlen(op)-1]='\0';
    if(digitonly(op)==0 || strcasecmp(op,"")==0 )
        option=-1;
    else
        option=atoi(op);
    return option;
}
int scope ()
{
    int option;
    char op[20];
    fflush(stdin);
    fgets(op,20,stdin);
    op[strlen(op)-1]='\0';
    if(digitonly(op)==0 || strcasecmp(op,"")==0 )
        option=-1;
    else
        option=atoi(op);
    return option;

}
void read_constr (int i,user **aos)
{
    char fn[20],ln[20],email[50],adr[50];
    int day,mon,yr;
    char snum[20],sday[5],smon[5],syr[6];
    fflush(stdin);
repeat1:
    printf("Enter First Name :");
    fgets(fn,20,stdin);
    fn[strlen(fn)-1]='\0';
    if(charonly(fn)==0)
    {
        printf("INVALID NAME\n");
        goto repeat1;
    }
repeat2:
    printf("Enter Your Last Name :");
    fgets(ln,20,stdin);
    ln[strlen(ln)-1]='\0';
    if(charonly(ln)==0)
    {
        printf("INVALID NAME\n");
        goto repeat2;
    }
repeat3:
    printf("Enter Your Phone Number :");
    fgets(snum,20,stdin);
    snum[strlen(snum)-1]='\0';
    if(strcmp(snum,"")==0)
        goto repeat4;
    if(digitonly(snum)==0)
    {
        printf("INVALID NUMBER\n");
        goto repeat3;
    }
    printf("Enter Your Date of Birth :\n");
repeat4:
    printf("\t\t    Day :");
    fflush(stdin);
    fgets(sday,4,stdin);
    sday[strlen(sday)-1]='\0';
    if(strcmp(sday,"")==0)
    {
        day=atoi(sday);
        goto repeat5;
    }
    if(digitonly(sday)==0)
    {
        printf("\t\tINVALID DAY\n");
        goto repeat4;
    }
    day=atoi(sday);
    if((day<=0) || (day>31))
    {
        printf("\t\tINVALID DAY\n");
        goto repeat4;
    }
repeat5:
    printf("\t\t  Month :");
    fflush(stdin);
    fgets(smon,4,stdin);
    smon[strlen(smon)-1]='\0';
    if(strcmp(smon,"")==0)
    {
        mon=atoi(smon);
        goto repeat6;
    }
    if(digitonly(smon)==0)
    {
        printf("\t\tINVALID MONTH\n");
        goto repeat5;
    }
    mon=atoi(smon);
    if((mon<=0) || (mon>12))
    {
        printf("\t\tINVALID MONTH\n");
        goto repeat5;
    }
    if((day==30 || day==31) && mon==2)
    {
        printf("\tNO SUCH A DAY IN FEBRUARY!\n");
        goto repeat5;
    }
repeat6:
    printf("\t\t   Year :");
    fflush(stdin);
    fgets(syr,6,stdin);
    syr[strlen(syr)-1]='\0';
    if(strcmp(syr,"")==0)
    {
        yr=atoi(syr);
        goto repeat8;
    }
    if(digitonly(syr)==0)
    {
        printf("\t\tINVALID YEAR\n");
        goto repeat6;
    }
    yr=atoi(syr);
    if(yr>2020 || yr<1900)
    {
        printf("\t\tINVALID YEAR\n");
        goto repeat6;
    }
    fflush(stdin);
repeat8:
    printf("Enter Your Address : ");
    fgets(adr,50,stdin);
    adr[strlen(adr)-1]='\0';
repeat7:
    printf("Enter Your Email :");
    fgets(email,50,stdin);
    email[strlen(email)-1]='\0';
    int k;
    for(k=1; k<strlen(email); k++)
    {
        if(email[0]=='@')
        {
            printf("INVALID EMAIL\n");
            goto repeat7;
        }
        if(email[k]=='@')
            break;
        else if(email[k]!='@' && k==strlen(email)-1)
        {
            printf("INVALID EMAIL\n");
            goto repeat7;
        }
    }
    printf("\n");
    date d;
    d.day=day;
    d.month=mon;
    d.year=yr;
    aos[i]=construct(snum,fn,ln,email,adr,&d);
}
int digitonly (char*str)
{
    while(*str)
    {
        if(isdigit(*str++)==0)
            return 0;
    }
    return 1;
}
int charonly (char*str)
{
    while(*str)
    {
        if(isalpha(*str++)==0)
            return 0;
    }
    return 1;
}
void readnoskip (int i,user **aos)
{
    char fn[20],ln[20],email[50],adr[50];
    int day,mon,yr;
    char snum[20],sday[5],smon[5],syr[6],buff[20];
    fflush(stdin);
repeat1:
    printf("Enter First Name :");
    fgets(fn,20,stdin);
    fn[strlen(fn)-1]='\0';
    if(charonly(fn)==0 || strcasecmp(fn,"")==0)
    {
        printf("INVALID NAME OR EMPTY ENTRY!\n");
        goto repeat1;
    }
repeat2:
    printf("Enter Your Last Name :");
    fgets(ln,20,stdin);
    ln[strlen(ln)-1]='\0';
    if(charonly(ln)==0 || strcasecmp(ln,"")==0)
    {
        printf("INVALID NAME OR EMPTY ENTRY!\n");
        goto repeat2;
    }
repeat3:
    printf("Enter Your Phone Number :");
    fgets(snum,20,stdin);
    snum[strlen(snum)-1]='\0';
    if(digitonly(snum)==0 || strcasecmp(snum,"")==0 )
    {
        printf("INVALID PHONE NUMBER OR EMPTY ENTRY!\n");
        goto repeat3;
    }
    printf("Enter Your Date of Birth :\n");
repeat4:
    printf("\t\t    Day :");
    fflush(stdin);
    fgets(sday,4,stdin);
    sday[strlen(sday)-1]='\0';
    if(digitonly(sday)==0 || strcasecmp(sday,"")==0)
    {
        printf("\t\tINVALID DAY OR EMPTY ENTRY!\n");
        goto repeat4;
    }
    day=atoi(sday);
    if((day<=0) || (day>31))
    {
        printf("\t\tINVALID DAY!\n");
        goto repeat4;
    }
repeat5:
    printf("\t\t  Month :");
    fflush(stdin);
    fgets(smon,4,stdin);
    smon[strlen(smon)-1]='\0';
    if(digitonly(smon)==0  || strcasecmp(smon,"")==0)
    {
        printf("\t\tINVALID MONTH!\n");
        goto repeat5;
    }
    mon=atoi(smon);
    if((mon<=0) || (mon>12))
    {
        printf("\t\tINVALID MONTH!\n");
        goto repeat5;
    }
    if((day==30 || day==31) && mon==2)
    {
        printf("\tNO SUCH A DAY IN FEBRUARY!\n");
        goto repeat5;
    }
repeat6:
    printf("\t\t   Year :");
    fflush(stdin);
    fgets(syr,6,stdin);
    syr[strlen(syr)-1]='\0';
    if(digitonly(syr)==0 || strcasecmp(syr,"")==0)
    {
        printf("\t\tINVALID YEAR!\n");
        goto repeat6;
    }
    yr=atoi(syr);
    if((yr>2020 || yr<1900))
    {
        printf("\t\tINVALID YEAR!\n");
        goto repeat6;
    }
    fflush(stdin);
repeat7:
    printf("Enter Your Address : ");
    fgets(adr,50,stdin);
    adr[strlen(adr)-1]='\0';
    if(strcasecmp(adr,"")==0)
    {
        printf("\t\tINVALID EMPTY ENTRY!\n");
        goto repeat7;
    }
repeat8:
    printf("Enter Your Email :");
    fgets(email,50,stdin);
    email[strlen(email)-1]='\0';
    if(strcasecmp(email,"")==0)
    {
        printf("\t\tINVALID EMPTY ENTRY!\n");
        goto repeat8;
    }
    int k;
    for(k=1; k<strlen(email); k++)
    {
        if(email[0]=='@')
        {
            printf("INVALID EMAIL!\n");
            goto repeat8;
        }
        if(email[k]=='@')
            break;
        else if(email[k]!='@' && k==strlen(email)-1)
        {
            printf("INVALID EMAIL!\n");
            goto repeat8;
        }
    }
    printf("\n");
    date d;
    d.day=day;
    d.month=mon;
    d.year=yr;
    aos[i]=construct(snum,fn,ln,email,adr,&d);
}
