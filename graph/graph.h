#ifndef GRAPH
#define GRAPH

#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

typedef struct _graph Graph;

typedef struct _graph_vertex_node GVertexNode;
typedef struct _graph_vertex GVertex;

typedef struct _graph_edge_node GEdgeNode;
typedef struct _graph_edge GEdge;

struct _graph_vertex_node {
	GVertex* vertex_;
	GVertexNode* next_;
};

struct _graph_vertex {
	const char* data_;
	int degree_;
	GEdgeNode* edges_;
};

struct _graph_edge_node {
	GEdge* edge_;
	GEdgeNode* next_;
};

struct _graph_edge {
	GVertex* vertices_[2];
};

struct _graph {
	int num_vertices_;
	int num_edges_;

	GVertexNode* vertices_;
	GEdgeNode* edges_;
};;

// USER INTERFACE
Graph* g_newGraph();

GVertex* g_insertVertex(Graph* graph, const char* data);
void g_removeVertex(Graph* graph, GVertex* vertex);

GEdge* g_insertEdge(Graph* graph, GVertex* vertex1, GVertex* vertex2);
void g_removeEdge(Graph* graph, GEdge* edge);

int g_existVertex(Graph* graph, GVertex* vertex);
int g_existEdge(Graph* graph, GEdge* edge);

GEdge* g_getEdge(GEdgeNode* list, GVertex* vertex1, GVertex* vertex2);

GVertex* g_oppositeVertex(GEdge* edge, GVertex* vertex);

// INNER METHODS;
GEdge* g_newEdge(GVertex* vertex1, GVertex* vertex2);
GEdgeNode* g_newEdgeNode(GEdge* edge);
void g_insertEdgeNode(GEdgeNode* list, GEdge* edge);
void g_removeEdgeNode(GEdgeNode* list, GEdge* edge);

GVertex* g_newVertex(const char* data);
GVertexNode* g_newVertexNode(GVertex* vertex);
void g_insertVertexNode(GVertexNode* list, GVertex* vertex);
void g_removeVertexNode(GVertexNode* list, GVertex* vertex);

void g_test_show(Graph* graph);

#endif