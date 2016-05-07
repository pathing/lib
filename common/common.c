#include <stdlib.h>
#include <string.h>

/**
* @fn int split(char *from, char separator, char ***to, int *item_num)
* @brief Separate string by separator
* @param from: buffer that want to separate
* @param separator: separator
* @param to: save return separate result
* @param item_num: splited data nums
* @return 0: success
*         -1: failed(malloc failed)
* @warn  remenber to free *to, so have to call split_free() after called explode()
*/
int split(char *from, char separator, char ***to, int *item_num)
{
    int i, k, n;
    unsigned int from_len = strlen(from);
    char **ret;

    for(i=0, n=1; from[i]!='\0'; i++){
        if (from[i] == separator){
            n++;
            from[i] = '\0';
        }
    }

    ret = (char **)malloc(n*sizeof(char *));
    if(ret == NULL){
        return -1;
    }

    ret[0] = from;
    for(i = 0, k = 1; i  < from_len && k < n; i++){
        if(from[i] == '\0'){
            ret[k] = &from[i + 1];
            k++;
        }
    }
    *to = ret;
    *item_num = n;

    return 0;
}

/**
* @fn void split_free(char ***to)
* @brief Free data which malloc by explode
         if you call explode once, and after used 'to',
         then you have to call this functions
* @param[in] to: pointer which point to malloc buffer
* @return none
*/
void split_free(char ***to)
{
    if(*to != NULL){
        free((void *)*to);
        *to = NULL;
    }
}
