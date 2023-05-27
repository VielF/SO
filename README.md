# OS

- Code provided by professor Felipe Viel to the Operating Systems class

- Only Unix-like systems

## How to run

### Change directory to the source folder

```
cd src/
```

### Compile

```
make all
```

### Run
```
./fcfs rr-schedule
```

```
./rr rr-schedule
```

```
./priority_rr rr-schedule_pri
```

### Clean

```
make clean
```

### Everything in a command

```
clear && make all && ./fcfs rr-schedule.txt && make clean
```

```
clear && make all && ./rr rr-schedule.txt && make clean
```


```
clear && make all && ./priority_rr rr-schedule_pri.txt && make clean
```
