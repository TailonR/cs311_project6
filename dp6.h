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
#include <tuple>
#include <functional>
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
void reverseList(unique_ptr<LLNode2<ValType>> & head)
{
    std::unique_ptr<LLNode2<ValType>> newhead= nullptr;
	std::unique_ptr<LLNode2<ValType>> next = nullptr;
    while(head)
    {   
        next = std::move(head->_next);
		head->_next = std::move(newhead);
		newhead = std::move(head);
		head = std::move(next);
    }
     head = std::move(newhead);
}




////////////////////////////////////////////////////////
// Exercise B Associative Dataset Class Template
// PRE:
// POST:
// ERROR:
// TYPE REQUIREMENTS:
// DISC:
// Invariants: 
////////////////////////////////////////////////////////

//LLMap is supposed to take an int and a string
template<typename KVType, typename KVType2>
class LLMap
{
    typedef KVType KEY_TYPE;
    typedef KVType2 DATA_TYPE;
    typedef std::tuple<KEY_TYPE, DATA_TYPE> KVTYPE3;
    typedef std::function<void (KEY_TYPE, DATA_TYPE)> FUNC;
    
////////////////////////////////////////////////////////
// Data Memeber
private:
    std::unique_ptr<LLNode2<KVType>> _head;
////////////////////////////////////////////////////////
// Deleted functions
public:
    //Copy Ctor
    LLMap(const LLMap & other) = delete;
    //Copy Assigment
    LLMap & operator =(const LLMap & other) = delete;
    //Move Ctor
    LLMap(LLMap && other) = delete;
    //Move Assignment
    LLMap & operator =(LLMap && other) = delete;


////////////////////////////////////////////////////////
// Member Functions
public:
    //Default Constuctor
    //
    LLMap();

    //Destructor
    ~LLMap();

    //Size of 
    size_t size() const;

    //Empty check
    bool empty() const noexcept;

    //Find key in const set
	const DATA_TYPE * find(const KEY_TYPE & key) const;

	//Find key in non const set
	DATA_TYPE * find(const KEY_TYPE & key);

    void insert(const KEY_TYPE & key, const DATA_TYPE & value);

    //Erase
    //Erases a key and vlaue pair by key
    void erase(const KEY_TYPE & key);

    void traverse(FUNC);

////////////////////////////////////////////////////////

};

template<typename KVType, typename KVType2>
LLMap<KVType, KVType2>::LLMap()
{
	_head = nullptr;
}

template<typename KVType, typename KVType2>
LLMap<KVType, KVType2>::~LLMap()
{
	//WRITE
}

template<typename KVType, typename KVType2>
size_t LLMap<KVType,KVType2>::size() const
{
     size_t counter = 1;
    // auto current = std::move(_head->_next);
    // while(current)
    // {
    //     current = std::move(current->_next);
    //     counter++;

    // }
    return counter;
}

template<typename KVType, typename KVType2>
bool LLMap<KVType,KVType2>::empty()const noexcept
{
    return true;
}

template<typename KVType, typename KVType2>
void LLMap<KVType,KVType2>::erase(const typename LLMap<KVType,KVType2>::KEY_TYPE & key)
{
    //WRITE
}
template<typename KVType, typename KVType2>
void LLMap<KVType,KVType2>::insert(const typename LLMap<KVType,KVType2>::KEY_TYPE & key, const typename LLMap<KVType,KVType2>::DATA_TYPE & value)
{
    //WRITE
}

template<typename KVType, typename KVType2>
const typename LLMap<KVType,KVType2>::DATA_TYPE * LLMap<KVType,KVType2>::find(const typename LLMap<KVType,KVType2>::KEY_TYPE & key) const
{
    // auto current = std::move(_head);
    DATA_TYPE * ptr = nullptr;
    // ptr = std::move(current);
    return  ptr;
}

template<typename KVType, typename KVType2>
typename LLMap<KVType,KVType2>::DATA_TYPE * LLMap<KVType,KVType2>::find(const typename LLMap<KVType,KVType2>::KEY_TYPE & key)
{
    DATA_TYPE * ptr = nullptr;
    return ptr;
}

template<typename KVType, typename KVType2>
void LLMap<KVType,KVType2>::traverse(const typename LLMap<KVType,KVType2>::FUNC f)
{
    //WRITE
}


#endif //FILE_DP6_H_INCLUDED
