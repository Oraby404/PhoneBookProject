#include "Header.h"
int main()
{
    user **aos=calloc(100,sizeof(user)*100);
    int op=0,i=0,n=0,j,p;
    int loaded=0;
    FILE *fp;
    printf("Welcome To PhoneBook Project!\n\t**********\n");
    while(1)
    {
        op=entry();
        if(op==1) //load
        {
            loaded=1;
            int pn,m;
            char buf[200];
            fp=fopen("Project.txt","a+");
            int rec=records(fp);
            fseek(fp,0L,SEEK_SET);
            for (i=0; i<rec; i++)
            {
                if (!fgets(buf,sizeof(buf),fp))
                    break;
                aos[i]=decodeText(buf);
            }
            printf("Do You Wish To Display The Loaded Data?\n1)Yes\t2)No\nOption:");
            m=scope();
            if(m==1)
                printalltoscreen(aos,rec);
            else if(m==2)
            {
                clearsreen();
                continue;
            }

            else
                printf("\nERROR : INVALID OPTION!\n");
            fclose(fp);

        }
        if (op==2) //search
        {
            char lname[20];
            int sm;
            int flag;
            if(loaded==0)
            {
                printf("\n\tERROR!! DATA ISN'T LOADED!!");
                clearsreen();
                continue;
            }
            printf("Choose A Searching Method : \n1)Search By Last Name\n2)Full Search\n");
back0:
            printf("Option :");
            sm=scope();
            if(sm==1)
            {
back1:
                printf("Please Enter The Last Name :");
                fgets(lname,20,stdin);
                lname[strlen(lname)-1]='\0';
                if(charonly(lname)==0 || strcasecmp(lname,"")==0)
                {
                    printf("INVALID NAME!\n");
                    goto back1;
                }
                searchbyln(aos,lname,i);
            }
            if(sm==2)
            {
                fp=fopen("Project.txt","a+");
                int flag=fullsearch(aos,i);
                if(!flag)
                    printf("No Record Found \n");

            }
            if(sm<1 ||sm>2)
            {
                printf("\nERROR : INVALID OPTION!\n");
                goto back0;
            }
        }
        if(op==3) //ADD
        {

            int c,k;
backa:
            printf("Enter The Number Of Contacts You Want To Add : ");
            n=scope();
            if(n<=0)
            {
                printf("ERROR! INVALID NUMBER OF CONTACTS!\n");
                goto backa;
            }
            fp=fopen("Project.txt","a+");
            if(i==0)
                c=0;
            else
                c=records(fp);
            for(i,k=1; i<n+c; i++,k++)
            {
                printf("Contact %d\n",k);
                readnoskip(i,aos);
            }
            printf("\n MAKE SURE TO SAVE THE CONTACT!\n");
            fclose(fp);
        }

        if(op==4) //Delete
        {
            if(loaded==0)
            {
                printf("\n\tERROR!! DATA ISN'T LOADED!!");
                clearsreen();
                continue;
            }
            char lname[20],fname[20];
            int del,q;
///////////
back2:
            printf("Please Enter The First Name :");
            fgets(fname,20,stdin);
            fname[strlen(fname)-1]='\0';
            if(charonly(fname)==0 || strcasecmp(fname,"")==0)
            {
                printf("INVALID NAME!\n");
                goto back2;
            }
back3:
            printf("Please Enter The Last Name :");
            fgets(lname,20,stdin);
            lname[strlen(lname)-1]='\0';
            if(charonly(lname)==0 || strcasecmp(lname,"")==0)
            {
                printf("INVALID NAME!\n");
                goto back3;
            }
            del=searchfullname(aos,fname,lname,i);
            if(del<0)
            {
                clearsreen();
                continue;
            }
            printtoscreen(aos[del]);
            printf("\nARE YOU SURE YOU WANT TO DELETE THIS CONTACT?\n1)Yes\t2)No\n");
backq:
            printf("Option : ");
            q=scope();
            if(q==1)
            {
                aos[del]=aos[i-1];
                i--;
                printf("\nContact Will Be Deleted After Saving");
                printf("\n MAKE SURE TO SAVE THE MODIFICATIONS!\n");
            }
            else if(q==2)
            {
                clearsreen();
                continue;
            }
            else
            {
                printf("\nERROR : INVALID OPTION!\n");
                goto backq;
            }

        }
        if(op==5) //Modify
        {
            if(loaded==0)
            {
                printf("\n\tERROR!! DATA ISN'T LOADED!!");
                clearsreen();
                continue;
            }
            char lname[20];
            int arr[100],f;
            int *p=arr;
back4:
            printf("Please Enter The Last Name :");
            fgets(lname,20,stdin);
            lname[strlen(lname)-1]='\0';
            if(charonly(lname)==0 || strcasecmp(lname,"")==0)
            {
                printf("INVALID NAME!\n");
                goto back4;
            }
            int norec=searchbylnmod(aos,lname,i,p);
            if(norec)
            {
                printf("\nPlease Choose A Contact To Modify :");
                p=scope();
                for(f=0; f<norec; f++)
                {
                    if(arr[f]==p)
                    {
                        readonly(p,aos);
                        printf("Contact Will Be Modified After Saving");
                        printf("\n MAKE SURE TO SAVE THE MODIFICATIONS!\n");
                        break;
                    }
                    else if (arr[f]!=p && f==norec-1)
                        printf("\n\nERROR!! CONTACT IS NOT LISTED ABOVE!");
                }

            }
        }
        if(op==6) //Sort
        {
            if(loaded==0)
            {
                printf("\n\tERROR!! DATA ISN'T LOADED!!");
                clearsreen();
                continue;
            }
            int sop,m;
            fp=fopen("Project.txt","a+");
            int rec=records(fp);
            printf("Choose a Sorting Option :\n1)Sort By First Name.\n2)Sort By Last Name.\n3)Sort By Date Of Birth.\n");
back:
            printf("Option :");
            sop=scope();
            if (sop==1)
                sortbyfname(aos,fp);
            if (sop==2)
                sortbylname(aos,fp);
            if(sop==3)
                sorbydob(aos,fp);
            if(sop<1 || sop>3)
            {
                printf("\nERROR : INVALID OPTION!\n");
                goto back;
            }
            printf("Do You Wish To Display The Sorted Data?\n1)Yes\t2)No\n");

backs:
            printf("Option :");
            m=scope();
            if(m==1)
                printalltoscreen(aos,rec);
            else if(m==2)
            {
                clearsreen();
                continue;
            }
            else
                printf("\nERROR : INVALID OPTION!\n");

            fclose(fp);
        }

        if(op==7) //save to file
        {
            int w;
            if(loaded==0)
            {
                fp=fopen("Project.txt","a+");
                for(w=0; w<i; w++)
                    printtofile(aos[w],fp);
                fclose(fp);
                printf("\nContacts Saved To File\n");
            }
            else
            {
                fp=fopen("Project.txt","w");
                for(w=0; w<i; w++)
                    printtofile(aos[w],fp);
                fclose(fp);
                printf("\nContacts Saved To File\n");
            }
        }
        if(op==8) //exit
        {
            int ex;
            printf("ALL CHANGES WILL BE DISCARDED , MAKE SURE TO SAVE FIRST!\n\n\tEXIT ANYWAY?\n\n\t1)YES\t2)NO\n");
backe:
            printf("Option :");
            ex=scope();
            if(ex==1)
                exit(0);
            else if(ex==2)
            {
                clearsreen();
                continue;
            }
            else
            {
                printf("\nERROR : INVALID OPTION!\n");
                goto backe;
            }


        }
        if(op>8 || op<=0)
            printf("ERROR : INVALID OPTION!\n");

        clearsreen();
    }
    free(aos);
    return 0;
}
