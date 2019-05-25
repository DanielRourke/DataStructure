#pragma once
#include "AVL_ADT.h"


template <class TYPE, class KTYPE>
class AssAvlTree :
	public AvlTree<TYPE, KTYPE>
{
private:

public:
	AssAvlTree();
	virtual ~AssAvlTree();
	bool  AVL_Update(TYPE dataIn);
};


template <class TYPE, class KTYPE>
AssAvlTree<TYPE, KTYPE>::AssAvlTree()
{
}

template <class TYPE, class KTYPE>
AssAvlTree<TYPE, KTYPE>::~AssAvlTree()
{
}

/*	==================== AVL_Update ===================

	if node data doesnt exiist it creates new node

	Retrieve node searches the tree for the node containing
	the requested key and returns pointer to its data.
	   Pre     dataIn contains data to be inserted
	   Post    tree searched and data has been updated/inserted or memory overflow
	   Return  if updated/inserted (true )  or overflow (false)
*/

//
//template <class TYPE, class KTYPE>
//bool   AssAvlTree<TYPE, KTYPE>
//::AVL_Update(TYPE dataIn)
//{
//	//	Local Definitions
//	NODE<TYPE> *node;
//	KTYPE key = dataIn->key;
//	//if tree is not empty try find data
//	//if found update frequency amount
//	if (tree && node = _retrieve(key, tree))
//	{
//		node->data += 1 ;
//		return true;
//	} // else insert new data node
//	else
//	{
//		return AVL_Insert(dataIn);
//	}
//}	
//

