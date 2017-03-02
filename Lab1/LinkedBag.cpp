#ifndef LINKEDBAG_CPP
#define LINKEDBAG_CPP

#include "Node.h"
#include "LinkedBag.h"
#include <vector>

using namespace std;

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag) {
    itemCount = aBag.itemCount;
    Node<ItemType>* origChainPtr = aBag.headPtr;

    if (origChainPtr == nullptr) {
        headPtr = nullptr; // Original data is empty; so is copy
    }
    else {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        // Copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr; // Last-node pointer
        while (origChainPtr != nullptr) {
            origChainPtr = origChainPtr->getNext(); // Advance pointer
   
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create next item from original chain
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);

            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr); // Flag end of new chain
    }
}

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry) {
    // Add to beginning of chain: new node references rest of chain;
    // (headPtr is nullptr if chain is empty)
    Node<ItemType>* newNodePtr = new Node<ItemType>();
    newNodePtr->setItem(newEntry);
    newNodePtr->setNext(headPtr);    // New node points to chain
    headPtr = newNodePtr;                  // New node is now first node
    itemCount++;

    return true;
}

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const {
    vector<ItemType> bagContents;
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount)) {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
       counter++;
    }
    return bagContents;
}

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
    return itemCount;
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
    int frequency = 0;
    int counter = 0;
    Node<ItemType>* curPtr = headPtr;
    while ((curPtr != nullptr) && (counter < itemCount)) {
        if (anEntry == curPtr->getItem()) {
            frequency++;
        }
        counter ++;
        curPtr = curPtr->getNext();
    }
    return frequency;
}

// Returns either a pointer to the node containing a given entry
// or the null pointer if the entry is not in the bag

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target) const {
    bool found = false;
    Node<ItemType>* curPtr = headPtr;
    while (!found && (curPtr != nullptr)) {
        if (target == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    }
    return curPtr;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const {
    return (getPointerTo(anEntry) != nullptr);
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemoveItem) {
        // Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());

        // Delete first node
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        itemCount--;
    }
    return canRemoveItem;
}

template<class ItemType>
void LinkedBag<ItemType>::clear() {
    while (headPtr != nullptr) {
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
    }
    // headPtr is nullptr

    itemCount = 0;
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
    clear();
}

#endif
