#include<stdlib.h>
#include<stdio.h>

class Parent {
public:
    int iparent;
    Parent():iparent(10){}
    virtual void f(){
        printf("parent::f()\n");
    }
    virtual void g(){
        printf("parent::g()\n");
    }
    virtual void h(){
        printf("parent::f()\n");
    }
};

class Child:public Parent{
public:
    int ichild;
    Child():ichild(100){}
    virtual void f(){
        printf("child::f()\n");
    }

    virtual void g_child(){
        printf("child::g_child()\n");
    }
    
    virtual void h_child(){
        printf("child::h_child()\n");
    }
};

class GrandChild:public Parent{
    public:
    int igrantchild;
    GrandChild():igrantchild(1000){}
    virtual void f(){
        printf("grantchild::f\n");
    }

    virtual void g_child(){
        printf("grantchild::g\n");
    }
    
    virtual void h_grant(){
        printf("grant::h\n");
    }
};

int main(){
typedef void(*Fun)(void);

GrandChild gc;
int **pVtab = (int**)&gc;
for(int i = 0; (Fun)pVtab[0][i]!=NULL;i++){
    ((Fun)pVtab[0][i])();
}
return 0;
}
