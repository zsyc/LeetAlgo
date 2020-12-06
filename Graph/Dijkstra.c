/* Dijkstra 迪杰斯特拉算法,最短路径算法
 * 在“图”中，任意两点路径都有数字标注，表明路径长度;
 * 目的是求从某一固定点（顶点）开始，到达任意点的最短路径。
 * 方法是
 * 1.起点标为0，其他点设置为无限大
 * 2.依次遍历与起点相连的点，然后标注距离数字
 * 3.接下来遍历剩下的点，标注距离数字，如果碰到已经标注过的点，那么比较并且保留小数值
 * 4.直到遍历全部点
 * 5.最后，除了起点是0，剩下所有点标注的数字都是从起点出发的最短路径数值 */

// 输入数据为二位数组，[[3,4,4],[1,2,4],[1,3,2],[2,3,3],[6,3,2],[3,5,5],[5,4,1],[3,2,1],[2,4,2],[2,5,3],[4,1,1]]
// 第一个数表示起点，第二个数表示终点，第三个数路径长度，这里为有向图！
// 比如上方案例为6个顶点，11条边

/* 本题使用队列来作为循环标记，因为有向图中可能存在环状结构，遍历时难以使用顺序方式
 * 队列用数组来实现 */

#define N 256
#include <stdio.h>

int Q[N], head=0, tail=0;	//queue

void enqueue(char c){	//队尾插入元素
	Q[tail++] = c;
}

char dequeue(void){		//队首删去元素,并返回删除的元素
	return 	Q[head++];	
}

int is_empty(void){
	return head==tail;
}

int have(char c){
	for (int i=head; i<tail;++i)
		if (Q[i]==c) return 1;
	return 0;
}

void Dijkstra(int graph[][3], int V, int Edge, int start, int dist[]){
	enqueue(1);
	int begin, end, weight, cost;
	while(!is_empty()){
		begin = dequeue();
		for (int grp=0; grp<Edge;++grp)
			if (graph[grp][0]==begin){
				end = graph[grp][1];
				if (end==start) continue;	//如果有指向起点的路径，不能更新起点消耗，起点始终为0！
				weight = graph[grp][2];
				cost = dist[begin]+weight;
				if (dist[end]==0 || cost<dist[end]){	//就近原则，先判断0,若未0则未开始，停止判断;否则判断路径长度
					dist[end]=cost;
					if (!have(end)) enqueue(end);	//不需要连续遍历两次相同位置	
			//	printf("%d %d %d %d %d %d\n",dist[1],dist[2],dist[3],dist[4],dist[5],dist[6]);
				}
			}
	}
	for (int i=1;i<=V;++i)	//索引0位置忽略，这样代码更为清晰
		if (dist[i]==0 && i!=start)	//起点始终为0
			dist[i]=-1;		//-1代替无穷大，表明起点无法到达此点
}

int main(void){
	int G[11][3] = {{3,4,4},{1,2,4},{1,3,2},{2,3,3},{6,3,2},{3,5,5},{5,4,1},{3,2,1},{2,4,2},{2,5,3},{4,1,1}};
	int D[7]={0};
	Dijkstra(G,6,11,1,D);
	for (int i=1;i<7;++i)
		printf("%d ",D[i]);
	putchar('\n');
	return 0;
}
