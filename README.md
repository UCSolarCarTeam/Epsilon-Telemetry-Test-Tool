# University of Calgary Solar Car Team Schulich Delta Telemetry Test Tool
Test tool to mock out the serial telemetry protocol defined in https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=0.

To use, create a pair of virtual com ports and connect with this program and the one that you are testing.

## Linux
You can test socat to create Virtual Serial Port doing the following procedure:

Open a terminal (let's call it Terminal 0) and execute:

```
socat -d -d pty,raw,echo=0 pty,raw,echo=0`
```

The code above returns:

```
2013/11/01 13:47:27 socat[2506] N PTY is /dev/pts/2
2013/11/01 13:47:27 socat[2506] N PTY is /dev/pts/3
2013/11/01 13:47:27 socat[2506] N starting data transfer loop with FDs [3,3] and [5,5]
```

The two ports /dev/pts/2 and /dev/pts/3 are now connected.
