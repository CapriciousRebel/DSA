# define M no_of_union_find_operations
# define N no_of_objects


class QuickFindUF:
    # O(M*N)
    '''
    Numbers is our base data structure here, which is an array.
    numbers[i] denotes the set to which i belongs
    if i, j belong to same set, then numbers[i] = numbers[j]
    *Tree = too flat*
    '''

    def __init__(self, n):
        self.size = n
        self.numbers = [i for i in range(n)]

    def connected(self, p, q):
        '''check if p and q have same id'''
        # O(1)
        if(self.numbers[p] == self.numbers[q]):
            return True
        return False

    def make_union(self, p, q):
        '''makes a union of sets that p and q belong to, to connect them'''
        # O(N)
        if(self.connected(p, q)):
            return False
        else:
            for i in range(self.size):
                if(self.numbers[i] == self.numbers[q]):
                    self.numbers[i] = self.numbers[p]


class QuickUnion:
    # O(M*N)
    '''
    numbers is our base data structure here, which is an array.
    numbers[i] is the parent of i
    root(i) = numbers[numbers[numbers[...numbers[i]...]]]
    *Tree = too tall*
    '''

    def __init__(self, n):
        self.size = n
        self.numbers = [i for i in range(n)]

    def find_root(self, i):
        # O(N)
        while(i != self.numbers[i]):
            i = self.numbers[i]
        return i

    def connected(self, p, q):
        '''check if p and q have same root'''
        # O(N)
        return self.find_root(p) == self.find_root(q)

    def make_union(self, p, q):
        '''make the roots of p and q the same to connect them'''
        # O(N)
        root_p = self.find_root(p)
        root_q = self.find_root(q)
        self.numbers[root_p] = root_q


class WeightedQuickUnion:
    # O(N + MlogN)
    '''
    To prevent *tall trees*, when doing union, 
    we will make the smaller tree the child of the larger tree
    >> MAX depth of any tree is log(N)/log(2)
       'Since when merging two trees into one, 
       we at least double the size of the smaller tree'
    '''

    def __init__(self, n):
        self.size = n
        self.numbers = [i for i in range(n)]
        self.tree_size = [1 for i in range(n)]

    def find_root(self, i):
        # O(N)
        while(i != self.numbers[i]):
            i = self.numbers[i]
        return i

    def connected(self, p, q):
        '''check if p and q have same root'''
        # O(N)
        return self.find_root(p) == self.find_root(q)

    def make_union(self, p, q):
        '''make the roots of p and q the same to connect them'''
        # O(N)
        root_p = self.find_root(p)
        root_q = self.find_root(q)

        if(self.tree_size[root_p] < self.tree_size[root_q]):
            self.numbers[root_p] = root_q
        else:
            self.numbers[root_q] = root_p


class WeightedQuickUnionImproved:
    # O(N + M*log*(N))
    '''(Path compression)
    While we find the root,
    let us also make it the immediate parent
    of all the elements encountered while transversing to it.
    '''

    def __init__(self, n):
        self.size = n
        self.numbers = [i for i in range(n)]
        self.tree_size = [1 for i in range(n)]

    def find_root(self, i):
        # O(N)
        temp = []
        while(i != self.numbers[i]):
            temp.append(i)
            i = self.numbers[i]
        for j in range(len(temp)):
            self.numbers[temp[j]] = i

    def connected(self, p, q):
        '''check if p and q have same root'''
        # O(N)
        return self.find_root(p) == self.find_root(q)

    def make_union(self, p, q):
        '''make the roots of p and q the same to connect them'''
        # O(N)
        root_p = self.find_root(p)
        root_q = self.find_root(q)

        if(self.tree_size[root_p] < self.tree_size[root_q]):
            self.numbers[root_p] = root_q
        else:
            self.numbers[root_q] = root_p


print("Quick Find...")
UnionFind = QuickFindUF(10)
print(UnionFind.numbers)

UnionFind.make_union(0, 5)
print(UnionFind.numbers)

UnionFind.make_union(1, 5)
print(UnionFind.numbers)

UnionFind.make_union(2, 8)
print(UnionFind.numbers)

UnionFind.make_union(2, 5)
print(UnionFind.numbers)

print("Quick Union...")
UnionFind = QuickUnion(10)
print(UnionFind.numbers)

UnionFind.make_union(0, 5)
print(UnionFind.numbers)

UnionFind.make_union(1, 5)
print(UnionFind.numbers)

UnionFind.make_union(2, 8)
print(UnionFind.numbers)

UnionFind.make_union(2, 5)
print(UnionFind.numbers)

print("Weighted Quick Union...")
UnionFind = WeightedQuickUnion(10)
print(UnionFind.numbers)

UnionFind.make_union(0, 5)
print(UnionFind.numbers)

UnionFind.make_union(1, 5)
print(UnionFind.numbers)

UnionFind.make_union(2, 8)
print(UnionFind.numbers)

UnionFind.make_union(2, 5)
print(UnionFind.numbers)

print("Weighted Quick Union Improved...")
UnionFind = WeightedQuickUnion(10)
print(UnionFind.numbers)

UnionFind.make_union(0, 5)
print(UnionFind.numbers)

UnionFind.make_union(1, 5)
print(UnionFind.numbers)

UnionFind.make_union(2, 8)
print(UnionFind.numbers)

UnionFind.make_union(2, 5)
print(UnionFind.numbers)