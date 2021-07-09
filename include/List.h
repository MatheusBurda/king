#pragma once

#include <iostream>

template <class TL>
class List {
private:
    /* Node to use as node of the list */
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

        void setPrevious(Node<TE>* pPrevious) { this->pPrevious = pPrevious; }
        Node<TE>* getPrevious() { return pPrevious; }

        void setInfo(TE* pInfo) { this->pInfo = pInfo; }
        TE* getInfo() { return pInfo; }
    };

    Node<TL>* pFirst;
    Node<TL>* pLast;
    int size;

public:
    List();
    ~List();

    void clear();
    void setNode(Node<TL>* pNode);
    void append(TL* pInfo);
    int length() { return size; }

    Node<TL>* getpFirst() { return pFirst; }
    Node<TL>* getpLast() { return pLast; }
    TL* operator[](int x);
};

template <class TL>
List<TL>::List() {
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

template <class TL>
TL* List<TL>::operator[](int x) {
    if (x >= size) {
        std::cout << "ERROR: Segmentation fault on template list. Exceeded boundaries." << std::endl;
        exit(1);
    }

    Node<TL>* pAux = pFirst;
    for (int i = 0; i < x; i++) {
        pAux = pAux->getNext();
    }
    return pAux->getInfo();
}