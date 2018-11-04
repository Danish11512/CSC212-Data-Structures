// You must provide all of this code.
#include "sequence2.h"
#include <cassert>
#include <algorithm>

namespace data_structures_assignment_3
{
//    //   sequence(size_type initial_capacity = DEFAULT_CAPACITY)
////     Postcondition: The sequence has been initialized as an empty sequence.
////     The insert/attach functions will work efficiently (without allocating
////     new memory) until this capacity is reached.
//// Constructor
//sequence::sequence(data_structures_assignment_3::sequence::size_type initial_capacity ) {
//        // use a default parameter or the ones you want
//
//        array = new sequence::value_type[initial_capacity];
//        capacity = initial_capacity;
//        used = 0;
//        cursor = INT_MAX; // the cursor points to nothing but an arbitrary number which will always be different from the capacity
//
//}
//
////     sequence(const sequence& source)
////    - write these preconditions and postconditions yourself!
//// Copy Constructor
//sequence::sequence(const data_structures_assignment_3::sequence &source) {
//
//    array = new sequence::value_type[source.capacity];
//    capacity = source.capacity;
//    used = source.used;
//
//    std::copy(source.array, source.array + used, array);
//}
//
////Destructor
//sequence::~sequence() {
//    delete[] array;
//}
//
////   void resize(size_type new_capacity)
////     Postcondition: The sequence's current capacity is changed to the
////     new_capacity (but not less that the number of items already on the
////     sequence). The insert/attach functions will work efficiently (without
////     allocating new memory) until this new capacity is reached.
//
//void sequence::resize(data_structures_assignment_3::sequence::size_type new_capacity) {
//    if(new_capacity == used){   // the size  has to be bigger, not less or equal
//        return;
//    }
//
//    if(new_capacity <used) // if new size if smaller than current used, set new size the same as used, so it never undercuts, and the used == new size
//    {
//        new_capacity = used;
//    }
//
//    sequence::value_type* new_array;        // new array
//    new_array = new value_type[new_capacity]; // set size of new array
//
//    std::copy(array, array + used, new_array); // copy data over
//
//    delete[] array; // delete contents from old array
//
//    array = new_array;  // link pointer from old array to the new one, they are now linked
//    capacity = new_capacity; // array capacity is set to the new capacity that is set
//}
//
//// Member Functions
//
////   void start( )
////     Postcondition: The first item on the sequence becomes the current item
////     (but if the sequence is empty, then there is no current item).
//void sequence::start() {
//        if (used > 0) { // if the array has something, then cursor is 0, otherwise its still INT_MAX
//            cursor = 0;
//        }
//
//    }
//    //   void advance( )
////     Precondition: is_item returns true.
////     Postcondition: If the current item was already the last item on the
////     sequence, then there is no longer any current item. Otherwise, the new
////     current item is the item immediately after the original current item.
//
//void sequence::advance() { // same as before
//        assert(is_item());
//        cursor +=1;
//        if (cursor > used-1)
//        {
//            cursor = INT_MAX;
//        }
//    }
//
//    //   void insert(const value_type& entry)
////     Postcondition: A new copy of entry has been inserted in the sequence before
////     the current item. If there was no current item, then the new entry has
////     been inserted at the front of the sequence. In either case, the newly
////     inserted item is now the current item of the sequence.
//
//void sequence::insert(const data_structures_assignment_3::sequence::value_type &entry) {
//
//    assert(size()<capacity);
//
//    if (size() +1  > capacity) { // if size is == to capacity resize, but just in case included >
//        sequence::resize(capacity + 10);
//    }
//
//
//    if (is_item()) { // cursor is in the bound of the array
//            if (used == 0) // used = 0
//            {
//                array[0] = entry;
//                cursor = 0;
//                used += 1;
//                return;
//            }
//            if (cursor == used - 1) // when current item is the last item
//            {
//                array[used] = array[int(cursor)]; // the one ahead of it is copied to cursor
//                array[int(cursor)] = entry;
//                used += 1;
//                return;
//            }
//            if (cursor < used - 1) // everything but the last item
//            {
//                for (int i = used - 1; i >= cursor; i--) {
//                    array[i + 1] = array[i];
//                }
//                array[int(cursor)] = entry;
//                used += 1;
//                return;
//            }
//        }
//        // cursor barely has the reason to go out of bounds, but if it is out of bounds
//        if (!is_item()) // the cursor is outside
//        {
//            if (used == 0) // used = 0 and cursor is outside
//                {
//                array[used] = entry;
//                cursor = used;
//                used += 1;
//                return;
//            } else { // cursor is outside and there are some elements in the array, just move them and insert, and set the cursor to the one inserted
//                for (int i = used - 1; i >= 0; i--) {
//                    array[i + 1] = array[i];
//                }
//                array[0] = entry;
//                cursor = 0;
//                used += 1;
//                return;
//            }
//
//        }
//
//}
//
////   void attach(const value_type& entry)
////     Postcondition: A new copy of entry has been inserted in the sequence after
////     the current item. If there was no current item, then the new entry has
////     been attached to the end of the sequence. In either case, the newly
////     inserted item is now the current item of the sequence.
//
//void sequence::attach(const data_structures_assignment_3::sequence::value_type &entry) {
//
//    assert(size()<capacity);
//
//    if (size()+1 > capacity) { // if the new size, with the new entry is more than capacity can hold, then it resizes the array
//        sequence::resize(capacity + 10);
//    }
//// nothing changes from the previous assignment, here and in insert
//
//    if (is_item()) // cursor is in the bound of the array
//    {
//        if (used == 0) // used = 0
//        {
//            array[used] = entry;
//            cursor = used;
//            used += 1;
//            return;
//        }
//        if (cursor == used - 1) // when current item is the last item
//        {
//            array[used] = entry; // the one ahead of it is a copy of cursor
//            cursor += 1;
//            used += 1;
//            return;
//        }
//        if (cursor < used - 1) // all the rest
//        {
//            for (int i = used - 1; i > cursor; i--) {
//                array[i + 1] = array[i];
//            }
//            array[int(cursor) + 1] = entry;
//            cursor += 1;
//            used += 1;
//        }
//    }
//
//    if (!is_item()) // the cursor is outside or used = 0
//    {
//        array[used] = entry;
//        cursor = used;
//        used += 1;
//    }
//
//}
////   void remove_current( )
////     Precondition: is_item returns true.
////     Postcondition: The current item has been removed from the sequence, and the
////     item after this (if there is one) is now the new current item.
//
//void sequence::remove_current() {
//    assert(is_item());
//
//    if(used == 0) // just in case
//    {
//        return;
//    }
//
//    if( cursor == used-1) // when current item is the last item
//    {
//        used -=1;
//        cursor = INT_MAX;
//        return;
//    }
//
//
//    if(cursor<used-1) // if there are multiple items
//    {
//        for (sequence::size_type i = cursor; i< used-1; i++)
//        {
//            array[i] = array[i+1];
//        }
//        used -= 1;
//        return;
//    }
//}
//
//void sequence::operator=(const data_structures_assignment_3::sequence &source) {
//
//
//    if(this != &source) {
//        if (capacity != source.capacity)
//        {
//            // to copy over the data, you need a new array:
//            sequence::value_type *new_array; // pointer
//            // with the size of 1st one
//            new_array = new sequence::value_type[source.capacity];
//
//            // delete the contents from old array so it can hold this one;
//            delete[] array;
//            array = new_array; // the one that was to be changed points to the new array
//            capacity = source.capacity;
//            used = source.used;
//            cursor = source.cursor;
//        }
//        // copy the data to the new array:
//        std::copy(source.array, source.array + source.used, array);
//    }
//}
//
////   size_type size( ) const
////     Postcondition: The return value is the number of items in the sequence.
//
//    sequence::size_type sequence::size() const {
//        return used;
//    }
//
////   bool is_item( ) const
////     Postcondition: A true return value indicates that there is a valid
////     "current" item that may be retrieved by activating the current
////     member function (listed below). A false return value indicates that
////     there is no valid current item.
//
//    bool sequence::is_item() const {
//        return cursor != INT_MAX;
//    }
//
////   value_type current( ) const
////     Precondition: is_item( ) returns true.
////     Postcondition: The item returned is the current item in the sequence.
//
//    sequence::value_type sequence::current() const {
//        assert(is_item());
//        return array[int(cursor)];
//    }
//
//














// comment this code, keep the ones orginal to this code, and copy over the old dynamic parts, change cursor property when it reaches out of bounds

sequence::sequence(data_structures_assignment_3::sequence::size_type initial_capacity) {
    //     Postcondition: The sequence has been initialized as an empty sequence.
    //     The insert/attach functions will work efficiently (without allocating
    //     new memory) until this capacity is reached.

    used = 0;
    cursor = initial_capacity+5; // have to remember to change everywhere
    capacity = initial_capacity;
    array = new sequence::value_type[initial_capacity]; // create an array with the capacity of initial capacity
    //all 4 things have been done.
}
 // copy constructor
sequence::sequence(const data_structures_assignment_3::sequence &source) {
    // Postcondition: copy the items from one bag to another
    // Copy all attributes

    array = new sequence::value_type[source.capacity];
    cursor = source.cursor;
    capacity = source.capacity;
    used = source.used;
    std::copy(source.array, source.array + used, array);
}
// passsed
void sequence::resize(data_structures_assignment_3::sequence::size_type new_capacity) {

        //     Postcondition: The sequence's current capacity is changed to the
//     new_capacity (but not less that the number of items already on the
//     sequence). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.

    if(new_capacity == capacity) {
        return;
    }


// instead of providing the the old capacity + the new capacity, jut provide by how much you want to resize. So it adds or negates as many slots as needed, it doesn't ask you for the old size + amount you want to add, just amount you want to add/reduce

        if(new_capacity <used) // if new size if smaller than current used, set new size the same as used, so it never undercuts, and the used == new size
        {
            new_capacity = used;
        }
// changing the cursor if its out of bounds, don't want it to be accidentally inside the array
        if( cursor == capacity+5)
            cursor = new_capacity + capacity +5; // the new capacity + 5


           // have to be greater or equal otherwise it wont run, = bc if they want to make the array as big as the used, they should be able to

           sequence::value_type *new_array;        // new array
            new_array = new value_type[new_capacity]; // set size of new array

            std::copy(array, array + used, new_array); // copy data over

            delete[] array; // delete contents from old array

            array = new_array;  // link pointer from old array to the new one, they are now linked
            capacity = new_capacity; // array capacity is set to the new capacity that is set
}
//void sequence::resize(data_structures_assignment_3::sequence::size_type new_capacity) {
//    if(new_capacity == used){   // the size  has to be bigger, not less or equal
//        return;
//    }
//
//    if(new_capacity <used) // if new size if smaller than current used, set new size the same as used, so it never undercuts, and the used == new size
//    {
//        new_capacity = used;
//    }
//
//        // changing the cursor if its out of bounds, don't want it to be accidentally inside the array
//    if( cursor == capacity+5)
//        cursor = new_capacity + capacity +5; // the new capacity + 5
//
//    sequence::value_type* new_array;        // new array
//    new_array = new value_type[new_capacity]; // set size of new array
//
//    std::copy(array, array + used, new_array); // copy data over
//
//    delete[] array; // delete contents from old array
//
//    array = new_array;  // link pointer from old array to the new one, they are now linked
//    capacity = new_capacity; // array capacity is set to the new capacity that is set
//}


void sequence::start() {
    //     Postcondition: The first item on the sequence becomes the current item
    //     (but if the sequence is empty, then there is no current item).

    if (used > 0) { // if the array has something, then cursor is 0, otherwise its still capacity +5
        cursor = 0;
    }
}

// passed test 2
void sequence::advance() {
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item on the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.

assert(is_item());
        cursor +=1;
        if(cursor > used-1)
            cursor= capacity+5;
}

void sequence::insert(const data_structures_assignment_3::sequence::value_type &entry) {
    //     Postcondition: A new copy of entry has been inserted in the sequence before
//     the current item. If there was no current item, then the new entry has
//     been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.

//    if(size()>=capacity)    // just as a precondition, checking if the array is full, then add 10 more . Its a replacement of the assert which gave an error if the size was >= to CAPACITY
//        resize(capacity + 10);
//    // everything else continues normally, nothing changed
//
//    if(is_item()) // cursor is on the bound of the array
//        {
//            if(used ==0 ) // used = 0
//            {
//                array[used] = entry;
//                cursor = used;
//                used+=1;
//                return;
//            }
//            if( cursor == used-1) // when current item is the last item
//            {
//                array[used] = array[int(cursor)]; // the one ahead of it is copied to cursor
//                array[int(cursor)] = entry;
//                used+=1;
//                return;
//            }
////            if(cursor == 0)
////            {  for (int i = used - 1; i >cursor; i--) {
////                    array[i + 1] = array[i];
////                }
////                array[0] = entry;
////                cursor = 0;
////                used += 1;
////                return;
////            }
//
//            if(cursor<used-1) // everything but the last item
//            {
//                    for (int i = used - 1; i > cursor; i--) {
//                        array[i + 1] = array[i];
//                    }
//                    array[int(cursor)] = entry;
//                    used += 1;
//                    return;
//            }
//        }
//
//        if(!is_item()) // the cursor is outside or used = 0 , inserting in the beginning
//        {
//            if(used ==0 ) // used = 0
//            {
//                array[used] = entry;
//                cursor = used;
//                used+=1;
//                return;
//            }else
//            {
//                for (int i = used-1; i>= 0; i--)
//                {
//                    array[i+1] = array[i];
//                }
//                array[0] = entry;
//                cursor = 0;
//                used +=1;
//                return;
//
//            }
//
//
//        }
    if( size() >= capacity ) // always resize by 10, makes it smoother to run a while
        resize(capacity + 10);

    if (is_item()) // cursor is on the bound of the array
    {
        for (size_type i = used; i > cursor; i--) {
            array[i] = array[i-1];
        }
        array[cursor] = entry;
        used++;
        // the other noes aren't working, so tried a simpler approach
    }
    if(!is_item()){ // the cursor is outside or used = 0 , inserting in the beginning
        for (size_type j = used; j > 0; j--) {
            array[j] = array[j-1];
        }
        cursor = 0;
        array[cursor] = entry;
        used++;
    }
    }

void sequence::attach(const data_structures_assignment_3::sequence::value_type &entry) {
    //     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.

    if(size()>=capacity)    // just as a precondition, checking if the array is full, then add 10 more . Its a replacement of the assert which gave an error if the size was >= to CAPACITY
        resize(capacity + 10);
    // everything else continues normally, nothing changed

//    if(is_item()) // cursor is on the bound of the array
//        {   if(used ==0 ) // used = 0
//            {
//                array[used] = entry;
//                cursor = used;
//                used+=1;
//                return;
//            }
//            if( cursor == used-1) // when current item is the last item
//            {
//                array[used] = entry; // the one ahead of it is a copy of cursor
//                cursor +=1;
//                used+=1;
//                return;
//            }
//            if(cursor<used-1) // all the rest
//            {
//                for (int i = used-1; i> cursor; i--)
//                {
//                    array[i+1] = array[i];
//                }
//                array[int(cursor)+1] = entry;
//                cursor +=1;
//                used +=1;
//            }
//        }
//
//        if(!is_item()) // the cursor is outside or used = 0
//        {
//            array[used] = entry;
//            cursor = used;
//            used+=1;
//        }
    if (is_item()) {
        if( cursor == used-1) // when current item is the last item
            {
                array[used] = entry; // the one ahead of it is a copy of cursor
                cursor +=1;
                used+=1;
                return;
            }

        for (size_type i = used; i > cursor + 1; i--) {
            array[i] = array[i-1];
        }
        cursor++;
        array[cursor] = entry;
        used++;
    }
    else { // if there is no current item then its put at the end
        used++;
        cursor = used - 1;
        array[cursor] = entry; // current item now
    }

    }

void sequence::remove_current() {
    //     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.


    if(used == 0) // just in case
    {
        return;
    }

    if( cursor == used-1) // when current item is the last item, so there is nothing in front of it
    {
        used -=1;
        cursor = capacity + 5;
        if(used ==0)
        {
            cursor = capacity +5;
        }
        return;
    }


    if(cursor<used) // anywhere else
    {
        for (int i = int(cursor); i< used-1; i++)
        {
            array[i] = array[i+1];
        }
        used -= 1;
        return;
    }


}


sequence::size_type sequence::size() const {
    //     Postcondition: The return value is the number of items on the sequence.
    return used;
}

bool sequence::is_item() const {
    //     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
return cursor<used;
}

sequence::value_type sequence::current() const {
    //     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item on the sequence.
        assert(is_item());
        return array[int(cursor)];
    }

//Destructor -  everything seems to work except this, the destructor fails in the exam and there is a leak, I don't see how to fix it .
sequence::~sequence() {
        delete[] array;
// teh code breaks down on line 897 in sequence_exam.cpp


}

void sequence::operator=(const data_structures_assignment_3::sequence &source) {

    if(this != &source) { // not the same bag
        if (capacity != source.capacity) {
            // to copy over the data, you need a new array:
            sequence::value_type *new_array; // pointer
            // with the size of 1st one
            new_array = new sequence::value_type[source.capacity];
            // delete the contents from old array so it can hold this one;
            delete[] array;
            array = new_array; // the one that was to be changed points to the new array
            capacity = source.capacity;
        }
            cursor = source.cursor; // didn't include this in test 6 so it failed the first few times.
            used = source.used;
        // copy the data to the new array:
        std::copy(source.array, source.array + source.used, array);
    }// along with everything, the data is copied to create a copy
}





























}// namespace parenthesis













