#include "LinkendList.hpp"

void printList(std::unique_ptr<Nodo> &head){
  Nodo* aux = head.get();
  if(aux == nullptr){
    std::cout<<"La cabeza es null"<<std::endl;
  }
  while(aux){
    std::cout << aux->number << "->";
    aux = aux->next.get();
  }
  std::cout << "\n";
}

void tailInsersion(std::unique_ptr<Nodo> &head, int value){
  if(head == nullptr){
    std::cout << "No existe la cabeza" << std::endl;
    return;
  }
  Nodo* aux = head.get();
  while(aux->next.get() != nullptr){
    aux = aux->next.get();
  }
  std::unique_ptr<Nodo> newNodo = std::make_unique<Nodo>(value);
  aux->next = std::move(newNodo);
}

Nodo* findFirst(std::unique_ptr<Nodo> &head, int value){
  if(head == nullptr){
    std::cout << "La cabeza no existe" << std::endl;
    return nullptr;
  }
  Nodo* aux = head.get();
  while(aux != nullptr){
    if(aux->number == value){
      return aux;
    }
    aux = aux->next.get();
  }
  return nullptr;
}

void updateValue(std::unique_ptr<Nodo> &head, int toReplace, int toInsert){
  if(head == nullptr){
    std::cout << "La cabeza no existe" << std::endl;
    return;
  }
  Nodo* finded = findFirst(head, toReplace);
  if(finded == nullptr){
    std::cout << "No se encontro resultado" << std::endl;
    return;
  }
  finded->number = toInsert;
}
void deleteNode(std::unique_ptr<Nodo> &head, int toDelete){
  if(head == nullptr){
    std::cout << "La cabeza no existe" << std::endl;
    return;
  }
  Nodo* aux = head.get();
  if(aux->number == toDelete){
    head = std::move(aux->next);
    return;
  }
  aux = findFirst(head, toDelete);
  if(aux == nullptr){
    std::cout << "No existe el nodo a eliminar" << std::endl;
    return;
  }
  Nodo* aux2 = head.get();
  while(aux != nullptr && aux2->next->number != aux->number) {
    aux2 = aux2->next.get();
  }
  aux2->next = std::move(aux->next);
}
std::unique_ptr<Nodo> headInsertion(std::unique_ptr<Nodo> &head, int value){
  if(head == nullptr){
    std::cout << "La cabeza no existe" << std::endl;
    return nullptr;
  }
  std::unique_ptr<Nodo> newHead = std::make_unique<Nodo>(value);
  newHead->next = std::move(head);
  return newHead;
}