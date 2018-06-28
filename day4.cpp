using namespace std;
#include <iostream>

class Person{
public:
   int age ;
   Person(int initial_Age);
   void amIOld();
   void yearPasses();
};
Person::Person(int initial_Age){
  // Add some more code to run some checks on initial_Age
    if(initial_Age<0){
        age = 0;
        cout<<"This is person is not valid, setting age to 0.\n";
    }else {
        age = initial_Age;

    }

}
void Person::amIOld(){
    // Do some computations in here and print out the correct statement to the console
    if(age<13){
        cout<<"You are young.\n";
    }else if (13<=age && age<18){
        cout<<"You are a teenager.\n";
    }else {
        cout<<"You are old.\n";
    }

}


void Person::yearPasses(){
  // Increment the age of the person in here
    age = age + 1;
  }

int main(){
    int T,age;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>age;
        Person p(age);
        p.amIOld();
        for(int j=0;j<3;j++)
        {
            p.yearPasses();

        }
        p.amIOld();
        cout<<"\n";
    }
    return 0;
}
