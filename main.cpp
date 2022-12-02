#include "Test/test.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

const int X = 500;

int main(int argc, char const *argv[])
{
    srand(time(nullptr));

    std::vector<std::string> users(X);
    std::vector<std::string> passwords(X);
    std::vector<std::string> dates(X);

    std::ifstream archivo("data.csv");
    std::string linea;
    char delimitador = ',';
    getline(archivo, linea);

    int i = 0;
    while (getline(archivo, linea))
    {
        std::stringstream stream(linea);
        std::string user, password, date;
        getline(stream, user, delimitador);
        getline(stream, password, delimitador);
        getline(stream, date, delimitador);
        users[i] = user;
        passwords[i] = password;
        dates[i] = date;
        i++;
    }

    archivo.close();

    Blockchain bch;

    for (int i = 0; i < X; i++)
    {   
        std::cout << "creando bloque de: " << users[i] << std::endl;
        bch.createUser(users[i], passwords[i]);
        std::cout << "con sus transacciones: " << std::endl;
        for (int j = 0; j < 4 + rand() % (7 - 4 + 1); j++)
        {
            int k = 0 + rand() % (X-1 - 0 + 1);
            int d = 0 + rand() % (X-1 - 0 + 1);
            float f = float(100 + rand() % (1500 - 100 + 1)) / 7.0;
            std::cout << users[i] << ", " << users[k] << ", " << f << ", " << dates[d] << std::endl;
            bch.setTx(users[i], passwords[i], users[k], f, dates[d]);
        }
        bch.mineCascade(users[i], passwords[i]);
        std::cout << std::endl;
    }

    std::ofstream blockchain("blockchain.txt");
    blockchain << bch;

    return 0;
}
