#include <iostream>
#include <string>
#include <math.h>
using namespace std;

    class Account;

    class Person
    {
        public:

        /**static**/ const int lvl = 0;
        string name, next_of_kin;
        int age;

        Person() {} //default
        Person(string n, int a, string nok) : name(n), age(a)
        {
            nok=next_of_kin;
        }

    };

    class Account
    {
        public:
        Person p1;

        Account(string n, int a, string nok)
        {
            p1.name= n;
            p1.age= a;
            p1.next_of_kin=nok;
        }

        virtual void show()=0;

    };

    class Savings: public Account
    {
        public:
        float interest;

        Savings(string n,  int a, string nok, float inter):Account(n,a,nok)
        {
            interest=inter;
        }


        void show()
        {
            cout<<"Name: " <<Account::p1.name <<endl;
            cout<<"Age: " <<Account::p1.age<<endl;
            cout<<"Next of kin " <<Account::p1.next_of_kin<<endl;
            cout<<"interest rate " <<interest <<endl;
        }
       /// ~Savings() {cout<<"I'm called" <<endl;}


    };


main()
{
    Savings *s1[2] = {new Savings("Raheem Muiz", 20, "Raheem Hameed", 0), new Savings("Raheem Muiz", 20, "Raheem Hameed", 0)};
    for(int i=0; i<2; i++)
    {

        s1[i]->show();
    }

    Savings s2("Qawaam", 20, "muiz",0);
    Savings s3(s2);
    s3.show();
}
