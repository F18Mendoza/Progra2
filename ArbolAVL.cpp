#include "ArbolAVL.h"
#include <iostream>

using namespace std;

void ArbolAVL::podar() {

    if (raiz != NULL) {

        podarRecursivo(raiz -> HIzq);
        podarRecursivo(raiz -> HDer);
        raiz -> marcas.podar();
        raiz -> inventario.podar();
        delete raiz;
    }
}

void ArbolAVL::podarRecursivo(NodoAVL *&r) {

    if (r != NULL) {

        podarRecursivo(r -> HIzq);
        podarRecursivo(r -> HDer);
        r -> marcas.podar();
        r -> inventario.podar();
        delete r;
    }
}

void ArbolAVL::insertar(string pNombre, int pCodProducto) {

    if (raiz == NULL){
        raiz = new NodoAVL(pNombre, pCodProducto);
    }
    else {

        if (!existeCodigo(pCodProducto)){

            if (pCodProducto < raiz -> codProducto)
                insertarRecursivo(raiz -> HIzq, pNombre, pCodProducto);
            else
                insertarRecursivo(raiz -> HDer, pNombre, pCodProducto);
        }
    }
}

void ArbolAVL::insertarRecursivo(NodoAVL *&r, string pNombre, int pCodProducto){

    if (r == NULL) {
    	r = new NodoAVL(pNombre, pCodProducto);
    } else {
        if (pCodProducto < r -> codProducto){
            insertarRecursivo(r -> HIzq, pNombre, pCodProducto);
        } else {
            insertarRecursivo(r -> HDer, pNombre, pCodProducto);
        }
    }
}

void ArbolAVL::insertarMarca(string pNombre, int pCodProducto, int pCodMarca, int pCantidad, float pPrecio) {
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.insertar(pNombre, pCodMarca, pCantidad, pPrecio);
	} else {
		
		if (pCodProducto < raiz -> codProducto) {
			insertarMarcaRecursivo(raiz -> HIzq, pNombre, pCodProducto, pCodMarca, pCantidad, pPrecio);
		} else {
			insertarMarcaRecursivo(raiz -> HDer, pNombre, pCodProducto, pCodMarca, pCantidad, pPrecio);
		}
	}
}

void ArbolAVL::insertarMarcaRecursivo(NodoAVL *&r, string pNombre, int pCodProducto, int pCodMarca, int pCantidad, float pPrecio) {
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.insertar(pNombre, pCodMarca, pCantidad, pPrecio);
	} else {
		
		if (pCodProducto < r -> codProducto) {
			insertarMarcaRecursivo(r -> HIzq, pNombre, pCodProducto, pCodMarca, pCantidad, pPrecio);
		} else {
			insertarMarcaRecursivo(r -> HDer, pNombre, pCodProducto, pCodMarca, pCantidad, pPrecio);
		}
	}
}

void ArbolAVL::insertarInventario(string pNombre, int pCodProducto, int pCodMarca, int pStock, int pCanasta) {
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> inventario.insertar(pNombre, pCodMarca, pStock, pCanasta);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			insertarInventarioRecursivo(raiz -> HIzq, pNombre, pCodProducto, pCodMarca, pStock, pCanasta);
		} else {
			insertarInventarioRecursivo(raiz -> HDer, pNombre, pCodProducto, pCodMarca, pStock, pCanasta);
		}
	}
}

void ArbolAVL::insertarInventarioRecursivo(NodoAVL *&r, string pNombre, int pCodProducto, int pCodMarca, int pStock, int pCanasta) {
	
	if (r -> codProducto == pCodProducto) {
		r -> inventario.insertar(pNombre, pCodMarca, pStock, pCanasta);
	} else {
		
		if (pCodProducto < r -> codProducto) {
			insertarInventarioRecursivo(r -> HIzq, pNombre, pCodProducto, pCodMarca, pStock, pCanasta);
		} else {
			insertarInventarioRecursivo(r -> HDer, pNombre, pCodProducto, pCodMarca, pStock, pCanasta);
		}
	}
}

bool ArbolAVL::existeCodigo(int pCodProducto) {

    if (raiz == NULL)
        return false;
    else {

        if (raiz -> codProducto == pCodProducto)
            return true;
        else {
            
            if (pCodProducto < raiz -> codProducto)
                return existeCodigoRecursivo(pCodProducto, raiz -> HIzq);
            else
                return existeCodigoRecursivo(pCodProducto, raiz -> HDer);
        }
    }
}

bool ArbolAVL::existeCodigoRecursivo(int pCodProducto, NodoAVL *&r) {

    if (r == NULL)
        return false;
    else {

        if (r -> codProducto == pCodProducto)
            return true;
        else {

            if (pCodProducto < r -> codProducto)
                return existeCodigoRecursivo(pCodProducto, r -> HIzq);
            else
                return existeCodigoRecursivo(pCodProducto, r -> HDer);
        }
    }
}

bool ArbolAVL::existeMarca(int pCodProducto, int pCodMarca) {
	
	if (raiz -> codProducto == pCodProducto) {
		return raiz -> marcas.existeCodigo(pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			return existeMarcaRecursivo(pCodProducto, pCodMarca, raiz -> HIzq);
		} else {
			return existeMarcaRecursivo(pCodProducto, pCodMarca, raiz -> HDer);
		}
	}
}

bool ArbolAVL::existeMarcaRecursivo(int pCodProducto, int pCodMarca, NodoAVL *&r) {
	
	if (r -> codProducto == pCodProducto) {
		return r -> marcas.existeCodigo(pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			return existeMarcaRecursivo(pCodProducto, pCodMarca, r -> HIzq);
		} else {
			return existeMarcaRecursivo(pCodProducto, pCodMarca, r -> HDer);
		}
	}
}

void ArbolAVL::mostrarProductos() {
	
	if (raiz != NULL) {
		cout << raiz -> codProducto << " " << raiz -> nombre << endl;
		mostrarProductosRecursivo(raiz -> HIzq);
		mostrarProductosRecursivo(raiz -> HDer);
	}
}

void ArbolAVL::mostrarProductosRecursivo(NodoAVL *&r) {
	
	if (r != NULL) {
		cout << r -> codProducto << " " << r -> nombre << endl;
		mostrarProductosRecursivo(r -> HIzq);
		mostrarProductosRecursivo(r -> HDer);
	}
}

void ArbolAVL::mostrarMarcas(int pCodProducto) {
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.mostrar();
	} else {
		if (pCodProducto < raiz -> codProducto) {
			mostrarMarcasRecursivo(raiz -> HIzq, pCodProducto);
		} else {
			mostrarMarcasRecursivo(raiz -> HDer, pCodProducto);
		}
	}
}

void ArbolAVL::mostrarMarcasRecursivo(NodoAVL *&r, int pCodProducto) {
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.mostrar();
	} else {
		if (pCodProducto < r -> codProducto) {
			mostrarMarcasRecursivo(r -> HIzq, pCodProducto);
		} else {
			mostrarMarcasRecursivo(r -> HDer, pCodProducto);
		}
	}
}

void ArbolAVL::mostrar() {
	
	if (raiz != NULL && !raiz -> marcas.vacio()) {
		cout << raiz -> codProducto << " " << raiz -> nombre << endl;
		raiz -> marcas.mostrar();
		mostrarRecursivo(raiz -> HIzq);
		mostrarRecursivo(raiz -> HDer);
	}
}

void ArbolAVL::mostrarRecursivo(NodoAVL *&r) {
	
	if (r != NULL && !r -> marcas.vacio()) {
		cout << r -> codProducto << " " << r -> nombre << endl;
		r -> marcas.mostrar();
		mostrarRecursivo(r -> HIzq);
		mostrarRecursivo(r -> HDer);
	}
}

void ArbolAVL::mostrarInventario() {
	
	if (raiz != NULL && !raiz -> inventario.vacio()) {
		cout << "Producto: " << raiz -> codProducto << " ";
		raiz -> inventario.mostrar();
		mostrarInventarioRecursivo(raiz -> HIzq);
		mostrarInventarioRecursivo(raiz -> HDer);
	}
}

void ArbolAVL::mostrarInventarioRecursivo(NodoAVL *&r) {
	
	if (r != NULL && !r -> inventario.vacio()) {
		cout << "Producto: " << r -> codProducto << " ";
		r -> inventario.mostrar();
		mostrarInventarioRecursivo(r -> HIzq);
		mostrarInventarioRecursivo(r -> HDer);
	}
}

void ArbolAVL::mostrarPrecio(int pCodProducto, int pCodMarca) {
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.mostrarPrecio(pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			mostrarPrecioRecursivo(pCodProducto, pCodMarca, raiz -> HIzq);
		} else {
			mostrarPrecioRecursivo(pCodProducto, pCodMarca, raiz -> HDer);
		}
	}
}

void ArbolAVL::mostrarPrecioRecursivo(int pCodProducto, int pCodMarca, NodoAVL *&r) {
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.mostrarPrecio(pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			mostrarPrecioRecursivo(pCodProducto, pCodMarca, r -> HIzq);
		} else {
			mostrarPrecioRecursivo(pCodProducto, pCodMarca, r -> HDer);
		}
	}
}


void ArbolAVL::modificarMarcaNombre (string pNombre, int pCodProducto, int pCodMarca){
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.modificarMarcaNombre(pNombre, pCodMarca);
		raiz -> inventario.modificarMarcaNombre (pNombre, pCodMarca);
	} else {
		if (pCodProducto < raiz -> codProducto) {
			modificarMarcaNombreRecursivo(raiz -> HIzq, pNombre, pCodProducto, pCodMarca);
		} else {
			modificarMarcaNombreRecursivo(raiz -> HDer, pNombre, pCodProducto, pCodMarca);
		}
	}
}


void ArbolAVL::modificarMarcaNombreRecursivo(NodoAVL *&r, string pNombre, int pCodProducto, int pCodMarca){
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.modificarMarcaNombre(pNombre, pCodMarca);
		r -> inventario.modificarMarcaNombre (pNombre, pCodMarca);
	} else {
		if (pCodProducto < r -> codProducto) {
			modificarMarcaNombreRecursivo(r -> HIzq, pNombre, pCodProducto, pCodMarca);
		} else {
			modificarMarcaNombreRecursivo(r -> HDer, pNombre, pCodProducto, pCodMarca);
		}
	}
}

void ArbolAVL::modificarMarcaPrecio (float pPrecio, int pCodProducto, int pCodMarca){
	
	if (raiz -> codProducto == pCodProducto) {
		raiz -> marcas.modificarMarcaPrecio(pPrecio, pCodMarca);

	} else {
		if (pCodProducto < raiz -> codProducto) {
			modificarMarcaPrecioRecursivo(raiz -> HIzq, pPrecio, pCodProducto, pCodMarca);
		} else {
			modificarMarcaPrecioRecursivo(raiz -> HDer, pPrecio, pCodProducto, pCodMarca);
		}
	}
}


void ArbolAVL::modificarMarcaPrecioRecursivo(NodoAVL *&r, float pPrecio, int pCodProducto, int pCodMarca){
	
	if (r -> codProducto == pCodProducto) {
		r -> marcas.modificarMarcaPrecio(pPrecio, pCodMarca);

	} else {
		if (pCodProducto < r -> codProducto) {
			modificarMarcaPrecioRecursivo(r -> HIzq, pPrecio, pCodProducto, pCodMarca);
		} else {
			modificarMarcaPrecioRecursivo(r -> HDer, pPrecio, pCodProducto, pCodMarca);
		}
	}
}
