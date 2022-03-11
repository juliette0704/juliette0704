#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include "my.h"

typedef struct element element;
struct element
{
    int elementkind;
    int value;
    int sign;
    struct element *stacknumber;
    struct element *suivant;
};

typedef struct stack stack;
struct stack
{
    struct element *premier;
};

char eval_expr(char const *string1);
int charToInt(char *string1);
void addElementToStack(struct stack*, int, int);
int unStack(struct stack *stackToDepile);
void printStack(stack*);
stack* infiniteMultiply(stack*, stack*);
stack* reverseStack(stack* stacktoreverse);
stack* infiniteSum(stack *stackstring1, stack *stackstring2);
void readString(const char *string1, stack*, stack*);
int isANumber (char chartotest);
void addStackToStack(stack *targetstack, struct stack *stacktoadd, int elementype, int sign);
void traitementSigne(struct stack *stackOp, struct stack *stackPoland, char signtoadd);
void readPoland(stack *Poland,stack *stackgrandtotal);
void unStackNumbers(stack *stackToDepile, stack *valuenum);
void cvtStackToQueu(stack *poland);
int sizeOfStack(stack *stackstring1);
stack* infiniteSub(stack *, stack *);
char transform_op(char *av, char *buff);
char transform_num(char *av, char *buff);
char transform_op_fin(char *av, char *buff);
char transform_num_fin(char *av, char *buff);

char transform_op(char *av, char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == av[0]) buff[i] = '(';
        if (buff[i] == av[1]) buff[i] = ')';
        if (buff[i] == av[2]) buff[i] = '+';
        if (buff[i] == av[3]) buff[i] = '-';
        if (buff[i] == av[4]) buff[i] = '*';
        if (buff[i] == av[5]) buff[i] = '/';
        if (buff[i] == av[6]) buff[i] = '%'; 
    }
}

char transform_num(char *av, char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == av[0]) buff[i] = '0';
        if (buff[i] == av[1]) buff[i] = '1';
        if (buff[i] == av[2]) buff[i] = '2';
        if (buff[i] == av[3]) buff[i] = '3';
        if (buff[i] == av[4]) buff[i] = '4';
        if (buff[i] == av[5]) buff[i] = '5';
        if (buff[i] == av[6]) buff[i] = '6';
        if (buff[i] == av[7]) buff[i] = '7';
        if (buff[i] == av[8]) buff[i] = '8';
        if (buff[i] == av[9]) buff[i] = '9';
    }
}

char transform_num_fin(char *av, char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '0') buff[i] = av[0];
        if (buff[i] == '1') buff[i] = av[1];
        if (buff[i] == '2') buff[i] = av[2];
        if (buff[i] == '3') buff[i] = av[3];
        if (buff[i] == '4') buff[i] = av[4];
        if (buff[i] == '5') buff[i] = av[5];
        if (buff[i] == '6') buff[i] = av[6];
        if (buff[i] == '7') buff[i] = av[7];
        if (buff[i] == '8') buff[i] = av[8];
        if (buff[i] == '9') buff[i] = av[9];
    }
}

char transform_op_fin(char *av, char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '+') buff[i] = av[2];
        if (buff[i] == '-') buff[i] = av[3];
    }
}

void printStack(stack *stacktoprint)
{
    element *read = malloc(sizeof(*read));
    read = stacktoprint->premier;
    while (read->suivant != NULL) { 
        my_put_nbr(read->value);
        read=read->suivant;
    }
    my_put_nbr(read->value);
}

void addElementToStack(struct stack *stack_charToInt, int valueToAdd, int elementkind)
{
    element *nouveau = malloc(sizeof(*nouveau));
    nouveau->value = valueToAdd;
    nouveau->suivant = stack_charToInt->premier;
    nouveau->stacknumber = NULL;
    nouveau->sign = 0;
    nouveau->elementkind = elementkind;
    stack_charToInt->premier = nouveau;
}

int unStack(struct stack *stackToDepile)
{
    int unstacknumber = 0;
    element *elementDepile = stackToDepile->premier;

    if (stackToDepile != NULL && stackToDepile->premier != NULL) {
        unstacknumber = elementDepile->value;
        stackToDepile->premier = elementDepile->suivant;
        free(elementDepile);
        return unstacknumber;
    }
    return 0;
}

int readElement (struct stack *stackToRead)
{
    int unstacknumber = 0;
    element *elementDepile = stackToRead->premier;

    if (stackToRead != NULL && stackToRead->premier != NULL) {
        unstacknumber = elementDepile->value;
        stackToRead->premier = elementDepile->suivant;
        return unstacknumber;
    }
    return 0;
}

stack* infiniteSub(stack *stackstring1, stack *stackstring2)
{
    int char1 = 0;
    int char2 = 0;
    int tmpsum = 0;
    int retenue = 0;
    stack *stacksum = malloc(sizeof(*stacksum));
    stacksum->premier = NULL;

    while ((stackstring1->premier != NULL) || (stackstring2->premier != NULL))
    {
        char1 = unStack(stackstring1);
        char2 = unStack(stackstring2);    
        tmpsum = char1 - (char2 + retenue);
        if (tmpsum < 0)
        {
            tmpsum = char1 + 10 - (char2 + retenue);
            retenue = 1;
        }
        addElementToStack(stacksum, tmpsum, 1);
    }
    if (stacksum->premier->value == 0) unStack(stacksum);    
    return stacksum;
}

stack* infiniteSum(stack *stackstring1, stack *stackstring2)
{
    int char1 = 0;
    int char2 = 0;
    int tmpsum = 0;
    int retenue = 0;
    stack *stacksum = malloc(sizeof(*stacksum));
    stacksum->premier = NULL;
    while ((stackstring1->premier != NULL) || (stackstring2->premier != NULL))
    {
        char1 = unStack(stackstring1);
        char2 = unStack(stackstring2);    
        tmpsum = char1 + char2 + retenue;
        retenue = 0;
        if (tmpsum < 10)
            addElementToStack(stacksum, tmpsum, 1);
        else
        {
            addElementToStack(stacksum, tmpsum -10 , 1);
            retenue = 1;
        }
    }
    if (retenue == 1)
        addElementToStack(stacksum, 1, 1);
    return stacksum;
}

stack* reverseStack(stack* stacktoreverse)
{
    stack *tmp = malloc(sizeof(*tmp));
    element *elementmp = malloc(sizeof(*elementmp));
    tmp->premier = NULL;
    elementmp = stacktoreverse->premier;
    while (stacktoreverse->premier != NULL) {
        addElementToStack(tmp, unStack(stacktoreverse), 1);        
    }
 return (tmp);
}

stack* infiniteMultiply(stack* stackstring1, stack* stackstring2)
{
    char char1 = 0;
    char char2 = 0;
    int tmpsum = 0;
    int retenue = 0;
    int addzero = 0;
    stack *stacksum = malloc(sizeof(*stacksum));
    stacksum->premier = NULL;
    stack *line1 = malloc(sizeof(*line1));
    line1->premier = NULL;
    stack *line2 = malloc(sizeof(*line2));
    line2->premier = NULL;
    stack *stackline = malloc(sizeof(*stackline));
    line2->premier = NULL;
    element *firstchar1 = malloc(sizeof(*firstchar1));
    firstchar1 = stackstring1->premier;
    void addStackToStack(stack *targetstack, stack *stacktoadd, int elementype, int sign);
    while (stackstring2->premier != NULL)
    {
        retenue = 0;
        if (line1->premier == NULL)
            stackline = line1;
        else
        {
            stackline = line2;
            addElementToStack(line2, 0, 1);
            for (int j = 1; j < addzero; j++)
            {
                addElementToStack(line2, 0, 1);
            }
        }
        char2 = readElement(stackstring2);
        while(stackstring1->premier != NULL)
        {
            char1 = readElement(stackstring1);
            tmpsum = char1 * char2 + retenue;
            retenue = 0;
            if (tmpsum < 10)
                addElementToStack(stackline, tmpsum, 1);
            else
            {
                addElementToStack(stackline, tmpsum - (((int)(tmpsum / 10)) * 10), 1);
                retenue = (int)(tmpsum / 10);
            }

        }
        if (retenue != 0)
            addElementToStack(stackline, retenue, 1);
        stackstring1->premier = firstchar1;
        addzero++;
        if (line2->premier != NULL)
        {      
            line1 = reverseStack(line1);
            line2 = reverseStack(line2);
            line1 = infiniteSum(line1, line2);
        }
    }
    return line1;
}

int isANumber (char chartotest)
{
    if (chartotest > 47 && chartotest < 58)
         return 1;
    else
         return 0;
}

void addStackToStack(stack *poland, struct stack *tmpstack, int elementype, int sign)
{    
    element *nouveau = malloc(sizeof(*nouveau));
    nouveau->stacknumber = tmpstack->premier;
    nouveau->value = 0;
    nouveau->sign = sign;
    nouveau->suivant = poland->premier;
    nouveau->elementkind = elementype;
    poland->premier = nouveau;

}

void readString(const char *string1, stack *stackOp,stack *poland)
{
    int k = 0;
    char *pointer = string1;

    stack *tmpstack = malloc(sizeof(*tmpstack));
    tmpstack->premier = NULL;

    while (*pointer != '\0')
    {   
        if (*pointer > 47 && *pointer < 58)
        {
            addElementToStack(tmpstack, *pointer -48, 1);
            pointer = pointer + sizeof(char);
        }
        else
        {
           if (tmpstack->premier != NULL) addStackToStack(poland, tmpstack, 3, 0);
            traitementSigne(stackOp,poland,*pointer);
            free (tmpstack);
            stack *tmpstack = malloc(sizeof(*tmpstack));
            tmpstack->premier = NULL;
            pointer = pointer + sizeof(char);
        }
    }
    if (*pointer == '\0')
    {
        if (tmpstack->premier != NULL) addStackToStack(poland, tmpstack, 3, 0);
            free (tmpstack);
        while (stackOp->premier != NULL)
           addElementToStack(poland, unStack(stackOp), 2);
    }
 }

void traitementSigne(struct stack *stackOp, struct stack *stackPoland, char signtoadd)
{   
    if (stackOp->premier != NULL)
    {
        element *prevOp = stackOp->premier;
        if (signtoadd == '+' && prevOp->value == '*')
        {
        addElementToStack(stackPoland, unStack(stackOp), 2);
        addElementToStack(stackOp, signtoadd, 2);
        } 
        else if (signtoadd == '-' && prevOp->value == '*')
        {
        addElementToStack(stackPoland, unStack(stackOp), 2);
        addElementToStack(stackOp, signtoadd, 2);
        } 
        else if (signtoadd == '(')
        {
            addElementToStack(stackOp, signtoadd, 2);
        }
        else if (signtoadd == ')')
        {
            int j = unStack(stackOp);
            while(j != '(')
            {
                addElementToStack(stackPoland, j, 2);
                j = unStack(stackOp);
            }
        }
        else
            addElementToStack(stackOp, signtoadd, 2);
    }
    else
        addElementToStack(stackOp, signtoadd, 2);
}

void unStackNumbers(stack *stackToDepile, stack *valuenum)
{
    element *elementDepile = stackToDepile->premier;
    valuenum->premier = elementDepile->stacknumber;

    if (stackToDepile != NULL && stackToDepile->premier != NULL)
    {
        stackToDepile->premier = elementDepile->suivant;
        free (elementDepile);
    }
}

void readPoland(stack *Poland, stack *stackgrandtotal)
{
    element *pointeur = Poland->premier;
    stack *value1 = malloc(sizeof(*value1));
    value1->premier = NULL;
    stack *value2 = malloc(sizeof(*value2));
    value2->premier = NULL;    
    stack *tmpstack = malloc(sizeof(*tmpstack));
    tmpstack->premier = NULL;
    if (pointeur->elementkind == 3)
    {
        tmpstack->premier = pointeur->stacknumber;
        addStackToStack(stackgrandtotal, tmpstack, 3, 0);
        Poland->premier = pointeur->suivant;
        free (pointeur);
    }else
        switch (pointeur->value)
        {
            case (42):
                unStackNumbers(stackgrandtotal, value1);
                unStackNumbers(stackgrandtotal, value2);
                tmpstack = infiniteMultiply(value1,value2);
                tmpstack = reverseStack(tmpstack);
                addStackToStack(stackgrandtotal, tmpstack, 3, 0);
                Poland->premier = pointeur->suivant;
                free (pointeur);
                break;
            case (43):
                unStackNumbers(stackgrandtotal ,value2);
                unStackNumbers(stackgrandtotal ,value1);
                tmpstack = infiniteSum(value1 ,value2);
                tmpstack = reverseStack(tmpstack);
                addStackToStack(stackgrandtotal, tmpstack, 3, 0);
                Poland->premier = pointeur->suivant;
                break;
            case (45):
                unStackNumbers(stackgrandtotal, value2);
                unStackNumbers(stackgrandtotal, value1);
                tmpstack = infiniteSub(value1, value2);
                tmpstack = reverseStack(tmpstack);
                addStackToStack(stackgrandtotal, tmpstack, 3, 0);
                Poland->premier = pointeur->suivant;
                break;
        }
}

void cvtStackToQueu(stack *poland)
{
    element *precedent = malloc(sizeof(*precedent));
    element *pointeur = malloc(sizeof(*pointeur));
    element *tmp = malloc(sizeof(*tmp));
    precedent = poland->premier;
    pointeur = precedent->suivant;
    tmp = pointeur->suivant;
    
    while (pointeur->suivant != NULL)
    {  
        pointeur->suivant = precedent; 
        precedent = pointeur; 
        pointeur = tmp; 
        tmp = tmp->suivant;
    }
    tmp = poland->premier;
    tmp->suivant = NULL;
    poland->premier = pointeur;
    pointeur->suivant = precedent;
}

char eval_expr(char const *string1)
{
    stack *poland = malloc(sizeof(*poland));
    poland->premier = NULL;
    stack *stackop = malloc(sizeof(*stackop));
    stackop->premier = NULL;
    stack *stackgrandtotal = malloc(sizeof(*stackgrandtotal));
    stackgrandtotal->premier = NULL;
    readString(string1, stackop, poland);
    cvtStackToQueu(poland);
    while(poland->premier != NULL)
    {    
      readPoland(poland,stackgrandtotal);  
    }
    stackgrandtotal->premier = stackgrandtotal->premier->stacknumber;
    stackgrandtotal = reverseStack(stackgrandtotal);
    printStack(stackgrandtotal);
}

int charToInt(char *string1)
{
    int totalValue = 0;
    int value = 0;
    int i = 0;
    int unite = 1;
    int j = 1;
    while (string1[i] != '\0')
    {
        value = string1[i] -48;
       
        totalValue += value * unite;  
        i++;
        while (j == i)
        {
            unite *= 10;
            j++;
        }
    }
    return totalValue;
}

int main(int ac , char **av)
{
    int size = charToInt(av[3]);
    char *buff = malloc((size + 1)*sizeof(char));
    int len = 0;

    len = read(0, buff, size);
    buff[size] = '\0';
    transform_num(av[1], buff);
    transform_op(av[2], buff);
    eval_expr(buff);
    my_putchar('\n');
    if (len < 0) return (84);
    return 0;  
}
