#include "Header.h"
void sortbylname (user **aos,FILE *fp)
{
    int i,j,sorted=0;
    fp=fopen("Project.txt","a+");
    int rec=records(fp);
    user *temp;
    for(i=1; i<rec && !sorted ; i++)
    {
        sorted=1;
        for(j=0; j<rec-i; j++)
        {
            if(stricmp(aos[j]->lname,aos[j+1]->lname)>0)
            {
                temp=aos[j];
                aos[j]=aos[j+1];
                aos[j+1]=temp;
                sorted=0;
            }
        }
        fclose(fp);
    }
}
void sortbyfname (user **aos,FILE *fp)
{
    int i,j,sorted=0;
    fp=fopen("Project.txt","a+");
    int rec=records(fp);
    user *temp;
    for(i=1; i<rec && !sorted ; i++)
    {
        sorted=1;
        for(j=0; j<rec-i; j++)
        {
            if(stricmp(aos[j]->fname,aos[j+1]->fname)>0)
            {
                temp=aos[j];
                aos[j]=aos[j+1];
                aos[j+1]=temp;
                sorted=0;
            }
        }
        fclose(fp);
    }
}
void sorbydob (user **aos,FILE *fp)
{
    int i,j,sorted=0;
    fp=fopen("Project.txt","a+");
    int rec=records(fp);
    user *temp;
    for(i=1; i<rec && !sorted ; i++)
    {
        sorted=1;
        for(j=0; j<rec-i; j++)
        {
            if (aos[j]->dob->year>aos[j+1]->dob->year)
            {
                temp=aos[j];
                aos[j]=aos[j+1];
                aos[j+1]=temp;
                sorted=0;
            }

            if (aos[j]->dob->year==aos[j+1]->dob->year)

            {

                if(aos[j]->dob->month>aos[j+1]->dob->month)
                {
                    temp=aos[j];
                    aos[j]=aos[j+1];
                    aos[j+1]=temp;
                    sorted=0;
                }
                if(aos[j]->dob->month==aos[j+1]->dob->month)
                {
                    if (aos[j]->dob->day>aos[j+1]->dob->day)
                    {
                        temp=aos[j];
                        aos[j]=aos[j+1];
                        aos[j+1]=temp;
                        sorted=0;
                    }
                }
            }
        }
    }
    fclose(fp);
}
