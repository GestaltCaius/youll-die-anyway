#ifndef UTIL_H
#define UTIL_H

/**
** @file util.h
** @brief misc functions
** @author Rod Guillaume
** @version 1.0
** @date 2017-12-03
*/


/**
** @brief 2D position structure
*/
struct pos
{
    float x;
    float y;
};

/**
** @brief creates a struct pos {x, y}
*/
struct pos pos_create(float x, float y);

#endif /* UTIL_H*/
