I sacrifice a little bit of performance to get better memory management.

## Environments

OS: Ubuntu 16.04 (PVE-LXC)

CPU: E5-2630 v3 (4 Core)

RAM: 8GB

SWAP: 4GB

## Result data:

```
Initlize (do 1000000 times).
Mem before (KB):2884
Mem after (KB):2884
Use mem (KB):0
time (s): 0
time (ms): 42
time (us): 42435
==========================
Clean and insert 1000000 items (do 100 times)
Mem before (KB):2884
Mem after (MB):33
Use mem (MB):30
time (s): 5
time (ms): 5578
time (us): 5578535
==========================
list *= 2 (do 100 times)
Mem before (MB):33
Mem after (MB):33
Use mem (MB):0
time (s): 1
time (ms): 602
time (us): 601787
==========================
list <= 1000000/2 (do 100 times)
Mem before (MB):33
Mem after (MB):63
Use mem (MB):30
time (s): 5
time (ms): 4975
time (us): 4974869
==========================
list[list <= 1000000/2] (do 100 times)
Mem before (MB):63
Mem after (MB):63
Use mem (MB):0
time (s): 11
time (ms): 11287
time (us): 11287571
==========================
list(1,0,2) == list[1:][::2] (do 100 times)
Mem before (MB):63
Mem after (MB):63
Use mem (MB):0
time (s): 4
time (ms): 3716
time (us): 3715386
==========================
list.sort(counter % 2) (do 100 times)
Mem before (MB):63
Mem after (MB):63
Use mem (B):0
time (s): 1
time (ms): 648
time (us): 647139
==========================
list.in(ListItem<size_t>(counter)) (do 100 times)
Mem before (MB):63
Mem after (MB):63
Use mem (B):0
time (s): 0
time (ms): 544
time (us): 544732
```
