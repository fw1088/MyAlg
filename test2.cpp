#include<stdlib.h>
#include<stdio.h>

class A{
    public:
    virtual  A(){
test(); 
      }
      ~A(){
       test();
       }
      virtual void test(){
    printf("A test\n");
};
};

class B:public A{
    public:
     B(){
   test();
     }
     void test(){
   printf("B test\n");
}
    
};

int main() {
 B b;
  return 0;
}
