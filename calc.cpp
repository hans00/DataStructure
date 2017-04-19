#include <iostream>

class String : public std::string { public: char pop() { const char tmp = this->back();this->pop_back();return tmp; }};

inline double calculation(const char act, double n1, double n2) {
	switch (act) {
		case '+': return n1+n2;
		case '-': return n1-n2;
		case '*': return n1*n2;
		case '/': return n1/n2;
	}
}

double eval_postfix(const char* postfix) {
	size_t size = strlen(postfix);
	double* stack = new double[size];
	size_t topofstack = 0;
	for (int i=0; i<size; i++)
		if ( postfix[i] < '0' ) {
			stack[topofstack-2] = calculation( postfix[i], stack[topofstack-2], stack[topofstack-1] );
			topofstack--;
		} else {
			stack[topofstack++] = (double)(postfix[i] - '0');
		}
	return stack[topofstack-1];
}

inline uint8_t priority(const char op) {
	switch (op) {
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		default: return 0;
	}
}

void toPostfix(std::string* orig, std::string* dest) {
	String stack;
	for (char& c : *orig)
		switch (c) {
			case '(': stack.push_back('('); break;
			case ')': while (stack.back() != '(') dest->push_back(stack.pop()); stack.pop_back(); break;
			case '+': case '-': case '*': case '/': while (priority(stack.back()) >= priority(c)) dest->push_back(stack.pop()); stack.push_back(c); break;
			default: dest->push_back(c);
		}
	while (stack.length() > 0) dest->push_back(stack.pop());
}

int main() {
	std::string orig, postfix;
	std::cout << "中序式：";
	getline(std::cin, orig);
	toPostfix(&orig, &postfix);
	std::cout << std::endl << "後序式：" << postfix << std::endl;
	std::cout << "  答案：" << eval_postfix(postfix.c_str()) << std::endl;
	return 0;
}