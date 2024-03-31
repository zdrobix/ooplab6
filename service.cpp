#include "service.h"
#include "domain.h"
#include <vector>
#include <string>

using namespace std;

const vector<Product> & Controller::getAllProducts() {

    return repository.getAll();
}

int Controller::numberProducts() {

    return repository.numberProducts();
}

bool Controller::add(const string& name, const string& producer, const string& type, float price) {

    if (name.empty() or producer.empty() or type.empty()) return false;

    if (price <= 0 ) return false;

    Product prt{name, producer, type, price};

    repository.addProduct(prt);

    return true;
}

bool Controller::update(int position, const string& nName, const string& pProducer, const string& tType, float pPrice) {

    if (repository.numberProducts() == 0 ) return false;

    if (position > repository.numberProducts() or position < 0) return false;

    if (nName.empty() or pProducer.empty() or pPrice <= 0 or tType.empty()) return false;

    repository.updateProduct(position, nName, pProducer, tType, pPrice);

    return true;
}

bool Controller::_delete(int position) {

    if (repository.numberProducts() == 0 ) return false;

    if (position > repository.numberProducts() or position < 0 ) return false;

    repository.deleteProduct(position);

    return true;
}

int Controller::filterPrice(int counter, int pos[100], float price, bool direction) {

    vector<Product>& lista = repository.getAll();

    int i = 0;

    for (const auto& prt: lista) {

        if (direction) {

            if (prt.getPrice() <= price) {

                pos[counter] = i;

                counter++;
            }
        } else if (prt.getPrice() >= price ) {

            pos[counter] = i;

            counter ++;
        }
        i ++;
    }
    return counter;
}

int Controller::filterName(int counter, int pos[100], char letter, bool nameProd) {

    vector<Product>& lista = repository.getAll();

    int i = 0;

    for (const auto& prt: lista) {

        if (nameProd) {

            if (prt.getName().at(0) == letter) {

                pos[counter] = i;

                counter++;
            }
        } else if (prt.getProducer().at(0) == letter ) {

            pos[counter] = i;

            counter ++;
        }
        i ++;
    }
    return counter;
}

void Controller::sortPrice(bool direction) {

    vector<Product>& lista=repository.getAll();

    for(int i = 0; i < lista.size() - 1 ; i ++)

        for (int j = i + 1; j <= lista.size() - 1; j ++){

            if (direction) {

                if (lista.at(i).getPrice() > lista.at(j).getPrice()) {

                    Product aux;

                    aux = lista.at(i);

                    lista.at(i) = lista.at(j);

                    lista.at(j) = aux;
                }
            }else if (lista.at(i).getPrice() < lista.at(j).getPrice()) {

                Product aux;

                aux = lista.at(i);

                lista.at(i) = lista.at(j);

                lista.at(j) = aux;
            }
        }
}

void Controller::sortName(bool direction, bool nameType) {

    vector<Product>& lista=repository.getAll();

    for(int i = 0; i <lista.size() - 1; i ++)

        for (int j = i + 1; j <= lista.size() - 1; j ++){

            if (direction) {

                if (nameType) {

                    if (lista.at(i).getName() > lista.at(j).getName()) {

                        Product aux;

                        aux = lista.at(i);

                        lista.at(i) = lista.at(j);

                        lista.at(j) = aux;
                    }
                } else {

                    if (lista.at(i).getType() > lista.at(j).getType()) {

                        Product aux;

                        aux = lista.at(i);

                        lista.at(i) = lista.at(j);

                        lista.at(j) = aux;
                    }
                }
            }else if (nameType) {

                if (lista.at(i).getName() < lista.at(j).getName()) {

                    Product aux;

                    aux = lista.at(i);

                    lista.at(i) = lista.at(j);

                    lista.at(j) = aux;
                }
            } else {

                if (lista.at(i).getType() < lista.at(j).getType()) {

                    Product aux;

                    aux = lista.at(i);

                    lista.at(i) = lista.at(j);

                    lista.at(j) = aux;
                }
            }
        }
}

void Controller::addStandard() {

    repository.addProduct(Product{"Ridge Cal Zin Paso Robles - 750Ml                 ", "A Vintners Selections                   ", "Wine          ", 319.80});
    repository.addProduct(Product{"Bodegas Castano Hecula - 750Ml                    ", "A Vintners Selections                   ", "Wine          ", 68.96});
    repository.addProduct(Product{"Hendry Block 7 Napa Zin - 750Ml                   ", "A Vintners Selections                   ", "Wine          ", 728.72});
    repository.addProduct(Product{"Alsace William Gew - 750Ml                        ", "Monsieur Touton Selection               ", "Wine          ", 159.46});
    repository.addProduct(Product{"Alsace William Cremant Brut - 750Ml               ", "Monsieur Touton Selection               ", "Wine          ", 344.30});
    repository.addProduct(Product{"Ch Darvigny Haut Medoc - 750Ml                    ", "Monsieur Touton Selection               ", "Wine          ", 994.37});
    repository.addProduct(Product{"Montevina Wh Zin - 750Ml                          ", "Republic National Distributing Co       ", "Wine          ", 791.98});
    repository.addProduct(Product{"Ravenswood Napa Vly Zin - 750Ml                   ", "Republic National Distributing Co       ", "Wine          ", 799.93});
    repository.addProduct(Product{"Chalk Hill Eb Chard - 750Ml                       ", "Republic National Distributing Co       ", "Wine          ", 499.68});
    repository.addProduct(Product{"Nederburg Shz - 750Ml                             ", "Southern Glazers Wine And Spirits       ", "Wine          ", 912.80});
    repository.addProduct(Product{"Veramonte P/Noir - 750Ml                          ", "Southern Glazers Wine And Spirits       ", "Wine          ", 982.42});
    repository.addProduct(Product{"Hitachino Anabai - 11.2Oz                         ", "Legends Ltd                             ", "Beer          ", 758.23});
    repository.addProduct(Product{"Long Trail Unearthed - 4/6 12.0Z Nr               ", "Legends Ltd                             ", "Beer          ", 988.67});
    repository.addProduct(Product{"Stillwater Gose Gone Wild - 22.0Z                 ", "Legends Ltd                             ", "Beer          ", 495.16});
    repository.addProduct(Product{"North Coast Old Rasputin - 22.0Z                  ", "Dops Inc                                ", "Beer          ", 416.60});
    repository.addProduct(Product{"Bear Republic Pace Car Racer - 12Oz               ", "Dops Inc                                ", "Beer          ", 660.16});
    repository.addProduct(Product{"Bear Republic Pace Car Racer - 12Oz               ", "Dops Inc                                ", "Beer          ", 130.42});
    repository.addProduct(Product{"Finest Call Lime Juice - 1L                       ", "Republic National Distributing Co       ", "Non-Alcohol   ", 848.60});
    repository.addProduct(Product{"Finest Call Lime Juice - 1L                       ", "Republic National Distributing Co       ", "Non-Alcohol   ", 861.14});
    repository.addProduct(Product{"Finest Call Lime Juice - 1L                       ", "Republic National Distributing Co       ", "Non-Alcohol   ", 385.21});
    repository.addProduct(Product{"Barkeep Baked Apple Org Bitters 6/Cs - 8Oz        ", "Bacchus Importers Ltd                   ", "Non-Alcohol   ", 473.77});
    repository.addProduct(Product{"Sutter Home Fre' Spark - 750Ml                    ", "Republic National Distributing Co       ", "Non-Alcohol   ", 147.81});
    repository.addProduct(Product{"Sutter Home Fre' Wh Zin - 750Ml                   ", "Republic National Distributing Co       ", "Non-Alcohol   ", 512.54});
    repository.addProduct(Product{"Sutter Home Fre' Wh Zin - 750Ml                   ", "Republic National Distributing Co       ", "Non-Alcohol   ", 958.45});
    repository.addProduct(Product{"Camille Cayran Cave Pas De La Beaume Cdr Wh       ", "Grapes & Barley Llc                     ", "Liquor        ", 58.70});
    repository.addProduct(Product{"Camille Cayran Cave Pas De La Beaume Cdr Wh       ", "Grapes & Barley Llc                     ", "Liquor        ", 692.83});
    repository.addProduct(Product{"Bodegas Hidalgo Fabuloso Solera Brandy - 750Ml    ", "Tradewinds Specialty Imports Llc        ", "Liquor        ", 833.46});
    repository.addProduct(Product{"Zoco Pacharan Navarro Liq - 1L                    ", "Tradewinds Specialty Imports Llc        ", "Liquor        ", 681.69});
    repository.addProduct(Product{"Founding Spirits Gin - 750Ml                      ", "Prestige Beverage Group Of Md Llc       ", "Liquor        ", 51.98});
    repository.addProduct(Product{"Founding Spirits Gin - 750Ml                      ", "Prestige Beverage Group Of Md Llc       ", "Liquor        ", 704.69});
    repository.addProduct(Product{"Founding Spirits Rye Whisky - 750Ml               ", "Prestige Beverage Group Of Md Llc       ", "Liquor        ", 711.16});
    repository.addProduct(Product{"Varan Coffee Liq - 750Ml                          ", "Bacchus Importers Ltd                   ", "Liquor        ", 734.96});
    repository.addProduct(Product{"Guotai Baijiu Legend - 1L                         ", "Young Won Trading Inc                   ", "Liquor        ", 640.82});
    repository.addProduct(Product{"Arak Ksarak - 750Ml                               ", "American Fidelity Trading               ", "Liquor        ", 472.51});
    repository.addProduct(Product{"Arak Ksarak - 750Ml                               ", "American Fidelity Trading               ", "Liquor        ", 260.80});
    repository.addProduct(Product{"Jam Sangria Red - 1/6 Keg                         ", "Tap26Md Llc                             ", "Kegs          ", 804.91});
    repository.addProduct(Product{"Vino Petite Pinot Grigio - 20L                    ", "Five Grapes Llc                         ", "Kegs          ", 258.65});
    repository.addProduct(Product{"Troegs Solid Sender Pale Ale - 1/2K               ", "Katcef Brothers Inc                     ", "Kegs          ", 294.62});
    repository.addProduct(Product{"Rogue 7 Hop - 1/2K                                ", "Katcef Brothers Inc                     ", "Kegs          ", 358.30});
    repository.addProduct(Product{"Smuttynose Robust Porter - 1/2K                   ", "Katcef Brothers Inc                     ", "Kegs          ", 545.46});
    repository.addProduct(Product{"Stelzer Fatti Schlob Export Lager - 30L           ", "Grapes & Barley Llc                     ", "Kegs          ", 684.84});
    repository.addProduct(Product{"Stelzer Fatti Schlob Export Lager - 30L           ", "Grapes & Barley Llc                     ", "Kegs          ", 68.13});
    repository.addProduct(Product{"Dc Brau Pils - 1/6K                               ", "Dc Brau Brewing Llc                     ", "Kegs          ", 832.12});
    repository.addProduct(Product{"Dc Brau Pils - 1/6K                               ", "Dc Brau Brewing Llc                     ", "Kegs          ", 809.66});
    repository.addProduct(Product{"Atlas Dance Of Days - 1/2K                        ", "Atlas Brew Works Llc                    ", "Kegs          ", 128.31});
    repository.addProduct(Product{"Atlas Dance Of Days - 1/2K                        ", "Atlas Brew Works Llc                    ", "Kegs          ", 606.66});
    repository.addProduct(Product{"Ballast Point Bonito - 4/6 12.Oz Can              ", "Home Brew Mart Inc                      ", "Beer          ", 1.51});
    repository.addProduct(Product{"Ballast Point Bonito - 4/6 12.Oz Can              ", "Home Brew Mart Inc                      ", "Beer          ", 664.58});
    repository.addProduct(Product{"La Socarrada - 330Ml                              ", "Tradewinds Specialty Imports Llc        ", "Beer          ", 364.99});
    repository.addProduct(Product{"La Socarrada - 330Ml                              ", "Tradewinds Specialty Imports Llc        ", "Beer          ", 869.90});
    repository.addProduct(Product{"La Socarrada - 330Ml                              ", "Tradewinds Specialty Imports Llc        ", "Beer          ", 834.51});
    repository.addProduct(Product{"Mikkeller Mexas Ranger - 11.2Oz                   ", "Bond Distributing Co                    ", "Beer          ", 759.18});
    repository.addProduct(Product{"Evolution Russian Imperial Stout - 750Ml          ", "Delmar Brewing Company Llc              ", "Beer          ", 598.95});
    repository.addProduct(Product{"Evolution Russian Imperial Stout - 750Ml          ", "Delmar Brewing Company Llc              ", "Beer          ", 400.47});
    repository.addProduct(Product{"Blvd The Calling Ipa 4/6 Nr-12Oz                  ", "Duvel Moortgat Usa Ltd                  ", "Beer          ", 461.46});
    repository.addProduct(Product{"Stone Jindia Pale Ale - 12.Oz 4/6 Nr              ", "Buck Distributing Company Inc           ", "Beer          ", 324.76});
    repository.addProduct(Product{"Nb French Oak Saison - 22.Oz Nr                   ", "New Belgium Brewing Inc                 ", "Beer          ", 550.84});
    repository.addProduct(Product{"Bitburger 1/2K                                    ", "Legends Ltd                             ", "Kegs          ", 932.80});
    repository.addProduct(Product{"Left Hand Nitro Milk Stout - 1/6K                 ", "Legends Ltd                             ", "Kegs          ", 970.50});
    repository.addProduct(Product{"Lagunitas Pils 1/2K                               ", "Legends Ltd                             ", "Kegs          ", 118.55});
    repository.addProduct(Product{"Sutter Home Fre' Premium Red - 750Ml              ", "Republic National Distributing Co       ", "Non-Alcohol   ", 21.84});
    repository.addProduct(Product{"Sutter Home Fre' Wh Zin - 750Ml                   ", "Republic National Distributing Co       ", "Non-Alcohol   ", 944.59});
}