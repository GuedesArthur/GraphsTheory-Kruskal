// Arthur N. Guedes - 11085314
#include <stdio.h> // printf, scanf
#include <stdlib.h> // malloc, qsort

typedef struct Edge
{
    short from, to, cost;
} Edge;

int edge_comparer(const void* edge1, const void* edge2)
{
    return ((Edge*)edge1)->cost - ((Edge*)edge2)->cost;
}

typedef struct Graph
{
    short nVertices, nEdges;
    int nonMSTNegativeCost;
    short* leader;
    short* size;
    Edge* edges;
    Edge* minTree;
} Graph;

void create_graph(Graph* graph)
{
    scanf("%hd %hd", &graph->nVertices, &graph->nEdges);
    graph->leader = (short*)malloc(graph->nVertices * sizeof(short));
    graph->size = (short*)malloc(graph->nVertices * sizeof(short));
    graph->nonMSTNegativeCost = 0;

    for (short i = 0; i < graph->nVertices; i++)
    {
        graph->leader[i] = i;
        graph->size[i] = 1;
    }

    graph->edges = (Edge*)malloc(graph->nEdges * sizeof(Edge));

    for (short i = 0, aux = 0; i < graph->nEdges; i++)
    {
        Edge* cur = graph->edges + i;
        scanf("%hd %hd %hd", &cur->from, &cur->to, &cur->cost);
    }

    qsort(graph->edges, graph->nEdges, sizeof(Edge), edge_comparer);
}

short find_set(short* leader, short vert)
{
    if (leader[vert] != vert)
        leader[vert] = find_set(leader, leader[vert]);

    return leader[vert];
}

void graph_union(short* leader, short* size, short v1, short v2)
{
    short l1 = find_set(leader, v1), l2 = find_set(leader, v2);

    if (size[l1] <= size[l2])
    {
        leader[l1] = l2;
        size[l2] += size[l1];
    }
    else
    {
        leader[l2] = l1;
        size[l1] += size[l2];
    }
}

int kruskal(Graph* graph, Edge* edges, short* leader, short* size, Edge* minTree)
{
    minTree = (Edge*)malloc((graph->nVertices - 1) * sizeof(Edge));
    short k = 0;
    int total_cost = 0;

    for (short i = 0; i < graph->nEdges; i++)
    {
        Edge e = edges[i];

        if (find_set(leader, e.from) != find_set(leader, e.to))
        {
            graph_union(leader, size, e.from, e.to);
            minTree[k++] = e;
            total_cost += e.cost;
        }
        else if (e.cost < 0) graph->nonMSTNegativeCost += e.cost;
    }

    return total_cost;
}

int main()
{
    Graph graph;
    create_graph(&graph);

    int kruskal_cost = kruskal(&graph, graph.edges, graph.leader, graph.size, graph.minTree);
    printf("%d", kruskal_cost + graph.nonMSTNegativeCost);
}