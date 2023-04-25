#include "Header.h"
user *decodeText(char *line)
{
    char *ln=strtok(line,",");
    char *fn=strtok(NULL,",");
    int day=atoi(strtok(NULL,"-"));
    int mon=atoi(strtok(NULL,"-"));
    int yr=atoi(strtok(NULL,","));
    char *adr=strtok(NULL,",");
    char *email=strtok(NULL,",");
    char *snum=strtok(NULL,",");
     snum[strlen(snum)-1]='\0';
    date dob;
    dob.day=day;
    dob.month=mon;
    dob.year=yr;
    return construct(snum,fn,ln,email,adr,&dob);
}
void printtofile (user *s,FILE *fp)
{

    fprintf(fp,"%s,%s,%d-%d-%d,%s,%s,%s\n",s->lname,s->fname,s->dob->day,s->dob->month,s->dob->year,s->address,s->email,s->phone);
}
int records (FILE *fp)
{
    char buf[200];
    int rec=0;
    while (fgets(buf,sizeof(buf),fp))
        rec++;
    return rec;
}
void clearsreen()
{
    printf("\n\n");
    system("pause");
    system("cls");

}
