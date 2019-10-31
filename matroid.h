#ifndef MATROID_H
#define MATROID_H

#include <stdio.h>
#include <stdlib.h>

#pragma once

#define MATROID_ALEN(a) (sizeof(a) / sizeof(*a))

#define matroid_base       \
    struct {            \
        size_t cap, len;\
    }

#define matroid(T)         \
    struct matroid##T {   \
        matroid_base;      \
        T data[];       \
    }

#define matroid_new(T, xs...)                                                    \
({                                                                            \
    const size_t initial_size = 16;                                           \
    const T _xs[] = {xs};                                                     \
    struct matroid_##T *v = malloc(sizeof(matroid(T)) + sizeof(T) * MATROID_ALEN(_xs));\
    v->cap = initial_size;                                                    \
    v->len = MATROID_ALEN(_xs);                                                  \
                                                                              \
    for (int i = 0; i < v->len; ++i)                                          \
        v->data[i] = _xs[i];                                                  \
                                                                              \
    v;                                                                        \
})

#define matroid_free(v) free(v)

#define matroid_pop(v) (v->data[--v->len])

#define matroid_ref(v, i) (&v->data[i])

#define matroid_at(v, i) (*(matroid_ref(v, i)))

#define matroid_push(v, i)                                  \
({                                                      \
        v->cap += sizeof(i);                            \
        typeof(v) tem =realloc(v, (2* sizeof(i) + v->cap * sizeof(v)) ) ;\
        v =  tem;    \
                                                        \
    v->data[v->len++] = (i);                            \
})

#define GET_FMT_SPEC(x) _Generic((x), int: "%d", float: "%f", char*: "%s")

#define matroid_print(v)                                                   \
({                                                                      \
    printf("[");                                                        \
    for (int i = 0; i < v->len; ++i) {                                  \
        printf(GET_FMT_SPEC(v->data[i]), v->data[i]);                   \
        if (i + 1 < v->len)                                             \
            printf(", ");                                               \
    }                                                                   \
    printf("]\n");                                                      \
})

#ifdef MATROID_USE_RAII
static inline _matroid_free(void **matroid) { free(*matroid); }
#define raii __attribute__ ((cleanup(_matroid_free)))
#endif

#endif