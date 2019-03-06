# University of Calgary Solar Car Team Schulich Delta Telemetry Test Tool
Test tool to mock out the serial telemetry protocol defined in https://docs.google.com/spreadsheets/d/1soVLjeD9Sl7z7Z6cYMyn1fmn-cG7tx_pfFDsvgkCqMU/edit#gid=0.

To use, create a pair of virtual com ports and connect with this program and the one that you are testing.

## Linux
You can test socat to create Virtual Serial Port doing the following procedure:

Open a terminal (let's call it Terminal 0) and execute:

```
socat -d -d pty,raw,echo=0 pty,raw,echo=0
```

The code above returns:

```
2013/11/01 13:47:27 socat[2506] N PTY is /dev/pts/2
2013/11/01 13:47:27 socat[2506] N PTY is /dev/pts/3
2013/11/01 13:47:27 socat[2506] N starting data transfer loop with FDs [3,3] and [5,5]
```

The two ports /dev/pts/2 and /dev/pts/3 are now connected.

## Testing
The telemetry test tool uses googletest and googlemock,so the gmock and gtest header files need to be in your include path `/usr/local/include` or `/usr/include`.

If you do not already have the library, you will need to compile it yourself.
Meaning you need a `libgmock.a` archive file in the test directory in order to compile the tests.

To create a `libgmock.a` file in a Linux system, follow these instructions in an arbitrary dir.

1. Get the googletest and googlemock source code:
    `git clone https://github.com/google/googletest.git`

2. Go into the cloned directory:
    `cd googletest/`

3. Compile googletest:
    `g++ -std=c++11 -isystem googletest/include/ -Igoogletest -isystem googlemock/include/ -Igooglemock -pthread -c googletest/src/gtest-all.cc`

4. Compile googlemock:
    `g++ -std=c++11 -isystem googletest/include/ -Igoogletest -isystem googlemock/include/ -Igooglemock -pthread -c googlemock/src/gmock-all.cc`

5. Collect both the resulting .o files into an archive file:
    `ar -rv libgmock.a gtest-all.o gmock-all.o`

You should now have a `libgmock.a` archive file.
Create a `build/.lib` directory using `mkdir -p Location_of_your_local_Test Tool_repository/build/.lib` and then place the `libmock.a` archive file in the new `build/.lib/` directory and you should be good to go.
Use `ls -a` to show all hidden files.


## RabbitMQ Dependencies

1) Installing rabbitMQ

In order to send messages, you must have a rabbitMQ server to send the messages to.
This can be installed [here](https://www.rabbitmq.com/) or via the package manager using:

`echo 'deb http://www.rabbitmq.com/debian/ testing main' | sudo tee /etc/apt/sources.list.d/rabbitmq.list && sudo apt-get update && sudo apt-get install rabbitmq-server`

2) Installing dependencies for SimpleAmqpClient

First, boost and cmake is required to generate the libraries below, you may install these using your appropriate package manager (such as apt-get on debian).
The following are the commands that could be used on a debian based distro to install these dependencies if you do not already have them.

`sudo apt-get install cmake libboost-dev openssl libssl-dev libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev`

SimpleAmqpClient requires rabbitmq-c, which can be downloaded and compiled from the repository [alanxz/rabbitmq-c](https://github.com/alanxz/rabbitmq-c).
Start by cloning the repository from github, this is recommended to be done in the `/tmp/` directory:

`git clone https://github.com/alanxz/rabbitmq-c`

Create a build directory and enter it with the following command:

`mkdir rabbitmq-c/build && cd rabbitmq-c/build`

You can now use cmake to generate the library required by SimpleAmqpClient:

`cmake ..`

`cmake --build .`

There should now be a `.a` file in your current directory, as well as multiple `*.so*` files. Use the following commands to make them visible to SimpleAmqpClient:

`sudo cp librabbitmq/*.a /usr/local/lib/`

`sudo cp librabbitmq/*.so* /usr/local/lib/`

3) Generating SimpleAmqpClient library

SimpleAmqpClient can be downloaded and compiled from [alanxz/SimpleAmqpClient](https://github.com/alanxz/SimpleAmqpClient).
Run the following command, recommended in the `/tmp/` directory:

`git clone https://github.com/alanxz/SimpleAmqpClient`

And once again generate a build directory and navigate to it:

`mkdir SimpleAmqpClient/build && cd SimpleAmqpClient/build`

Run the following commands to generate the libraries needed by Hermes:

`cmake -DRabbitmqc_INCLUDE_DIR=../../rabbitmq-c/librabbitmq -DRabbitmqc_LIBRARY=../../rabbitmq-c/build/librabbitmq ..`

`make`

4) Including the generated SimpleAmqpClient library

The generated library needs to be included in the list of local libraries. To do this, first generate a directory for it:

`sudo mkdir /usr/local/include/SimpleAmqpClient`

Then, run the following commands to copy the library over:

`sudo cp *.so* /usr/local/lib/`

`sudo cp ../src/SimpleAmqpClient/*.h /usr/local/include/SimpleAmqpClient`

### Start Server

`sudo rabbitmq-server` can be used to start the server on Linux.

### Refresh Server

On linux to refresh the contents of the server perform the following commands:

`rabbitmqctl stop_app`

`rabbitmqctl reset`

`rabbitmqctl start_app`
