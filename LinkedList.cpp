#include "LinkedList.h"

Node::Node()
:musicclipPtr(), next(NULL)
{
}

MusicClipPtr& Node::getData()
{
    return musicclipPtr;
}

void Node::setNext(Node* node)
{
    this->next = node;
}

Node* Node::getNext()
{
    return next;
}

LinkedList::LinkedList()
:head(), currentNode(head)
{
    tail = head -> getNext();
}

LinkedList::LinkedList(int size)
:head(new Node), currentNode(head)
{
    Node* cur = head;
    for(int i = 0; i < size - 1; i++)
    {
        cur->setNext(new Node);
        cur = cur->getNext();
    }
	tail = cur->getNext();
}

void LinkedList::recursiveDelete(Node* node)
{
	if (!node)
	{
		return;
	}
	this->recursiveDelete(node->getNext());
	delete node;
}

LinkedList::~LinkedList()
{
	recursiveDelete(this->head);
}

void LinkedList::setCurrentNode(Iterator iter)
{
	this->currentNode = iter;
}

Iterator LinkedList::begin()
{
	return Iterator(head);
}

Iterator LinkedList::end()
{
	return Iterator(tail);
}

Iterator& LinkedList::getCurrentNode()
{
	return currentNode;
}
Iterator::Iterator(Node* iterNode)
:node(iterNode)
{
}

void Iterator::operator++()
{
	node = node->getNext();
}

void Iterator::operator++(int)
{
	node = node->getNext();
}

void Iterator::operator=(Iterator iter)
{
	this->node = iter.node;
}

bool Iterator::operator!=(Iterator& iter)
{
	return this->node != iter.node;
}

Node* Iterator::operator->() const
{
	return node;
}

Iterator::operator Node*()
{
	return node;
}

