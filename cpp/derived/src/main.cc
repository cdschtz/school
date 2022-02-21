#include <vector>
#include <iostream>

class Client {
public:
  Client() {};
  virtual ~Client() {};
  const virtual void Greet() {std::cout << "Hi" << std::endl; return;};
protected:
  int value;
};

class SpecificClientOne: public Client {
public:
  SpecificClientOne() {
    this->value = 1;
  }
  const void Greet() {
    std::cout << "Hello from One. My value is: " << this->value << std::endl;
  }
};

class SpecificClientTwo: public Client {
public:
  SpecificClientTwo() {
    this->value = 2;
  }
  const void Greet() {
    std::cout << "Hello from Two. My value is: " << this->value << std::endl;
  }
};

class ClientManager {
public:
  ClientManager() {
    this->clients_ = {};
  };
  void CreateClients() {
    this->clients_.push_back(new SpecificClientOne());
    this->clients_.push_back(new SpecificClientTwo());
  }
  void RunClients() {
    for (auto client : this->clients_) {
      client->Greet();
    }
  }

private:
  std::vector<Client*> clients_;
};

int main() {
  ClientManager manager;
  manager.CreateClients();
  manager.RunClients();
  return 0;
}
