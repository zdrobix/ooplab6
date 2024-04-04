#include "tests.h"
#include "repo.h"
#include "service.h"
#include "ui.h"

using namespace std;

int main() {

    testAll();

    cout << "Contor: " << Product::contor << endl;

    Repo repository{};

    Controller controller{repository};

    Ui console{controller};

    console.runApp();

    return 0;
}