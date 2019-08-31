#include <iostream>
#include <string>

using namespace std;

struct Nodo{
	int dato;
	Nodo* sig;
}*inicio,*fin;

struct NodoPila{
    int dato;
	NodoPila* sig;
}*inicioPila;

class Pila{
	public:
		Pila(){
			inicioPila = nullptr;
		}
		NodoPila* CrearNodo(int valor){
			NodoPila *n = new NodoPila;
			n->dato = valor;
			n->sig = nullptr;
			return n;
		}
		void push(int valor){
			NodoPila *n = CrearNodo(valor);
			n->sig = inicioPila;
			inicioPila = n;
		}
		void mostrarPila(){
			NodoPila *temp = inicioPila;
			if(!inicioPila){
				cout<<"Pila vacia"<<endl;
			}
			else{
				while(temp->sig){
					cout<<temp->dato<<",";
					temp = temp->sig;
				}
				cout<<temp->dato<<endl;
			}
		}
};

class Cola{
	public:
		Cola(){
			inicio=nullptr;
			fin = nullptr;
		}
		Nodo* crearNodo(int valor){
			Nodo *n = new Nodo;
			n->dato = valor;
			n->sig = nullptr;
			return n;
		}
		void push(int valor){
			Nodo *n = crearNodo(valor);
			if(!inicio){
				inicio = n;
				fin = n;
			}
			else{
				fin->sig=n;
				fin = n;
			}
		}
		void mostrarCola(){
			Nodo *temp = inicio;
			if(!inicio){
				cout<<"Cola vacia"<<endl;
			}
			else{
				while(temp->sig){
					cout<<temp->dato<<",";
					temp = temp->sig;
				}
				cout<<temp->dato<<endl;
			}
		}
		
		void invertirCola(){
			Nodo *temp,*aux =inicio;
			int cont=0;
			while(aux != fin){//se recorre la cola hasta llegar el ultimo valor
				aux = aux->sig;
				cont++;
			}
			fin = inicio; //el primer valor pasa a ser el ultimo
			inicio = aux;// el ultimo valor pasa a ser el primero
			for(int i=0;i<cont;i++){//Como la cola esta apuntando hacia atras se cambia esa direccion para todos los valores
				temp = fin;
				while(temp->sig != aux){//se crea un temp que guardara el nodo anterior al que se quiere cambiar la direccion
					temp = temp->sig;
				}
				aux->sig = temp;//se cambia la dirrecion del nodo hacia el nodo encontrado anteriormente
				temp->sig = nullptr;//se elimina la dirreccion para atras del nodo
				aux = aux->sig;//el nuevo nodo a cambiar pasa a ser el siguiente el cual tiene temp
			}
		}
		void colaEnPila(Pila p){
			Nodo *temp = inicio;
			while(temp){
				p.push(temp->dato);
				temp = temp->sig;
			}
		}
}; 

int main()
{
  Cola c;
  Pila p;
  c.push(1);
  c.push(2);
  c.push(3);
  c.push(4);
  cout<<"Cola sin ordenar: ";
  c.mostrarCola();
  c.invertirCola();
  cout<<"Cola ordenada: ";
  c.mostrarCola();
  c.colaEnPila(p);
  cout<<"Pila: ";
  p.mostrarPila();
}
