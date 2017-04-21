I sacrifice a little bit of performance to get better memory management.

## Environments

MacBook Air (Early 2014)

## Result data:

```
Initlize (do 1000000 times).
Mem before (KB):672
Mem after (KB):712
Use mem (KB):40
time (s): 0
time (ms): 130
time (us): 130052

==========================

Clean and insert 1000000 items (do 100 times)
Mem before (KB):712
Mem after (MB):34
Use mem (MB):33
time (s): 24
time (ms): 23303
time (us): 23302968

==========================

list *= 2 (do 100 times)
Mem before (MB):34
Mem after (MB):34
Use mem (B):0
time (s): 1
time (ms): 1000
time (us): 999607

==========================

list <= 1000000/2 (do 100 times)
Mem before (MB):34
Mem after (MB):65
Use mem (MB):30
time (s): 24
time (ms): 24723
time (us): 24723972

==========================

list[list <= 1000000/2] (do 100 times)
Mem before (MB):65
Mem after (MB):70
Use mem (MB):5
time (s): 45
time (ms): 45130
time (us): 45130900

==========================

list(1,0,2) same list[1:][::2] in py (do 100 times)
Mem before (MB):70
Mem after (MB):70
Use mem (B):0
time (s): 14
time (ms): 13478
time (us): 13477830

==========================

list.sort(counter % 2) (do 100 times)
Mem before (MB):70
Mem after (MB):70
Use mem (B):0
time (s): 1
time (ms): 1076
time (us): 1076595

==========================

list.in(ListItem<size_t>(counter)) (do 100 times)
Mem before (MB):70
Mem before (MB):70
Mem after (MB):70
Use mem (B):0
time (s): 1
time (ms): 764
time (us): 763081
```
