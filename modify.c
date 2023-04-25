#include "Header.h"
void readonly (int i,user **aos)
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
    date d;

    if(strcasecmp(fn,"")==0)
        strcpy(fn,aos[i]->fname);
    if(strcasecmp(ln,"")==0)
        strcpy(ln,aos[i]->lname);
    if(strcasecmp(adr,"")==0)
        strcpy(adr,aos[i]->address);
    if(strcasecmp(email,"")==0)
        strcpy(email,aos[i]->email);
    if(strcasecmp(snum,"")==0)
        strcpy(snum,aos[i]->phone);
    if(day==NULL)
        day=aos[i]->dob->day;
    if(mon==NULL)
        mon=aos[i]->dob->month;
    if(yr==NULL)
        yr=aos[i]->dob->year;
    printf("\n");
    d.day=day;
    d.month=mon;
    d.year=yr;
    aos[i]=construct(snum,fn,ln,email,adr,&d);
}
int searchbylnmod (user **aos,char*lname,int i,int *arr)
{
    int x,y,j=0;
    for(x=0; x<i; x++)
    {
        y=strcasecmp(lname,aos[x]->lname);
        if(y==0)
        {
            arr[j]=x;
            j++;
            printf("%d)",x);

            printtoscreen(aos[x]);
        }
        else if((y!=0) && x==(i-1) && j==0)

            printf("No Record Found \n");
    }
    return j;
}
