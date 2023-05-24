#include "Class.h"
#include <iostream>
int main()
{
    Agenda agenda;
    Prieten* prieten1=new Prieten("Ana", "20/10/2003", "0712345678", "Strada Ceva");
    Prieten* prieten2 = new Prieten("Eduard", "17/04/2003", "0712345678", "Strada Altceva");
    Prieten* prieten3 = new Prieten("Lavinia", "29/12/2003", "0712345678", "Strada Ce");
    Cunoscut* cunoscut = new Cunoscut("Maria", "0712345678");
    Coleg* coleg = new Coleg("Sebi", "0712345678", "FII", "Strada IDK");
    //verific functia AddContact
    agenda.AddContact(prieten1);
    agenda.AddContact(prieten2);
    agenda.AddContact(prieten3);
    agenda.AddContact(cunoscut);
    agenda.AddContact(coleg);

    //verific functia GetPrieteni
    vector<Prieten*> test1 = agenda.GetPrieteni();
    for (Prieten* p : test1)
    {
        printf("Name: %s\n", p->GetName().c_str());
        printf("Birth Date: %s\n", p->GetBirthDate().c_str());
        printf("Phone Number: %s\n", p->GetPhoneNumber().c_str());
        printf("Address: %s\n", p->GetAddress().c_str());
    }

    printf("\n\n");
    
    //verific functia FindContact
    Contact* contactGasit = agenda.FindContact("Sebi");
    if (contactGasit != nullptr) {

        printf("Contact Found: %s\n",contactGasit->GetName().c_str());//daca este coleg/cunoscut afisez doar nume
        //daca este prieten
        if (Prieten* prieten = dynamic_cast<Prieten*>(contactGasit)) {
            printf("Birth Date: %s\n", prieten->GetBirthDate().c_str());
            printf("PhoneNumber: %s\n", prieten->GetPhoneNumber().c_str());
            printf("Adresa: %s\n",prieten->GetAddress().c_str());
        }
    }
    else 
        printf("I didn't find contact\n");//daca nu este prieten nici contact nici cunostinta nu afisez nimic

    printf("\n\n");

    //verific functia EraseContact
    agenda.EraseContact("Eduard");
    printf("Erase contact : Eduard (test)\n\n");
    //verific functia GetPrieteni
    vector<Prieten*> test2 = agenda.GetPrieteni();
    for (Prieten* p : test2)
    {
        printf("Name: %s\n",p->GetName().c_str());
        printf("Birth Date: %s\n",p->GetBirthDate().c_str());
        printf("Phone Number: %s\n",p->GetPhoneNumber().c_str());
        printf("Address: %s\n",p->GetAddress().c_str());
    }
    return 0;
}