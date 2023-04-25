#include "Header.h"
int searchbyln (user **aos,char*lname,int i)
{
    int x,y,j=0;
    for(x=0; x<i; x++)
    {
        y=strcasecmp(lname,aos[x]->lname);
        if(y==0)
        {

            j++;
            printtoscreen(aos[x]);
        }
        else if((y!=0) && x==(i-1) && j==0)

            printf("No Record Found \n");
    }
    return j;
}
int searchfullname (user **aos,char*fname,char*lname,int i)
{
    int x,y,j;
    for(x=0; x<i; x++)
    {
        y=strcasecmp(lname,aos[x]->lname);
        j=strcasecmp(fname,aos[x]->fname);
        if(y==0 && j==0)
        {

            return x;
        }
        else if((y!=0) && x==(i-1) && j!=0)
        {
            printf("No Record Found \n");
            return -1;
        }
    }
}
int fullsearch (user **aos,int i)
{
    int j,flag=0;
    read_constr(i,aos);
    for(j=0; j<i; j++)
    {
        if(strcasecmp(aos[j]->fname,aos[i]->fname)==0 || strcasecmp(aos[i]->fname,"")==0)
            if(strcasecmp(aos[j]->lname,aos[i]->lname)==0 || strcasecmp(aos[i]->lname,"")==0)
                if(strcasecmp(aos[j]->address,aos[i]->address)==0 || strcasecmp(aos[i]->address,"")==0)
                    if(strcasecmp(aos[j]->email,aos[i]->email)==0 || strcasecmp(aos[i]->email,"")==0)
                        if(strcasecmp(aos[j]->phone,aos[i]->phone)==0 || strcasecmp(aos[i]->phone,"")==0)
                            if(aos[j]->dob->day==aos[i]->dob->day || aos[i]->dob->day==NULL)
                                if(aos[j]->dob->month==aos[i]->dob->month || aos[i]->dob->month==NULL)
                                    if(aos[j]->dob->year==aos[i]->dob->year || aos[i]->dob->year==NULL)
                                    {
                                        printtoscreen(aos[j]);
                                        flag=1;
                                    }

    }
    return flag;
}
