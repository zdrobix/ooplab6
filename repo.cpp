#include "repo.h"
#include <vector>

using namespace std;

vector<Product>& Repo::getAll() {

    return lista;
}

int Repo::numberProducts() {

    return int(lista.size());
}

void Repo::addProduct(const Product& participant) {

    lista.push_back(participant);
}

void Repo::updateProduct(int position, const string &nName, const string &pProducer, const string &tType, float pPrice) {

    lista.at(position).setName(const_cast<string &>(nName));

    lista.at(position).setProducer(const_cast<string &>(pProducer));

    lista.at(position).setType(const_cast<string &>(tType));

    lista.at(position).setPrice(pPrice);
}

void Repo::deleteProduct(int position) {

    lista.erase(lista.begin() + position);
}