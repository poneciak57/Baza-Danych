#pragma once
#include "Libraries_Engine.h"

template <typename T>
struct Node
{
	int index;

	T rekord;

	Node<T>* next;
	Node<T>* prev;

	Node() : next(NULL), prev(NULL) {};

};

