#ifndef ARBOLB_H
#define ARBOLB_H

#include <iostream>
#include "NodoB.h"

using namespace std;

class ArbolB {

    private:
        NodoB *raiz;
    
    public:
        ArbolB() {raiz = NULL;}

        void insertar(int pCedula, string pNombre, int pTelefono, string pCorreo);
        void insertarRecursivo(NodoB *&r, int pCedula, string pNombre, int pTelefono, string pCorreo);
        void insertar(int pAdmin, string pNombre);
        void insertarRecursivo(NodoB *&r, int pAdmin, string pNombre);
        void podar();
        void podarRecursivo(NodoB *&r);
        bool existeCedula(int pCedula);
        bool existeCedulaRecursivo(int pCedula, NodoB *&r);
        bool existeAdmin(int pAdmin);
        bool existeAdminRecursivo(int pAdmin, NodoB *&r);
        void mostrar();
        void mostrarRecursivo(NodoB *&r);
        void mostrarAdmin();
        void mostrarAdminRecursivo(NodoB *&r);

};

#endif
