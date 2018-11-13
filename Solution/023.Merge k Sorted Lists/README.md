Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

两种思路：
1.两两merge
代码见solution2.cpp，两两merge的速度挺快的，复杂度为O(n)，运行时间16ms

2.取每个子链的首元素，建立小顶堆，每次拿堆顶的元素，此元素属于第g条子链，然后再第g条子链的下一个元素放到堆顶，再更新堆。若第g条子链的下一个元素为空，则拿堆末尾元素放置堆顶，堆长度减1，再更新堆。
代码见solution1.cpp，复杂度为k+nlog(k)，运行时间63ms。这么做的原因是觉得堆好玩[笑哭]。


重要事情说三遍，分配内存不要用malloc，用new！分配内存不要用malloc，用new！分配内存不要用malloc，用new！
否则会提示内存不对齐[黑人问号]