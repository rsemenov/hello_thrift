Hello world example based on Open Source Thrift.

# Generate code from IDL with Thrift
```
thrift --gen cpp ./hello.thrift
```

# Build with cmake

```
mkdir build
cd build
cmake ..
// ccmake ..
make .
// make VERBOSE=1
```

# Build directly with clang

Client
```
clang++ -o client hello_client.cpp gen-cpp/helloSvc.cpp -Wall -std=c++11 -lthrift
```

Pregenerated server
```
clang++ -o server gen-cpp/HelloSvc_server.skeleton.cpp gen-cpp/helloSvc.cpp -Wall -std=c++11 -lthrift
```

Custom server
```
clang++ -o server hello_server.cpp gen-cpp/helloSvc.cpp -Wall -std=c++11 -lthrift
```

# Other resources
https://github.com/lefticus/cpp_starter_project/blob/master/CMakeLists.txt



