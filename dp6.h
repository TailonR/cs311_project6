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

//Listmap is supposed to take an int and a string
template<typename KVType, typename KVType2>
class ListMap
{
public:
    using value_type = KVType;
	using value_type2 = KVType2;
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
    const int size() const noexcept
    {
        //TODO Write Size 
        return 0;

    }

    //Empty check
    bool empty() const noexcept
    {   
        //TODO Write Empty 
        return true;
    };

    //Find key in const set
	const value_type2 * find(value_type key) const
	{
		//WRITE
		return this; //&std::basic_string<char, std::char_traits<char>, std::allocator<char>>;
	}

	//Find key in non const set
	value_type2 * find(value_type key)
	{
		//WRITE
		return this; //&std::basic_string<char, std::char_traits<char>, std::allocator<char>>;
	}

    void insert(value_type key, value_type2 value);

    //Erase
    //Erases a key and vlaue pair by key
    void erase(value_type key);

	template<typename T3>
    void traverse(T3);

////////////////////////////////////////////////////////

};

template<typename T, typename T2>
ListMap<T, T2>::ListMap()
{
	//WRITE
}

template<typename T, typename T2>
ListMap<T, T2>::~ListMap()
{
	//WRITE
}

template<typename T, typename T2>
void ListMap<T, T2>::erase(value_type key)
{
    //WRITE
}
template<typename T, typename T2>
void ListMap<T, T2>::insert(value_type key, value_type2 value)
{
    //WRITE
}

template<typename T, typename T2>
template <typename T3>
void ListMap<T, T2>::traverse(T3)
{
    //WRITE
}


#endif //FILE_DP6_H_INCLUDED
