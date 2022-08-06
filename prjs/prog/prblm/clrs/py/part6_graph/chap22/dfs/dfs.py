import enum
from collections import namedtuple

class Vertex:
    def __init__(self,name):
        self.edges = []
        self.name = name
        self.id = -1  # unintialized id
    def addEdge(self,v):
        self.edges.append(v)
        return self
    def getEdge(self,idx):
        return self.edges[idx]
    def getNumEdges(self):
        return len(self.edges)
    def getName(self):
        return self.name

class AdjGraph:

    @classmethod
    def CreateGraphFromDict(cls,graph_data):
        g = AdjGraph()
        for v in graph_data:
            g.addVertex(Vertex(v))
        for u in graph_data:
            vert = g.getVertexByName(u)
            edges = graph_data[u]
            # add edge (u,v)
            for v in edges:
                vert.addEdge(g.getVertexByName(v).id)
        return g


    def __init__(self):
        self.vertices = []
        self.vertexMap = {}
    def getNumVertices(self):
        return len(self.vertices)
    def addVertex(self,v):
        v.id = self.getNumVertices()
        self.vertexMap[v.getName()]=v.id
        self.vertices.append(v)
        return self
    def getVertex(self,idx):
        return self.vertices[idx]
    def getVertexByName(self,name):
        return self.getVertex(self.vertexMap[name])



def DFS(graph):

    # enum class color
    # defines three enums 
    # used as vertex states
    # as it is traversed DFS
    class Color(enum.Enum):
        WHITE = 1
        GRAY = 2
        BLACK = 3

    num_vertices = graph.getNumVertices()

    # used to maintain state for each vertex
    # each vertex can be either 
    # unvisited, discovered, finished 
    # these states are represented by colors
    # WHITE, GRAY and BLACK respectively
    color = [Color.WHITE] * num_vertices


    # predecessor array. After DFS pi[u] points to the vertex from
    # which 'u' was first discovered
    # it can be used to build dfs-search-tree
    pi = [None] * num_vertices

    # d[u] contains the time when vertex u is visited
    d = [0] * num_vertices

    # f[u] contains the time when vertex u is finished 
    f = [0] * num_vertices

    # initialize color and pi
    for u in range(0,num_vertices):
        color[u] = Color.WHITE
        pi[u] = None
    
    time = 0


    # DFS_VISIT sub routine used by
    # DFS 
    def DFS_VISIT(u):
        color[u] = Color.GRAY
        nonlocal time
        time = time + 1
        d[u] = time
        vertex_u = graph.getVertex(u)
        for edge_idx in range(0,vertex_u.getNumEdges()):
            v = vertex_u.getEdge(edge_idx)
            # first time discovering v
            if color[v] == Color.WHITE:
                pi[v] = u
                DFS_VISIT(v)
        # vertex u is finished
        color[u] = Color.BLACK
        time = time + 1
        f[u] = time

    DFSResult = namedtuple("DFSResult",["pi","d","f"])


    for u in range(0, num_vertices):
        if color[u] == Color.WHITE:
            DFS_VISIT(u)
   
    return DFSResult(pi,d,f)

