def findSet(u):
	while u != parent[u]:
		u = parent[u]
	return u
def unionSet(u, v):
	up = findSet(u)
	vp = findSet(v)
	parent[vp] = up