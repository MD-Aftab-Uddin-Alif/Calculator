#include<iostream>
using namespace std;
//Static
class Static
{
public:
    static void display()
    {
        cout<<"This is a calculator"<<endl;
    }
};
class CO_and_MU
{
private:
    int n;
    friend void factorial(CO_and_MU n);//Friend function
public:
    void input()
    {
        cout<<"Enter a number: ";
        cin>>n;
    }
};
//Call friend function
void factorial(CO_and_MU t)
    {
    int f=1,i;
    for(i=1;i<=t.n;i++)
    {
        f=f*i;
    }
    cout<<"Factorial: "<<f<<endl;
   }
//Hybrid inheritance
class summation
{
public:
    mutable int x1,y1;//Mutable
    void input() const//Constant function
    {
        cout<<"Enter your inputs: ";
        cin>>x1>>y1;
        cout<<"Sum is:"<<x1+y1<<endl;
    }
};
class summation1: public virtual summation//Virtual
{
public:
    mutable double x2,y2;//Mutable
    void input()const//Constant function & Function overriding
    {
        cout<<"Enter your inputs: ";
        cin>>x2>>y2;
        cout<<"Sum is:"<<x2+y2<<endl;
    }
};
class summation2: public virtual summation//Virtual
{
public:
    mutable double x3;//Mutable
    mutable int y3;//Mutable
    void input()const//Constant function & Function overriding
    {
        cout<<"Enter your inputs: ";
        cin>>x3>>y3;
        cout<<"Sum is:"<<x3+y3<<endl;
    }
};
class summation3: public summation1,public summation2
{
public:
    mutable int x4;//Mutable
    mutable double y4;//Mutable
    void input()const//Constant function & Function overriding
    {
        cout<<"Enter your inputs: ";
        cin>>x4>>y4;
        cout<<"Sum is:"<<x4+y4<<endl;
    }
};
//Multilevel inheritance
class subtraction
{
public:
    int x1,y1;
    void sub()
    {
        cout<<"Enter your inputs: ";
        cin>>x1>>y1;
        cout<<"Sum is:"<<x1-y1<<endl;
    }
};
class subtraction1: public subtraction//Parent class subtraction
{
public:
    double x2,y2;
    void sub1()
    {
        cout<<"Enter your inputs: ";
        cin>>x2>>y2;
        cout<<"Sub is:"<<x2-y2<<endl;
    }
};
class subtraction2: public subtraction1//Parent class subtraction1
{
public:
    double x3;
    int y3;
    void sub2()
    {
        cout<<"Enter your inputs: ";
        cin>>x3>>y3;
        cout<<"Sub is:"<<x3-y3<<endl;
    }
};
class subtraction3: public subtraction2//Parent class subtraction2
{
public:
    int x4;
    double y4;
    void sub3()
    {
        cout<<"Enter your inputs: ";
        cin>>x4>>y4;
        cout<<"Sub is:"<<x4-y4<<endl;
    }
};
class FO_and_EH
{
public:
    int x1,y1;
    double x2,y2;
    int x3; double y3;
    double x4; int y4;
    void division(int a,int b)//Function overloading
    {
        //Exceptional handeling
        try
        {
            if (b != 0)
                {
                float div = (float)a/b;
                if (div < 0)
                throw 'e';
                cout<<"a/b = "<<div<<endl;
               }
            else throw b;
       }
       catch (int e)
       {
        cout<<"Exception: Division by zero"<<endl;
       }
       catch (char st)
       {
        cout<<"Exception: Division is less than 1"<<endl;
       }
       catch (...)
       {
           cout << "Default Exception\n";
       }
    }
    void division(double a,double b)//Function overloading
    {
        //Exceptional handeling
        try
        {
            if (b != 0)
                {
                float div = (float)a/b;
                if (div < 0)
                throw 'e';
                cout<<"a/b = "<<div<<endl;
               }
            else throw b;
       }
       catch (double e)
       {
        cout<<"Exception: Division by zero"<<endl;
       }
       catch (char st)
       {
        cout<<"Exception: Division is less than 1"<<endl;
       }
       catch (...)
       {
           cout << "Default Exception\n";
       }
    }
    void division(int a,double b)//Function overloading
    {
        //Exceptional handeling
        try
        {
            if (b != 0)
                {
                float div = (float)a/b;
                if (div < 0)
                throw 'e';
                cout<<"a/b = "<<div<<endl;
               }
            else throw b;
       }
       catch (double e)
       {
        cout<<"Exception: Division by zero"<<endl;
       }
       catch (char st)
       {
        cout<<"Exception: Division is less than 1"<<endl;
       }
       catch (...)
       {
           cout << "Default Exception\n";
       }
    }
    void division(double a,int b)//Function overloading
    {
        //Exceptional handeling
        try
        {
            if (b != 0)
                {
                float div = (float)a/b;
                if (div < 0)
                throw 'e';
                cout<<"a/b = "<<div<<endl;
               }
            else throw b;
       }
       catch (int e)
       {
        cout<<"Exception: Division by zero"<<endl;
       }
       catch (char st)
       {
        cout<<"Exception: Division is less than 1"<<endl;
       }
       catch (...)
       {
           cout << "Default Exception\n";
       }
    }
};
class circle
{
public:
    int a,b;
    double c;
    void area(int test) throw(int, double);
};
void circle::area(int test) throw(int, double)//Use scope rsolution and resting exception
{
if(test==1) throw test; // throw int
if(test==2) throw 123.23; // throw double
if(test==3) throw 'a'; // throw char
}
class operator_overloading
{
public:
    int a;
    inline int cube(void)
    {
        return a*a*a;//Inline function
    }
    operator_overloading operator+(const operator_overloading& y)//Constant & Operator overloading
    {
        operator_overloading obj;
        obj.a=this->a+y.a;//This pointer
        return obj;
    }
};
class multiplication
{
public:
    double x,y;
    multiplication (double i,double j)//Parameterized constructor
    {
        x=i;
        y=j;
        cout<<"Multiple: "<<i*j<<endl;
    }
};
int main()
{
    int choice;
    Static::display();//Use scope resolution
    while(1)
    {
    cout<<"\n------------------------------------------------------------------------------------"<<endl;
    cout<<"1.Division\n2.Summation\n3.Cube\n4.Factorial\n5.Subtraction\n6.Find area of circle\n7.Multiplication\n8.Close this program"<<endl;
    cout<<"Please enter your choice:";
    cin>>choice;
    cout<<endl;
    switch(choice)
        {
        case 1:
            {
            int c;
            FO_and_EH object;
            cout<<"1.Int by int\n2.Double by double\n3.Int by Double\n4.Double by Int"<<endl;
            cout<<"Enter your formula: ";
            cin>>c;
            switch(c)
            {
            case 1:
            {
            cout<<"Enter your inputs: ";
            cin>>object.x1;
            cin>>object.y1;
            object.division(object.x1,object.y1);
            break;
            }
            case 2:
            {
            cout<<"Enter your inputs: ";
            cin>>object.x2;
            cin>>object.y2;
            object.division(object.x2,object.y2);
            break;
            }
            case 3:
            {
            cout<<"Enter your inputs: ";
            cin>>object.x3;
            cin>>object.y3;
            object.division(object.x3,object.y4);
            break;
            }
            case 4:
            {
            cout<<"Enter your inputs: ";
            cin>>object.x4;
            cin>>object.y4;
            object.division(object.x4,object.y4);
            break;
            }
            }
            cout<<"Here he use\n1.Function overloading\n2.Exceptional handling\n"<<endl;
            break;
            }
        case 2:
            {
            int c;
            cout<<"1.Int and int\n2.Double and double\n3.Double and Int\n4.Int and Double"<<endl;
            cout<<"Enter your formula: ";
            cin>>c;
            switch(c)
            {
            case 1:
                {
                summation object=summation1();
                object.input();
                break;
                }
            case 2:
                {
                summation1 object1=summation1();
                object1.input();
                break;
                }
            case 3:
                {
                summation2 object2=summation2();
                object2.input();
                break;
                }
            case 4:
                {
                summation3 object3=summation3();
                object3.input();
                break;
                }
            }
            cout<<"Here he use\n1.Hybrid inheritance\n2.Mutable\n3.Constant function\n4.Function overriding\n5.Virtual"<<endl;
            break;
            }
        case 3:
            {
            operator_overloading obj1;
            operator_overloading obj2;
            operator_overloading obj3;
            cout<<"Please enter your 1st value:";
            cin>>obj1.a;
            cout<<obj1.a<<"^3: "<<obj1.cube()<<endl;
            cout<<"Please enter your 2nd value:";
            cin>>obj2.a;
            cout<<obj2.a<<"^3: "<<obj2.cube()<<endl;
            obj3=obj1+obj2;
            cout<<"("<<obj1.a<<"+"<<obj2.a<<")^3: "<<obj3.cube()<<endl;
            cout<<"Here he use\n1.Operator overloading\n2.Inline function\n3.Constant variable\n4.This pointer"<<endl;
            break;
            }
        case 4:
            {
            CO_and_MU t;
            t.input();
            factorial(t);
            cout<<"Here he use\n1.Friend function"<<endl;
            break;
            }
        case 5:
            {
            int c;
            cout<<"1.Int and int\n2.Double and double\n3.Double and Int\n4.Int and Double"<<endl;
            cout<<"Please enter your formula: ";
            cin>>c;
            switch(c)
            {
            case 1:
                {
                subtraction3 object;
                object.sub();
                break;
                }
            case 2:
                {
                subtraction3 object;
                object.sub1();
                break;
                }
            case 3:
                {
                subtraction3 object;
                object.sub2();
                break;
                }
            case 4:
                {
                subtraction3 object;
                object.sub3();
                break;
                }
            }
            cout<<"Here he use\n1.Multilevel inheritance"<<endl;
            break;
            }
        case 6:
            {
            circle object;
            cout<<"If your radius is integer press:1\nIf your radius is double press:2\nWhen you press other no output\nPress:";
            cin>>object.a;
            try
            {
            object.area(object.a);
            }
            catch(int i)
            {
            cout<<"Radius: ";
            cin>>object.b;
            cout<<"Area: "<<3.1416*object.b*object.b<<endl;
            }
            catch(double d)
            {
            cout<<"Radius: ";
            cin>>object.c;
            cout<<"Area: "<<3.1416*object.c*object.c<<endl;
            }
            cout<<"Here he use\n1.Scope resolution\n2.Resticting handling"<<endl;
            break;
            }
        case 7:
            {
                double a,b;
                cout<<"Enter your input: ";
                cin>>a>>b;
                multiplication object(a,b);
                break;
            }
         case 8:
            {
            circle object;
            try
            {
            object.area(3);
            }
            catch(char i)
            {
            cout<<"It is character value"<<endl;
            }
            }
        }
    }
return 0;
}
