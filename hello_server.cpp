#include "gen-cpp/HelloSvc.h"
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <memory>
#include <iostream>

using namespace ::apache::thrift::server;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace example::hello;
using std::shared_ptr;
using std::make_shared;

class HelloSvcHandler : public HelloSvcIf {
public:
    virtual void get_hello(std::string& _return, const std::string& name) override {
        std::cout << "Server received: " << name << ", from client" << std::endl;
        _return = "Hello " + name;
    }
};

int main() {
    auto handler = make_shared<HelloSvcHandler>();
    auto proc = make_shared<HelloSvcProcessor>(handler);
    auto trans_svr = make_shared<TServerSocket>(9090);
    auto trans_fac = make_shared<TBufferedTransportFactory>();
    auto proto_fac = make_shared<TBinaryProtocolFactory>();
    TSimpleServer server(proc, trans_svr, trans_fac, proto_fac);
    server.serve();
    return 0;
}