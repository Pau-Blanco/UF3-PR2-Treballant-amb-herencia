#include <iostream>
#include <ctime>
#include "Enemigos.h"

using namespace std;

const int MAP_SIZE = 5;
int mapa[MAP_SIZE][MAP_SIZE];
Enemigos heroe(100, 10, "Heroe", 0, 0);
Enemigos enemigos[5];

void inicializarMapa()
{
    srand(time(0));
    for (int x = 0; x < MAP_SIZE; x++)
    {
        for (int y = 0; y < MAP_SIZE; y++)
        {
            mapa[x][y] = 0;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        int x, y;
        do {
            x = rand() % MAP_SIZE;
            y = rand() % MAP_SIZE;
        } while (mapa[y][x] != 0 || (x == heroe.getEneXpos() && y == heroe.getEneYpos()));

        enemigos[i] = Enemigos(50, 5, "Enemigo", y, x);
        mapa[y][x] = 1; 
    }
}

void imprimirMapa()
{
    for (int y = 0; y < MAP_SIZE; y++)
    {
        for (int x = 0; x < MAP_SIZE; x++)
        {
            if (heroe.getEneYpos() == y && heroe.getEneXpos() == x)
            {
                cout << "H ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

void atacarEnemigo(int eneRef)
{
    Enemigos& enemigo = enemigos[eneRef];
    cout << "¡Te has encontrado con un " << enemigo.getEneName() << "!\n";

    cout << "Comienza el combate: \n";
    cout << "Heroe HP: " << heroe.getEneHp() << ", Enemigo HP: " << enemigo.getEneHp() <<"\n";

    while (heroe.getEneHp() > 0 && enemigo.getEneHp() > 0)
    {
        cout << "Elige una opción: (1 Atacar, 2 Salir del combate)\n";
        int opcion;
        cin >> opcion;

        if (opcion == 2)
        {
            cout << "Has decidido salir del combate.\n";
            return;
        }
        else if (opcion == 1)
        {
            int heroAtk = rand() % (heroe.getEneDamage() + 1); 
            int enemyAtk = rand() % (enemigo.getEneDamage() + 1); 

            enemigo.setEneHp(enemigo.getEneHp() - heroAtk);
            if (enemigo.getEneHp() < 0) enemigo.setEneHp(0); 
            cout << "Has atacado al " << enemigo.getEneName() << " con " << heroAtk << " de daño. Le queda " << enemigo.getEneHp() << " HP.\n";

            if (enemigo.getEneHp() > 0) 
            {
                heroe.setEneHp(heroe.getEneHp() - enemyAtk);
                if (heroe.getEneHp() < 0) heroe.setEneHp(0);
                cout << enemigo.getEneName() << " te ha atacado con " << enemyAtk << " de daño. Te queda " << heroe.getEneHp() << " HP.\n";
            }
        }
        else
        {
            cout << "Opcion no valida.\n";
        }
    }

    if (heroe.getEneHp() <= 0)
    {
        cout << "Te han derrotado. ¡Game Over!\n";
        exit(0);
    }
    else
    {
        cout << "Has derrotado a " << enemigo.getEneName() << "!\n";

        mapa[enemigo.getEneYpos()][enemigo.getEneXpos()] = 0;
        enemigos[eneRef] = Enemigos(0, 0, "", -1, -1); 
    }
}

void mover()
{
    cout << "Introduce el movimiento que quieres realizar (1 Arriba, 2 Izq, 3 Abajo, 4 Drcha): ";
    int movimiento_pers;
    cin >> movimiento_pers;
    int posX = heroe.getEneXpos();
    int posY = heroe.getEneYpos();

    switch (movimiento_pers)
    {
    case 1:
        posX--;
        break;
    case 2:
        posY--;
        break;
    case 3:
        posY++;
        break;
    case 4:
        posX++;
        break;
    default:
        cout << "Opcion no valida.\n";
        return;
    }

    if (posX >= 0 && posX < MAP_SIZE && posY >= 0 && posY < MAP_SIZE)
    {
        bool spawnEne = false;
        for (int i = 0; i < 5; i++)
        {
            if (enemigos[i].getEneXpos() == posX && enemigos[i].getEneYpos() == posY)
            {
                spawnEne = true;
                heroe.setEneXpos(posX);
                heroe.setEneYpos(posY);
                atacarEnemigo(i);
                imprimirMapa();
                return;
            }
        }

        if (mapa[posY][posX] == 2)
        {
            cout << "¡Fin de la partida, salida encontrada!\n";
            exit(0);
        }

        if (!spawnEne)
        {
            heroe.setEneXpos(posX);
            heroe.setEneYpos(posY);
            imprimirMapa();
        }
    }
    else
    {
        cout << "No puedes avanzar hacia esa direccion.\n";
    }
}

int main()
{
    cout << "BIENVENIDO AL ESCAPAZONE 2.0 By Segura\n";
    inicializarMapa();
    imprimirMapa();

    while (true)
    {
        mover();
    }
    return 0;
}
