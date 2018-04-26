class A{
 public:
   A(){
       int a = 0;
       a = a+1;
   }
   char* str = "Hello";
   static int b;
};
int A::b = 12;
int main(){
    A a;
    return 0;
}
