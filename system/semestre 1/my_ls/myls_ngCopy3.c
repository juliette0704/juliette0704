/*
** EPITECH PROJECT, 2021
** my_ls.c
** File description:
** task
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

typedef struct dirElement dirElement;
struct dirElement
{
    char *fileName;
    char fileType;
    char *path;
    struct ls_string *nextDir;
         
    dirElement *nextElement;
};

typedef struct ls_string ls_string;
struct ls_string
{
    char *basedir;
    dirElement *first_Element;
    int ptrlen;
    
};



typedef struct bool bool;
struct bool
{
    int flag_l;
    int flag_a;
    int flag_t;
};

void readLs(ls_string* ls);
char* stringConcat(char* prevdir,char* chartoadd);
void printf_list_R(ls_string *ptr);

//////////////////////////////////////////////////////////////////////////////////////:
/////////////////////////////////                        /////////////////////////////::
/////////////////////////////:                               ///////////////////////////


void printf_list(ls_string *ptr)
{
    dirElement *ptrname = malloc(sizeof(*ptrname));
    ptrname = ptr->first_Element;
    
    printf("%s :  \n", ptr->basedir);
    while (ptrname != NULL) {
        
        printf("%s  ", ptrname->fileName);
        ptrname = ptrname->nextElement;
    }
    
}

void printf_list_R(ls_string *ptr)
{
    dirElement *ptrname = malloc(sizeof(*ptrname));
    ptrname->fileName = ptr->first_Element->fileName;
    ptrname->nextElement= ptr->first_Element->nextElement;
    while (ptrname != NULL) 
    {
        
        if (ptrname->fileType==0x4 && ptrname->fileName[0] !='.')
        {
            printf("\n\n");
            printf_list(ptrname->nextDir);
            
            printf_list_R(ptrname->nextDir);
        }
        ptrname = ptrname->nextElement;
    }
    
    
}

void addFileToList(struct dirent* readfile,ls_string* ls)
{
    struct dirElement *file2Add = malloc(sizeof(*file2Add));       
                    
        file2Add->fileName = readfile->d_name; 
        file2Add->fileType = readfile->d_type;
                
        //numberoffiles += 1; 
        
        if (ls->first_Element == NULL) 
        {
            file2Add->path=ls->basedir;
            file2Add->nextElement = NULL;
            }
        else 
        {
            
            file2Add->nextElement = ls->first_Element;
            
            }
        if (readfile->d_type==0x4 && readfile->d_name[0] !='.')
        {
            ls_string* newdir=malloc(sizeof(*newdir));
            file2Add->nextDir=newdir;
            newdir->first_Element=NULL;
            newdir->basedir=stringConcat(ls->basedir,file2Add->fileName);
            readLs(newdir);
            
        }

        ls->first_Element = file2Add;
}

char* stringConcat(char* prevdir,char* chartoadd)
{
    int stringlen=0;
    int lenchartoadd=0;
    int i=0;
    int j=0;
    
     while(prevdir[stringlen] != '\0')
            {
                stringlen+=1;
            }
    while (chartoadd[lenchartoadd] != '\0')
            {
                lenchartoadd+=1;
            }
    char* NewDirName = malloc((stringlen+lenchartoadd+1)*sizeof(char));
    for (;i<stringlen;i++)
    {
        NewDirName[i]=prevdir[i];
    }
     NewDirName[i]='/';
    for (i=stringlen;i<stringlen+lenchartoadd;i++)
    {
         NewDirName[i]=chartoadd[j];
         j+=1;
    }
    NewDirName[i]='/';
return NewDirName;
}

void readLs(ls_string* ls)
{
    struct dirent *readfile;   
    DIR *repo;
    int numberoffiles = 0;
    //numberoffiles = 0;
    repo = opendir(ls->basedir);
    readfile = readdir(repo);
    while (readfile) 
    {
        addFileToList(readfile,ls);        
        readfile = readdir(repo);
        
    }


    
}

int main(int ac, char **av)
{
    bool *whatflag = malloc(sizeof(*whatflag));
    ls_string *ls = malloc(sizeof(*ls));
    
    ls->first_Element=NULL;
    ls->basedir="./";
    if (ac > 2) 
    {
        //whatflag=lecture(whatflag, av);        
        readLs(ls);
        //alpha_order(fnbp);
        printf_list(ls);
        printf_list_R(ls);
        //makeDirString(basedir,fnbp);
        if (whatflag->flag_a)
        {
            //fnbp=flag_a(fnbp);
        }
    }
}