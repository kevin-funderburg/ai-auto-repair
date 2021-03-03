# include <iostream>
#include <string>
#include <map>
#include <queue>

#define VAR_LST_SIZE 1
#define NUM_STATEMENTS 38
#define CLS_VAR_LIST_SIZE NUM_STATEMENTS * VAR_LST_SIZE


using namespace std;

class Inference_engine
{
public:
map<string, string> varlt;              // variable list
queue <string> cnvarq;                  // conclusion variable queue
string clvarlt[CLS_VAR_LIST_SIZE];      // clause variable list 
string fault;                           // fault 
string repair;                          // repair 

public:
Inference_engine() {};
bool check_instantiation(string key);
string instantiate(string key);
void print_structures(int option);
void execute_then(int snum);
bool check_rule(int snum);
void check_clauses(int snum);
bool present(string v, int snum);
};