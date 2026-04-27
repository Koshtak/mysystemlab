#include<stdint.h>
#include<libmm.h>
#include<stdio.h>
#include<stddef.h>



SlabPool* slab_init(size_t obj_size, size_t count){
size_t bitmap_bytes = (count+7)/8;
size_t total_size =sizeof(SlabPool)+ bitmap_bytes + (count*obj_size);

void *mem = mmap(NULL, total_size, PROT_READ|PROT_WRITE, MAP_PRIVATE, MAP_ANONYMOUS, -1, 0);

if(mem==MAP_FAILED){
	perror("mmap failed");
	return NULL;}

SlabPool *pool = (SlabPool*)mem;


pool->obj_size = obj_size;
pool->obj_size = obj_size;
pool->total_objs = count;
pool->start =(uint8_t*)(pool->bitmap + bitmap_bytes);

memset(pool->bitmap, 0, pool->bitmap_bytes);

return pool;
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
