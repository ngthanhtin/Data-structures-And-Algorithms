def pathRecursion(u, v, path):
    step = 0
    while u!=v:
        if path[v] == (-1,-1):
            return 0
        v = path[v]
        step += 1
    return step
        
def minimumMoves(grid, startX, startY, goalX, goalY):
    # Write your code here
    queue_ = []
    src = (startX, startY)
    goal = (goalX, goalY)
    queue_.append(src)
    visited = {}
    path = {}
    #convert grid to matrix form
    size_grid = len(grid)
    new_grid = []
    for r in grid:
        new_r = []
        for c in r:
            new_r.append(c)
        new_grid.append(new_r)
    # initialize visited, and path dictionary
    for i in range(size_grid):
        for j in range(size_grid):
            visited[(i,j)] = 0
            path[(i, j)] = (-1, -1)
    # BFS
    while len(queue_) > 0:
        src = queue_.pop(0)
        #get all possible moves from src
        moves = []
        for i in range(src[0]+1, size_grid): #move row up to down
            if new_grid[i][src[1]] != 'X':
                moves.append((i, src[1]))
            else:
                break
        for i in range(src[0]-1, -1, -1): #move row down to up
            if new_grid[i][src[1]] != 'X':
                moves.append((i, src[1]))
            else:
                break
        for i in range(src[1]+1, size_grid): #move column left to right
            if new_grid[src[0]][i] != 'X':
                moves.append((src[0], i))
            else:
                break
        for i in range(src[1]-1, -1, -1): # move column right to left
            if new_grid[src[0]][i] != 'X':
                moves.append((src[0], i))
            else:
                break
        # try moves
        for move in moves:
            if visited[move] == 0:
                visited[move] = 1
                queue_.append(move)
                path[move] = src
        
    src = (startX, startY)
    goal = (goalX, goalY)
    min_path = pathRecursion(src, goal, path)
    return min_path