#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct unitt
{
    int *numb;

    struct unitt *bef;
    
}unitt;

unitt *mv_to_struct(unitt *old, int *content);

#endif