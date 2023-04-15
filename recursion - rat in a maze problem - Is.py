
def valid_move(m, n, x, y):
    if((x > -1) and (y> -1) and (x<n) and (y<n) and (m[x][y]==1)):
        return True
    return False 



def path(m, n, x, y, ouput, ans):
    if((x==n-1) and (y ==n-1)):
        ans.append(ouput)
        return
    
    m[x][y] = 0

    if(valid_move(m, n, x+1, y)):          #Down
        ouput += 'D'
        path(m, n,x+1,y, ouput, ans)
        ouput = ouput[:-1]

    if(valid_move(m, n, x, y+1)):          #Right
        ouput += 'R'
        path(m, n,x,y+1, ouput ,ans)
        ouput = ouput[:-1]

    if(valid_move(m, n, x, y-1)):          #Left
        ouput += 'L'
        path(m, n,x,y-1, ouput, ans)
        ouput = ouput[:-1]

    if(valid_move(m, n, x, y-1)):          #Up
        ouput += 'U'
        path(m, n,x-1,y, ouput, ans)
        ouput = ouput[:-1]

    m[x][y] = 1



m = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]

ans = []

path(m, len(m),0,0, "", ans)


print(*ans)


