#include "graph.h"

int main() {
	Graph* graph = g_newGraph();

	GVertex* vertexA = g_insertVertex(graph,"A");
	GVertex* vertexB = g_insertVertex(graph,"B");
	GVertex* vertexC = g_insertVertex(graph,"C");
	GVertex* vertexD = g_insertVertex(graph,"D");
	GVertex* vertexE = g_insertVertex(graph,"E");
	GVertex* vertexF = g_insertVertex(graph,"F");
	GVertex* vertexG = g_insertVertex(graph,"G");
	GVertex* vertexH = g_insertVertex(graph,"H");
	GVertex* vertexI = g_insertVertex(graph,"I");
	GEdge* edgeAB = g_insertEdge(graph,vertexA,vertexB);
	GEdge* edgeAD = g_insertEdge(graph,vertexA,vertexD);
	GEdge* edgeAF = g_insertEdge(graph,vertexA,vertexF);
	GEdge* edgeBC = g_insertEdge(graph,vertexB,vertexC);
	GEdge* edgeBD = g_insertEdge(graph,vertexB,vertexD);
	GEdge* edgeDE = g_insertEdge(graph,vertexD,vertexE);
	GEdge* edgeFG = g_insertEdge(graph,vertexF,vertexG);
	GEdge* edgeGH = g_insertEdge(graph,vertexG,vertexH);
	GEdge* edgeHI = g_insertEdge(graph,vertexH,vertexI);	

	g_test_show(graph);
	g_BFS(graph);
	g_DFS(graph);

	return 0;
}