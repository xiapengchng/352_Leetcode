Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.

解题思路：
交换相邻2各节点l1和l2，至少需要3个节点的信息，另外一个节点是l0。三者关系如下：
l0->l1->l2
令l1，l2指向对方节点，再将l2插入到l1节点后面，再将l1赋值给l0所指节点的next域，那么
l0->Newl1->Newl2
Newl1为原来的l2，实现交换相邻节点的目的。
再将l0值更新为Newl2，进行下一轮交换，不断迭代。