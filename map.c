#include <stdio.h>
#include "libs/map.h"

//map is 24x12
void initialze_map()
{
    printf("##########################\n");
    for(int j = 0; j < 12; j++)
    {
        printf("#                        #\n");
    }
    printf("##########################\n");    
}