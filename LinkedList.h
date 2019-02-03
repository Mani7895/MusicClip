#include "MusicClipPtr.h"

class Node
{
private:
    MusicClipPtr musicclipPtr;
    Node* next;

public:
    Node();
    MusicClipPtr& getData();
    Node* getNext();
    void setNext(Node* );
};

class Iterator
{
private:
	Node* node;
public:
	Iterator(Node*);
	void operator++();
	void operator++(int);
	void operator=(Iterator);
	bool operator!=(Iterator&);
	Node* operator->() const;
	operator Node*();
};

class LinkedList
{
private:
    Node* head;
    Node* tail;
    Iterator currentNode;
    void recursiveDelete(Node*);
public:
    LinkedList();
    LinkedList(int);
    ~LinkedList();
    void setCurrentNode(Iterator);
    Iterator begin();
    Iterator end();
    Iterator& getCurrentNode();
};
