#include <stdio.h>
#include <stdlib.h>

char bes_algorithms_err=0;
//heap is a struct i-->i*2+1&&i*2+2
;;;;;;;;;;;;;;;;;;;;;;;
//swaps
void swapld(long *a,long *b){
    long t;
    t=*a;
    *a=*b;
    *b=t;
    return;
}
void swapu(unsigned int *a,unsigned int *b){
    long t;
    t=*a;
    *a=*b;
    *b=t;
    return;
}
long maxld(long *nums,unsigned int length){
	long max=nums[0];
	for (unsigned int i=1;i<length;i++)max=(max>nums[i])?max:nums[i];
	return max;
}
long minld(long *nums,unsigned int length){
	long min=nums[0];
	for (unsigned int i=1;i<length;i++)min=(min<nums[i])?min:nums[i];
	return min;
}

//package for max heap
void bes_max_heap(long *heap,unsigned int length,unsigned int index,unsigned int * ret){
    //printf("%u ",index);
    //fflush(stdout);
    unsigned int left;
    unsigned int right;
    left=(index<<1)+1;
    right=(index<<1)+2;
    if (right<length){
        // shift & under
        if (heap[index]>heap[left] && heap[index]>heap[right])return;  // index is the max number
        if (heap[left]>heap[right]){
            swapld(&heap[index],&heap[left]);
            if (ret!=NULL)swapu(&ret[left],&ret[index]);
            bes_max_heap(heap,length,left,ret);
        }else{
            swapld(&heap[index],&heap[right]);
            if (ret!=NULL)swapu(&ret[right],&ret[index]);
            bes_max_heap(heap,length,right,ret);
        }
    }else{
        // no right tree
        if (left<length) {
            if (heap[left]>heap[index]) {
                swapld(&heap[index],&heap[left]);
                if (ret!=NULL)swapu(&ret[left],&ret[index]);
            }
        }
    }
    return;
}
void bes_build_heap(long *heap,unsigned int length,unsigned int * ret){
    for (unsigned int i=(length>>1);i!=4294967295;i--)bes_max_heap(heap,length,i,ret);
    return;
}

//sort
//quicksort
/*
unsigned int * bes_quicksort(long *nums,unsigned int length,char (*cmp)(long,long)){
	//undefined
}
*/
void lambda__bes_quicksort0(long *nums,unsigned int length,unsigned int * ret){
	if (length<=1)return;
	unsigned int j=0;
	for (unsigned int i=0;i<length-1;i++){
		if (nums[i]<nums[length-1]){
			swapld(&nums[i],&nums[j]);
			if (ret!=NULL)swapu(&ret[i],&ret[j]);
			j++;
		}
	}
	lambda__bes_quicksort0(nums,j,ret);
	lambda__bes_quicksort0(nums+j,length-j-1,ret+j);
	return;
}
unsigned int * bes_quicksort(long *nums,unsigned int length){
	// nums gives the numbers to sort
	// length gives the length of nums
	// returns index
	// passed
	unsigned int * ret;
	ret=malloc(sizeof (unsigned int) * length);
	long cpy[length];
	for (unsigned int i=0;i<length;i++)cpy[i]=nums[i];
	for (unsigned int i=0;i<length;i++)ret[i]=i;
	lambda__bes_quicksort0(cpy,length,ret);
	return ret;
}
void lambda__bes_heap_sort0(long * heap,unsigned int length,unsigned int * ret){
	for (unsigned int i=length-1;i!=4294967295;i--){
		swapld(&heap[0],&heap[i]);
		if (ret!=NULL)swapu(&ret[0],&ret[i]);
		bes_max_heap(heap,i,0,ret);
	}
	return;
}
unsigned int * bes_heapsort(long *nums,unsigned int length){
	unsigned int *r;
	r=malloc(length*sizeof(unsigned int));
	long cpy[length];
	for (unsigned int i=0;i<length;i++)cpy[i]=nums[i];
	for (unsigned int i=0;i<length;i++)r[i]=i;
	lambda__bes_heap_sort0(cpy,length,r);
	return r;
}

// bits sorting

void lambda__bes_bits_sort(long *nums,unsigned int length,unsigned int *ret){
	// caution only ret is changed
	unsigned int f[length],v[length];
	unsigned int df=0,dv=0;
	for (unsigned int i=1;i!=0x80000000;i<<=1){
		dv=df=0;
		// shift i 1 each time
		// part 1 mov to f&&v
		for (unsigned int j=0;j<length;j++){
			if ((nums[ret[j]]&i))v[dv++]=ret[j];
			else f[df++]=ret[j];
		}
		// part 2 swapback
		for (unsigned int j=0;j<df;j++)ret[j]=f[j];
		for (unsigned int j=0;j<dv;j++)ret[df+j]=v[j];
	}
	df=dv=0;
	for (unsigned int i=0;i<length;i++){
		// >0 or <0
		if (nums[ret[i]]>0)v[dv++]=ret[i];
		else f[df++]=ret[i];
	}
	for (unsigned int i=0;i<df;i++)ret[i]=f[i];
	for (unsigned int i=0;i<dv;i++)ret[df+i]=v[i];
	return;
}
unsigned int * bes_bits_sort(long *nums,unsigned int length){
	unsigned int *r=malloc(sizeof (unsigned int)*length);
	for (unsigned int i=0;i<length;i++)r[i]=i;
	lambda__bes_bits_sort(nums,length,r);
	return r;
}

// bucket sorting

void lambda__bucket_sort0(long * nums,unsigned int length,unsigned int *ret){
	long max=maxld(nums,length),min=minld(nums,length);
	long bucket[length];
	long l[length];
	unsigned int nret[length];
	for (unsigned int i=0;i<length;i++)l[i]=0;
	for (unsigned int i=0;i<length;i++){
		l[(nums[i]-min)*length/(max-min+1)]++;
	}
	bucket[0]=0;
	for (unsigned int i=1;i<length;i++){
		bucket[i]=l[i-1]+bucket[i-1];
	}
	// now bucket is the sum of the number of numbers
	for (unsigned int i=0;i<length;i++){
		if (ret!=NULL)nret[bucket[(nums[i]-min)*length/(max-min+1)]]=ret[i];
		l[bucket[(nums[i]-min)*length/(max-min+1)]++]=nums[i];
	}
	lambda__bes_quicksort0(l,bucket[0],nret);
	for (unsigned int i=1;i<length;i++){
		lambda__bes_quicksort0(&l[bucket[i-1]],bucket[i]-bucket[i-1],&nret[bucket[i-1]]);
	}
	for (unsigned int i=0;i<length;i++)ret[i]=nret[i];
	for (unsigned int i=0;i<length;i++)nums[i]=l[i];
	return;
}
unsigned int * bes_bucket_sort(long *nums,unsigned int length){
	unsigned int *r=malloc(sizeof (unsigned int) * length);
	for (unsigned int i=0;i<length;i++)r[i]=i;
	long x[length];
	for (unsigned int i=0;i<length;i++){
		x[i]=nums[i];
	}
	lambda__bucket_sort0(x,length,r);
	return r;
}

// insert-sorting
// passed

//the nth smallest number

long lambda__quick_find_nth_smallest_number(long *nums,unsigned int length,unsigned int n){
    if (length==0){return nums[0];}
    //first keep the last number and divide it
    unsigned int j=0;
    for (unsigned int i=0;i<length-1;i++) if (nums[i]<nums[length-1])swapld(&nums[i],&nums[j++]); // just like quick-sort
    if (j>n){
        // j>n which means in the later array
        return lambda__quick_find_nth_smallest_number(&nums[j],length-1-j,n-1-j);
    }else if (j<n){
        return lambda__quick_find_nth_smallest_number(nums,j,n);
    }else {
        return nums[length-1];
    }
    return 0;
}

// data-structure

struct bes_d_stack
{
    unsigned int top;  // to discribe how many members in the stack
    long * vals;  // to remember numbers
    unsigned int valsmaxlength;  // to describe the max possible number of members
};
void bes_stack_push(struct bes_d_stack *stack,long sth){
    if ((*stack).valsmaxlength<=(*stack).top){
        bes_algorithms_err+=1;
        return;
        // error caused by memory overflow
    }
    (*stack).vals[(*stack).top++]=sth;
    return;
}
long bes_stack_pop(struct bes_d_stack *stack){
    if ((*stack).top<=0){
        bes_algorithms_err+=1;
        return 0;
    }
    (*stack).top--;
    return (*stack).vals[(*stack).top];
}
struct bes_d_stack new__bes_d_stack(unsigned int length){
    struct bes_d_stack r;
    r.top=0;
    r.vals=malloc(sizeof(long)*length);
    r.valsmaxlength=length;
    return r;
}
void delete__bes_d_stack(struct bes_d_stack stack){
    free(stack.vals);
}

struct bes_d_queue{
    unsigned int low;
    unsigned int high;
    long *vals;
    unsigned int valsmaxlength;
};
void bes_queue_en(struct bes_d_queue * queue,long sth){
    if ((*queue).low==(*queue).high){
        bes_algorithms_err+=1;
        return;
    }
    (*queue).vals[(*queue).high]=sth;
    (*queue).high++;
    (*queue).high%=(*queue).valsmaxlength;
}
long bes_queue_de(struct bes_d_queue * queue){
    if ((*queue).low==((*queue).high-1)%(*queue).valsmaxlength){
        bes_algorithms_err+=1;
        return 0;
    }
    (*queue).low=((*queue).low+1)%(*queue).valsmaxlength;
    return (*queue).vals[(*queue).low];
}
struct bes_d_queue new__bes_d_queue(unsigned int length){
    struct bes_d_queue r;
    r.high=0;
    r.low=length-1;
    r.vals=malloc(sizeof(long)*length);
    r.valsmaxlength=length;
    return r;
}
void delete__bes_d_queue(struct bes_d_stack stack){
    free(stack.vals);
}
struct bes_d_deque{
    unsigned int high;
    unsigned int low;
    long * vals;
    unsigned int valsmaxlength;
};
void bes_deque_enforward(struct bes_d_deque * queue,long sth){
    if ((*queue).low==(*queue).high){
        bes_algorithms_err+=1;
        return;
    }
    (*queue).vals[(*queue).high]=sth;
    (*queue).high++;
    (*queue).high%=(*queue).valsmaxlength;
}
void bes_deque_enbackward(struct bes_d_deque * queue,long sth){
    if ((*queue).low==(*queue).high){
        bes_algorithms_err+=1;
        return;
    }
    (*queue).vals[(*queue).low]=sth;
    (*queue).low=((*queue).low==0)?((*queue).valsmaxlength-1):((*queue).low-1);
    return;
}
long bes_deque_debackward(struct bes_d_deque * queue){
    if (((*queue).low+1)%(*queue).valsmaxlength==((*queue).high)){
        bes_algorithms_err+=1;
        return 0;
    }
    (*queue).low=((*queue).low+1)%(*queue).valsmaxlength;
    return (*queue).vals[(*queue).low];
}
long bes_deque_deforward(struct bes_d_deque * queue){
    if (((*queue).low+1)%(*queue).valsmaxlength==((*queue).high)){
        bes_algorithms_err+=1;
        return 0;
    }
    (*queue).high=((*queue).high==0)?((*queue).valsmaxlength-1):((*queue).high-1);
    return (*queue).vals[(*queue).high];
}
struct bes_d_deque new__bes_d_deque(unsigned int length){
    struct bes_d_deque r;
    r.high=0;
    r.low=length-1;
    r.vals=malloc(sizeof(long)*length);
    r.valsmaxlength=length;
    return r;
}
void delete__bes_d_deque(struct bes_d_stack stack){
    free(stack.vals);
}

struct bes_d_linked_list_object
{
    struct bes_d_linked_list_object * up;
    struct bes_d_linked_list_object * down;
    long value;
};



int main(){
    return 0;
}