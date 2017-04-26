I sacrifice a little bit of performance to get better memory management.

## Environments

MacBook Air (Early 2014)

## Result data:

```
Initlize (do 1000000 times).
Mem before (MB):1
Mem after (MB):1
Use mem (KB):52
time (s): 0
time (ms): 131
time (us): 131817

==========================

Clean and insert 1000000 items (do 100 times)
Mem before (MB):1
Mem after (MB):36
Use mem (MB):34
time (s): 22
time (ms): 22320
time (us): 22320330

==========================

list *= 2 (do 100 times)
Mem before (MB):36
Mem after (MB):36
Use mem (B):0
time (s): 1
time (ms): 693
time (us): 692024

==========================

list <= 1000000/2 (do 100 times)
Mem before (MB):36
Mem after (MB):69
Use mem (MB):32
time (s): 23
time (ms): 23313
time (us): 23313658

==========================

list[list <= 1000000/2] (do 100 times)
Mem before (MB):69
Mem after (MB):80
Use mem (MB):11
time (s): 45
time (ms): 44415
time (us): 44414584

==========================

list(1,0,2) same list[1:][::2] in py (do 100 times)
Mem before (MB):80
Mem after (MB):80
Use mem (B):0
time (s): 13
time (ms): 13293
time (us): 13293636

==========================

list.sort(counter % 2) (do 100 times)
Mem before (MB):80
Mem after (MB):80
Use mem (B):0
time (s): 1
time (ms): 761
time (us): 760521

==========================

list.in(ListItem<size_t>(counter)) (do 100 times)
Mem before (MB):80
Mem after (MB):80
Use mem (B):0
time (s): 0
time (ms): 545
time (us): 545218
```
