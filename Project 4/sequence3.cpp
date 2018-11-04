// You need to write this entire file.
#include "sequence3.h"
#include "node1.h"
#include <cassert>
#include <cstdlib>

namespace data_structures_assignment3
{

    // CONSTRUCTOR for the sequence class:
    //   sequence( )
    //   Postcondition: The sequence has been initialized as an empty sequence.

    sequence::sequence() {
        head_ptr = nullptr; // head pointer and tail pointer point to nothing right now
        tail_ptr = nullptr;
        many_nodes = 0; // there is nothing in the list as of yet
        cursor = nullptr; // cursor and precursor are pointing to nothing right now
        precursor = nullptr;
    }
//-------------------------------------------------------------------------------------------------------------------
    // MODIFICATION MEMBER FUNCTIONS for the sequence class:
    //   void start( )
    //     Postcondition: The first item on the sequence becomes the current item
    //     (but if the sequence is empty, then there is no current item).

    void sequence::start() {
        cursor = head_ptr; // points to the head pointer, which if its null_ptr is now also null_ptr
        precursor = nullptr; // want it to stay behind the cursor
    }
//-------------------------------------------------------------------------------------------------------------------
    //   bool is_item( ) const
    //     Postcondition: A true return value indicates that there is a valid
    //     "current" item that may be retrieved by activating the current
    //     member function (listed below). A false return value indicates that
    //     there is no valid current item.

    bool sequence::is_item() const {
        // means that there is a current node, if there is no current node then its null_ptr
        return cursor != nullptr;
    }
//--------------------------------------2-----------------------------------------------------------------------------

    //   void advance( )
    //     Precondition: is_item returns true.
    //     Postcondition: If the current item was already the last item on the
    //     sequence, then there is no longer any current item. Otherwise, the new
    //     current item is the item immediately after the original current item.

    void sequence::advance() {
        assert(is_item()); // is_item returns tru, meaning the cursor doesn't point to something for now

        if(cursor == tail_ptr) // if the cursor and tail pointer are pointing to the same thing,
                               // then this is the end of the list and cursor now points to nothing,
        {
            precursor = cursor; // point to the next ones ( the last one)
            cursor = nullptr; // point nowhere now
        } else{                 // otherwise, the cursor points to the next link , and so does the precursor
            precursor = cursor; // point to the next one, what the cursor used to point at.
            cursor = cursor->link(); // point to the next one

        }
    }
//-------------------------------------------------------------------------------------------------------------------
    //   void insert(const value_type& entry)
    //     Postcondition: A new copy of entry has been inserted in the sequence before
    //     the current item. If there was no current item, then the new entry has
    //     been inserted at the front of the sequence. In either case, the newly
    //     inserted item is now the current item of the sequence.

    void sequence::insert(const data_structures_assignment3::sequence::value_type &entry) {

        if( !is_item()) // if there is no current item then do head_insert and set
                                // cursor = head link, precursor = null, takes care if many_nodes = 0
        {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            precursor = nullptr;

            if(many_nodes == 0)
            {
                tail_ptr = head_ptr; // if its empty now the tail pointer points to the head pointer, which points to
                // the only node present
            }
        }else { //  if cursor is there, then use list insert instead and do the same thing again and set cursor
            // to previous_ptr->link, so now cursor points to the newly inserted one, and precursor never changed.
            if(cursor == head_ptr) // if head and cursor point to the first thing,
            {// dont need to care if there is one node but that the cursor points to the first node
                list_head_insert(head_ptr, entry); // points to the only node
                cursor = head_ptr; //head pointer and cursor point to the same thing, the new node in front of headptr
                precursor = nullptr;

            } else{
                list_insert(precursor, entry); //more than one node, didn't mess with previous pointer
                cursor = precursor->link(); // set to the one ahead of it.
            }
        }
        ++many_nodes;
    }
//-------------------------------------------------------------------------------------------------------------------
    //   void attach(const value_type& entry)
    //     Postcondition: A new copy of entry has been inserted in the sequence after
    //     the current item. If there was no current item, then the new entry has
    //     been attached to the end of the sequence. In either case, the newly
    //     inserted item is now the current item of the sequence.
    // this is where the tail pointer comes into use.

    void sequence::attach(const data_structures_assignment3::sequence::value_type &entry) {

        if(!is_item()) // the cursor is outside so it doesn't exist, adding it to the end
        {
            if( many_nodes == 0) // if the node is empty
            {
                list_head_insert(head_ptr, entry); // create a new node that points to nothing but has the value
                cursor = head_ptr; // point to the new node
                tail_ptr = head_ptr; // point to the new node
                precursor = nullptr; // point to nothing since there is only one node
                ++many_nodes;
                return;
            }else // attaching to the end
            {
                // make the cursor point to the last item, or what the tail points to
                cursor = tail_ptr;
                // with the cursor being the precursor you can pass it into the list_insert
                list_insert(cursor, entry);
                // set precursor to point to the next node, set cursor to point to the next node, and set tail pointer
                // to point at the last node, which is cursor
                precursor = precursor->link();
                cursor = cursor->link();
                tail_ptr = cursor;
                ++many_nodes;
            }

        }else{ // the cursor is inside the list and is anywhere

            //similar to attaching to the end of the insert function
            // pass in cursor as precursor

            list_insert(cursor, entry);
            if (cursor == tail_ptr) // if it was at the end, now the tail pointer points to the end to
            {
                tail_ptr = cursor->link();
            }
            // have everything point to the next thing
            precursor = cursor;
            cursor = cursor->link();

            ++many_nodes;
        }
    }
//-------------------------------------------------------------------------------------------------------------------
    //   void remove_current( )
    //     Precondition: is_item returns true.
    //     Postcondition: The current item has been removed from the sequence, and the
    //     item after this (if there is one) is now the new current item.

    void sequence::remove_current() {
        assert(is_item());
        // 3 scenarios - beginning, middle, end ( need to take care that cursor goes to nothing and tail goes
        // for the last one )

        // beginning
//        if (head_ptr == cursor ) // works with only one node as well
//        {
//            // use list_head_remove, and set pre cursor to nothing, cursor to new head node, and if there is no
//            // other pointer, the tail points to nothing, along with everything else
//            list_head_remove(head_ptr);
//            cursor = head_ptr;
//            precursor = nullptr;
//            --many_nodes;
//            if (many_nodes==0)
//            {
//                tail_ptr = head_ptr; // which is null
//            }
//
//        }else { // end and middle
//            if (cursor == tail_ptr)// end
//            {// same as on top
//                list_remove(precursor); // this set cursor to null or next item
//                // precursor has no need to change so only change tail pointer to point at precursor if it was at the end
//                tail_ptr = precursor;
//                cursor = nullptr; // just in case
//                --many_nodes;
//            } else // middle
//            {   cursor = cursor->link();
//                list_remove(precursor);
//                --many_nodes;
//            }
//        }
//------------------------------------------------------------
//        if(precursor == nullptr)
//        {
//            list_head_remove(head_ptr);
//            --many_nodes;
//            if(head_ptr == nullptr)
//            {
//                cursor = nullptr;
//            } else{
//                cursor = head_ptr;
//            }
//        } else{
//            list_remove(precursor);
//            --many_nodes;
//        }
//--------------------------------------
        node* i=head_ptr;

        while(i!= cursor)
        {
            i = i->link();
        }
        precursor = i;
        cursor->set_link(cursor->link());
        --many_nodes;



    }

//--------------------------------------------------------------------------------------------------------------------
    //   size_t size( ) const
    //     Postcondition: The return value is the number of items on the sequence.
    size_t sequence::size() const {
        return many_nodes;

    }

//-------------------------------------------------------------------------------------------------------------------

//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item on the sequence.

sequence::value_type sequence::current() const {
    if (is_item()) return cursor->data(); // only return data if there is a current item
}


//-------------------------------------------------------------------------------------------------------------------
 // Copy Constructor

    sequence::sequence(const data_structures_assignment3::sequence &source) {
        list_piece(source.head_ptr, source.tail_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;

        cursor = head_ptr;
        precursor = nullptr;
    }

//-------------------------------------------------------------------------------------------------------------------
    // Destructor
    sequence::~sequence() = default;

//-------------------------------------------------------------------------------------------------------------------
    // = Operator overload

    void sequence::operator=(const data_structures_assignment3::sequence &source) {
        if (this == &source) // makes sure its not the same
        {
            return;
        }
        // empty the list
        many_nodes = 0;
        // have to

        list_piece(source.head_ptr, source.tail_ptr, head_ptr, tail_ptr); // copy over
        many_nodes = source.many_nodes;
        cursor = source.cursor;
        precursor = source.precursor;

    }

//-------------------------------------------------------------------------------------------------------------------























}
