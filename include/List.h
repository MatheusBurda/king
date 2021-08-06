#pragma once

#include "stdafx.h"

template <class TL>
class List {
private:
    /* template Node to use as node of the list */
    template <class TE>
    class Node {
    private:
        Node<TE>* pNext;
        Node<TE>* pPrevious;
        TE* pInfo;

    public:
        Node() {
            pNext = NULL;
            pPrevious = NULL;
            pInfo = NULL;
        }
        ~Node() {
            pNext = NULL;
            pPrevious = NULL;
            pInfo = NULL;
        }
        /* Set next template Node - internal list use */
        void setNext(Node<TE>* pNext) { this->pNext = pNext; }
        /* Get next node of the list */
        Node<TE>* getNext() { return pNext; }
        /* Set previous node */
        void setPrevious(Node<TE>* pPrevious) { this->pPrevious = pPrevious; }
        /* Get previous node */
        Node<TE>* getPrevious() { return pPrevious; }
        /* Sets the pointer the template Node points to*/
        void setInfo(TE* pInfo) { this->pInfo = pInfo; }
        /* Returns the pointer the template Node points to. */
        TE* getInfo() { return pInfo; }
    };

    Node<TL>* pFirst;
    Node<TL>* pLast;
    int size;

public:
    List();
    ~List();

    void clear();
    void append(TL* pInfo);
    int length() { return size; }
    TL* operator[](int x);
    bool remove(TL* pTL);

private:
    void setNode(Node<TL>* pNode);
    Node<TL>* getpFirst() { return pFirst; }
    Node<TL>* getpLast() { return pLast; }
};

template <class TL>
List<TL>::List() :
pFirst(), pLast(), size(0) {
    clear();
}

template <class TL>
List<TL>::~List() {
    clear();
}

/* Delete the whole List */
template <class TL>
void List<TL>::clear() {
    Node<TL>* paux1;
    Node<TL>* paux2;

    paux1 = pFirst;
    paux2 = paux1;

    while (paux1 != NULL) {
        delete (paux1->getInfo());
        paux2 = paux1->getNext();
        delete (paux1);
        paux1 = paux2;
    }

    pFirst = NULL;
    pLast = NULL;
    size = 0;
}

/* Add new Node to List - internal use */
template <class TL>
void List<TL>::setNode(Node<TL>* pNode) {
    if (pNode != NULL) {
        if (pFirst == NULL) {
            pFirst = pNode;
            pLast = pNode;
        } else {
            pLast->setNext(pNode);
            pNode->setPrevious(pLast);
            pLast = pNode;
        }
        size++;

    } else {
        std::cout << "ERROR: on List<TL>::setNode -> Pointer pNode == NULL. Insert not succeeded." << std::endl;
    }
}

/* Append new node to the template list */
template <class TL>
void List<TL>::append(TL* pInfo) {
    if (pInfo != NULL) {
        Node<TL>* pNode = NULL;
        pNode = new Node<TL>();
        pNode->setInfo(pInfo);
        setNode(pNode);

    } else {
        std::cout << "ERROR: on List<TL>::append -> pInfo == NULL" << std::endl;
    }
}

/* Iterate through the list, similar to a static vector. Returns the pointer the template list points to.  */
template <class TL>
TL* List<TL>::operator[](int x) {
    if (x >= size || x < 0) {
        std::cout << "ERROR: Segmentation fault on template list. Exceeded boundaries." << std::endl;
        exit(1);
    }

    Node<TL>* pAux = pFirst;
    for (int i = 0; i < x; i++) {
        pAux = pAux->getNext();
    }

    if (pAux == NULL) {
        cout << "ERROR: on template operator[] pAux == NULL." << endl;
        exit(1);
    }
    return pAux->getInfo();
}

/* Removes a specific element fom list. Return true if was completed. */
template <class TL>
bool List<TL>::remove(TL* pTL) {
    Node<TL>* pAux = pFirst;
    Node<TL>* pPrev = NULL;
    while (pAux != NULL) {
        if (pAux->getInfo() == pTL) {
            if (pAux == pFirst)
                pFirst = pAux->getNext();
            else
                pPrev->setNext(pAux->getNext());

            //delete (pTL);
            delete (pAux);
            size--;
            return true;
        }
        pPrev = pAux;
        pAux = pAux->getNext();
    }
    return false;
}
