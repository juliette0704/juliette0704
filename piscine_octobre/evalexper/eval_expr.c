/*
** EPITECH PROJECT, 2021
** eval_expr.c
** File description:
** task
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct element element;
struct element
{
    int elementkind;
    int value;
    struct element *next;
};

typedef struct stack stack;
struct stack
{
    struct element *first;
};

int isNum (char chartotest)
{
    if (chartotest > 47 && chartotest < 58)
        return 1;
    else
        return 0;
}

void addElementToStack(struct stack *stack_charToInt, int valueToAdd, int elementkind)
{
    element *new = malloc(sizeof(*new));
    new->value = valueToAdd;
    new->next = stack_charToInt->first;
    new->elementkind = elementkind;
    stack_charToInt->first = new;
}

int unStack(struct stack *stackToDepile)
{
    int unstacknumber = 0;
    element *elementPop = stackToDepile->first;

    if (stackToDepile != NULL && stackToDepile->first != NULL)
    {
        unstacknumber = elementPop->value;
        stackToDepile->first = elementPop->next;
        free(elementPop);
    }
    return unstacknumber;
}

int charToInt(struct stack *stackCharToInt)
{
    int totalValue = 0, value = 0, i = 0;
    int unite = 1;
    int j = 1;

    while (stackCharToInt->first != NULL)
    {
        value = unStack(stackCharToInt) -48;
        
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

int readPoland(struct stack *stackPoland,struct stack *stackTotal)
{
    element *pointer = stackPoland->first;
    int value1 = 0, value2 = 0, valuetoadd = 0;

    if (pointer->elementkind == 1)
    {
        addElementToStack(stackTotal, pointer->value, 1);
        stackPoland->first = pointer->next;
        free (pointer);
    }else
        switch (pointer->value)
        {
            case (42):
                value2 = unStack(stackTotal);
                value1 = unStack(stackTotal);
                valuetoadd = value1 * value2;
                addElementToStack(stackTotal, valuetoadd, 1);
                stackPoland->first = pointer->next;
                free (pointer);
                break;
            case (43):
                value2 = unStack(stackTotal);
                value1 = unStack(stackTotal);
                valuetoadd = value1 + value2;
                addElementToStack(stackTotal, valuetoadd, 1);
                stackPoland->first = pointer->next;
                free (pointer);
                break;  
            case (45):
                value2 = unStack(stackTotal);
                value1 = unStack(stackTotal);
                valuetoadd = value1 - value2;
                addElementToStack(stackTotal, valuetoadd, 1);
                stackPoland->first = pointer->next;
                free (pointer);
                break;
        }
}

void addToPoland(struct stack *stackPoland, int valuetoadd, int typedeval)
{
    element *newElement = malloc(sizeof(*newElement));
    
    newElement->value = valuetoadd;
    newElement->elementkind = typedeval;
    newElement->next = NULL;

    if (stackPoland->first != NULL)
    {
        element *pointer = stackPoland->first;
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
        }
        pointer->next = newElement;
    }
    else
    {
        stackPoland->first = newElement;
    }
}

void traitementSigne(struct stack *stackOp, struct stack *stackPoland, char signtoadd)
{
    if (stackOp->first != NULL)
    {
        element *prevOp = stackOp->first;
        if (signtoadd == '+' && prevOp->value == '*')
        {
        addToPoland(stackPoland, unStack(stackOp), 2);
        addElementToStack(stackOp, signtoadd, 2);
        } 
        else if (signtoadd == '-' && prevOp->value == '*')
        {
        addToPoland(stackPoland, unStack(stackOp), 2);
        addElementToStack(stackOp, signtoadd, 2);
        } 
        else if (signtoadd == '(')
        {
            addElementToStack(stackOp, signtoadd, 2);
        }
        else if (signtoadd == ')')
        {
            int j = unStack(stackOp);
            while(j !='(')
            {
                addToPoland(stackPoland, j, 2);
                j = unStack(stackOp);
            }
        }
        else
            addElementToStack(stackOp, signtoadd, 2);
    }
    else
        addElementToStack(stackOp, signtoadd, 2);
}

int eval_expr(char const *string1)
{
    int i = 0, isnumeric = 0, valueint = 0, val1 = 0;
    int grandtotal = 0;
    struct stack *stackCharToInt = malloc(sizeof(*stackCharToInt));
    stackCharToInt->first = NULL;
    struct stack *stackPoland = malloc(sizeof(*stackPoland));
    struct stack *stackOp = malloc(sizeof(*stackOp));
    stackOp->first = NULL;
    stackPoland->first = NULL;
    struct stack *stackTotal = malloc(sizeof(*stackTotal));
    stackTotal->first = NULL;

    while (string1[i] != '\0')
    {
        isnumeric = isNum(string1[i]);
        if (isnumeric == 1 && string1[i+1] == '\0')
        {
             if (stackCharToInt->first != NULL)
            {
                valueint = charToInt(stackCharToInt);
                addToPoland(stackPoland, valueint, 1);
            } 
            else
                addToPoland(stackPoland,string1[i]-48,1);
         }
        else if (isnumeric == 1)
            addElementToStack(stackCharToInt, string1[i], 0);
        else
        {
            if (stackCharToInt->first != NULL)
            {
                valueint = charToInt(stackCharToInt);
                addToPoland(stackPoland, valueint, 1);
            }
            traitementSigne(stackOp, stackPoland, string1[i]);
        }
        i++;
    }
    while (stackOp->first != NULL)
    {
       addToPoland(stackPoland, unStack(stackOp), 2);
    }
    while(stackPoland->first != NULL)
    {
      readPoland(stackPoland,stackTotal);
    }
    element *read = stackTotal->first;
    grandtotal = read->value;
    return grandtotal;
}

int main(int ac , char **av)
{
     
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return 0;
    }
    return 84;
}
