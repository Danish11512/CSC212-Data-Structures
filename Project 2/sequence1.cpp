
//                                                Danish Faruqi
//                                                CSC21200 - FG
//                                                Data Structures Assignment#2


// You must add all the code for this file.
#include <cassert>
#include <algorithm>
#include "sequence1.h"

namespace data_structures_assignment_2
{

    sequence::sequence() { // don't care, just setting everything to zero, cursor points at 0 as long as there aren't 2 items
        cursor = CAPACITY; // last possible one
        used = 0;
    }

//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).

    void sequence::start() {

        if(used>0) { // if the array has something, then cursor is 0, otherwise its still CAPACITY
            cursor = 0;
        }
    }

//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.

    void sequence::advance() {
        assert(is_item());

        cursor +=1;
        if (cursor > used-1)
        {
            cursor = CAPACITY;
        }
    }

//   void insert(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.

void sequence::insert(const data_structures_assignment_2::sequence::value_type &entry) {
        assert(size()<CAPACITY);

        if(is_item()) // cursor is on the bound of the array
        {
                if(used ==0 ) // used = 0
                {
                    array[used] = entry;
                    cursor = used;
                    used+=1;
                    return;
                }
            if( cursor == used-1) // when current item is the last item
            {
                array[used] = array[int(cursor)]; // the one ahead of it is copied to cursor
                array[int(cursor)] = entry;
                used+=1;
                return;
            }
            if(cursor<used-1) // everything but the last item
            {
                for (int i = used-1; i>= cursor; i--)
                    {
                        array[i+1] = array[i];
                    }
                    array[int(cursor)] = entry;
                    used +=1;
                    return;
            }
        }

        if(!is_item()) // the cursor is outside or used = 0 , inserting in the beginning
        {
            if(used ==0 ) // used = 0
            {
                array[used] = entry;
                cursor = used;
                used+=1;
                return;
            }else
            {
                for (int i = used-1; i>= 0; i--)
                {
                    array[i+1] = array[i];
                }
                array[0] = entry;
                cursor = 0;
                used +=1;
                return;

            }


        }

    }

//    void attach(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.

void sequence::attach(const data_structures_assignment_2::sequence::value_type &entry) {
        assert(size()<CAPACITY);

    if(is_item()) // cursor is on the bound of the array
    {   if(used ==0 ) // used = 0
        {
            array[used] = entry;
            cursor = used;
            used+=1;
            return;
        }
        if( cursor == used-1) // when current item is the last item
        {
            array[used] = entry; // the one ahead of it is a copy of cursor
            cursor +=1;
            used+=1;
            return;
        }
        if(cursor<used-1) // all the rest
        {
            for (int i = used-1; i> cursor; i--)
            {
                array[i+1] = array[i];
            }
            array[int(cursor)+1] = entry;
            cursor +=1;
            used +=1;
        }
    }

    if(!is_item()) // the cursor is outside or used = 0
    {
        array[used] = entry;
        cursor = used;
        used+=1;
    }

    }

//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.

void sequence::remove_current() {
        assert(is_item());

        if(used == 0) // just in case
        {
            return;
        }

        if( cursor == used-1) // when current item is the last item, so there is nothing in front of it
        {
            used -=1;
            cursor = CAPACITY;
            if(used ==0)
            {
                cursor = CAPACITY;
            }
            return;
        }


        if(cursor<used-1)
        {
            for (int i = int(cursor); i< used-1; i++)
            {
                array[i] = array[i+1];
            }
            used -= 1;
            return;
        }
    }

//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.

sequence::size_type sequence::size() const {
        return used;
    }

//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.

    bool sequence::is_item() const {
        return cursor != CAPACITY;
    }

//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.

    sequence::value_type sequence::current() const {
        assert(is_item());
        return array[int(cursor)];
    }





}




























    // Constructor
//sequence::sequence() {
//    used = 0;
//    current_item = INT_MAX;
//}
//
////   void start( )
////     Postcondition: The first item on the sequence becomes the current item
////     (but if the sequence is empty, then there is no current item).
//
//void sequence::start() {
//    if (used == 0)
//    {
//       current_item = INT_MAX;
//    }
//    else
//    {
//        current_item = 0;
//    }
//
//
//}
//
////   void advance( )
////     Precondition: is_item returns true.
////     Postcondition: If the current item was already the last item in the
////     sequence, then there is no longer any current item. Otherwise, the new
////     current item is the item immediately after the original current item.
//
//void sequence::advance() {
//    assert(is_item());
//
//        current_item +=1;                   // +1 the spot r
//}
//
////   void insert(const value_type& entry)
////     Precondition: size( ) < CAPACITY.
////     Postcondition: A new copy of entry has been inserted in the sequence
////     before the current item. If there was no current item, then the new entry
////     has been inserted at the front of the sequence. In either case, the newly
////     inserted item is now the current item of the sequence.
//
//void sequence::insert(const data_structures_assignment_2::sequence::value_type &entry) {
//    assert(size()<CAPACITY);
//
//    if (current_item < used-1 )    // insert in the middle of the sequence
//    {
//        for (int i = used-1; i>= current_item; i--)
//        {
//            array[i+1] = array[i];
//        }
//        array[int(current_item)] = entry;
//        used++;
//
//    }
//    if( current_item == used-1) // when current item is the last itme
//    {
//        array[int(current_item+1)] = current_item;
//        array[int(current_item)] = entry;
//        used++;
//    }
//
//    if(used == 0) // set last one as entry and current item
//    {
//        array[used] = entry;
//        current_item = used;
//        used++;
//    }
//
//    if(current_item == INT_MAX && used > 0) // no current but has vars
//    {
//        array[used] = entry;
//        current_item = used;
//        used++;
//
//    }
//}
//
////    void attach(const value_type& entry)
////     Precondition: size( ) < CAPACITY.
////     Postcondition: A new copy of entry has been inserted in the sequence after
////     the current item. If there was no current item, then the new entry has
////     been attached to the end of the sequence. In either case, the newly
////     inserted item is now the current item of the sequence.
//
//void sequence::attach(const data_structures_assignment_2::sequence::value_type &entry) {
//    assert(size()<CAPACITY);
//
//        if(current_item < used -1 )// current is in the array
//        {
//            for(int i= used-1; i>current_item; i--) // moved all elements until they reach current_item
//            {
//                array[i+1] = array[i];
//            }
//            array[int(current_item+1)] = entry;
//            current_item+=1;
//            ++used;
//        }
//
//        if( current_item == used-1) // when current item is the last itme
//        {
//            array[int(current_item+1)] = entry;
//            current_item +=1;
//            used = used+1;
//        }
//        if(used == 0) //array is empty
//        {
//            array[0] = entry;
//            current_item = 0;
//            used =1;
//        }
//
//}
//
////   void remove_current( )
////     Precondition: is_item returns true.
////     Postcondition: The current item has been removed from the sequence, and the
////     item after this (if there is one) is now the new current item.
//
//void sequence::remove_current() {
//    assert(size());
//    if(used ==0)
//    {
//        current_item = INT_MAX;
//    }
//    if (current_item == used-1 ) // if its the last one, or the only one
//    {
//        used = used-1;
//        current_item = current_item-1;
//    }else {
//        for (int i = int(current_item); i < used - 1; i++) // removing the current_item
//        {
//            array[i] = array[i + 1];
//
//        }
//        --used; // cuurent item stays the same
//    }
//
//}
//
////   size_type size( ) const
////     Postcondition: The return value is the number of items in the sequence.
//
//sequence::size_type sequence::size() const {
//    return used;
//}
//
////   bool is_item( ) const
////     Postcondition: A true return value indicates that there is a valid
////     "current" item that may be retrieved by activating the current
////     member function (listed below). A false return value indicates that
////     there is no valid current item.
//
//bool sequence::is_item() const {
//    return current_item < INT_MAX;
//}
//
////   value_type current( ) const
////     Precondition: is_item( ) returns true.
////     Postcondition: The item returned is the current item in the sequence.
//
//sequence::value_type sequence::current() const {
//    assert(is_item());
//    return array[int(current_item)];
//}
//

