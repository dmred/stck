#include "stack.cpp"
#include <catch.hpp>
#include <iostream>
using namespace std;

SCENARIO("count", "[count]"){
  stack<int> s;
  s.push(1);
  REQUIRE(s.count()==1);
}

SCENARIO("push", "[push]"){
  stack<int> s;
  s.push(1);
  REQUIRE(s.count()==1);
  REQUIRE(s.pop()==0);
}

SCENARIO("top", "[top]"){
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  REQUIRE(s.pop()==2);
  REQUIRE(s.top()==3);
}
SCENARIO("operprisv", "[operprisv]"){
  stack<int> a;
  a.push(1);
  stack<int> b;
  b=a;
  REQUIRE(b.count()==a.count());
}

SCENARIO("operator==", "[op==]") {
	stack<int> a, b;
	a.push(5);
	a.push(3);
	a.push(5);
	b.push(5);
	b.push(3);
	b.push(5);
	REQUIRE(a == b);
}

SCENARIO("copy", "[copy]")
{
	stack<int> a;
	a.push(7);
	a.push(6);
	a.push(8);
	a.push(9);
	stack<int> b = a;
	REQUIRE(b == a);
}
