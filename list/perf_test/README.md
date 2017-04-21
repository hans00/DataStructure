I sacrifice a little bit of performance to get better memory management.

## Environments

OS: Ubuntu 16.04 (PVE-LXC)

CPU: E5-2630 v3 (4 Core)

RAM: 8GB

SWAP: 4GB

## Result data:

```
Initlize (do 1000000 times).
Mem before (KB):3048
Mem after (KB):3048
Use mem (KB):0
time (s): 0
time (ms): 41
time (us): 41925
==========================
Clean and insert 1000000 items (do 100 times)
Mem before (KB):3048
Mem after (MB):33
Use mem (MB):30
time (s): 6
time (ms): 5535
time (us): 5534176
==========================
list *= 2 (do 100 times)
Mem before (MB):33
Mem after (MB):33
Use mem (MB):0
time (s): 0
time (ms): 615
time (us): 615704
==========================
list <= 1000000/2 (do 100 times)
Mem before (MB):33
Mem after (MB):63
Use mem (MB):30
time (s): 5
time (ms): 5047
time (us): 5047720
==========================
list[list <= 1000000/2] (do 100 times)
Mem before (MB):63
Mem after (MB):94
Use mem (MB):30
time (s): 12
time (ms): 11836
time (us): 11835917
==========================
list(1,0,2) == list[1:][::2] (do 100 times)
Mem before (MB):94
Mem after (MB):94
Use mem (MB):0
time (s): 4
time (ms): 3867
time (us): 3866158
==========================
list.sort(counter % 2) (do 100 times)
Mem before (MB):94
Mem after (MB):94
Use mem (B):0
time (s): 1
time (ms): 674
time (us): 673004
==========================
list.in(ListItem<size_t>(counter)) (do 100 times)
Mem before (MB):94
Mem after (MB):94
Use mem (B):0
time (s): 0
time (ms): 549
time (us): 549474
root@test:~/DataStructure/list/perf_test# ./perf_test
Initlize (do 1000000 times).
Mem before (KB):3048
Mem after (KB):3048
Use mem (KB):0
time (s): 0
time (ms): 42
time (us): 42076
==========================
Clean and insert 1000000 items (do 100 times)
Mem before (KB):3048
Mem after (MB):33
Use mem (MB):30
time (s): 6
time (ms): 5647
time (us): 5646414
==========================
list *= 2 (do 100 times)
Mem before (MB):33
Mem after (MB):33
Use mem (MB):0
time (s): 1
time (ms): 595
time (us): 594617
==========================
list <= 1000000/2 (do 100 times)
Mem before (MB):33
Mem after (MB):63
Use mem (MB):30
time (s): 5
time (ms): 5113
time (us): 5113838
==========================
list[list <= 1000000/2] (do 100 times)
Mem before (MB):63
Mem after (MB):94
Use mem (MB):30
time (s): 12
time (ms): 11822
time (us): 11821090
==========================
list(1,0,2) == list[1:][::2] (do 100 times)
Mem before (MB):94
Mem after (MB):94
Use mem (MB):0
time (s): 3
time (ms): 3841
time (us): 3841109
==========================
list.sort(counter % 2) (do 100 times)
Mem before (MB):94
Mem after (MB):94
Use mem (B):0
time (s): 1
time (ms): 678
time (us): 677164
==========================
list.in(ListItem<size_t>(counter)) (do 100 times)
Mem before (MB):94
Mem after (MB):94
Use mem (B):0
time (s): 1
time (ms): 544
time (us): 543210
```
