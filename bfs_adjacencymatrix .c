#include<stdio.h>
#include <time.h>
int no_vertices;
void printGraph(int adj[][no_vertices])
{
	for(int i=0;i<no_vertices;i++)
	{
		for(int j =0;j<no_vertices;j++)
		{
			printf(" %d  ",adj[i][j]);
		}
		printf("\n");
	}

}

void bfs(int adj[][no_vertices], int start)
{
	int visited[no_vertices],queue[no_vertices],front=-1,rear=-1;

	for(int i=0;i<no_vertices;i++)
		visited[i] =0;

	front++;
	queue[++rear] = start;
	visited[start] = 1;

	while(front<=rear)
	{
		start = queue[front++];
		printf("%d\t",start);

		for(int i=0;i<no_vertices;i++)
		{
			if(adj[start][i]==1 && visited[i] != 1)
			{
				queue[++rear] = i;
				visited[i] =1;
			}
		}


	}

}
int main()
{	
	int s,d,ch,start;
	clock_t start_t, end_t;
	printf("\nEnter the number of vertices : ");
	scanf("%d",&no_vertices);
	int adj[no_vertices][no_vertices],visited[no_vertices];
	

	for(int i =0;i<no_vertices;i++)
		for(int j=0;j<no_vertices;j++)
			adj[i][j] =0;

	while(s!=-1 && d!=-1)
	{
	printf("Enter an edge from node (0 to %d) to node(0 to %d) : ",no_vertices,no_vertices);
	scanf("%d%d",&s,&d);
	adj[s][d] = 1;
	adj[d][s] = 1;
	}

	do
	{
		printf("\nEnter 1 for BFS\nEnter 2 for printing adjacency matrix\nEnter 3 to Exit : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			    start_t = clock();
				printf("Enter the Vertex fron which do you wanted to start : ");
				scanf("%d",&start);
				bfs(adj,start);
				end_t = clock();
				printf("\nstart_t değeri: %ld\n", start_t);
                printf("end_t değeri: %ld\n", end_t);
                printf("CPU süreci (saniye): %f\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
				break;

			break;
			case 2:printGraph(adj);break;
			case 3: break;
		}

	}while(ch != 3);

	return 0;
}