// FILE: bstbag.template
// -------------------------------------------------------------------------
// This is a partial implementation of the bag template class from Section
// 10.5 of "Data Structures and Other Objects Using C++". The parts marked
// with ***STUDENT WORK*** are left as a project for data structures
// students.
// -------------------------------------------------------------------------
// TEMPLATE CLASS IMPLEMENTED: bag<Item> (see bag6.h for documentation)
// INVARIANT of the ADT:
//   root_ptr is the root pointer of a binary search tree that contains the
//   bag's items.

#include <cassert>
#include <cstdlib>
#include "bstbag.h"
#include <vector>
#include <cdoex.h>

namespace data_structures_assignment6
{
    template<class Item>
    void bst_remove_max(binary_tree_node<Item>*& root_ptr, Item& removed)
    // Precondition: root_ptr is a root pointer of a non-empty binary
    // search tree.
    // Postcondition: The largest item in the binary search tree has been
    // removed, and root_ptr now points to the root of the new (smaller)
    // binary search tree. The reference parameter, removed, has been set
    // to a copy of the removed item.
    {
        /***STUDENT WORK***
         ** This recursive function should be implemented by the student.
         ** The base case occurs when there is no right child of the
         ** root_ptr node. In this case, the root_ptr should be moved down
         ** to its left child and then the original root node must be
         ** deleted. There is also a recursive case, when the root does
         ** have a right child. In this case, a recursive call can be made
         ** using root_ptr->right() as the first parameter. Please notice
         ** the return value from root_ptr->right().
         ** The & symbol in the return type means that the return value is
         ** a reference to the actual right pointer in the node. Any changes
         ** made to this pointer in the recursive call will directly change
         ** the right pointer in the root_ptr's node.
         */
        // what if there are two identical maxs?
//        if(root_ptr->right() == nullptr && root_ptr->left() == nullptr) // no children - just deletion
//        {
//            if (removed < root_ptr->data()) // if the current removed is smaller than the node data you are on,
//                                            // then make it the new node. Otherwise it stays where it is
//            {
//                removed = root_ptr->data();
//            }
//            delete root_ptr;
//            return;  // reached the last node that you need to delete, so return after this.
//        }
//
//        if(root_ptr->right() != nullptr) // yes right child - keep going right
//        {
//            bst_remove_max(root_ptr->right(), removed);
//        }
//
//        if(root_ptr->right() == nullptr && root_ptr->left() != nullptr) // only a left child
//        {
//            /* if there is no more right node, look at the left, take its data as the parent data and delete the
//             * left node, given that that left node doesn't have any other children*/
//
//            removed = root_ptr->data(); // make remove the largest data
//            root_ptr->set_data(root_ptr->left()); // set parent node to the left node
//            bst_remove_max(root_ptr->left(), removed); // remove the left node
//
//        }
            //base cse - when there is nothing on left side or right side of the node - just delete
//            if(root_ptr->left() && root_ptr->left() == nullptr)
//            {
//                if (removed < root_ptr->data()) // if the current removed is smaller than the node data you are on,
//                                            // then make it the new node. Otherwise it stays where it is
//                {
//                    removed = root_ptr->data();
//                }
//                delete root_ptr;
//                return;  // reached the last node that you need to delete, so return after this.
//
//
//            }
//            if(root_ptr->right() != nullptr) // yes right child - keep going right
//            {
//                bst_remove_max(root_ptr->right(), removed);
//            }
//            if(root_ptr->right() == nullptr && root_ptr->left() != nullptr) // only a left child
//            {
//                /* if there is no more right node, look at the left, take its data as the parent data and delete the
//                 * left node, given that that left node doesn't have any other children*/
//
//                removed = root_ptr->data(); // make remove the largest data
//                binary_tree_node<Item>* temp = root_ptr->left();
//                root_ptr->set_data(temp->data()); // set parent node data to the left node
//                bst_remove_max(root_ptr->left(), removed); // remove the left node
//
//            }
//        The base case occurs when there is no right child of the
//        ** root_ptr node. In this case, the root_ptr should be moved down
//        ** to its left child and then the original root node must be
//        ** deleted. There is also a recursive case, when the root does
//        ** have a right child. In this case, a recursive call can be made
//        ** using root_ptr->right() as the first parameter.
        binary_tree_node<Item>* oldptr;
        binary_tree_node<Item>* cursor = root_ptr;

        if(cursor->right() == nullptr) // when nothing on the right move to the left
        {
            removed = cursor->data(); // store the data first
            oldptr = cursor;          // store oldptr so you don't loose place
            root_ptr = root_ptr->left(); // move to the left
            delete oldptr; // delete the original
        }
        if(cursor->right() != nullptr) // keep moving right if there is a right child
        {
            bst_remove_max(cursor->right(), removed);
        }


    }

    template<class Item>
    bool bst_remove(binary_tree_node<Item>*& root_ptr, const Item& target)
    // Precondition: root_ptr is a root pointer of a binary search tree
    // or may be nullptr for an empty tree).
    // Postcondition: If target was in the tree, then one copy of target
    // has been removed, and root_ptr now points to the root of the new
    // (smaller) binary search tree. In this case the function returns true.
    // If target was not in the tree, then the tree is unchanged (and the
    // function returns false).
    {
        binary_tree_node<Item>* oldroot_ptr;

        if (root_ptr == nullptr) // Empty tree
        {
            return false;
        }

        if (target < root_ptr->data())
        {   // Continue looking in the left subtree
            // Note: Any change made to root_ptr->left by this recursive
            // call will change the actual left pointer (because the return
            // value from the left() member function is a reference to the
            // actual left pointer.
            return bst_remove(root_ptr->left(), target);
        }

        if (target > root_ptr->data())
        {   // Continue looking in the right subtree
            // Note: Any change made to root_ptr->right by this recursive
            // call will change the actual right pointer (because the return
            // value from the right() member function is a reference to the
            // actual right pointer.
            return bst_remove(root_ptr->right(), target);
        }

        if (root_ptr->left() == nullptr)
        {   // Target was found and there is no left subtree, so we can
            // remove this node, making the right child be the new root.
            oldroot_ptr = root_ptr;
            root_ptr = root_ptr->right();
            delete oldroot_ptr;
            return true;
        }

        // If code reaches this point, then we must remove the target from
        // the current node. We'll actually replace this target with the
        // maximum item in our left subtree.
        // Note: Any change made to root_ptr->left by bst_remove_max
        // will change the actual left pointer (because the return
        // value from the left() member function is a reference to the
        // actual left pointer.
        bst_remove_max(root_ptr->left(), root_ptr->data());
        return true;
    }

    template<class Item>
    typename bag<Item>::size_type bst_remove_all
            (binary_tree_node<Item>*& root_ptr, const Item& target)
    // Precondition: root_ptr is a root pointer of a binary search tree
    // or may be nullptr for an empty tree).
    // Postcondition: All copies of target have been removed from the tree
    // has been removed, and root_ptr now points to the root of the new
    // (smaller) binary search tree. The return value tells how many copies
    // of the target were removed.
    {
        /** STUDENT WORK
         ** Note: This implementation is similar to bst_remove, except that
         ** all occurrences of the target must be removed, and the return
         ** value is the number of copies that were removed.
         */
        // use a recursive function to find if there is an instance of the target left
        binary_tree_node<Item>* oldroot_ptr;

        if (root_ptr == nullptr)
        {   // Empty tree
            /* STUDENT WORK */
            return 0;
        }

        if (target < root_ptr->data())
        {   // Continue looking in the left subtree
            /* STUDENT WORK */
            bst_remove_all(root_ptr->left(), target);
        }

        if (target > root_ptr->data())
        {   // Continue looking in the right subtree
            /* STUDENT WORK */
            bst_remove_all(root_ptr->right(), target);
        }

        if (root_ptr->left() == nullptr)
        {   // Target was found and there is no left subtree, so we can
            // remove this node, making the right child be the new root.
            oldroot_ptr = root_ptr;
            root_ptr = root_ptr->right();
            delete oldroot_ptr;
            return 1;
        }

        // If code reaches this point, then we must remove the target from
        // the current node. We'll actually replace this target with the
        // maximum item in our left subtree. We then continue
        // searching for more copies of the target to remove.
        // This continued search must start at the current root (since
        // the maximum element that we moved up from our left subtree
        // might also be a copy of the target).
        /* STUDENT WORK */
        bst_remove_max(root_ptr->left(),root_ptr->data());
        return bst_remove_all(root_ptr, target);

    }

    template<class Item>
    bag<Item>::bag(const bag <Item>& source)
    // Library facilities used: bintree.h
    {
        root_ptr = tree_copy(source.root_ptr);
    }

    template<class Item>
    bag<Item>::~bag()
    // Header file used: bintree.h
    {
        tree_clear(root_ptr);
    }

    template<class Item>
    typename bag<Item>::size_type bag<Item>::size() const
    // Header file used: bintree.h
    {
        return tree_size(root_ptr);
    }

    template<class Item>
    void bag<Item>::insert(const Item& entry)
    // Header file used: bintree.h
    {
        binary_tree_node<Item>* cursor;

        if (root_ptr == nullptr)
        {   // Add the first node of the binary search tree:
            root_ptr = new binary_tree_node<Item>(entry);
            cursor = root_ptr;
            return;
        }

        else
            {   // Move down the tree and add a new leaf:
            cursor = root_ptr;
            bool done = false;
//            temp = root_ptr;
//            /* STUDENT WORK */
//            //---------------------------------------------------------------------------------------------------------
//
//            // check the if root has any children, then the rest for the bottom
//
//            while ( cursor != nullptr)
//            {
//                // First time is parent check, then it checks the node sif there are any
//
//                // move through the binary tree according to the rules, if bigger then right otherwise left
//                if(entry > cursor->data()) // bigger
//                {
//                    temp = cursor;
//                    cursor = cursor->right();
//                }else // smaller or equal
//                {
//                    temp = cursor;
//                    cursor = cursor->left();
//                }
//
//            }
//            // when you have reach the spot where you want to insert this into, you create a new node to insert it at
//            // temp makes sure keeps track of the parent node, so when cursor gets to null, temp is gonna be used to
//            // insert a new node
//            binary_tree_node<Item>* n_node = new binary_tree_node<Item>(entry); //create a new node, and add the data
//            // since cursor points to nothing, and temp points to the parent node right before cursor, we don't
//            // actually know if the new node should be on the left, or the right side of the parent node.
//            if(entry > temp->data()) {
//                temp->right() = n_node;
//            }else
//            {
//                temp->left() = n_node;
//            }

            while(!done)
            {
                if(entry>cursor->data()) // (const) entry is bigger - move to the right side
                {
                    if(cursor->right() == nullptr) // nothing on the right side - add new node there with the entry
                    {
                        cursor->right() = new binary_tree_node<Item>(entry); // (not const)
                        done = true; // loop breaks bc you inserted the node
                    }else{
                        cursor = cursor->right(); // (const) keep moving ahead to the right to check again
                    }
                }

                if(entry<cursor->data()) // (const) entry is lower - move to  the left side
                {
                    if(cursor->left() == nullptr) // nothing on the left side - add new node there with the entry
                    {
                        cursor->left() = new binary_tree_node<Item>(entry); // (not const)
                        done = true; // loop breaks bc you inserted the node
                    }else{
                        cursor = cursor->left(); // (const) keep moving ahead to the left to check again
                    }

                }

                if(entry == cursor->data()) // (const) entry is equal - move to the left and make a new node
                // if there is nothing on its left node put it there, otherwise go the the left node's right pointer,
                    // if there is something down there, just loop back to the stuff on top to find the next right place
                {
                    if(cursor->left() == nullptr) // (const) if there is nothing on left -  insert it there and exit
                    {
                        cursor->left() = new binary_tree_node<Item>(entry);
                        done = true;
                    }else
                    {
                        cursor = cursor->left(); // (const) if there is a left node - set cursor to it and repeat process
                    }
                }



            }
            return;

        }
    }

    template <class Item>
    typename bag<Item>::size_type bag<Item>::rcount(data_structures_assignment6::binary_tree_node<Item> *& root, const Item &rTarget) const
    {
        // base case, you hit a null pointer so just return
         if(root == nullptr)
         {
             return 0;
         }
        // keep it const - nothing here is changed
        if( root->data() == rTarget) //  // if you do have a match - +1 and look on oth sides
        {
            return 1 + rcount(root->left(), rTarget) + rcount(root->right(), rTarget);
        }
         // the rest of the nodes under the one where it found a match
        if( rTarget < root->data()) // if target is less then move to the left
        {
            return rcount(root->left(), rTarget);
        } else { // otherwise move to the right
            return rcount(root->right(), rTarget); // return answer instead, take it in as a parameter
        }
 // this makes sure that if there are more than one occurrences then it will count the first one, move to the left
 // compare and move to the right where the other occurrence could be.
}



    template<class Item>
    typename bag<Item>::size_type bag<Item>::count(const Item& target) const
    {
        size_type answer = 0;
        binary_tree_node<Item>* cursor;

        cursor = root_ptr;
        /* STUDENT WORK */

        return rcount(cursor, target);
    }

    template<class Item>
    typename bag<Item>::size_type bag<Item>::erase(const Item& target)
    {
        return bst_remove_all(root_ptr, target);
    }

    template<class Item>
    bool bag<Item>::erase_one(const Item& target)
    {
        return bst_remove(root_ptr, target);
    }

    template<class Item>
    void bag<Item>::operator=(const bag <Item>& source)
    // Header file used: bintree.h
    {
        if (root_ptr == source.root_ptr)
            return;
        tree_clear(root_ptr);
        root_ptr = tree_copy(source.root_ptr);
    }

    template<class Item>
    void bag<Item>::operator+=(const bag <Item>& addend)
    {
        if (root_ptr == addend.root_ptr)
        {
            bag<Item> copy = addend;
            insert_all(copy.root_ptr);
        }
        else
            insert_all(addend.root_ptr);
    }

    template<class Item>
    bag <Item> operator+(const bag <Item>& b1, const bag <Item>& b2)
    {
        bag<Item> answer = b1;
        answer += b2;
        return answer;
    }
//    template <class Item>
//    void bag<Item>::operator-=(const bag <Item>& addend)
//    {
//        // x -=x - nothing left
//        if(root_ptr == addend.root_ptr)
//        {
//            tree_clear(root_ptr); // just clear the tree
//        }
//
//        binary_tree_node<Item> newone = tree_copy(root_ptr);
//        tree_clear(root_ptr);
//        root_ptr = newone - addend;
//
//
//    }
//
//    template <class Item>
//    bag<Item> operator-( bag<Item> & x, bag<Item>& y)
//    {
//        bag<Item> answer;
//        // x-x
//        if (x.root_ptr == y.root_ptr)
//        {
//            answer.root_ptr = nullptr; // the new tree stays empty
//        }
//        else
//        {
//            std::vector<Item> my_vector; // keep track of all elements in y
//            r_vector_add(y.root_ptr, my_vector); // put all elements of y in element
//
//            answer = tree_copy(x.root_ptr); // copy x's elements to answer
//
//            while(my_vector.size()!= 0) // go through every element while poping the last one to your'e always check the last element
//            {
//                answer.erase_one(my_vector(my_vector.size()-1)); // removes the element if its there
//                my_vector.pop_back();
//
//            }
//        }
//        return answer;
//
//    }
    template<class Item>
    void r_vector_add(binary_tree_node<Item>* root_ptr,  Item& mvector) // using copy
    {
        if(root_ptr == nullptr)
        {
            return;
        }
        else
        {
            mvector.push_back(root_ptr->data());
            r_vector_add(root_ptr->left(), mvector);
            r_vector_add(root_ptr->right(), mvector);
            return;
        }
    }




    template<class Item>
    void bag<Item>::insert_all(binary_tree_node<Item>* addroot_ptr)
    // Precondition: addroot_ptr is the root pointer of a binary search tree that
    // is separate for the binary search tree of the bag that activated this
    // method.
    // Postcondition: All the items from the addroot_ptr's binary search tree
    // have been added to the binary search tree of the bag that activated this
    // method.
    {
        if (addroot_ptr != nullptr)
        {
            insert(addroot_ptr->data());
            insert_all(addroot_ptr->left());
            insert_all(addroot_ptr->right());
        }
    }
}
