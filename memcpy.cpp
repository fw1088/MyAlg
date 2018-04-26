#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void memcpy(char* dst,char* src){
	if(dst == NULL || src == NULL){
		return;
	}
	int len = strlen(src)+1;
	if(dst >= src && dst <= src+len-1){
		dst = dst + len - 1;
		src = src + len -1;
		while(len--){
			*dst = *src;
		}
	} else {
		while(len--){
			*dst++ = *src++;
		}
	}
}

void* memcpy(void* dst,void* src,size_t count){
	if(dst == NULL || src == NULL){
		return NULL;
	}
	unsigned char* pdst = (unsigned char*)dst;
	const unsigned char* psrc = (const unsigned char*)src;
	bool flag1 = (pdst >= psrc && pdst < psrc + count);
	bool flag2 = (psrc >= pdst && psrc < pdst + count);
	if(flag1 || flag2){
		return NULL;
	}

	while(count--){
		*pdst = *psrc;
		pdst++;
		psrc++;
	}
	return dst;
}

char* test() {
	char test[] = "cccc";
	return test;
}

int main(){
	printf("%s",test());
	return 0;
	char* d = "cccc";
	char src[] = "Hello";
	char* dst = new char[strlen(src)];
	char a[5]="CC";
	char b[] = "Hello";
	char* c = new char[5];
	printf("%d-%d-%d\n",strlen(a),strlen(b),strlen(c));
	printf("%d-%d-%d\n",sizeof(a),sizeof(b),sizeof(c));
	printf("%s\n",a);
	//memcpy(dst,src,strlen(src));
	//printf("%s--%d\n",src,strlen(src));
	return 0;

}
