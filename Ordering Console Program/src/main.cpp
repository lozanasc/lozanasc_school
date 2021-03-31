/*
  Made by: Sean Christian Lozana
*/
#include <iostream>
#include "Clear.hpp"
#include "Shop.hpp"

Shop Cafe;

void Start(){
  clear();
  string name, pass;
  std::cin>>name>>pass;
  Cafe.Login(name, pass);
}


int main(){
  Cafe.CreateAccount(1, "asdasd", "zana", "zana");
  Start();
  return 0;
}
