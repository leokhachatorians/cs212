/** Implementation file for the class ArrayBag
  @file ArrayBag.cpp */

#ifndef ARRAYBAG_CPP
#define ARRAYBAG_CPP

#include "ArrayBag.h"

template<class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{

} // end default constructor

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = newEntry;
        itemCount++;
    } // end if

    return hasRoomToAdd;
} // end add

template<class ItemType>
vector<ItemType> ArrayBag<ItemType>:: toVector() const
{
    vector<ItemType> bagContents;
    for (int i = 0; i < itemCount; i++)
        bagContents.push_back(items[i]);
    return bagContents;
} // end toVector

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return itemCount;
} // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem)
    {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    } // end if

    return canRemoveItem;
} // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
    itemCount = 0;
} // end clear

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const
{
    bool found = false;
    int curIndex = 0;  // Current array index
    while (!found && (curIndex < itemCount))
    {
        if (target == items[curIndex])
        {
            found = true;
        }
        curIndex++;  // Increment to next entry
     } // end while

    return found;
} // end contains

template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;

    // If the bag is empty, itemCount is zero, so loop is skipped
    while (!found && (searchIndex < itemCount))
    {
        if (items[searchIndex] == target)
        {
            found = true;
            result = searchIndex;
        }
        else
        {
             searchIndex++;
        } // end if
    } // end while

    return result;
} // end of getIndexOf

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
    int frequency = 0;
    int curIndex = 0; // Current array index
    while (curIndex < itemCount)
    {
        if (items[curIndex] == anEntry)
       {
            frequency++;
        } // end if
 
        curIndex++;  // Increment to next entry
    } // end while

    return frequency;
} // end getFrequencyOf

#endif

