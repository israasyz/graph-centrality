import networkx as nx
import matplotlib.pyplot as plt
import operator
from itertools import islice

with open('myfile.txt') as f:
    first_line = f.readline()
res = [int(j) for j in first_line.split() if j.isdigit()]
n = res[0]
m = res[1]
G = nx.Graph()
color_map = []
node_sizes = []
input = input('For Degree Centrality enter "d"\nFor Betweenness Centrality enter "b"\nFor Closeness Centrality enter "c":')

for i in range(n):
    G.add_node(i, pos=(i, 2*i*i*i))
with open('myfile.txt', 'r') as myfile:
    for line in islice(myfile, 1, None):
        result = [int(k) for k in line.split() if k.isdigit()]
        u = result[0]
        v = result[1]
        w = result[2]
        G.add_edge(u, v, weight=w)

if input == 'd':
    deg_cen = G.degree()
    x = max([val for (node, val) in G.degree()])
    print(x)
    print("# Degree centrality:" + str(deg_cen))
    for node in G:
        if deg_cen[node] == x:
            color_map.append('blue')
            node_sizes.append(750)
        else:
            color_map.append('red')
            node_sizes.append(250)


if input == 'b':
    bet_cen = nx.betweenness_centrality(G, weight="weight", normalized=False)
    y = max(bet_cen.items(), key=operator.itemgetter(1))[0]
    print(y)
    print("# Betweenness centrality:" + str(bet_cen))
    for node in G:
        if bet_cen[node] == bet_cen[y]:
            color_map.append('blue')
            node_sizes.append(750)
        else:
            color_map.append('red')
            node_sizes.append(250)

if input == 'c':
    clo_cen = nx.closeness_centrality(G, distance="weight")
    z = max(clo_cen.items(), key=operator.itemgetter(1))[0]
    print(z)
    print("# Closeness centrality:" + str(clo_cen))
    for node in G:
        if clo_cen[node] == clo_cen[z]:
            color_map.append('blue')
            node_sizes.append(750)
        else:
            color_map.append('red')
            node_sizes.append(250)

pos = nx.get_node_attributes(G, 'pos')
nx.draw(G, pos, node_size = node_sizes, with_labels=True, node_color=color_map)
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, node_size = node_sizes, edge_labels=labels)
plt.savefig("path.png")
plt.show()