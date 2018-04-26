#include<stdio.h>
#include<stdlib.h>

class Parent{
  public:
      int a=100;
      virtual void test(){
        printf("Parent");
      }
};

class normal {
 public:
    int a = 1;
    void test(){}
};

class Child1:virtual public Parent{
  public:
      int b;
      virtual void test(){
         printf("B");
      }
      void test1(){}
      int a=12;
};

class Child2:virtual public Parent{
  public:
      virtual void test12(){
          printf("C\n");
      }
      void test1(){}
      int c;
      int a = 14;
};

class D: public Child1,public Child2{
   public:
      int d;
      virtual void test4(){
          printf("D-test4\n");
      }
      virtual void test(){
          printf("D--call test\n");
      }
      virtual void test3(){
          printf("D-test3\n");
      }
};


int main(){
   D* d = new D;
   int a = d->a;
   printf("%d\n",a);
   
  //    normal n;
  //  int *a = new int[5];
   // D d;
   // typedef void(*F)();
   // int** pVtable = NULL;
   // pVtable = (int**)&d;
   // F pFun =(F)pVtable[0][2];
   // pFun();
    //int* op = reinterpret_cast<int*>(&d);
    //int* table = reinterpret_cast<int*>(*(op));
    //F fun = reinterpret_cast<F>(*(table));
    //fun();
    return 0;
}
