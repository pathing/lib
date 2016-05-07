#ifndef _COMMON_H_JSDFKHSDJFKHSKLDFHKLSDF
#define _COMMON_H_JSDFKHSDJFKHSKLDFHKLSDF

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
int split(char *from, char separator, char ***to, int *item_num);
/**
* @fn void split_free(char ***to)
* @brief Free data which malloc by explode
         if you call explode once, and after used 'to',
         then you have to call this functions
* @param[in] to: pointer which point to malloc buffer
* @return none
*/
void split_free(char ***to);

#endif
