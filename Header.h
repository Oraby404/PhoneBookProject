#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    int day;
    int month;
    int year;
} date;
typedef struct
{
    char *phone;
    char *fname;
    char *lname;
    char *email;
    char *address;
    date *dob;
} user;
user* construct (char* x,char*fn,char*ln,char*email,char*adr,date *birthd);
user *decodeText(char *line);
void printtofile (user *s,FILE *fp);
void printtoscreen(user *s);
void printalltoscreen (user **ps,int n);
int records (FILE *fp);
int entry ();
int fullsearch (user **aos,int i);
int searchbyln (user **aos,char*lname,int i);
int searchfullname (user **aos,char*fname,char*lname,int i);
int searchbylnmod (user **aos,char*lname,int i,int *arr);
void sortbylname (user **aos,FILE *fp);
void sortbyfname (user **aos,FILE *fp);
void sorbydob (user **aos,FILE *fp);
int digitonly (char*str);
int charonly (char*str);
void read_constr (int i,user **aos);
void readonly (int i,user **aos);
void readnoskip (int i,user **aos);
int scope();
void clearsreen();
#endif // HEADER_H_INCLUDED
