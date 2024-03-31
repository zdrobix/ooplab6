#ifndef DOMAIN_H
#define DOMAIN_H
#include <string>

using namespace std;

class Product {

public:
    string name;

    string producer;

    string type;

    float price;

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
