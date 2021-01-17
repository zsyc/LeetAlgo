/* BST.h Binarysearchtree */
#ifndef BST_H
#define BST_H

/* 键与数值类型未知，因而使用结构体 */
typedef struct{

}Key;

typedef struct{

}Value;

typedef struct {
	Key key;
	Value value;
	Node left,right;
	int N;	//以该结点为根的子树中的结点总数
}Node;

Value get(Key key);
void put (Key key, Value val);

#endif
