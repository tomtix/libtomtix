/*
  Copyright (C) 2016 Thomas Mijieux

  This file is part of libtomtix.

  libtomtix is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  libtomtix is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef t_ERROR_H
#define t_ERROR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

#define TOMTIX_ERROR_LIST(ERROR)                \
    ERROR(TOMTIX_SUCCESS)                       \
    ERROR(TOMTIX_ERR_UNKNOWN_ERROR)             \
    ERROR(TOMTIX_ERR_INVAL)                     \
    ERROR(TOMTIX_ERR_FILE_ERROR)                \
    ERROR(TOMTIX_ERR_FILE_BAD_ENCODING)         \


#define CHECK_ERROR(expr, finally)              \
    do {                                        \
        int err_macro_;                         \
        if ((err_macro_ = (expr)) < 0) {        \
            finally;                            \
            return err_macro_;                  \
        }                                       \
    } while (0)

#define TOMTIX_ERROR_TO_ENUM(error) error,

enum t_error_code {
    TOMTIX_ERROR_LIST(TOMTIX_ERROR_TO_ENUM)
};

const char *t_errmsg(int errcode);

#ifndef __GNUC__
#	define __PRETTY_FUNCTION__    __FUNCDNAME__
#endif


#define __FILENAME__ (strrchr(__FILE__, '/') ?                  \
                      strrchr(__FILE__, '/') + 1 : __FILE__)

#define t_error(format, ...)                                    \
    do {                                                        \
        fprintf(stderr, "ERROR: %s: %d|%s: ",  __FILENAME__ ,   \
                __LINE__, __PRETTY_FUNCTION__);                 \
        fprintf(stderr, format, ##__VA_ARGS__);                 \
    } while(0)

#define t_warning(format, ...)                                  \
    do {                                                        \
        fprintf(stderr, "WARNING: %s: %d|%s: ",  __FILENAME__ , \
                __LINE__, __PRETTY_FUNCTION__);                 \
        fprintf(stderr, format, ##__VA_ARGS__);                 \
    } while(0)


#define t_malloc(size__) malloc(size__)
#define t_free(ptr__) free(ptr__)


#ifdef DEBUG
#define t_debug(format, ...)                                    \
    fprintf(stderr, "DEBUG: %s:%d|%s: " format, __FILENAME__ ,  \
            __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__);
#else // DEBUG
# define t_debug(format, ...) ((void) (format))
#endif // DEBUG

#endif // t_ERROR_H
