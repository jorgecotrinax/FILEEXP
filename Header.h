#include<iostream>
#include<string>
using namespace std;
template<class A,class B,class C,class D,class E,class F,class G,class H>
class Nodo {
private:	
	A numdenuencia;
	B agraviado;
	C dniagraviado;
	D agresor;
	E dniagresor;
	F tipodelito;
	G  gravedad;
	H testimonio;

	Nodo<A, B, C, D, E, F, G,H>*izquierda;
	Nodo<A, B, C, D, E, F, G,H>*derecha;
	int altura;
public:
	Nodo() {
		izquierda = nullptr;
		derecha = nullptr;
		altura = 0;
    }	
};
template<class A, class B, class C, class D, class E, class F, class G,class H>
class ArbolAVL{
private:
	Nodo<A, B, C, D, E, F, G,H>* raiz;
	void(*procesar)(A, B, C, D, E, F, G,H);

	int _altura(Nodo<A, B, C, D, E, F, G,H>* nodo) {
		if (nodo == nullptr) return 0;
		return nodo->altura;
	}
	void _rotarDerecha(Nodo<A, B, C, D, E, F, G,H>*& nodo) {
		Nodo<A, B, C, D, E, F, G,H>* p = nodo->izq;
		nodo->izq = p->der;
		p->der = nodo;
		nodo = p;
	}
	void _rotarIzquierda(Nodo<A, B, C, D, E, F, G,H>*& nodo) {
		Nodo<A, B, C, D, E, F, G,H>* p = nodo->der;
		nodo->der = p->izq;
		p->izq = nodo;
		nodo = p;
	}
	void _balanceo(Nodo<A, B, C, D, E, F, G,H>*& nodo) {
		int hizq = _altura(nodo->izq);
		int hder = _altura(nodo->der);
		int fb = hder - hizq;

		if (fb > 1) { 
			int hhizq = _altura(nodo->der->izq);
			int hhder = _altura(nodo->der->der);
			if (hhizq > hhder) { 
				_rotarDerecha(nodo->der);
			}
			_rotarIzquierda(nodo);
		}
		if (fb < -1) { 
			int hhizq = _altura(nodo->izq->izq);
			int hhder = _altura(nodo->izq->der);
			if (hhizq < hhder) {
				_rotarIzquierda(nodo->izq);
			}
			_rotarDerecha(nodo);
		}		
		hizq = _altura(nodo->izq);
		hder = _altura(nodo->der);
		nodo->altura = 1 + ((hizq > hder) ? hizq : hder);
	}

	bool _insertar(Nodo<A, B, C, D, E, F, G,H>*& nodo, A id ,B agra, C dniagra, D agre, E dniagre, F tipo, G grave, H testio) {

		if (nodo == nullptr) {			
			nodo = new Nodo<A, B, C, D, E, F, G,H>();
			nodo->numdenuencia = id;
			nodo->agraviado = dniagra;
			nodo->dniagraviado = dniagra;
			nodo->agresor = agre;
			nodo->dniagresor = dniagre;
			nodo->tipodelito = tipo;
			nodo->gravedad = grave;
			nodo->testimonio = testio;
			return true;
		}
		else if (id == nodo->elemento)
			return false;
		else if (id < nodo->elemento) {
			_insertar(nodo->izq, id);
		}
		else if (id > nodo->elemento) {
			_insertar(nodo->der, id);
		}
		_balanceo(nodo);
		return true;
	}
public:
	ArbolAVL(void(*nuevaFuncion)(A, B, C, D, E, F, G, H)) {
		this->procesar = nuevaFuncion;
		this->raiz = nullptr;
	}
	bool Insertar(A id, B agra, C dniagra, D agre, E dniagre, F tipo, G grave, H testio) {
		return _insertar(raiz,id,agra,dniagra,agre,dniagre,tipo,grave,testio);
	}

};

