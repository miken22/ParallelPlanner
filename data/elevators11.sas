begin_version
3
end_version
begin_metric
0
end_metric
9
begin_variable
var0
-1
16
Atom boarded(p0, fast0)
Atom boarded(p0, slow0-0)
Atom boarded(p0, slow1-0)
Atom passenger-at(p0, n0)
Atom passenger-at(p0, n1)
Atom passenger-at(p0, n10)
Atom passenger-at(p0, n11)
Atom passenger-at(p0, n12)
Atom passenger-at(p0, n2)
Atom passenger-at(p0, n3)
Atom passenger-at(p0, n4)
Atom passenger-at(p0, n5)
Atom passenger-at(p0, n6)
Atom passenger-at(p0, n7)
Atom passenger-at(p0, n8)
Atom passenger-at(p0, n9)
end_variable
begin_variable
var1
-1
16
Atom boarded(p1, fast0)
Atom boarded(p1, slow0-0)
Atom boarded(p1, slow1-0)
Atom passenger-at(p1, n0)
Atom passenger-at(p1, n1)
Atom passenger-at(p1, n10)
Atom passenger-at(p1, n11)
Atom passenger-at(p1, n12)
Atom passenger-at(p1, n2)
Atom passenger-at(p1, n3)
Atom passenger-at(p1, n4)
Atom passenger-at(p1, n5)
Atom passenger-at(p1, n6)
Atom passenger-at(p1, n7)
Atom passenger-at(p1, n8)
Atom passenger-at(p1, n9)
end_variable
begin_variable
var2
-1
16
Atom boarded(p2, fast0)
Atom boarded(p2, slow0-0)
Atom boarded(p2, slow1-0)
Atom passenger-at(p2, n0)
Atom passenger-at(p2, n1)
Atom passenger-at(p2, n10)
Atom passenger-at(p2, n11)
Atom passenger-at(p2, n12)
Atom passenger-at(p2, n2)
Atom passenger-at(p2, n3)
Atom passenger-at(p2, n4)
Atom passenger-at(p2, n5)
Atom passenger-at(p2, n6)
Atom passenger-at(p2, n7)
Atom passenger-at(p2, n8)
Atom passenger-at(p2, n9)
end_variable
begin_variable
var3
-1
5
Atom lift-at(fast0, n0)
Atom lift-at(fast0, n12)
Atom lift-at(fast0, n3)
Atom lift-at(fast0, n6)
Atom lift-at(fast0, n9)
end_variable
begin_variable
var4
-1
7
Atom lift-at(slow0-0, n0)
Atom lift-at(slow0-0, n1)
Atom lift-at(slow0-0, n2)
Atom lift-at(slow0-0, n3)
Atom lift-at(slow0-0, n4)
Atom lift-at(slow0-0, n5)
Atom lift-at(slow0-0, n6)
end_variable
begin_variable
var5
-1
7
Atom lift-at(slow1-0, n10)
Atom lift-at(slow1-0, n11)
Atom lift-at(slow1-0, n12)
Atom lift-at(slow1-0, n6)
Atom lift-at(slow1-0, n7)
Atom lift-at(slow1-0, n8)
Atom lift-at(slow1-0, n9)
end_variable
begin_variable
var6
-1
4
Atom passengers(fast0, n0)
Atom passengers(fast0, n1)
Atom passengers(fast0, n2)
Atom passengers(fast0, n3)
end_variable
begin_variable
var7
-1
3
Atom passengers(slow0-0, n0)
Atom passengers(slow0-0, n1)
Atom passengers(slow0-0, n2)
end_variable
begin_variable
var8
-1
3
Atom passengers(slow1-0, n0)
Atom passengers(slow1-0, n1)
Atom passengers(slow1-0, n2)
end_variable
9
begin_mutex_group
16
0 0
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0 9
0 10
0 11
0 12
0 13
0 14
0 15
end_mutex_group
begin_mutex_group
16
1 0
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
1 14
1 15
end_mutex_group
begin_mutex_group
16
2 0
2 1
2 2
2 3
2 4
2 5
2 6
2 7
2 8
2 9
2 10
2 11
2 12
2 13
2 14
2 15
end_mutex_group
begin_mutex_group
5
3 0
3 1
3 2
3 3
3 4
end_mutex_group
begin_mutex_group
7
4 0
4 1
4 2
4 3
4 4
4 5
4 6
end_mutex_group
begin_mutex_group
7
5 0
5 1
5 2
5 3
5 4
5 5
5 6
end_mutex_group
begin_mutex_group
4
6 0
6 1
6 2
6 3
end_mutex_group
begin_mutex_group
3
7 0
7 1
7 2
end_mutex_group
begin_mutex_group
3
8 0
8 1
8 2
end_mutex_group
begin_state
3
3
8
3
6
5
0
0
0
end_state
begin_goal
3
0 9
1 6
2 13
end_goal
362
begin_operator
board p0 fast0 n0 n0 n1
1
3 0
2
0 0 3 0
0 6 0 1
1
end_operator
begin_operator
board p0 fast0 n0 n1 n2
1
3 0
2
0 0 3 0
0 6 1 2
1
end_operator
begin_operator
board p0 fast0 n0 n2 n3
1
3 0
2
0 0 3 0
0 6 2 3
1
end_operator
begin_operator
board p0 fast0 n12 n0 n1
1
3 1
2
0 0 7 0
0 6 0 1
1
end_operator
begin_operator
board p0 fast0 n12 n1 n2
1
3 1
2
0 0 7 0
0 6 1 2
1
end_operator
begin_operator
board p0 fast0 n12 n2 n3
1
3 1
2
0 0 7 0
0 6 2 3
1
end_operator
begin_operator
board p0 fast0 n3 n0 n1
1
3 2
2
0 0 9 0
0 6 0 1
1
end_operator
begin_operator
board p0 fast0 n3 n1 n2
1
3 2
2
0 0 9 0
0 6 1 2
1
end_operator
begin_operator
board p0 fast0 n3 n2 n3
1
3 2
2
0 0 9 0
0 6 2 3
1
end_operator
begin_operator
board p0 fast0 n6 n0 n1
1
3 3
2
0 0 12 0
0 6 0 1
1
end_operator
begin_operator
board p0 fast0 n6 n1 n2
1
3 3
2
0 0 12 0
0 6 1 2
1
end_operator
begin_operator
board p0 fast0 n6 n2 n3
1
3 3
2
0 0 12 0
0 6 2 3
1
end_operator
begin_operator
board p0 fast0 n9 n0 n1
1
3 4
2
0 0 15 0
0 6 0 1
1
end_operator
begin_operator
board p0 fast0 n9 n1 n2
1
3 4
2
0 0 15 0
0 6 1 2
1
end_operator
begin_operator
board p0 fast0 n9 n2 n3
1
3 4
2
0 0 15 0
0 6 2 3
1
end_operator
begin_operator
board p0 slow0-0 n0 n0 n1
1
4 0
2
0 0 3 1
0 7 0 1
1
end_operator
begin_operator
board p0 slow0-0 n0 n1 n2
1
4 0
2
0 0 3 1
0 7 1 2
1
end_operator
begin_operator
board p0 slow0-0 n1 n0 n1
1
4 1
2
0 0 4 1
0 7 0 1
1
end_operator
begin_operator
board p0 slow0-0 n1 n1 n2
1
4 1
2
0 0 4 1
0 7 1 2
1
end_operator
begin_operator
board p0 slow0-0 n2 n0 n1
1
4 2
2
0 0 8 1
0 7 0 1
1
end_operator
begin_operator
board p0 slow0-0 n2 n1 n2
1
4 2
2
0 0 8 1
0 7 1 2
1
end_operator
begin_operator
board p0 slow0-0 n3 n0 n1
1
4 3
2
0 0 9 1
0 7 0 1
1
end_operator
begin_operator
board p0 slow0-0 n3 n1 n2
1
4 3
2
0 0 9 1
0 7 1 2
1
end_operator
begin_operator
board p0 slow0-0 n4 n0 n1
1
4 4
2
0 0 10 1
0 7 0 1
1
end_operator
begin_operator
board p0 slow0-0 n4 n1 n2
1
4 4
2
0 0 10 1
0 7 1 2
1
end_operator
begin_operator
board p0 slow0-0 n5 n0 n1
1
4 5
2
0 0 11 1
0 7 0 1
1
end_operator
begin_operator
board p0 slow0-0 n5 n1 n2
1
4 5
2
0 0 11 1
0 7 1 2
1
end_operator
begin_operator
board p0 slow0-0 n6 n0 n1
1
4 6
2
0 0 12 1
0 7 0 1
1
end_operator
begin_operator
board p0 slow0-0 n6 n1 n2
1
4 6
2
0 0 12 1
0 7 1 2
1
end_operator
begin_operator
board p0 slow1-0 n10 n0 n1
1
5 0
2
0 0 5 2
0 8 0 1
1
end_operator
begin_operator
board p0 slow1-0 n10 n1 n2
1
5 0
2
0 0 5 2
0 8 1 2
1
end_operator
begin_operator
board p0 slow1-0 n11 n0 n1
1
5 1
2
0 0 6 2
0 8 0 1
1
end_operator
begin_operator
board p0 slow1-0 n11 n1 n2
1
5 1
2
0 0 6 2
0 8 1 2
1
end_operator
begin_operator
board p0 slow1-0 n12 n0 n1
1
5 2
2
0 0 7 2
0 8 0 1
1
end_operator
begin_operator
board p0 slow1-0 n12 n1 n2
1
5 2
2
0 0 7 2
0 8 1 2
1
end_operator
begin_operator
board p0 slow1-0 n6 n0 n1
1
5 3
2
0 0 12 2
0 8 0 1
1
end_operator
begin_operator
board p0 slow1-0 n6 n1 n2
1
5 3
2
0 0 12 2
0 8 1 2
1
end_operator
begin_operator
board p0 slow1-0 n7 n0 n1
1
5 4
2
0 0 13 2
0 8 0 1
1
end_operator
begin_operator
board p0 slow1-0 n7 n1 n2
1
5 4
2
0 0 13 2
0 8 1 2
1
end_operator
begin_operator
board p0 slow1-0 n8 n0 n1
1
5 5
2
0 0 14 2
0 8 0 1
1
end_operator
begin_operator
board p0 slow1-0 n8 n1 n2
1
5 5
2
0 0 14 2
0 8 1 2
1
end_operator
begin_operator
board p0 slow1-0 n9 n0 n1
1
5 6
2
0 0 15 2
0 8 0 1
1
end_operator
begin_operator
board p0 slow1-0 n9 n1 n2
1
5 6
2
0 0 15 2
0 8 1 2
1
end_operator
begin_operator
board p1 fast0 n0 n0 n1
1
3 0
2
0 1 3 0
0 6 0 1
1
end_operator
begin_operator
board p1 fast0 n0 n1 n2
1
3 0
2
0 1 3 0
0 6 1 2
1
end_operator
begin_operator
board p1 fast0 n0 n2 n3
1
3 0
2
0 1 3 0
0 6 2 3
1
end_operator
begin_operator
board p1 fast0 n12 n0 n1
1
3 1
2
0 1 7 0
0 6 0 1
1
end_operator
begin_operator
board p1 fast0 n12 n1 n2
1
3 1
2
0 1 7 0
0 6 1 2
1
end_operator
begin_operator
board p1 fast0 n12 n2 n3
1
3 1
2
0 1 7 0
0 6 2 3
1
end_operator
begin_operator
board p1 fast0 n3 n0 n1
1
3 2
2
0 1 9 0
0 6 0 1
1
end_operator
begin_operator
board p1 fast0 n3 n1 n2
1
3 2
2
0 1 9 0
0 6 1 2
1
end_operator
begin_operator
board p1 fast0 n3 n2 n3
1
3 2
2
0 1 9 0
0 6 2 3
1
end_operator
begin_operator
board p1 fast0 n6 n0 n1
1
3 3
2
0 1 12 0
0 6 0 1
1
end_operator
begin_operator
board p1 fast0 n6 n1 n2
1
3 3
2
0 1 12 0
0 6 1 2
1
end_operator
begin_operator
board p1 fast0 n6 n2 n3
1
3 3
2
0 1 12 0
0 6 2 3
1
end_operator
begin_operator
board p1 fast0 n9 n0 n1
1
3 4
2
0 1 15 0
0 6 0 1
1
end_operator
begin_operator
board p1 fast0 n9 n1 n2
1
3 4
2
0 1 15 0
0 6 1 2
1
end_operator
begin_operator
board p1 fast0 n9 n2 n3
1
3 4
2
0 1 15 0
0 6 2 3
1
end_operator
begin_operator
board p1 slow0-0 n0 n0 n1
1
4 0
2
0 1 3 1
0 7 0 1
1
end_operator
begin_operator
board p1 slow0-0 n0 n1 n2
1
4 0
2
0 1 3 1
0 7 1 2
1
end_operator
begin_operator
board p1 slow0-0 n1 n0 n1
1
4 1
2
0 1 4 1
0 7 0 1
1
end_operator
begin_operator
board p1 slow0-0 n1 n1 n2
1
4 1
2
0 1 4 1
0 7 1 2
1
end_operator
begin_operator
board p1 slow0-0 n2 n0 n1
1
4 2
2
0 1 8 1
0 7 0 1
1
end_operator
begin_operator
board p1 slow0-0 n2 n1 n2
1
4 2
2
0 1 8 1
0 7 1 2
1
end_operator
begin_operator
board p1 slow0-0 n3 n0 n1
1
4 3
2
0 1 9 1
0 7 0 1
1
end_operator
begin_operator
board p1 slow0-0 n3 n1 n2
1
4 3
2
0 1 9 1
0 7 1 2
1
end_operator
begin_operator
board p1 slow0-0 n4 n0 n1
1
4 4
2
0 1 10 1
0 7 0 1
1
end_operator
begin_operator
board p1 slow0-0 n4 n1 n2
1
4 4
2
0 1 10 1
0 7 1 2
1
end_operator
begin_operator
board p1 slow0-0 n5 n0 n1
1
4 5
2
0 1 11 1
0 7 0 1
1
end_operator
begin_operator
board p1 slow0-0 n5 n1 n2
1
4 5
2
0 1 11 1
0 7 1 2
1
end_operator
begin_operator
board p1 slow0-0 n6 n0 n1
1
4 6
2
0 1 12 1
0 7 0 1
1
end_operator
begin_operator
board p1 slow0-0 n6 n1 n2
1
4 6
2
0 1 12 1
0 7 1 2
1
end_operator
begin_operator
board p1 slow1-0 n10 n0 n1
1
5 0
2
0 1 5 2
0 8 0 1
1
end_operator
begin_operator
board p1 slow1-0 n10 n1 n2
1
5 0
2
0 1 5 2
0 8 1 2
1
end_operator
begin_operator
board p1 slow1-0 n11 n0 n1
1
5 1
2
0 1 6 2
0 8 0 1
1
end_operator
begin_operator
board p1 slow1-0 n11 n1 n2
1
5 1
2
0 1 6 2
0 8 1 2
1
end_operator
begin_operator
board p1 slow1-0 n12 n0 n1
1
5 2
2
0 1 7 2
0 8 0 1
1
end_operator
begin_operator
board p1 slow1-0 n12 n1 n2
1
5 2
2
0 1 7 2
0 8 1 2
1
end_operator
begin_operator
board p1 slow1-0 n6 n0 n1
1
5 3
2
0 1 12 2
0 8 0 1
1
end_operator
begin_operator
board p1 slow1-0 n6 n1 n2
1
5 3
2
0 1 12 2
0 8 1 2
1
end_operator
begin_operator
board p1 slow1-0 n7 n0 n1
1
5 4
2
0 1 13 2
0 8 0 1
1
end_operator
begin_operator
board p1 slow1-0 n7 n1 n2
1
5 4
2
0 1 13 2
0 8 1 2
1
end_operator
begin_operator
board p1 slow1-0 n8 n0 n1
1
5 5
2
0 1 14 2
0 8 0 1
1
end_operator
begin_operator
board p1 slow1-0 n8 n1 n2
1
5 5
2
0 1 14 2
0 8 1 2
1
end_operator
begin_operator
board p1 slow1-0 n9 n0 n1
1
5 6
2
0 1 15 2
0 8 0 1
1
end_operator
begin_operator
board p1 slow1-0 n9 n1 n2
1
5 6
2
0 1 15 2
0 8 1 2
1
end_operator
begin_operator
board p2 fast0 n0 n0 n1
1
3 0
2
0 2 3 0
0 6 0 1
1
end_operator
begin_operator
board p2 fast0 n0 n1 n2
1
3 0
2
0 2 3 0
0 6 1 2
1
end_operator
begin_operator
board p2 fast0 n0 n2 n3
1
3 0
2
0 2 3 0
0 6 2 3
1
end_operator
begin_operator
board p2 fast0 n12 n0 n1
1
3 1
2
0 2 7 0
0 6 0 1
1
end_operator
begin_operator
board p2 fast0 n12 n1 n2
1
3 1
2
0 2 7 0
0 6 1 2
1
end_operator
begin_operator
board p2 fast0 n12 n2 n3
1
3 1
2
0 2 7 0
0 6 2 3
1
end_operator
begin_operator
board p2 fast0 n3 n0 n1
1
3 2
2
0 2 9 0
0 6 0 1
1
end_operator
begin_operator
board p2 fast0 n3 n1 n2
1
3 2
2
0 2 9 0
0 6 1 2
1
end_operator
begin_operator
board p2 fast0 n3 n2 n3
1
3 2
2
0 2 9 0
0 6 2 3
1
end_operator
begin_operator
board p2 fast0 n6 n0 n1
1
3 3
2
0 2 12 0
0 6 0 1
1
end_operator
begin_operator
board p2 fast0 n6 n1 n2
1
3 3
2
0 2 12 0
0 6 1 2
1
end_operator
begin_operator
board p2 fast0 n6 n2 n3
1
3 3
2
0 2 12 0
0 6 2 3
1
end_operator
begin_operator
board p2 fast0 n9 n0 n1
1
3 4
2
0 2 15 0
0 6 0 1
1
end_operator
begin_operator
board p2 fast0 n9 n1 n2
1
3 4
2
0 2 15 0
0 6 1 2
1
end_operator
begin_operator
board p2 fast0 n9 n2 n3
1
3 4
2
0 2 15 0
0 6 2 3
1
end_operator
begin_operator
board p2 slow0-0 n0 n0 n1
1
4 0
2
0 2 3 1
0 7 0 1
1
end_operator
begin_operator
board p2 slow0-0 n0 n1 n2
1
4 0
2
0 2 3 1
0 7 1 2
1
end_operator
begin_operator
board p2 slow0-0 n1 n0 n1
1
4 1
2
0 2 4 1
0 7 0 1
1
end_operator
begin_operator
board p2 slow0-0 n1 n1 n2
1
4 1
2
0 2 4 1
0 7 1 2
1
end_operator
begin_operator
board p2 slow0-0 n2 n0 n1
1
4 2
2
0 2 8 1
0 7 0 1
1
end_operator
begin_operator
board p2 slow0-0 n2 n1 n2
1
4 2
2
0 2 8 1
0 7 1 2
1
end_operator
begin_operator
board p2 slow0-0 n3 n0 n1
1
4 3
2
0 2 9 1
0 7 0 1
1
end_operator
begin_operator
board p2 slow0-0 n3 n1 n2
1
4 3
2
0 2 9 1
0 7 1 2
1
end_operator
begin_operator
board p2 slow0-0 n4 n0 n1
1
4 4
2
0 2 10 1
0 7 0 1
1
end_operator
begin_operator
board p2 slow0-0 n4 n1 n2
1
4 4
2
0 2 10 1
0 7 1 2
1
end_operator
begin_operator
board p2 slow0-0 n5 n0 n1
1
4 5
2
0 2 11 1
0 7 0 1
1
end_operator
begin_operator
board p2 slow0-0 n5 n1 n2
1
4 5
2
0 2 11 1
0 7 1 2
1
end_operator
begin_operator
board p2 slow0-0 n6 n0 n1
1
4 6
2
0 2 12 1
0 7 0 1
1
end_operator
begin_operator
board p2 slow0-0 n6 n1 n2
1
4 6
2
0 2 12 1
0 7 1 2
1
end_operator
begin_operator
board p2 slow1-0 n10 n0 n1
1
5 0
2
0 2 5 2
0 8 0 1
1
end_operator
begin_operator
board p2 slow1-0 n10 n1 n2
1
5 0
2
0 2 5 2
0 8 1 2
1
end_operator
begin_operator
board p2 slow1-0 n11 n0 n1
1
5 1
2
0 2 6 2
0 8 0 1
1
end_operator
begin_operator
board p2 slow1-0 n11 n1 n2
1
5 1
2
0 2 6 2
0 8 1 2
1
end_operator
begin_operator
board p2 slow1-0 n12 n0 n1
1
5 2
2
0 2 7 2
0 8 0 1
1
end_operator
begin_operator
board p2 slow1-0 n12 n1 n2
1
5 2
2
0 2 7 2
0 8 1 2
1
end_operator
begin_operator
board p2 slow1-0 n6 n0 n1
1
5 3
2
0 2 12 2
0 8 0 1
1
end_operator
begin_operator
board p2 slow1-0 n6 n1 n2
1
5 3
2
0 2 12 2
0 8 1 2
1
end_operator
begin_operator
board p2 slow1-0 n7 n0 n1
1
5 4
2
0 2 13 2
0 8 0 1
1
end_operator
begin_operator
board p2 slow1-0 n7 n1 n2
1
5 4
2
0 2 13 2
0 8 1 2
1
end_operator
begin_operator
board p2 slow1-0 n8 n0 n1
1
5 5
2
0 2 14 2
0 8 0 1
1
end_operator
begin_operator
board p2 slow1-0 n8 n1 n2
1
5 5
2
0 2 14 2
0 8 1 2
1
end_operator
begin_operator
board p2 slow1-0 n9 n0 n1
1
5 6
2
0 2 15 2
0 8 0 1
1
end_operator
begin_operator
board p2 slow1-0 n9 n1 n2
1
5 6
2
0 2 15 2
0 8 1 2
1
end_operator
begin_operator
leave p0 fast0 n0 n1 n0
1
3 0
2
0 0 0 3
0 6 1 0
1
end_operator
begin_operator
leave p0 fast0 n0 n2 n1
1
3 0
2
0 0 0 3
0 6 2 1
1
end_operator
begin_operator
leave p0 fast0 n0 n3 n2
1
3 0
2
0 0 0 3
0 6 3 2
1
end_operator
begin_operator
leave p0 fast0 n12 n1 n0
1
3 1
2
0 0 0 7
0 6 1 0
1
end_operator
begin_operator
leave p0 fast0 n12 n2 n1
1
3 1
2
0 0 0 7
0 6 2 1
1
end_operator
begin_operator
leave p0 fast0 n12 n3 n2
1
3 1
2
0 0 0 7
0 6 3 2
1
end_operator
begin_operator
leave p0 fast0 n3 n1 n0
1
3 2
2
0 0 0 9
0 6 1 0
1
end_operator
begin_operator
leave p0 fast0 n3 n2 n1
1
3 2
2
0 0 0 9
0 6 2 1
1
end_operator
begin_operator
leave p0 fast0 n3 n3 n2
1
3 2
2
0 0 0 9
0 6 3 2
1
end_operator
begin_operator
leave p0 fast0 n6 n1 n0
1
3 3
2
0 0 0 12
0 6 1 0
1
end_operator
begin_operator
leave p0 fast0 n6 n2 n1
1
3 3
2
0 0 0 12
0 6 2 1
1
end_operator
begin_operator
leave p0 fast0 n6 n3 n2
1
3 3
2
0 0 0 12
0 6 3 2
1
end_operator
begin_operator
leave p0 fast0 n9 n1 n0
1
3 4
2
0 0 0 15
0 6 1 0
1
end_operator
begin_operator
leave p0 fast0 n9 n2 n1
1
3 4
2
0 0 0 15
0 6 2 1
1
end_operator
begin_operator
leave p0 fast0 n9 n3 n2
1
3 4
2
0 0 0 15
0 6 3 2
1
end_operator
begin_operator
leave p0 slow0-0 n0 n1 n0
1
4 0
2
0 0 1 3
0 7 1 0
1
end_operator
begin_operator
leave p0 slow0-0 n0 n2 n1
1
4 0
2
0 0 1 3
0 7 2 1
1
end_operator
begin_operator
leave p0 slow0-0 n1 n1 n0
1
4 1
2
0 0 1 4
0 7 1 0
1
end_operator
begin_operator
leave p0 slow0-0 n1 n2 n1
1
4 1
2
0 0 1 4
0 7 2 1
1
end_operator
begin_operator
leave p0 slow0-0 n2 n1 n0
1
4 2
2
0 0 1 8
0 7 1 0
1
end_operator
begin_operator
leave p0 slow0-0 n2 n2 n1
1
4 2
2
0 0 1 8
0 7 2 1
1
end_operator
begin_operator
leave p0 slow0-0 n3 n1 n0
1
4 3
2
0 0 1 9
0 7 1 0
1
end_operator
begin_operator
leave p0 slow0-0 n3 n2 n1
1
4 3
2
0 0 1 9
0 7 2 1
1
end_operator
begin_operator
leave p0 slow0-0 n4 n1 n0
1
4 4
2
0 0 1 10
0 7 1 0
1
end_operator
begin_operator
leave p0 slow0-0 n4 n2 n1
1
4 4
2
0 0 1 10
0 7 2 1
1
end_operator
begin_operator
leave p0 slow0-0 n5 n1 n0
1
4 5
2
0 0 1 11
0 7 1 0
1
end_operator
begin_operator
leave p0 slow0-0 n5 n2 n1
1
4 5
2
0 0 1 11
0 7 2 1
1
end_operator
begin_operator
leave p0 slow0-0 n6 n1 n0
1
4 6
2
0 0 1 12
0 7 1 0
1
end_operator
begin_operator
leave p0 slow0-0 n6 n2 n1
1
4 6
2
0 0 1 12
0 7 2 1
1
end_operator
begin_operator
leave p0 slow1-0 n10 n1 n0
1
5 0
2
0 0 2 5
0 8 1 0
1
end_operator
begin_operator
leave p0 slow1-0 n10 n2 n1
1
5 0
2
0 0 2 5
0 8 2 1
1
end_operator
begin_operator
leave p0 slow1-0 n11 n1 n0
1
5 1
2
0 0 2 6
0 8 1 0
1
end_operator
begin_operator
leave p0 slow1-0 n11 n2 n1
1
5 1
2
0 0 2 6
0 8 2 1
1
end_operator
begin_operator
leave p0 slow1-0 n12 n1 n0
1
5 2
2
0 0 2 7
0 8 1 0
1
end_operator
begin_operator
leave p0 slow1-0 n12 n2 n1
1
5 2
2
0 0 2 7
0 8 2 1
1
end_operator
begin_operator
leave p0 slow1-0 n6 n1 n0
1
5 3
2
0 0 2 12
0 8 1 0
1
end_operator
begin_operator
leave p0 slow1-0 n6 n2 n1
1
5 3
2
0 0 2 12
0 8 2 1
1
end_operator
begin_operator
leave p0 slow1-0 n7 n1 n0
1
5 4
2
0 0 2 13
0 8 1 0
1
end_operator
begin_operator
leave p0 slow1-0 n7 n2 n1
1
5 4
2
0 0 2 13
0 8 2 1
1
end_operator
begin_operator
leave p0 slow1-0 n8 n1 n0
1
5 5
2
0 0 2 14
0 8 1 0
1
end_operator
begin_operator
leave p0 slow1-0 n8 n2 n1
1
5 5
2
0 0 2 14
0 8 2 1
1
end_operator
begin_operator
leave p0 slow1-0 n9 n1 n0
1
5 6
2
0 0 2 15
0 8 1 0
1
end_operator
begin_operator
leave p0 slow1-0 n9 n2 n1
1
5 6
2
0 0 2 15
0 8 2 1
1
end_operator
begin_operator
leave p1 fast0 n0 n1 n0
1
3 0
2
0 1 0 3
0 6 1 0
1
end_operator
begin_operator
leave p1 fast0 n0 n2 n1
1
3 0
2
0 1 0 3
0 6 2 1
1
end_operator
begin_operator
leave p1 fast0 n0 n3 n2
1
3 0
2
0 1 0 3
0 6 3 2
1
end_operator
begin_operator
leave p1 fast0 n12 n1 n0
1
3 1
2
0 1 0 7
0 6 1 0
1
end_operator
begin_operator
leave p1 fast0 n12 n2 n1
1
3 1
2
0 1 0 7
0 6 2 1
1
end_operator
begin_operator
leave p1 fast0 n12 n3 n2
1
3 1
2
0 1 0 7
0 6 3 2
1
end_operator
begin_operator
leave p1 fast0 n3 n1 n0
1
3 2
2
0 1 0 9
0 6 1 0
1
end_operator
begin_operator
leave p1 fast0 n3 n2 n1
1
3 2
2
0 1 0 9
0 6 2 1
1
end_operator
begin_operator
leave p1 fast0 n3 n3 n2
1
3 2
2
0 1 0 9
0 6 3 2
1
end_operator
begin_operator
leave p1 fast0 n6 n1 n0
1
3 3
2
0 1 0 12
0 6 1 0
1
end_operator
begin_operator
leave p1 fast0 n6 n2 n1
1
3 3
2
0 1 0 12
0 6 2 1
1
end_operator
begin_operator
leave p1 fast0 n6 n3 n2
1
3 3
2
0 1 0 12
0 6 3 2
1
end_operator
begin_operator
leave p1 fast0 n9 n1 n0
1
3 4
2
0 1 0 15
0 6 1 0
1
end_operator
begin_operator
leave p1 fast0 n9 n2 n1
1
3 4
2
0 1 0 15
0 6 2 1
1
end_operator
begin_operator
leave p1 fast0 n9 n3 n2
1
3 4
2
0 1 0 15
0 6 3 2
1
end_operator
begin_operator
leave p1 slow0-0 n0 n1 n0
1
4 0
2
0 1 1 3
0 7 1 0
1
end_operator
begin_operator
leave p1 slow0-0 n0 n2 n1
1
4 0
2
0 1 1 3
0 7 2 1
1
end_operator
begin_operator
leave p1 slow0-0 n1 n1 n0
1
4 1
2
0 1 1 4
0 7 1 0
1
end_operator
begin_operator
leave p1 slow0-0 n1 n2 n1
1
4 1
2
0 1 1 4
0 7 2 1
1
end_operator
begin_operator
leave p1 slow0-0 n2 n1 n0
1
4 2
2
0 1 1 8
0 7 1 0
1
end_operator
begin_operator
leave p1 slow0-0 n2 n2 n1
1
4 2
2
0 1 1 8
0 7 2 1
1
end_operator
begin_operator
leave p1 slow0-0 n3 n1 n0
1
4 3
2
0 1 1 9
0 7 1 0
1
end_operator
begin_operator
leave p1 slow0-0 n3 n2 n1
1
4 3
2
0 1 1 9
0 7 2 1
1
end_operator
begin_operator
leave p1 slow0-0 n4 n1 n0
1
4 4
2
0 1 1 10
0 7 1 0
1
end_operator
begin_operator
leave p1 slow0-0 n4 n2 n1
1
4 4
2
0 1 1 10
0 7 2 1
1
end_operator
begin_operator
leave p1 slow0-0 n5 n1 n0
1
4 5
2
0 1 1 11
0 7 1 0
1
end_operator
begin_operator
leave p1 slow0-0 n5 n2 n1
1
4 5
2
0 1 1 11
0 7 2 1
1
end_operator
begin_operator
leave p1 slow0-0 n6 n1 n0
1
4 6
2
0 1 1 12
0 7 1 0
1
end_operator
begin_operator
leave p1 slow0-0 n6 n2 n1
1
4 6
2
0 1 1 12
0 7 2 1
1
end_operator
begin_operator
leave p1 slow1-0 n10 n1 n0
1
5 0
2
0 1 2 5
0 8 1 0
1
end_operator
begin_operator
leave p1 slow1-0 n10 n2 n1
1
5 0
2
0 1 2 5
0 8 2 1
1
end_operator
begin_operator
leave p1 slow1-0 n11 n1 n0
1
5 1
2
0 1 2 6
0 8 1 0
1
end_operator
begin_operator
leave p1 slow1-0 n11 n2 n1
1
5 1
2
0 1 2 6
0 8 2 1
1
end_operator
begin_operator
leave p1 slow1-0 n12 n1 n0
1
5 2
2
0 1 2 7
0 8 1 0
1
end_operator
begin_operator
leave p1 slow1-0 n12 n2 n1
1
5 2
2
0 1 2 7
0 8 2 1
1
end_operator
begin_operator
leave p1 slow1-0 n6 n1 n0
1
5 3
2
0 1 2 12
0 8 1 0
1
end_operator
begin_operator
leave p1 slow1-0 n6 n2 n1
1
5 3
2
0 1 2 12
0 8 2 1
1
end_operator
begin_operator
leave p1 slow1-0 n7 n1 n0
1
5 4
2
0 1 2 13
0 8 1 0
1
end_operator
begin_operator
leave p1 slow1-0 n7 n2 n1
1
5 4
2
0 1 2 13
0 8 2 1
1
end_operator
begin_operator
leave p1 slow1-0 n8 n1 n0
1
5 5
2
0 1 2 14
0 8 1 0
1
end_operator
begin_operator
leave p1 slow1-0 n8 n2 n1
1
5 5
2
0 1 2 14
0 8 2 1
1
end_operator
begin_operator
leave p1 slow1-0 n9 n1 n0
1
5 6
2
0 1 2 15
0 8 1 0
1
end_operator
begin_operator
leave p1 slow1-0 n9 n2 n1
1
5 6
2
0 1 2 15
0 8 2 1
1
end_operator
begin_operator
leave p2 fast0 n0 n1 n0
1
3 0
2
0 2 0 3
0 6 1 0
1
end_operator
begin_operator
leave p2 fast0 n0 n2 n1
1
3 0
2
0 2 0 3
0 6 2 1
1
end_operator
begin_operator
leave p2 fast0 n0 n3 n2
1
3 0
2
0 2 0 3
0 6 3 2
1
end_operator
begin_operator
leave p2 fast0 n12 n1 n0
1
3 1
2
0 2 0 7
0 6 1 0
1
end_operator
begin_operator
leave p2 fast0 n12 n2 n1
1
3 1
2
0 2 0 7
0 6 2 1
1
end_operator
begin_operator
leave p2 fast0 n12 n3 n2
1
3 1
2
0 2 0 7
0 6 3 2
1
end_operator
begin_operator
leave p2 fast0 n3 n1 n0
1
3 2
2
0 2 0 9
0 6 1 0
1
end_operator
begin_operator
leave p2 fast0 n3 n2 n1
1
3 2
2
0 2 0 9
0 6 2 1
1
end_operator
begin_operator
leave p2 fast0 n3 n3 n2
1
3 2
2
0 2 0 9
0 6 3 2
1
end_operator
begin_operator
leave p2 fast0 n6 n1 n0
1
3 3
2
0 2 0 12
0 6 1 0
1
end_operator
begin_operator
leave p2 fast0 n6 n2 n1
1
3 3
2
0 2 0 12
0 6 2 1
1
end_operator
begin_operator
leave p2 fast0 n6 n3 n2
1
3 3
2
0 2 0 12
0 6 3 2
1
end_operator
begin_operator
leave p2 fast0 n9 n1 n0
1
3 4
2
0 2 0 15
0 6 1 0
1
end_operator
begin_operator
leave p2 fast0 n9 n2 n1
1
3 4
2
0 2 0 15
0 6 2 1
1
end_operator
begin_operator
leave p2 fast0 n9 n3 n2
1
3 4
2
0 2 0 15
0 6 3 2
1
end_operator
begin_operator
leave p2 slow0-0 n0 n1 n0
1
4 0
2
0 2 1 3
0 7 1 0
1
end_operator
begin_operator
leave p2 slow0-0 n0 n2 n1
1
4 0
2
0 2 1 3
0 7 2 1
1
end_operator
begin_operator
leave p2 slow0-0 n1 n1 n0
1
4 1
2
0 2 1 4
0 7 1 0
1
end_operator
begin_operator
leave p2 slow0-0 n1 n2 n1
1
4 1
2
0 2 1 4
0 7 2 1
1
end_operator
begin_operator
leave p2 slow0-0 n2 n1 n0
1
4 2
2
0 2 1 8
0 7 1 0
1
end_operator
begin_operator
leave p2 slow0-0 n2 n2 n1
1
4 2
2
0 2 1 8
0 7 2 1
1
end_operator
begin_operator
leave p2 slow0-0 n3 n1 n0
1
4 3
2
0 2 1 9
0 7 1 0
1
end_operator
begin_operator
leave p2 slow0-0 n3 n2 n1
1
4 3
2
0 2 1 9
0 7 2 1
1
end_operator
begin_operator
leave p2 slow0-0 n4 n1 n0
1
4 4
2
0 2 1 10
0 7 1 0
1
end_operator
begin_operator
leave p2 slow0-0 n4 n2 n1
1
4 4
2
0 2 1 10
0 7 2 1
1
end_operator
begin_operator
leave p2 slow0-0 n5 n1 n0
1
4 5
2
0 2 1 11
0 7 1 0
1
end_operator
begin_operator
leave p2 slow0-0 n5 n2 n1
1
4 5
2
0 2 1 11
0 7 2 1
1
end_operator
begin_operator
leave p2 slow0-0 n6 n1 n0
1
4 6
2
0 2 1 12
0 7 1 0
1
end_operator
begin_operator
leave p2 slow0-0 n6 n2 n1
1
4 6
2
0 2 1 12
0 7 2 1
1
end_operator
begin_operator
leave p2 slow1-0 n10 n1 n0
1
5 0
2
0 2 2 5
0 8 1 0
1
end_operator
begin_operator
leave p2 slow1-0 n10 n2 n1
1
5 0
2
0 2 2 5
0 8 2 1
1
end_operator
begin_operator
leave p2 slow1-0 n11 n1 n0
1
5 1
2
0 2 2 6
0 8 1 0
1
end_operator
begin_operator
leave p2 slow1-0 n11 n2 n1
1
5 1
2
0 2 2 6
0 8 2 1
1
end_operator
begin_operator
leave p2 slow1-0 n12 n1 n0
1
5 2
2
0 2 2 7
0 8 1 0
1
end_operator
begin_operator
leave p2 slow1-0 n12 n2 n1
1
5 2
2
0 2 2 7
0 8 2 1
1
end_operator
begin_operator
leave p2 slow1-0 n6 n1 n0
1
5 3
2
0 2 2 12
0 8 1 0
1
end_operator
begin_operator
leave p2 slow1-0 n6 n2 n1
1
5 3
2
0 2 2 12
0 8 2 1
1
end_operator
begin_operator
leave p2 slow1-0 n7 n1 n0
1
5 4
2
0 2 2 13
0 8 1 0
1
end_operator
begin_operator
leave p2 slow1-0 n7 n2 n1
1
5 4
2
0 2 2 13
0 8 2 1
1
end_operator
begin_operator
leave p2 slow1-0 n8 n1 n0
1
5 5
2
0 2 2 14
0 8 1 0
1
end_operator
begin_operator
leave p2 slow1-0 n8 n2 n1
1
5 5
2
0 2 2 14
0 8 2 1
1
end_operator
begin_operator
leave p2 slow1-0 n9 n1 n0
1
5 6
2
0 2 2 15
0 8 1 0
1
end_operator
begin_operator
leave p2 slow1-0 n9 n2 n1
1
5 6
2
0 2 2 15
0 8 2 1
1
end_operator
begin_operator
move-down-fast fast0 n12 n0
0
1
0 3 1 0
1
end_operator
begin_operator
move-down-fast fast0 n12 n3
0
1
0 3 1 2
1
end_operator
begin_operator
move-down-fast fast0 n12 n6
0
1
0 3 1 3
1
end_operator
begin_operator
move-down-fast fast0 n12 n9
0
1
0 3 1 4
1
end_operator
begin_operator
move-down-fast fast0 n3 n0
0
1
0 3 2 0
1
end_operator
begin_operator
move-down-fast fast0 n6 n0
0
1
0 3 3 0
1
end_operator
begin_operator
move-down-fast fast0 n6 n3
0
1
0 3 3 2
1
end_operator
begin_operator
move-down-fast fast0 n9 n0
0
1
0 3 4 0
1
end_operator
begin_operator
move-down-fast fast0 n9 n3
0
1
0 3 4 2
1
end_operator
begin_operator
move-down-fast fast0 n9 n6
0
1
0 3 4 3
1
end_operator
begin_operator
move-down-slow slow0-0 n1 n0
0
1
0 4 1 0
1
end_operator
begin_operator
move-down-slow slow0-0 n2 n0
0
1
0 4 2 0
1
end_operator
begin_operator
move-down-slow slow0-0 n2 n1
0
1
0 4 2 1
1
end_operator
begin_operator
move-down-slow slow0-0 n3 n0
0
1
0 4 3 0
1
end_operator
begin_operator
move-down-slow slow0-0 n3 n1
0
1
0 4 3 1
1
end_operator
begin_operator
move-down-slow slow0-0 n3 n2
0
1
0 4 3 2
1
end_operator
begin_operator
move-down-slow slow0-0 n4 n0
0
1
0 4 4 0
1
end_operator
begin_operator
move-down-slow slow0-0 n4 n1
0
1
0 4 4 1
1
end_operator
begin_operator
move-down-slow slow0-0 n4 n2
0
1
0 4 4 2
1
end_operator
begin_operator
move-down-slow slow0-0 n4 n3
0
1
0 4 4 3
1
end_operator
begin_operator
move-down-slow slow0-0 n5 n0
0
1
0 4 5 0
1
end_operator
begin_operator
move-down-slow slow0-0 n5 n1
0
1
0 4 5 1
1
end_operator
begin_operator
move-down-slow slow0-0 n5 n2
0
1
0 4 5 2
1
end_operator
begin_operator
move-down-slow slow0-0 n5 n3
0
1
0 4 5 3
1
end_operator
begin_operator
move-down-slow slow0-0 n5 n4
0
1
0 4 5 4
1
end_operator
begin_operator
move-down-slow slow0-0 n6 n0
0
1
0 4 6 0
1
end_operator
begin_operator
move-down-slow slow0-0 n6 n1
0
1
0 4 6 1
1
end_operator
begin_operator
move-down-slow slow0-0 n6 n2
0
1
0 4 6 2
1
end_operator
begin_operator
move-down-slow slow0-0 n6 n3
0
1
0 4 6 3
1
end_operator
begin_operator
move-down-slow slow0-0 n6 n4
0
1
0 4 6 4
1
end_operator
begin_operator
move-down-slow slow0-0 n6 n5
0
1
0 4 6 5
1
end_operator
begin_operator
move-down-slow slow1-0 n10 n6
0
1
0 5 0 3
1
end_operator
begin_operator
move-down-slow slow1-0 n10 n7
0
1
0 5 0 4
1
end_operator
begin_operator
move-down-slow slow1-0 n10 n8
0
1
0 5 0 5
1
end_operator
begin_operator
move-down-slow slow1-0 n10 n9
0
1
0 5 0 6
1
end_operator
begin_operator
move-down-slow slow1-0 n11 n10
0
1
0 5 1 0
1
end_operator
begin_operator
move-down-slow slow1-0 n11 n6
0
1
0 5 1 3
1
end_operator
begin_operator
move-down-slow slow1-0 n11 n7
0
1
0 5 1 4
1
end_operator
begin_operator
move-down-slow slow1-0 n11 n8
0
1
0 5 1 5
1
end_operator
begin_operator
move-down-slow slow1-0 n11 n9
0
1
0 5 1 6
1
end_operator
begin_operator
move-down-slow slow1-0 n12 n10
0
1
0 5 2 0
1
end_operator
begin_operator
move-down-slow slow1-0 n12 n11
0
1
0 5 2 1
1
end_operator
begin_operator
move-down-slow slow1-0 n12 n6
0
1
0 5 2 3
1
end_operator
begin_operator
move-down-slow slow1-0 n12 n7
0
1
0 5 2 4
1
end_operator
begin_operator
move-down-slow slow1-0 n12 n8
0
1
0 5 2 5
1
end_operator
begin_operator
move-down-slow slow1-0 n12 n9
0
1
0 5 2 6
1
end_operator
begin_operator
move-down-slow slow1-0 n7 n6
0
1
0 5 4 3
1
end_operator
begin_operator
move-down-slow slow1-0 n8 n6
0
1
0 5 5 3
1
end_operator
begin_operator
move-down-slow slow1-0 n8 n7
0
1
0 5 5 4
1
end_operator
begin_operator
move-down-slow slow1-0 n9 n6
0
1
0 5 6 3
1
end_operator
begin_operator
move-down-slow slow1-0 n9 n7
0
1
0 5 6 4
1
end_operator
begin_operator
move-down-slow slow1-0 n9 n8
0
1
0 5 6 5
1
end_operator
begin_operator
move-up-fast fast0 n0 n12
0
1
0 3 0 1
1
end_operator
begin_operator
move-up-fast fast0 n0 n3
0
1
0 3 0 2
1
end_operator
begin_operator
move-up-fast fast0 n0 n6
0
1
0 3 0 3
1
end_operator
begin_operator
move-up-fast fast0 n0 n9
0
1
0 3 0 4
1
end_operator
begin_operator
move-up-fast fast0 n3 n12
0
1
0 3 2 1
1
end_operator
begin_operator
move-up-fast fast0 n3 n6
0
1
0 3 2 3
1
end_operator
begin_operator
move-up-fast fast0 n3 n9
0
1
0 3 2 4
1
end_operator
begin_operator
move-up-fast fast0 n6 n12
0
1
0 3 3 1
1
end_operator
begin_operator
move-up-fast fast0 n6 n9
0
1
0 3 3 4
1
end_operator
begin_operator
move-up-fast fast0 n9 n12
0
1
0 3 4 1
1
end_operator
begin_operator
move-up-slow slow0-0 n0 n1
0
1
0 4 0 1
1
end_operator
begin_operator
move-up-slow slow0-0 n0 n2
0
1
0 4 0 2
1
end_operator
begin_operator
move-up-slow slow0-0 n0 n3
0
1
0 4 0 3
1
end_operator
begin_operator
move-up-slow slow0-0 n0 n4
0
1
0 4 0 4
1
end_operator
begin_operator
move-up-slow slow0-0 n0 n5
0
1
0 4 0 5
1
end_operator
begin_operator
move-up-slow slow0-0 n0 n6
0
1
0 4 0 6
1
end_operator
begin_operator
move-up-slow slow0-0 n1 n2
0
1
0 4 1 2
1
end_operator
begin_operator
move-up-slow slow0-0 n1 n3
0
1
0 4 1 3
1
end_operator
begin_operator
move-up-slow slow0-0 n1 n4
0
1
0 4 1 4
1
end_operator
begin_operator
move-up-slow slow0-0 n1 n5
0
1
0 4 1 5
1
end_operator
begin_operator
move-up-slow slow0-0 n1 n6
0
1
0 4 1 6
1
end_operator
begin_operator
move-up-slow slow0-0 n2 n3
0
1
0 4 2 3
1
end_operator
begin_operator
move-up-slow slow0-0 n2 n4
0
1
0 4 2 4
1
end_operator
begin_operator
move-up-slow slow0-0 n2 n5
0
1
0 4 2 5
1
end_operator
begin_operator
move-up-slow slow0-0 n2 n6
0
1
0 4 2 6
1
end_operator
begin_operator
move-up-slow slow0-0 n3 n4
0
1
0 4 3 4
1
end_operator
begin_operator
move-up-slow slow0-0 n3 n5
0
1
0 4 3 5
1
end_operator
begin_operator
move-up-slow slow0-0 n3 n6
0
1
0 4 3 6
1
end_operator
begin_operator
move-up-slow slow0-0 n4 n5
0
1
0 4 4 5
1
end_operator
begin_operator
move-up-slow slow0-0 n4 n6
0
1
0 4 4 6
1
end_operator
begin_operator
move-up-slow slow0-0 n5 n6
0
1
0 4 5 6
1
end_operator
begin_operator
move-up-slow slow1-0 n10 n11
0
1
0 5 0 1
1
end_operator
begin_operator
move-up-slow slow1-0 n10 n12
0
1
0 5 0 2
1
end_operator
begin_operator
move-up-slow slow1-0 n11 n12
0
1
0 5 1 2
1
end_operator
begin_operator
move-up-slow slow1-0 n6 n10
0
1
0 5 3 0
1
end_operator
begin_operator
move-up-slow slow1-0 n6 n11
0
1
0 5 3 1
1
end_operator
begin_operator
move-up-slow slow1-0 n6 n12
0
1
0 5 3 2
1
end_operator
begin_operator
move-up-slow slow1-0 n6 n7
0
1
0 5 3 4
1
end_operator
begin_operator
move-up-slow slow1-0 n6 n8
0
1
0 5 3 5
1
end_operator
begin_operator
move-up-slow slow1-0 n6 n9
0
1
0 5 3 6
1
end_operator
begin_operator
move-up-slow slow1-0 n7 n10
0
1
0 5 4 0
1
end_operator
begin_operator
move-up-slow slow1-0 n7 n11
0
1
0 5 4 1
1
end_operator
begin_operator
move-up-slow slow1-0 n7 n12
0
1
0 5 4 2
1
end_operator
begin_operator
move-up-slow slow1-0 n7 n8
0
1
0 5 4 5
1
end_operator
begin_operator
move-up-slow slow1-0 n7 n9
0
1
0 5 4 6
1
end_operator
begin_operator
move-up-slow slow1-0 n8 n10
0
1
0 5 5 0
1
end_operator
begin_operator
move-up-slow slow1-0 n8 n11
0
1
0 5 5 1
1
end_operator
begin_operator
move-up-slow slow1-0 n8 n12
0
1
0 5 5 2
1
end_operator
begin_operator
move-up-slow slow1-0 n8 n9
0
1
0 5 5 6
1
end_operator
begin_operator
move-up-slow slow1-0 n9 n10
0
1
0 5 6 0
1
end_operator
begin_operator
move-up-slow slow1-0 n9 n11
0
1
0 5 6 1
1
end_operator
begin_operator
move-up-slow slow1-0 n9 n12
0
1
0 5 6 2
1
end_operator
0
