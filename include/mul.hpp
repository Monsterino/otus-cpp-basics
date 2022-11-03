#pragma once

#include <string>

#include "astnode.hpp"

class Mul : public ASTNode {
public:
	Mul(ASTNode *left, ASTNode *right) : ASTNode(std::string(1, '*'), left, right), val_(std::string(1, '*')) {}


	std::string value() const {
		return val_;
	}

private:
	std::string val_;
};
