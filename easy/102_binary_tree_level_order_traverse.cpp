// 用一个队列或栈保存即可
// 这个题目要求把每层分开保存, 诀窍就在于限制一个循环遍历的次数等于遍历开始时队列中元素的个数
// 另一个方法用递归, 本质上就是深度优先遍历/前序遍历, 这个是可以的, 因为只需要保证每一层的顺序是从左到右排列, 在遍历每一层的时候放到对应的数组中即可