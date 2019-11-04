// dp6.h
// Matt Perry
// Tailon Russell
// Started : 11/1/2019
// Finished:
// For CS311 Project6
// dp6.h is a header file for Reversing a Linked List
// As well as Associative Dataset Class Template



#ifndef FILE_DP6_H_INCLUDED
#define FILE_DP6_H_INCLUDED

#include "llnode2.h"

////////////////////////////////////////////////////////
// Exercise A Reversing a Linked List
// Function template named reverseList
// PRE:
// POST:
// ERROR:
// TYPE REQUIREMENTS:
// DISC:
////////////////////////////////////////////////////////
template<typename ValType>
void reverseList(unique_ptr<LLNode2<ValType>> & head);




////////////////////////////////////////////////////////
// Exercise B Associative Dataset Class Template
// PRE:
// POST:
// ERROR:
// TYPE REQUIREMENTS:
// DISC:
// Invariants: 
////////////////////////////////////////////////////////

template<typename KVType>
class ListMap
{
public:
    using value_type = KVType;
    using size_type = std::size_t;
////////////////////////////////////////////////////////
// Data Memeber
private:
    std::unique_ptr<LLNode2<KVType>> _data;
////////////////////////////////////////////////////////
// Deleted functions
public:
    //Copy Ctor
    ListMap(const ListMap & other) = delete;
    //Copy Assigment
    ListMap & operator =(const ListMap & other) = delete;
    //Move Ctor
    ListMap(ListMap && other) = delete;
    //Move Assignment
    ListMap & operator =(ListMap && other) = delete;


////////////////////////////////////////////////////////
// Member Functions
public:
    //Default Constuctor
    //
    ListMap();

    //Destructor
    ~ListMap();

    //Size of 
    int size() noexcept
    {
        //TODO Write Size 
        return 0;

    }

    //Empty check
    bool empty()const noexcept
    {   
        //TODO Write Empty 
        return true;
    };

    //Find key in const set & non const
    const iterate find(value_type key);
    * iterate find(value_type key);
    void insert(value_type key,value_type value);

    //Erase
    //Erases a key and vlaue pair by key
    void erase(value_type key);

    void traverse();

////////////////////////////////////////////////////////

};

template<typename T>
void ListMap<T>::erase(value_type key)
{
    //WRITE
}
template<typename T>
void ListMap<T>::insert(value_type key, value_type value)
{
    //WRITE
}

template<typename T>
void ListMap<T>::traverse()
{
    
}


#endif //#ifndef FILE_DP6_H_INCLUDED
