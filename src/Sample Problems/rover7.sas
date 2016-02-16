begin_version
3
end_version
begin_metric
0
end_metric
30
begin_variable
var0
-1
6
Atom at(rover0, waypoint0)
Atom at(rover0, waypoint1)
Atom at(rover0, waypoint2)
Atom at(rover0, waypoint3)
Atom at(rover0, waypoint4)
Atom at(rover0, waypoint5)
end_variable
begin_variable
var1
-1
6
Atom at(rover1, waypoint0)
Atom at(rover1, waypoint1)
Atom at(rover1, waypoint2)
Atom at(rover1, waypoint3)
Atom at(rover1, waypoint4)
Atom at(rover1, waypoint5)
end_variable
begin_variable
var2
-1
6
Atom at(rover2, waypoint0)
Atom at(rover2, waypoint1)
Atom at(rover2, waypoint2)
Atom at(rover2, waypoint3)
Atom at(rover2, waypoint4)
Atom at(rover2, waypoint5)
end_variable
begin_variable
var3
-1
4
Atom at_rock_sample(waypoint2)
Atom have_rock_analysis(rover0, waypoint2)
Atom have_rock_analysis(rover1, waypoint2)
Atom have_rock_analysis(rover2, waypoint2)
end_variable
begin_variable
var4
-1
4
Atom at_rock_sample(waypoint3)
Atom have_rock_analysis(rover0, waypoint3)
Atom have_rock_analysis(rover1, waypoint3)
Atom have_rock_analysis(rover2, waypoint3)
end_variable
begin_variable
var5
-1
4
Atom at_rock_sample(waypoint4)
Atom have_rock_analysis(rover0, waypoint4)
Atom have_rock_analysis(rover1, waypoint4)
Atom have_rock_analysis(rover2, waypoint4)
end_variable
begin_variable
var6
-1
4
Atom at_rock_sample(waypoint5)
Atom have_rock_analysis(rover0, waypoint5)
Atom have_rock_analysis(rover1, waypoint5)
Atom have_rock_analysis(rover2, waypoint5)
end_variable
begin_variable
var7
-1
3
Atom at_soil_sample(waypoint1)
Atom have_soil_analysis(rover0, waypoint1)
Atom have_soil_analysis(rover2, waypoint1)
end_variable
begin_variable
var8
-1
3
Atom at_soil_sample(waypoint4)
Atom have_soil_analysis(rover0, waypoint4)
Atom have_soil_analysis(rover2, waypoint4)
end_variable
begin_variable
var9
-1
2
Atom calibrated(camera0, rover0)
NegatedAtom calibrated(camera0, rover0)
end_variable
begin_variable
var10
-1
2
Atom calibrated(camera1, rover2)
NegatedAtom calibrated(camera1, rover2)
end_variable
begin_variable
var11
-1
2
Atom communicated_image_data(objective0, colour)
NegatedAtom communicated_image_data(objective0, colour)
end_variable
begin_variable
var12
-1
2
Atom communicated_image_data(objective0, high_res)
NegatedAtom communicated_image_data(objective0, high_res)
end_variable
begin_variable
var13
-1
2
Atom communicated_image_data(objective1, colour)
NegatedAtom communicated_image_data(objective1, colour)
end_variable
begin_variable
var14
-1
2
Atom communicated_image_data(objective1, high_res)
NegatedAtom communicated_image_data(objective1, high_res)
end_variable
begin_variable
var15
-1
2
Atom communicated_rock_data(waypoint2)
NegatedAtom communicated_rock_data(waypoint2)
end_variable
begin_variable
var16
-1
2
Atom communicated_rock_data(waypoint3)
NegatedAtom communicated_rock_data(waypoint3)
end_variable
begin_variable
var17
-1
2
Atom communicated_rock_data(waypoint4)
NegatedAtom communicated_rock_data(waypoint4)
end_variable
begin_variable
var18
-1
2
Atom communicated_rock_data(waypoint5)
NegatedAtom communicated_rock_data(waypoint5)
end_variable
begin_variable
var19
-1
2
Atom communicated_soil_data(waypoint1)
NegatedAtom communicated_soil_data(waypoint1)
end_variable
begin_variable
var20
-1
2
Atom communicated_soil_data(waypoint4)
NegatedAtom communicated_soil_data(waypoint4)
end_variable
begin_variable
var21
-1
2
Atom empty(rover0store)
Atom full(rover0store)
end_variable
begin_variable
var22
-1
2
Atom empty(rover1store)
Atom full(rover1store)
end_variable
begin_variable
var23
-1
2
Atom empty(rover2store)
Atom full(rover2store)
end_variable
begin_variable
var24
-1
2
Atom have_image(rover0, objective0, colour)
NegatedAtom have_image(rover0, objective0, colour)
end_variable
begin_variable
var25
-1
2
Atom have_image(rover0, objective0, high_res)
NegatedAtom have_image(rover0, objective0, high_res)
end_variable
begin_variable
var26
-1
2
Atom have_image(rover0, objective1, colour)
NegatedAtom have_image(rover0, objective1, colour)
end_variable
begin_variable
var27
-1
2
Atom have_image(rover0, objective1, high_res)
NegatedAtom have_image(rover0, objective1, high_res)
end_variable
begin_variable
var28
-1
2
Atom have_image(rover2, objective0, high_res)
NegatedAtom have_image(rover2, objective0, high_res)
end_variable
begin_variable
var29
-1
2
Atom have_image(rover2, objective1, high_res)
NegatedAtom have_image(rover2, objective1, high_res)
end_variable
12
begin_mutex_group
6
0 0
0 1
0 2
0 3
0 4
0 5
end_mutex_group
begin_mutex_group
6
1 0
1 1
1 2
1 3
1 4
1 5
end_mutex_group
begin_mutex_group
6
2 0
2 1
2 2
2 3
2 4
2 5
end_mutex_group
begin_mutex_group
4
3 0
3 1
3 2
3 3
end_mutex_group
begin_mutex_group
4
4 0
4 1
4 2
4 3
end_mutex_group
begin_mutex_group
4
5 0
5 1
5 2
5 3
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
begin_mutex_group
2
21 0
21 1
end_mutex_group
begin_mutex_group
2
22 0
22 1
end_mutex_group
begin_mutex_group
2
23 0
23 1
end_mutex_group
begin_state
2
3
4
0
0
0
0
0
0
1
1
1
1
1
1
1
1
1
1
1
1
0
0
0
1
1
1
1
1
1
end_state
begin_goal
6
12 0
15 0
16 0
17 0
19 0
20 0
end_goal
151
begin_operator
calibrate rover0 camera0 objective0 waypoint0
1
0 0
1
0 9 -1 0
1
end_operator
begin_operator
calibrate rover0 camera0 objective0 waypoint1
1
0 1
1
0 9 -1 0
1
end_operator
begin_operator
calibrate rover0 camera0 objective0 waypoint2
1
0 2
1
0 9 -1 0
1
end_operator
begin_operator
calibrate rover0 camera0 objective0 waypoint3
1
0 3
1
0 9 -1 0
1
end_operator
begin_operator
calibrate rover0 camera0 objective0 waypoint4
1
0 4
1
0 9 -1 0
1
end_operator
begin_operator
calibrate rover2 camera1 objective1 waypoint0
1
2 0
1
0 10 -1 0
1
end_operator
begin_operator
calibrate rover2 camera1 objective1 waypoint1
1
2 1
1
0 10 -1 0
1
end_operator
begin_operator
calibrate rover2 camera1 objective1 waypoint2
1
2 2
1
0 10 -1 0
1
end_operator
begin_operator
calibrate rover2 camera1 objective1 waypoint3
1
2 3
1
0 10 -1 0
1
end_operator
begin_operator
communicate_image_data rover0 general objective0 colour waypoint0 waypoint3
2
0 0
24 0
1
0 11 -1 0
1
end_operator
begin_operator
communicate_image_data rover0 general objective0 colour waypoint2 waypoint3
2
0 2
24 0
1
0 11 -1 0
1
end_operator
begin_operator
communicate_image_data rover0 general objective0 colour waypoint4 waypoint3
2
0 4
24 0
1
0 11 -1 0
1
end_operator
begin_operator
communicate_image_data rover0 general objective0 high_res waypoint0 waypoint3
2
0 0
25 0
1
0 12 -1 0
1
end_operator
begin_operator
communicate_image_data rover0 general objective0 high_res waypoint2 waypoint3
2
0 2
25 0
1
0 12 -1 0
1
end_operator
begin_operator
communicate_image_data rover0 general objective0 high_res waypoint4 waypoint3
2
0 4
25 0
1
0 12 -1 0
1
end_operator
begin_operator
communicate_image_data rover0 general objective1 colour waypoint0 waypoint3
2
0 0
26 0
1
0 13 -1 0
1
end_operator
begin_operator
communicate_image_data rover0 general objective1 colour waypoint2 waypoint3
2
0 2
26 0
1
0 13 -1 0
1
end_operator
begin_operator
communicate_image_data rover0 general objective1 colour waypoint4 waypoint3
2
0 4
26 0
1
0 13 -1 0
1
end_operator
begin_operator
communicate_image_data rover0 general objective1 high_res waypoint0 waypoint3
2
0 0
27 0
1
0 14 -1 0
1
end_operator
begin_operator
communicate_image_data rover0 general objective1 high_res waypoint2 waypoint3
2
0 2
27 0
1
0 14 -1 0
1
end_operator
begin_operator
communicate_image_data rover0 general objective1 high_res waypoint4 waypoint3
2
0 4
27 0
1
0 14 -1 0
1
end_operator
begin_operator
communicate_image_data rover2 general objective0 high_res waypoint0 waypoint3
2
2 0
28 0
1
0 12 -1 0
1
end_operator
begin_operator
communicate_image_data rover2 general objective0 high_res waypoint2 waypoint3
2
2 2
28 0
1
0 12 -1 0
1
end_operator
begin_operator
communicate_image_data rover2 general objective0 high_res waypoint4 waypoint3
2
2 4
28 0
1
0 12 -1 0
1
end_operator
begin_operator
communicate_image_data rover2 general objective1 high_res waypoint0 waypoint3
2
2 0
29 0
1
0 14 -1 0
1
end_operator
begin_operator
communicate_image_data rover2 general objective1 high_res waypoint2 waypoint3
2
2 2
29 0
1
0 14 -1 0
1
end_operator
begin_operator
communicate_image_data rover2 general objective1 high_res waypoint4 waypoint3
2
2 4
29 0
1
0 14 -1 0
1
end_operator
begin_operator
communicate_rock_data rover0 general waypoint2 waypoint0 waypoint3
2
0 0
3 1
1
0 15 -1 0
1
end_operator
begin_operator
communicate_rock_data rover0 general waypoint2 waypoint2 waypoint3
2
0 2
3 1
1
0 15 -1 0
1
end_operator
begin_operator
communicate_rock_data rover0 general waypoint2 waypoint4 waypoint3
2
0 4
3 1
1
0 15 -1 0
1
end_operator
begin_operator
communicate_rock_data rover0 general waypoint3 waypoint0 waypoint3
2
0 0
4 1
1
0 16 -1 0
1
end_operator
begin_operator
communicate_rock_data rover0 general waypoint3 waypoint2 waypoint3
2
0 2
4 1
1
0 16 -1 0
1
end_operator
begin_operator
communicate_rock_data rover0 general waypoint3 waypoint4 waypoint3
2
0 4
4 1
1
0 16 -1 0
1
end_operator
begin_operator
communicate_rock_data rover0 general waypoint4 waypoint0 waypoint3
2
0 0
5 1
1
0 17 -1 0
1
end_operator
begin_operator
communicate_rock_data rover0 general waypoint4 waypoint2 waypoint3
2
0 2
5 1
1
0 17 -1 0
1
end_operator
begin_operator
communicate_rock_data rover0 general waypoint4 waypoint4 waypoint3
2
0 4
5 1
1
0 17 -1 0
1
end_operator
begin_operator
communicate_rock_data rover0 general waypoint5 waypoint0 waypoint3
2
0 0
6 1
1
0 18 -1 0
1
end_operator
begin_operator
communicate_rock_data rover0 general waypoint5 waypoint2 waypoint3
2
0 2
6 1
1
0 18 -1 0
1
end_operator
begin_operator
communicate_rock_data rover0 general waypoint5 waypoint4 waypoint3
2
0 4
6 1
1
0 18 -1 0
1
end_operator
begin_operator
communicate_rock_data rover1 general waypoint2 waypoint0 waypoint3
2
1 0
3 2
1
0 15 -1 0
1
end_operator
begin_operator
communicate_rock_data rover1 general waypoint2 waypoint2 waypoint3
2
1 2
3 2
1
0 15 -1 0
1
end_operator
begin_operator
communicate_rock_data rover1 general waypoint2 waypoint4 waypoint3
2
1 4
3 2
1
0 15 -1 0
1
end_operator
begin_operator
communicate_rock_data rover1 general waypoint3 waypoint0 waypoint3
2
1 0
4 2
1
0 16 -1 0
1
end_operator
begin_operator
communicate_rock_data rover1 general waypoint3 waypoint2 waypoint3
2
1 2
4 2
1
0 16 -1 0
1
end_operator
begin_operator
communicate_rock_data rover1 general waypoint3 waypoint4 waypoint3
2
1 4
4 2
1
0 16 -1 0
1
end_operator
begin_operator
communicate_rock_data rover1 general waypoint4 waypoint0 waypoint3
2
1 0
5 2
1
0 17 -1 0
1
end_operator
begin_operator
communicate_rock_data rover1 general waypoint4 waypoint2 waypoint3
2
1 2
5 2
1
0 17 -1 0
1
end_operator
begin_operator
communicate_rock_data rover1 general waypoint4 waypoint4 waypoint3
2
1 4
5 2
1
0 17 -1 0
1
end_operator
begin_operator
communicate_rock_data rover1 general waypoint5 waypoint0 waypoint3
2
1 0
6 2
1
0 18 -1 0
1
end_operator
begin_operator
communicate_rock_data rover1 general waypoint5 waypoint2 waypoint3
2
1 2
6 2
1
0 18 -1 0
1
end_operator
begin_operator
communicate_rock_data rover1 general waypoint5 waypoint4 waypoint3
2
1 4
6 2
1
0 18 -1 0
1
end_operator
begin_operator
communicate_rock_data rover2 general waypoint2 waypoint0 waypoint3
2
2 0
3 3
1
0 15 -1 0
1
end_operator
begin_operator
communicate_rock_data rover2 general waypoint2 waypoint2 waypoint3
2
2 2
3 3
1
0 15 -1 0
1
end_operator
begin_operator
communicate_rock_data rover2 general waypoint2 waypoint4 waypoint3
2
2 4
3 3
1
0 15 -1 0
1
end_operator
begin_operator
communicate_rock_data rover2 general waypoint3 waypoint0 waypoint3
2
2 0
4 3
1
0 16 -1 0
1
end_operator
begin_operator
communicate_rock_data rover2 general waypoint3 waypoint2 waypoint3
2
2 2
4 3
1
0 16 -1 0
1
end_operator
begin_operator
communicate_rock_data rover2 general waypoint3 waypoint4 waypoint3
2
2 4
4 3
1
0 16 -1 0
1
end_operator
begin_operator
communicate_rock_data rover2 general waypoint4 waypoint0 waypoint3
2
2 0
5 3
1
0 17 -1 0
1
end_operator
begin_operator
communicate_rock_data rover2 general waypoint4 waypoint2 waypoint3
2
2 2
5 3
1
0 17 -1 0
1
end_operator
begin_operator
communicate_rock_data rover2 general waypoint4 waypoint4 waypoint3
2
2 4
5 3
1
0 17 -1 0
1
end_operator
begin_operator
communicate_rock_data rover2 general waypoint5 waypoint0 waypoint3
2
2 0
6 3
1
0 18 -1 0
1
end_operator
begin_operator
communicate_rock_data rover2 general waypoint5 waypoint2 waypoint3
2
2 2
6 3
1
0 18 -1 0
1
end_operator
begin_operator
communicate_rock_data rover2 general waypoint5 waypoint4 waypoint3
2
2 4
6 3
1
0 18 -1 0
1
end_operator
begin_operator
communicate_soil_data rover0 general waypoint1 waypoint0 waypoint3
2
0 0
7 1
1
0 19 -1 0
1
end_operator
begin_operator
communicate_soil_data rover0 general waypoint1 waypoint2 waypoint3
2
0 2
7 1
1
0 19 -1 0
1
end_operator
begin_operator
communicate_soil_data rover0 general waypoint1 waypoint4 waypoint3
2
0 4
7 1
1
0 19 -1 0
1
end_operator
begin_operator
communicate_soil_data rover0 general waypoint4 waypoint0 waypoint3
2
0 0
8 1
1
0 20 -1 0
1
end_operator
begin_operator
communicate_soil_data rover0 general waypoint4 waypoint2 waypoint3
2
0 2
8 1
1
0 20 -1 0
1
end_operator
begin_operator
communicate_soil_data rover0 general waypoint4 waypoint4 waypoint3
2
0 4
8 1
1
0 20 -1 0
1
end_operator
begin_operator
communicate_soil_data rover2 general waypoint1 waypoint0 waypoint3
2
2 0
7 2
1
0 19 -1 0
1
end_operator
begin_operator
communicate_soil_data rover2 general waypoint1 waypoint2 waypoint3
2
2 2
7 2
1
0 19 -1 0
1
end_operator
begin_operator
communicate_soil_data rover2 general waypoint1 waypoint4 waypoint3
2
2 4
7 2
1
0 19 -1 0
1
end_operator
begin_operator
communicate_soil_data rover2 general waypoint4 waypoint0 waypoint3
2
2 0
8 2
1
0 20 -1 0
1
end_operator
begin_operator
communicate_soil_data rover2 general waypoint4 waypoint2 waypoint3
2
2 2
8 2
1
0 20 -1 0
1
end_operator
begin_operator
communicate_soil_data rover2 general waypoint4 waypoint4 waypoint3
2
2 4
8 2
1
0 20 -1 0
1
end_operator
begin_operator
drop rover0 rover0store
0
1
0 21 1 0
1
end_operator
begin_operator
drop rover1 rover1store
0
1
0 22 1 0
1
end_operator
begin_operator
drop rover2 rover2store
0
1
0 23 1 0
1
end_operator
begin_operator
navigate rover0 waypoint0 waypoint2
0
1
0 0 0 2
1
end_operator
begin_operator
navigate rover0 waypoint0 waypoint4
0
1
0 0 0 4
1
end_operator
begin_operator
navigate rover0 waypoint1 waypoint2
0
1
0 0 1 2
1
end_operator
begin_operator
navigate rover0 waypoint2 waypoint0
0
1
0 0 2 0
1
end_operator
begin_operator
navigate rover0 waypoint2 waypoint1
0
1
0 0 2 1
1
end_operator
begin_operator
navigate rover0 waypoint2 waypoint3
0
1
0 0 2 3
1
end_operator
begin_operator
navigate rover0 waypoint2 waypoint5
0
1
0 0 2 5
1
end_operator
begin_operator
navigate rover0 waypoint3 waypoint2
0
1
0 0 3 2
1
end_operator
begin_operator
navigate rover0 waypoint4 waypoint0
0
1
0 0 4 0
1
end_operator
begin_operator
navigate rover0 waypoint5 waypoint2
0
1
0 0 5 2
1
end_operator
begin_operator
navigate rover1 waypoint0 waypoint1
0
1
0 1 0 1
1
end_operator
begin_operator
navigate rover1 waypoint0 waypoint3
0
1
0 1 0 3
1
end_operator
begin_operator
navigate rover1 waypoint0 waypoint5
0
1
0 1 0 5
1
end_operator
begin_operator
navigate rover1 waypoint1 waypoint0
0
1
0 1 1 0
1
end_operator
begin_operator
navigate rover1 waypoint2 waypoint3
0
1
0 1 2 3
1
end_operator
begin_operator
navigate rover1 waypoint3 waypoint0
0
1
0 1 3 0
1
end_operator
begin_operator
navigate rover1 waypoint3 waypoint2
0
1
0 1 3 2
1
end_operator
begin_operator
navigate rover1 waypoint3 waypoint4
0
1
0 1 3 4
1
end_operator
begin_operator
navigate rover1 waypoint4 waypoint3
0
1
0 1 4 3
1
end_operator
begin_operator
navigate rover1 waypoint5 waypoint0
0
1
0 1 5 0
1
end_operator
begin_operator
navigate rover2 waypoint0 waypoint1
0
1
0 2 0 1
1
end_operator
begin_operator
navigate rover2 waypoint0 waypoint3
0
1
0 2 0 3
1
end_operator
begin_operator
navigate rover2 waypoint0 waypoint4
0
1
0 2 0 4
1
end_operator
begin_operator
navigate rover2 waypoint1 waypoint0
0
1
0 2 1 0
1
end_operator
begin_operator
navigate rover2 waypoint2 waypoint5
0
1
0 2 2 5
1
end_operator
begin_operator
navigate rover2 waypoint3 waypoint0
0
1
0 2 3 0
1
end_operator
begin_operator
navigate rover2 waypoint4 waypoint0
0
1
0 2 4 0
1
end_operator
begin_operator
navigate rover2 waypoint4 waypoint5
0
1
0 2 4 5
1
end_operator
begin_operator
navigate rover2 waypoint5 waypoint2
0
1
0 2 5 2
1
end_operator
begin_operator
navigate rover2 waypoint5 waypoint4
0
1
0 2 5 4
1
end_operator
begin_operator
sample_rock rover0 rover0store waypoint2
1
0 2
2
0 3 0 1
0 21 0 1
1
end_operator
begin_operator
sample_rock rover0 rover0store waypoint3
1
0 3
2
0 4 0 1
0 21 0 1
1
end_operator
begin_operator
sample_rock rover0 rover0store waypoint4
1
0 4
2
0 5 0 1
0 21 0 1
1
end_operator
begin_operator
sample_rock rover0 rover0store waypoint5
1
0 5
2
0 6 0 1
0 21 0 1
1
end_operator
begin_operator
sample_rock rover1 rover1store waypoint2
1
1 2
2
0 3 0 2
0 22 0 1
1
end_operator
begin_operator
sample_rock rover1 rover1store waypoint3
1
1 3
2
0 4 0 2
0 22 0 1
1
end_operator
begin_operator
sample_rock rover1 rover1store waypoint4
1
1 4
2
0 5 0 2
0 22 0 1
1
end_operator
begin_operator
sample_rock rover1 rover1store waypoint5
1
1 5
2
0 6 0 2
0 22 0 1
1
end_operator
begin_operator
sample_rock rover2 rover2store waypoint2
1
2 2
2
0 3 0 3
0 23 0 1
1
end_operator
begin_operator
sample_rock rover2 rover2store waypoint3
1
2 3
2
0 4 0 3
0 23 0 1
1
end_operator
begin_operator
sample_rock rover2 rover2store waypoint4
1
2 4
2
0 5 0 3
0 23 0 1
1
end_operator
begin_operator
sample_rock rover2 rover2store waypoint5
1
2 5
2
0 6 0 3
0 23 0 1
1
end_operator
begin_operator
sample_soil rover0 rover0store waypoint1
1
0 1
2
0 7 0 1
0 21 0 1
1
end_operator
begin_operator
sample_soil rover0 rover0store waypoint4
1
0 4
2
0 8 0 1
0 21 0 1
1
end_operator
begin_operator
sample_soil rover2 rover2store waypoint1
1
2 1
2
0 7 0 2
0 23 0 1
1
end_operator
begin_operator
sample_soil rover2 rover2store waypoint4
1
2 4
2
0 8 0 2
0 23 0 1
1
end_operator
begin_operator
take_image rover0 waypoint0 objective0 camera0 colour
1
0 0
2
0 9 0 1
0 24 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint0 objective0 camera0 high_res
1
0 0
2
0 9 0 1
0 25 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint0 objective1 camera0 colour
1
0 0
2
0 9 0 1
0 26 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint0 objective1 camera0 high_res
1
0 0
2
0 9 0 1
0 27 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint1 objective0 camera0 colour
1
0 1
2
0 9 0 1
0 24 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint1 objective0 camera0 high_res
1
0 1
2
0 9 0 1
0 25 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint1 objective1 camera0 colour
1
0 1
2
0 9 0 1
0 26 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint1 objective1 camera0 high_res
1
0 1
2
0 9 0 1
0 27 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint2 objective0 camera0 colour
1
0 2
2
0 9 0 1
0 24 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint2 objective0 camera0 high_res
1
0 2
2
0 9 0 1
0 25 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint2 objective1 camera0 colour
1
0 2
2
0 9 0 1
0 26 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint2 objective1 camera0 high_res
1
0 2
2
0 9 0 1
0 27 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint3 objective0 camera0 colour
1
0 3
2
0 9 0 1
0 24 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint3 objective0 camera0 high_res
1
0 3
2
0 9 0 1
0 25 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint3 objective1 camera0 colour
1
0 3
2
0 9 0 1
0 26 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint3 objective1 camera0 high_res
1
0 3
2
0 9 0 1
0 27 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint4 objective0 camera0 colour
1
0 4
2
0 9 0 1
0 24 -1 0
1
end_operator
begin_operator
take_image rover0 waypoint4 objective0 camera0 high_res
1
0 4
2
0 9 0 1
0 25 -1 0
1
end_operator
begin_operator
take_image rover2 waypoint0 objective0 camera1 high_res
1
2 0
2
0 10 0 1
0 28 -1 0
1
end_operator
begin_operator
take_image rover2 waypoint0 objective1 camera1 high_res
1
2 0
2
0 10 0 1
0 29 -1 0
1
end_operator
begin_operator
take_image rover2 waypoint1 objective0 camera1 high_res
1
2 1
2
0 10 0 1
0 28 -1 0
1
end_operator
begin_operator
take_image rover2 waypoint1 objective1 camera1 high_res
1
2 1
2
0 10 0 1
0 29 -1 0
1
end_operator
begin_operator
take_image rover2 waypoint2 objective0 camera1 high_res
1
2 2
2
0 10 0 1
0 28 -1 0
1
end_operator
begin_operator
take_image rover2 waypoint2 objective1 camera1 high_res
1
2 2
2
0 10 0 1
0 29 -1 0
1
end_operator
begin_operator
take_image rover2 waypoint3 objective0 camera1 high_res
1
2 3
2
0 10 0 1
0 28 -1 0
1
end_operator
begin_operator
take_image rover2 waypoint3 objective1 camera1 high_res
1
2 3
2
0 10 0 1
0 29 -1 0
1
end_operator
begin_operator
take_image rover2 waypoint4 objective0 camera1 high_res
1
2 4
2
0 10 0 1
0 28 -1 0
1
end_operator
0
