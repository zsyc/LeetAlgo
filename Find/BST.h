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
	Node left,right;	//左链接指向一棵小于该结点的键组成的二叉查找树，右链接相反
	int N;	//以该结点为根的子树中的结点总数+1
}Node;
Node root;	//根节点
Value get(Key key);	//获得键对应的数值
void put (Key key, Value val);	//查找键，找到就更新，否则添加新元素
void del (Key key);
#endif
