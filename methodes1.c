#include "push_swap.h"

unitt *mv_to_struct(unitt *old, int *content)
{
    unitt   *p;

    p = malloc(sizeof(unitt));
    if (!p)
        return(NULL);
    (*p).numb = content;
    (*p).bef = old;
}

