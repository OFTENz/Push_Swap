#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct unitt
{
    int *numb;

    struct unitt *bef;
    
}unitt;

unitt *orgnz(int *content);

#endif