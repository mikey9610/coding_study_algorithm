#include "graph.h"

// USER INTERFACE

Graph* g_newGraph() {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->vertices_ = g_newVertexNode(NULL);
	graph->num_vertices_= 0;
	graph->edges_ = g_newEdgeNode(NULL);
	graph->num_edges_= 0;
	return graph;
}
// create new empty graph and return it


GVertex* g_insertVertex(Graph* graph, const char* data) {
	GVertex* vertex = g_newVertex(data);
	g_insertVertexNode(graph->vertices_,vertex);
	graph->num_vertices_++;
	return vertex;
}
// create new vertex with data and insert the vertex node into the vertex list of the graph and return the vertex


void g_removeVertex(Graph* graph, GVertex* vertex) {
	if(!g_existVertex(graph,vertex))	return;	// check validity
	while(vertex->edges_->next_ != NULL)
		g_removeEdge(graph,vertex->edges_->next_->edge_);	// remove the edges of the vertex
	free(vertex->edges_);
	g_removeVertexNode(graph->vertices_,vertex);	// remove the vertex node from vertex list of the graph
	free(vertex);	// free the vertex
}
// remove the edges of the vertex and remove the vertex node from vertex list of graph and free the vertex


GEdge* g_insertEdge(Graph* graph, GVertex* vertex1, GVertex* vertex2) {
	GEdge* edge = g_newEdge(vertex1,vertex2);
	g_insertEdgeNode(graph->edges_,edge);
	g_insertEdgeNode(vertex1->edges_,edge);
	g_insertEdgeNode(vertex2->edges_,edge);
	graph->num_edges_++;
	vertex1->degree_++;
	vertex2->degree_++;
	return edge;
}
// create new edge whose vertices are vertex1,2 and insert edge node into the edge list of the graph, vertex1,2 and return the edge


void g_removeEdge(Graph* graph, GEdge* edge) {
	if(!g_existEdge(graph,edge))	return;	// check validity
	g_removeEdgeNode(graph->edges_,edge);	// remove the edge node from edge list of the graph
	g_removeEdgeNode(edge->vertices_[0]->edges_,edge);	// remove the edge node from edge list of the vertex1
	g_removeEdgeNode(edge->vertices_[1]->edges_,edge);	// remove the edge node from edge list of the vertex2
	edge->vertices_[0]->degree_--;
	edge->vertices_[1]->degree_--;
	free(edge);	// free the edge
}
// remove the edge nodes from edge list of the graph, vertex1, vertext2 and free the edge


int g_existVertex(Graph* graph, GVertex* vertex) {
	GVertexNode* list = graph->vertices_->next_;
	while(list != NULL && list->vertex_ != vertex)	list = list->next_;
	return list->vertex_ == vertex;
}
// check whether there exists the vertex inside the graph


int g_existEdge(Graph* graph, GEdge* edge) {
	GEdgeNode* list = graph->edges_->next_;
	while(list != NULL && list->edge_ != edge)	list = list->next_;
	return list->edge_ == edge;
}
// check whether there exists the edge inside the graph


GEdge* g_getEdge(GEdgeNode* list, GVertex* vertex1, GVertex* vertex2) {
	GEdgeNode* pVisited = list->next_;
	while(pVisited != NULL) {
		for(int i=0;i<2;i++)
			if(pVisited->edge_->vertices_[i]==vertex1 && pVisited->edge_->vertices_[(i-1)*(-1)]==vertex2)
				return pVisited->edge_;
		pVisited = pVisited->next_;
	}
	return NULL;
}
// get the edge whose vertices are vertex1,2


GVertex* g_oppositeVertex(GEdge* edge, GVertex* vertex) {
	return (edge->vertices_[0]==vertex) ? edge->vertices_[1] : edge->vertices_[0];
}
// return vertex in the opposite side of the edge of the vertex 



// INNER METHODS

GEdge* g_newEdge(GVertex* vertex1, GVertex* vertex2) {
	GEdge* edge = (GEdge*)malloc(sizeof(GEdge));
	edge->vertices_[0] = vertex1;
	edge->vertices_[1] = vertex2;
	return edge;
}
// create new edge whose vertices are vertex 1 & 2 and return it


GEdgeNode* g_newEdgeNode(GEdge* edge) {
	GEdgeNode* node = (GEdgeNode*)malloc(sizeof(GEdgeNode));
	node->edge_ = edge;
	node->next_ = NULL;
	return node;
}
// create new edge node and return it


void g_insertEdgeNode(GEdgeNode* list, GEdge* edge) {
	while(list->next_ != NULL) list = list->next_;
	list->next_ = g_newEdgeNode(edge);
}
// create new edge node and insert it into back of the list


void g_removeEdgeNode(GEdgeNode* list, GEdge* edge) {
	while(list->next_->edge_ != edge)	list = list->next_;	// not check validity
	GEdgeNode* node = list->next_;
	list->next_ = list->next_->next_;
	free(node);
}
// find edge node which is supposed to be removed and remove it from the list
// assume that there exists the edge node inside the list


GVertex* g_newVertex(const char* data) {
	GVertex* vertex = (GVertex*)malloc(sizeof(GVertex));
	vertex->data_ = data;
	vertex->degree_ = 0;
	vertex->edges_ = g_newEdgeNode(NULL);
	return vertex;
}
// create new vertex and return it


GVertexNode* g_newVertexNode(GVertex* vertex) {
	GVertexNode* node = (GVertexNode*)malloc(sizeof(GVertexNode));
	node->vertex_ = vertex;
	node->next_ = NULL;
	return node;
}
// create new vertex node and return it


void g_insertVertexNode(GVertexNode* list, GVertex* vertex) {
	while(list->next_ != NULL) list = list->next_;
	list->next_ = g_newVertexNode(vertex);
}
// create new vertex node and insert it into back of the list


void g_removeVertexNode(GVertexNode* list, GVertex* vertex) {
	while(list->next_->vertex_ != vertex)	list = list->next_;	// not check validity
	GVertexNode* node = list->next_;
	list->next_ = list->next_->next_;
	free(node);
}
// find vertex node which is supposed to be removed and remove it from the list
// assume that there exists the vertex node inside the list

void g_test_show(Graph* graph) {
	GVertexNode* vertex_list = graph->vertices_->next_;
	while(vertex_list != NULL) {
		printf("vertex %s[%d] : ",vertex_list->vertex_->data_,vertex_list->vertex_->degree_);
		GVertexNode* opponent = graph->vertices_->next_;
		while(opponent != NULL) {
			if(g_getEdge(vertex_list->vertex_->edges_,vertex_list->vertex_,opponent->vertex_)!=NULL) {
				printf("%s ",opponent->vertex_->data_);
			}
			opponent = opponent->next_;
		}
		printf("\n");
		vertex_list = vertex_list->next_;
	}
	printf("===================================\n");
}