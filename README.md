# leetcode
开始刷题啦！！！

680		可以优化成子函数模式！

88		两个有序数组合并为一个数组时，注意从尾部开始比较！

141		成环的问题，考虑使用快慢指针法，一个指针走两步，另一个指针走一步，有环两个指针必定会相遇。

215		快排要自己能写出来

347		o（nlog2n）的时间复杂度大于o（n），n越大差距越大，排序算法时间复杂度最小就是o（nlog2n）。大顶堆，小顶堆，优先级队列使用场景，频率最高的前k个元素，仿函数的构建

451 	频率,排序相关的问题都可以考虑 map统计频率，设置顶堆方式，优先级队列，来做

75		关键是如何只做一次遍历，且原地排序 0，1，2. 核心在于用2个or3个指针，分别指向0，1，2三个数字的起始或者结束位置。

435		给子函数传递值的时候，记得把vector变量加一个引用传递，这样就不用额外复制一次这个变量到内存里，执行速度会快很多

665		当vector中两个相邻的元素相互比较，然后需要修改其中某一个的时候，一定要想清除，修改前面的，还是后面的；可以两种都试试，如果有一个成果结果就算成果。或者看看是否根据联系再前一个元素和再后一个元素，就可以判断到底要改哪个元素了。

665		(if (i - 2 >= 0 && nums[i - 2] > nums[i]))	可以这样判断边界情况！！！防止 i-2 或者 i+2 超出数组索引范围

69		需要解决运算溢出： int a,b   a*b > x，这里a*b的运算可能会溢出2的31次方，因此可以改为，a>x / b,这样运算的结果就不会溢出了，另外 x/b会被向下取整，因此可以再改为 x/(b*1.0)，转为浮点运算，保留小数

744		二分法使用while循环做，设立left和right，当right和left距离不足1时，就退出循环，手动判断left和right哪个是需要的数据。 *用二分法还有一个核心是，如何判断那个区间是下一批迭代的区间*

241		递归、迭代、回溯算法核心是：如何将原始的大的问题，拆解为多个类似的小问题，一步一步拆下来，可以55拆解，也可以19拆解，1就是递归问题的退出边界。      ①定义好递归函数的参数；②定义好递归函数的退出条件；③子进程的返回值如何在当前进程中使用；

95		回溯的时候，定义的子函数参数大多数都是[left, right]，然后一直分解left right，直到两个相等或者left+1=right；所以思考问题可以朝着这个方向
```bash
		回溯算法的模板框架
		void backtracking(参数) {
			if (终止条件) {
				存放结果;
				return;
			}

			for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
				处理节点;
				backtracking(路径，选择列表); // 递归
				回溯，撤销处理结果
			}
		}
```bash
1091	每一层遍历的节点都与根节点距离相同。设 di 表示第 i 个节点与根节点的距离，推导出一个结论：对于先遍历的节点 i 与后遍历的节点 j，有 di <= dj。利用这个结论，可以求解最短路径等 最优解 问题：第一次遍历到目的节点，其所经过的路径为最短路径。应该注意的是，使用 BFS 只能求解无权图的最短路径，无权图是指从一个节点到另一个节点的代价都记为 1。

		在程序实现 BFS 时需要考虑以下问题：

		队列：用来存储每一轮遍历得到的节点（也就是下一轮需要遍历的节点）；用vector的话可以定义两个，一个now，一个next。用queue的话可以定义一个，走过的就pop出去，新的就push进来
		标记：对于遍历过的节点，应该将它标记，防止重复遍历。--->标记最好在原始数据上修改确认标记，不要重新开辟一个vector存储已经遍历过的元素，否则每个新元素都得find一下，增加了时间复杂度
		
		DFS是属于每次深入去找，发现不行了再回头继续找的那种方法，适合找东西个数的问题（海岛数量的那题）
		BFS是属于每次都进行一步，走完一步之后才走下一步，而下一步中涵盖了所有的可能的这种方法，适合找到最短路径/最少次数的问题（如腐烂的橘子）
		

279		求最小数量，最短路径，类型的题目都可以考虑BFS，其中起始状态和终点状态都看为节点，然后考虑怎么构建中间的节点。（中间节点和起始、中止节点 类型（数据类型、作用、思想类型） 都一样）

695		dfs,在程序实现 DFS 时需要考虑以下问题：在得到一个新节点时立即对新节点进行遍历(递归调用)，如此反复以这种方式遍历新节点，直到没有新节点了，此时返回。使用 DFS 对一个图进行遍历时，能够遍历到的节点都是从初始节点可达的，DFS 常用来求解这种 可达性 问题。
		栈：用栈来保存当前节点信息，当遍历新节点返回时能够继续遍历当前节点。可以使用递归栈。
		标记：和 BFS 一样同样需要对已经遍历过的节点进行标记。
		dfs模板
		for point : points{
			不对point做任何判断，直接dfs，判断由dfs进入后立刻进行
			dfs(point);
		}
		function dfs(point){
			判断是否越界，是否重复；
			判断是否需要返回；
			for(num : nums)
				处理num，判断num是否满足要求
				返回值 = 不返回的话继续dfs；
			return 返回值；
		}
		
130		首先对边界上每一个'O'做深度优先搜索，将与其相连的所有'O'改为'-'。然后遍历矩阵，将矩阵中所有'O'改为'X',将矩阵中所有'-'变为'O'


417		声明指定大小且初始值全为0的vector ：vector<vector<int>> po_arrive(m, vector<int>(n, 0));		容器的pushback，可以直接pushback({1, 1});	被标记的点最好是已经拿到该点的执行结果，对于很多（顺序，比大小）问题经常要考虑逆向解法，从外到内。
		比如迷宫问题，是要从某个点走到终点，则可以考虑从终点出发，bfs走，看能不能走到起点。
		
93		回溯问题，主函数里面尽量设计简单的写法，将迭代区间引入 回溯 函数中处理，保证回溯函数中迭代时，每次的输入输出参数都一样。	如果不好做到的话，就把回溯函数中的大部分代码（前处理、调用回溯、后处理）直接写到主函数吧

79		对于ops上下左右移动的题目，以后不要用for(op : ops)这样做了，直接 dfs(1)||dfs(2)||...这样做，不会超时。

47		全排列第二题，需要对全排列的数据进行去重，去重操作最简单的就是利用set，但是太low了。	考虑新算法（去重本质上就是continue掉两个相邻数中的某一个迭代）：
		1. 先排序，保证所有重复数字相邻；
		2. 迭代时（被标记的索引直接continue），判断该数的下一个数和该数是不是一样，如果是的话，则说明下一个数字不用迭代了直接跳过，标记需要跳过的索引
		3. 标记当前正在遍历的数字，并对标记后的数组进行dfs迭代
		if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1])	// 在dfs中 实例化一个visited的 vector，无需传递给下一次dfs，在dfs回溯时加如下去重代码，前提nums是有序的才行。
		{
			continue;
		}