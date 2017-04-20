Umm... C++ no auto garbage collection.

It will use much memory to run.

P.S.  I'm used up RAM and used half SWAP.

## Environments

OS: Ubuntu 16.04 (PVE-LXC)

CPU: E5-2630 v3 (4 Core)

RAM: 8GB

SWAP: 4GB

## Result data:

```
Initlize (do 1000000 times).
Mem before (KB):1640
Mem after (KB):1640
Use mem (KB):0
time (s): 0
time (ms): 36
time (us): 36980
==========================
Clean and insert 1000000 items (do 100 times)
Mem before (KB):1640
Mem after (MB):33
Use mem (MB):31
time (s): 5
time (ms): 5299
time (us): 5299567
==========================
list *= 2 (do 100 times)
Mem before (MB):33
Mem after (MB):33
Use mem (MB):0
time (s): 1
time (ms): 583
time (us): 582697
==========================
list <= 1000000/2 (do 100 times)
Mem before (MB):33
Mem after (MB):3054
Use mem (MB):3021
time (s): 4
time (ms): 4445
time (us): 4445245
==========================
list[list <= 1000000/2] (do 100 times)
Mem before (MB):3054
Mem after (MB):8191
Use mem (MB):5137
time (s): 12
time (ms): 11275
time (us): 11274244
==========================
list(1,0,2) == list[1:][::2] (do 100 times)
Mem before (MB):8191
Mem after (MB):8191
Use mem (MB):0
time (s): 5
time (ms): 5384
time (us): 5384383
==========================
list.sort(counter % 2) (do 100 times)
Mem before (MB):8191
Mem after (MB):8191
Use mem (B):0
time (s): 1
time (ms): 655
time (us): 654522
==========================
list.in(ListItem<size_t>(counter)) (do 100 times)
Mem before (MB):8191
Mem after (MB):8191
Use mem (B):0
time (s): 0
time (ms): 537
time (us): 537978
```
