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
// reverseList(unique_ptr<LLNode2<ValType>> & head)
// reverses a linked list
// Function template named reverseList
// Pre: head needs to the point to a linked list
// Error: Strong Guarantee
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




//////////////////////////////////////////////////////////////////////////////
// Exercise B Associative Dataset Class Template
// class LLMap
// LLMap creates a linked list of LLNode2's of type KVType3
// Invariants: Head points to a LLNode2 of KVType3 which is be a tuple
////////////////////////////////////////////////////////////////////////////

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
    std::unique_ptr<LLNode2<KVTYPE3>> _head;
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
    //construct LLMap with head being a null pointer and size = 0
	//Pre: None
	//Error: None
    LLMap();

    //Default Destructor
	//Pre: None
	//Error: None
	~LLMap() = default;

    //size()
	//returns the number of nodes in the linked list
	//Pre: None
	//Error: None
	size_t size() const;

    //empty()
	//returns true if size() = 0, false if not
	//Error: No-except
	bool empty() const noexcept;

    //const find()
	//returns a const pointer to the value of a given key
	//Pre: key needs to have a valid type 
	//Error: No-except
	const DATA_TYPE * find(const KEY_TYPE & key) const;

	//non-const find()
	//returns a pointer to the value of a given key
	//Pre: key needs to have a valid type
	//Error: No-except
	DATA_TYPE * find(const KEY_TYPE & key);

	//insert()
	//returns a pointer to the value of a given key
	//Pre: key and value need to have a valid
	//Error: No-except
    void insert(const KEY_TYPE & key, const DATA_TYPE & value);

    //erase()
    //erases the key and vlaue pair indicated by key
	//Pre: key needs to be of a valid type
	//Error: Strong Guarantee
    void erase(const KEY_TYPE & key);

	//traverse(funct)
	//calls the given template function on every key-value pair of the linked list
	//Pre: the given function needs to be a valid template function
	//Error: None
    void traverse(FUNC);

////////////////////////////////////////////////////////

};

//See class definition above for docs
template<typename KVType, typename KVType2>
LLMap<KVType, KVType2>::LLMap()
{
	_head = nullptr;
}

//See class definition above for docs
template<typename KVType, typename KVType2>
size_t LLMap<KVType,KVType2>::size() const
{
    return ::size(_head);
}

//See class definition above for docs
template<typename KVType, typename KVType2>
bool LLMap<KVType,KVType2>::empty()const noexcept
{
	return(size() == 0);
}

//See class definition above for docs
template<typename KVType, typename KVType2>
void LLMap<KVType,KVType2>::erase(const typename LLMap<KVType,KVType2>::KEY_TYPE & key)
{
	auto current = _head.get();
	while (true)
	{
		if (key == std::get<0>(current->_data))
		{
			try
			{
				std::swap(current->_data, _head->_data);
			}
			catch (...)
			{
				throw;
			}

			::pop_front(_head);
			break;
		}
		current = current->_next.get();
	}
}

//See class definition above for docs
template<typename KVType, typename KVType2>
void LLMap<KVType,KVType2>::insert(const typename LLMap<KVType,KVType2>::KEY_TYPE & key, const typename LLMap<KVType,KVType2>::DATA_TYPE & value)
{
	auto current = _head.get();
	auto ptr = find(key);
	if (find(key))
	{
		std::get<1>(current->_data) = value;
	}
	else
	{
		::push_front(_head, std::make_tuple(key, value));
	}
}

//See class definition above for docs
template<typename KVType, typename KVType2>
const typename LLMap<KVType,KVType2>::DATA_TYPE * LLMap<KVType,KVType2>::find(const typename LLMap<KVType,KVType2>::KEY_TYPE & key) const
{
    auto current = _head.get();
	DATA_TYPE* ptr = nullptr;
	while (current)
	{
		if (key == std::get<0>(current->_data))
		{
			ptr = &(std::get<1>(current->_data));
		}
		current = current->_next.get();
	}
    return ptr;
}

//See class definition above for docs
template<typename KVType, typename KVType2>
typename LLMap<KVType,KVType2>::DATA_TYPE * LLMap<KVType,KVType2>::find(const typename LLMap<KVType,KVType2>::KEY_TYPE & key)
{
	auto current = _head.get();
	DATA_TYPE* ptr = nullptr;
	while (current)
	{
		if (key == std::get<0>(current->_data))
		{
			ptr = &(std::get<1>(current->_data));
		}
		current = current->_next.get();
	}
	return ptr;
}

//See class definition above for docs
template<typename KVType, typename KVType2>
void LLMap<KVType,KVType2>::traverse(const typename LLMap<KVType,KVType2>::FUNC f)
{
	auto current = _head.get();
	while (current)
	{
		KEY_TYPE& key = std::get<0>(current->_data);
		DATA_TYPE& value = std::get<1>(current->_data);
		f(key, value);
		current = current->_next.get();
	}
}

#endif //FILE_DP6_H_INCLUDED
