#pragma once
#include <string>
#include <vector>
using namespace std;
class Contact {
private:
    string name;
public:
    Contact(const string& name) : name(name) {}
    ~Contact() {}
    virtual const string& GetName(){
        return name;
    }
};

enum class TipContact {
    Prieten,
    Cunoscut,
    Coleg
};

class Prieten : public Contact {
private:
    string birthDate;
    string phoneNumber;
    string address;
public:
    Prieten(const string& name, const string& birthDate, const string& phoneNumber, const string& address)
        : Contact(name), birthDate(birthDate), phoneNumber(phoneNumber), address(address)
    {}
    ~Prieten() {};
    const string& GetBirthDate(){
        return birthDate;
    }
    const string& GetPhoneNumber(){
        return phoneNumber;
    }
    const string& GetAddress(){
        return address;
    }
};

class Cunoscut : public Contact {
private:
    string phoneNumber;
public:
    Cunoscut(const string& name, const string& phoneNumber)
        : Contact(name), phoneNumber(phoneNumber) {}
    ~Cunoscut() {};
    const string& GetPhoneNumber(){
        return phoneNumber;
    }
};

class Coleg : public Contact {
private:
    string phoneNumber;
    string firma;
    string address;

public:
    Coleg(const string& name, const string& phoneNumber, const string& firma, const string& address)
        : Contact(name), phoneNumber(phoneNumber), firma(firma), address(address) {}
    ~Coleg() {};
    const string& GetPhoneNumber(){
        return phoneNumber;
    }
    const string& GetFirma(){
        return firma;
    }
    const string& GetAddress(){
        return address;
    }
};

class Agenda
{
private:
    vector<Contact*> contacte;
public:
    Agenda() {}; //constructor default
    ~Agenda()
    {
        for (Contact* i : contacte)
            delete i;
    }
    //adauga un anumit contact
    void AddContact(Contact* name)
    {
        contacte.push_back(name);
    }
    //cautarea contact dupa nume
    Contact* FindContact(const string& name)
    {
        for (Contact* i : contacte) 
            if (i->GetName() == name) 
                return i;
        return nullptr; 
    }
    //sterge un anumit contact dupa nume
    void EraseContact(const string& name)
    {
        for (auto i = contacte.begin(); i != contacte.end(); i++) {
            if ((*i)->GetName() == name) {
                delete* i;
                contacte.erase(i);
                break;
            }
        }
    }

    //returneaza o lista de prieteni(contacte de tipul Prieten)
    vector <Prieten*> GetPrieteni() {
        vector <Prieten*> prieteni;
        for(Contact* i : contacte)
            if (dynamic_cast<Prieten*>(i)!=NULL)
                prieteni.push_back(dynamic_cast<Prieten*>(i));
        return prieteni;
    }
};