#ifndef DOMAIN_H
#define DOMAIN_H
#include <string>
#include <iostream>

using namespace std;

class Product {

private:
    string name;

    string producer;

    string type;

    float price;
public:

    static int contor;

    Product(const string& name, const string& producer, const string& type, const float price){

        this-> name = name;
        this-> producer = producer;
        this-> type = type;
        this-> price = price;
        contor ++;
    };

    Product(){

        this-> name = "";
        this-> producer = "";
        this-> type = "";
        this-> price = 0;
    };

    ~Product() {

        this-> name = " ";
        this-> producer = " ";
        this-> type = " ";
        this-> price = 0;
        contor --;
    };

    Product(const Product& ot) {

        name = ot.name;
        producer = ot.producer;
        type = ot.type;
        price = ot.price;
        //contor ++;
    };



    string getName() const;

    string getProducer() const;

    string getType() const;

    float getPrice() const;

    void setName (string& nName);

    void setProducer (string& pProducer);

    void setType (string& tType);

    void setPrice (float pPrice);
};

#endif //DOMAIN_H
