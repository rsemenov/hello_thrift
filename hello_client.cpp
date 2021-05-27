#include "gen-cpp/HelloSvc.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <memory>
#include <iostream>

using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;
using namespace example::hello;
using std::shared_ptr;
using std::make_shared;

int main() {
    shared_ptr<TTransport> trans;
    trans = make_shared<TSocket>("localhost", 9090);
    trans = make_shared<TBufferedTransport>(trans);
    auto proto = make_shared<TBinaryProtocol>(trans);
    HelloSvcClient client(proto);

    try {
        trans->open();
        std::string msg;
        client.get_hello(msg, "world!");
        std::cout << msg << std::endl;
    } catch(...) {
        std::cout << "Client caught an exception" << std::endl;
    } 
    trans->close();
}
