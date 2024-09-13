#include <iostream>
#include<string>

class Employee{
    protected:
    std::string name;
    int salary;

    Employee(std::string n="", int s =0) : name(n), salary(s){}
};

class Manager : public Employee{ 
    protected:   
    std::string department;

    Manager(std::string n="", int s =0) : name(n), salary(s){}
    void toString(){
        std::cout<<name<<":"<<department<<":"<<salary<<std::endl;
    }
};

class Executive : public Manager{
    void toString(){
        std::cout<<"Executive "<<name<<":"<<department<<":"<<salary<<std::endl;
    }
};

int main(){
    Employee A("aman",20000);
    Manager B("aman2",30000)
}