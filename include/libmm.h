#ifndef LIBMM_H
#define LIBMM_H

typedef struct{
void *start
size_t obj_size
size_t total_objs
uint8_t *bitmap[]; //flexible array member
}SlabPool;

SlabPool* slab_init(size_t obj_size, size_t count);
void* slab_alloc(SlabPool *pool);
void slab_free(SlabPool *pool, void *ptr);

#endif
