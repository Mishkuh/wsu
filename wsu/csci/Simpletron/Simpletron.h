#ifndef SIMPLETRON_H
#define SIMPLETRON_H

#include <iostream>
#include <string>

// input/output operations
#define READ 10;
#define WRITE 11;
// load/store operations
#define LOAD 20;
#define STORE 21;
// arithmetic operations
#define ADD 30;
#define SUBTRACT 31;
#define DIVIDE 32;
#define MULTIPLY 33;
// transfer-of-control operations
#define BRANCH 40;
#define BRANCHNEG 41;
#define BRANCHZERO 42;
#define HALT 43;

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Simpletron
{
public:
	Simpletron();
	Simpletron(FILE *newInput, int newAccumulator, int newOpCode, int newOperand, int newWord, int index);
	~Simpletron();

	void read();
	void write();

	void load();
	void store();

	void add();
	void subtract();
	void divide();
	void multiply();

	// setters
	void setFile(FILE *newInput);
	void setAccumulator(int newAccumulator);
	void setOpCode(int newOpCode);
	void setOperand(int newOperand);
	void setWord(int newWord, int index);

	// getters
	FILE *getFile();
	int getAccumulator();
	int getOpCode();
	int getOperand();
	int getWord(int index);

private:
	FILE *input;
	int accumulator;
	int opCode;
	int operand;
	int word[100];
};

#endif // !SIMPLETRON