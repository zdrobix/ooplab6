#include "repo.h"
#include <vector>
#include <cstdlib>

using namespace std;

Product* Repo::getAll() const {

    return list;
}

int Repo::numberProducts() const {

    return lg;
}

void Repo::redim() {

    //auto* newL = new Product[2* cp];

    for ( int i = 0; i < lg ; i ++ )

        //newL[i] = list[i];
        int ok = 1;


}

void Repo::addProduct(const Product& participant) {

    if (lg >= cp )

        redim();

    list[lg++] = participant;
}

void Repo::updateProduct(int position, const string &nName, const string &pProducer, const string &tType, float pPrice) {

    list[position].setName(const_cast<string &>(nName));

    list[position].setProducer(const_cast<string &>(pProducer));

    list[position].setType(const_cast<string &>(tType));

    list[position].setPrice(pPrice);
}

void Repo::deleteProduct(int position) {

    if (position < 0 || position >= lg ) return;

    for ( int i = position; i < lg; i ++ )

        list[i] = list[i + 1];

    lg --;
}

