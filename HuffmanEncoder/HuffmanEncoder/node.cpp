#include "Classes.h"

node::node() : ch(' '), parent(-1), num1(-1), num2(-1), branch(false)
{};

node::node(int i) : ch(char(i)), parent(-1), num1(-1), num2(-1), branch(false)
{}; 

node::node(int a, int b) : ch(' '), parent(-1), num1(a), num2(b), branch(false)
{};

void node::setParent(int par)
{
	this->parent = par;
};

void node::setBranch(bool br)
{
	this->branch = br;
};

