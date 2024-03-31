#include "service.h"
#include "domain.h"
#include <vector>
#include <string>
#include <algorithm>

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

    vector<Product>& list=repository.getAll();

    auto comparePriceAsc = [](const Product& a, const Product& b) {
        return a.getPrice() < b.getPrice();
    };

    auto comparePriceDesc = [](const Product& a, const Product& b) {
        return a.getPrice() > b.getPrice();
    };

    auto compare = direction ? comparePriceAsc : comparePriceDesc;

    sort(list.begin(), list.end(), compare);
}

void Controller::sortName(bool direction, bool nameType) {

    vector<Product>& list = repository.getAll();

    auto compareNameAsc = [](const Product& a, const Product& b) {
        return a.getName() < b.getName();
    };

    auto compareTypeAsc = [](const Product& a, const Product& b) {
        return a.getType() < b.getType();
    };

    auto compareNameDesc = [](const Product& a, const Product& b) {
        return a.getName() > b.getName();
    };

    auto compareTypeDesc = [](const Product& a, const Product& b) {
        return a.getType() > b.getType();
    };

    auto compareFunctionAsc = nameType ? compareNameAsc : compareTypeAsc;

    auto compareFunctionDesc = nameType ? compareNameDesc : compareTypeDesc;

    if (direction)

        sort(list.begin(), list.end(), compareFunctionAsc);

    else sort(list.begin(), list.end(), compareFunctionDesc);
}

void Controller::addStandard() {

    repository.addProduct(Product{"Ridge Cal Zin Paso Robles - 750Ml", "A Vintners Selections", "Wine", 274.66});
    repository.addProduct(Product{"Bodegas Castano Hecula - 750Ml", "A Vintners Selections", "Wine", 577.60});
    repository.addProduct(Product{"Hendry Block 7 Napa Zin - 750Ml", "A Vintners Selections", "Wine", 445.86});
    repository.addProduct(Product{"Alsace William Gew - 750Ml", "Monsieur Touton Selection", "Wine", 341.78});
    repository.addProduct(Product{"Alsace William Cremant Brut - 750Ml", "Monsieur Touton Selection", "Wine", 632.12});
    repository.addProduct(Product{"Ch Darvigny Haut Medoc - 750Ml", "Monsieur Touton Selection", "Wine", 227.36});
    repository.addProduct(Product{"Montevina Wh Zin - 750Ml", "Republic National Distributing Co", "Wine", 466.84});
    repository.addProduct(Product{"Ravenswood Napa Vly Zin - 750Ml", "Republic National Distributing Co", "Wine", 733.27});
    repository.addProduct(Product{"Chalk Hill Eb Chard - 750Ml", "Republic National Distributing Co", "Wine", 512.63});
    repository.addProduct(Product{"Nederburg Shz - 750Ml", "Southern Glazers Wine And Spirits", "Wine", 837.70});
    repository.addProduct(Product{"Veramonte P/Noir - 750Ml", "Southern Glazers Wine And Spirits", "Wine", 447.90});
    repository.addProduct(Product{"Hitachino Anabai - 11.2Oz", "Legends Ltd", "Beer", 996.34});
    repository.addProduct(Product{"Long Trail Unearthed - 4/6 12.0Z Nr", "Legends Ltd", "Beer", 426.65});
    repository.addProduct(Product{"Stillwater Gose Gone Wild - 22.0Z", "Legends Ltd", "Beer", 114.83});
    repository.addProduct(Product{"North Coast Old Rasputin - 22.0Z", "Dops Inc", "Beer", 534.91});
    repository.addProduct(Product{"Bear Republic Pace Car Racer - 12Oz", "Dops Inc", "Beer", 950.50});
    repository.addProduct(Product{"Bear Republic Pace Car Racer - 12Oz", "Dops Inc", "Beer", 331.75});
    repository.addProduct(Product{"Finest Call Lime Juice - 1L", "Republic National Distributing Co", "Non-Alcohol", 87.10});
    repository.addProduct(Product{"Finest Call Lime Juice - 1L", "Republic National Distributing Co", "Non-Alcohol", 133.85});
    repository.addProduct(Product{"Finest Call Lime Juice - 1L", "Republic National Distributing Co", "Non-Alcohol", 59.16});
    repository.addProduct(Product{"Barkeep Baked Apple Org Bitters 6/Cs - 8Oz", "Bacchus Importers Ltd", "Non-Alcohol", 446.58});
    repository.addProduct(Product{"Sutter Home Fre' Spark - 750Ml", "Republic National Distributing Co", "Non-Alcohol", 95.55});
    repository.addProduct(Product{"Sutter Home Fre' Wh Zin - 750Ml", "Republic National Distributing Co", "Non-Alcohol", 124.79});
    repository.addProduct(Product{"Sutter Home Fre' Wh Zin - 750Ml", "Republic National Distributing Co", "Non-Alcohol", 948.58});
    repository.addProduct(Product{"Camille Cayran Cave De Cairanne Pas De La Beaume", "Grapes & Barley Llc", "Liquor", 772.52});
    repository.addProduct(Product{"Camille Cayran Cave De Cairanne Pas De La Beaume", "Grapes & Barley Llc", "Liquor", 749.40});
    repository.addProduct(Product{"Bodegas Hidalgo Fabuloso Solera Brandy - 750Ml", "Tradewinds Specialty Imports Llc", "Liquor", 454.19});
    repository.addProduct(Product{"Zoco Pacharan Navarro Liq - 1L", "Tradewinds Specialty Imports Llc", "Liquor", 389.54});
    repository.addProduct(Product{"Founding Spirits Gin - 750Ml", "Prestige Beverage Group Of Md Llc", "Liquor", 454.77});
    repository.addProduct(Product{"Founding Spirits Gin - 750Ml", "Prestige Beverage Group Of Md Llc", "Liquor", 23.32});
    repository.addProduct(Product{"Founding Spirits Rye Whisky - 750Ml", "Prestige Beverage Group Of Md Llc", "Liquor", 503.58});
    repository.addProduct(Product{"Varan Coffee Liq - 750Ml", "Bacchus Importers Ltd", "Liquor", 114.67});
    repository.addProduct(Product{"Guotai Baijiu Legend - 1L", "Young Won Trading Inc", "Liquor", 206.72});
    repository.addProduct(Product{"Arak Ksarak - 750Ml", "American Fidelity Trading", "Liquor", 692.79});
    repository.addProduct(Product{"Arak Ksarak - 750Ml", "American Fidelity Trading", "Liquor", 931.88});
    repository.addProduct(Product{"Jam Sangria Red - 1/6 Keg", "Tap26Md Llc", "Kegs", 502.27});
    repository.addProduct(Product{"Vino Petite Pinot Grigio - 20L", "Five Grapes Llc", "Kegs", 376.31});
    repository.addProduct(Product{"Troegs Solid Sender Pale Ale - 1/2K", "Katcef Brothers Inc", "Kegs", 405.30});
    repository.addProduct(Product{"Rogue 7 Hop - 1/2K", "Katcef Brothers Inc", "Kegs", 227.45});
    repository.addProduct(Product{"Smuttynose Robust Porter - 1/2K", "Katcef Brothers Inc", "Kegs", 143.42});
    repository.addProduct(Product{"Stelzer Fatti Schlob Export Lager - 30L", "Grapes & Barley Llc", "Kegs", 380.82});
    repository.addProduct(Product{"Stelzer Fatti Schlob Export Lager - 30L", "Grapes & Barley Llc", "Kegs", 710.48});
    repository.addProduct(Product{"Dc Brau Pils - 1/6K", "Dc Brau Brewing Llc", "Kegs", 749.42});
    repository.addProduct(Product{"Dc Brau Pils - 1/6K", "Dc Brau Brewing Llc", "Kegs", 222.64});
    repository.addProduct(Product{"Atlas Dance Of Days - 1/2K", "Atlas Brew Works Llc", "Kegs", 958.98});
    repository.addProduct(Product{"Atlas Dance Of Days - 1/2K", "Atlas Brew Works Llc", "Kegs", 436.18});
    repository.addProduct(Product{"Ballast Point Bonito - 4/6 12.Oz Can", "Home Brew Mart Inc", "Beer", 618.86});
    repository.addProduct(Product{"Ballast Point Bonito - 4/6 12.Oz Can", "Home Brew Mart Inc", "Beer", 174.54});
    repository.addProduct(Product{"La Socarrada - 330Ml", "Tradewinds Specialty Imports Llc", "Beer", 434.93});
    repository.addProduct(Product{"La Socarrada - 330Ml", "Tradewinds Specialty Imports Llc", "Beer", 334.83});
    repository.addProduct(Product{"La Socarrada - 330Ml", "Tradewinds Specialty Imports Llc", "Beer", 629.67});
    repository.addProduct(Product{"Mikkeller Mexas Ranger - 11.2Oz", "Bond Distributing Co", "Beer", 833.42});
    repository.addProduct(Product{"Evolution Russian Imperial Stout - 750Ml", "Delmar Brewing Company Llc", "Beer", 416.98});
    repository.addProduct(Product{"Evolution Russian Imperial Stout - 750Ml", "Delmar Brewing Company Llc", "Beer", 645.15});
    repository.addProduct(Product{"Blvd The Calling Ipa 4/6 Nr-12Oz", "Duvel Moortgat Usa Ltd", "Beer", 312.50});
    repository.addProduct(Product{"Stone Jindia Pale Ale - 12.Oz 4/6 Nr", "Buck Distributing Company Inc", "Beer", 272.98});
    repository.addProduct(Product{"Nb French Oak Saison - 22.Oz Nr", "New Belgium Brewing Inc", "Beer", 648.70});
    repository.addProduct(Product{"Bitburger 1/2K", "Legends Ltd", "Kegs", 704.47});
    repository.addProduct(Product{"Left Hand Nitro Milk Stout - 1/6K", "Legends Ltd", "Kegs", 641.71});
    repository.addProduct(Product{"Lagunitas Pils 1/2K", "Legends Ltd", "Kegs", 682.20});
    repository.addProduct(Product{"Sutter Home Fre' Premium Red - 750Ml", "Republic National Distributing Co", "Non-Alcohol", 566.62});
    repository.addProduct(Product{"Sutter Home Fre' Wh Zin - 750Ml", "Republic National Distributing Co", "Non-Alcohol", 619.76});
    repository.addProduct(Product{"Sutter Home Fre' Wh Zin - 750Ml", "Republic National Distributing Co", "Non-Alcohol", 993.23});
    repository.addProduct(Product{"Flying Dog The Truth - 1/6K", "Flying Dog Brewery Lllp", "Kegs", 339.98});
    repository.addProduct(Product{"Evolution Jacques Au Lantern1/2K", "Delmar Brewing Company Llc", "Kegs", 164.21});
    repository.addProduct(Product{"Konig Ludwig Weissbier - 50L Keg", "Warsteiner Importers", "Kegs", 49.37});
    repository.addProduct(Product{"Boulevard Collaboration #7 1/6 Keg", "Duvel Moortgat Usa Ltd", "Kegs", 319.55});
    repository.addProduct(Product{"Blvd Tank 7 1/2K", "Duvel Moortgat Usa Ltd", "Kegs", 753.96});
    repository.addProduct(Product{"Free Will Kragel Ipa 1/2 Keg", "Backup Beverage", "Kegs", 685.22});
    repository.addProduct(Product{"Two Brothers Blood Pinball 1/2 Keg", "Backup Beverage", "Kegs", 454.75});
    repository.addProduct(Product{"Epic Sour Pineapple 1/4 Keg", "Backup Beverage", "Kegs", 637.47});
    repository.addProduct(Product{"Flying Dog Barrel Aged Gonzo 1/6K", "Flying Dog Brewery Lllp", "Kegs", 376.77});
    repository.addProduct(Product{"Avery Ipa 1/6 Keg", "Backup Beverage", "Kegs", 891.18});
    repository.addProduct(Product{"Atlas Ponzi 1/2 Keg", "Atlas Brew Works Llc", "Kegs", 505.72});
    repository.addProduct(Product{"Smirnoff Bloody Mary Mix - 32Oz", "Diageo North America Inc", "Non-Alcohol", 895.86});
    repository.addProduct(Product{"Smirnoff Bloody Mary Mix - 32Oz", "Diageo North America Inc", "Non-Alcohol", 116.65});
    repository.addProduct(Product{"Smirnoff Bloody Mary Mix - 32Oz", "Diageo North America Inc", "Non-Alcohol", 695.20});
    repository.addProduct(Product{"Wine Aerator-In Bottle", "Default", "Ref", 689.52});
    repository.addProduct(Product{"Wine Aerator-In Bottle", "Default", "Ref", 65.21});
    repository.addProduct(Product{"Wine Aerator-In Bottle", "Default", "Ref", 338.86});
    repository.addProduct(Product{"Yuengling Ipl 1/2 Keg", "Yuengling Brewery", "Kegs", 198.52});
    repository.addProduct(Product{"Evolution Lucky 7 Porter 1/2K", "Delmar Brewing Company Llc", "Kegs", 499.58});
    repository.addProduct(Product{"Stelzer Fatti Bio-Perle Pilsner - 30L", "Grapes & Barley Llc", "Kegs", 353.47});
    repository.addProduct(Product{"Laughing Dog  Ipa 1/2K", "Kysela Pere Et Fils Ltd", "Kegs", 975.95});
    repository.addProduct(Product{"Leinenkugel Grapefruit Shandy 1/2Kg", "Miller Brewing Company", "Kegs", 516.18});
    repository.addProduct(Product{"Escutcheon 4Th & 1 Pilsner - 1/6Keg", "Kysela Pere Et Fils Ltd", "Kegs", 907.91});
    repository.addProduct(Product{"Stiegl 50Ltr 1/2 Keg", "Buck Distributing Company Inc", "Kegs", 952.80});
    repository.addProduct(Product{"Elysian Bifrost 1/2Keg", "Anheuser Busch Inc", "Kegs", 668.33});
    repository.addProduct(Product{"Store Special Beer Quart", "Default", "Ref", 370.40});
    repository.addProduct(Product{"Store Special Beer Quart", "Default", "Ref", 453.27});
    repository.addProduct(Product{"Two Bottle Wine Tote", "Default", "Supplies", 67.95});
    repository.addProduct(Product{"Finest Call Bloody Mary Mix Spicey - 1L", "Republic National Distributing Co", "Non-Alcohol", 124.87});
    repository.addProduct(Product{"Finest Call Bloody Mary Mix Spicey - 1L", "Republic National Distributing Co", "Non-Alcohol", 456.48});
    repository.addProduct(Product{"Finest Call Bloody Mary Mix Spicey - 1L", "Republic National Distributing Co", "Non-Alcohol", 84.77});
    repository.addProduct(Product{"Master Of Mixes S/Aple Mart - 1L", "American Beverage Marketers", "Non-Alcohol", 502.21});
    repository.addProduct(Product{"Master Of Mixes S/Aple Mart - 1L", "American Beverage Marketers", "Non-Alcohol", 294.73});
    repository.addProduct(Product{"Gator Rons Divine Bl/Mary - 24Oz", "Gator Ron'S Llc", "Non-Alcohol", 377.65});
    repository.addProduct(Product{"Wine Gift Tote 4 Bottle", "Default", "Supplies", 497.73});
    repository.addProduct(Product{"Wine Gift Tote 4 Bottle", "Default", "Supplies", 843.67});
}