#include<stdlib.h>
#include<stdio.h>

class A {
  public:
    A(){
     int c = 0;
     c = c+1;
     }
    virtual void test() {
        printf("A test\n");
    }
    virtual ~A(){
    printf("A destroy\n");
   }
   int a = 100;
};

class B: public A {
  public:
    B(){}
    void test() {
       printf("B test\n");
    }
    ~B(){
     printf("B destroy\n");
    }
};

class C:public B{
    public:
        void test(){
        printf("c test\n");
    }
};

int main() {
    B* b = new B;
    A* a = (A*)b;
    a->test();
    delete a;
    C* c = new C;
    A* b1 = (A*)c;
    b1->test();
    return 0;
}
