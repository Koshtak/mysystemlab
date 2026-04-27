#include<stdint.h>
#include<libmm.h>
#include<stdio.h>
#include<stddef.h>



SlabPool* slab_init(size_t obj_size, size_t count){

void *mem = mmap(NULL, sizeof(SlabPool)+((count+7)/8)+(obj_size*count), PROT_READ|PROT_WRITE, MAP_PRIVATE, MAP_ANONYMOUS, -1, 0);
	if(mem==MAP_FAILED){
		perror("mmap failed");
		return NULL;
	}
SlabPool *pool = (SlabPool*)mem;


pool->obj_size = obj_size;
pool->bitmap_size = bitmap_bytes;


pool->bitmap = (uint_t*)(mem + sizeof(SlabPool));
pool->start =(void*)(pool->bitmap+bitmap_size);

memset(pool->bitmap, 0, pool->bitmap_size);
}



/*
void* slab_alloc(SlabPool *pool){
	for(size_t i=0;i<=pool->total_objs/8;i++){
		if(pool->bitmap[i]==0xFF){i++}
		else for(int j;j<8;j++)
	
	}	
	
}





void slab_free(SlabPool *pool, void *ptr){



}
*/
