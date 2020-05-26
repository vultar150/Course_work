// header file of functions 

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "tinyxml2.h" // additional library (XML Parser)


using namespace tinyxml2;


// prototypes of functions
bool comparator(Task * task1, Task * task2);

void setTasks(XMLNode * xmlNode, 
	          map<int,Task*> & tasks, 
	          map<int, bool> & usd,
	          Processors & processors);

void setLinks(XMLNode *xmlNode, map<int,Task*> & tasks);

void setNumGraph(const int & id,  
	             map<int, Task*> & tasks, 
                 map<int, bool> & usd, 
                 const int & graphNum, 
                 vector<TaskGraph> & graphs);

void setInfoTasks(map<int, Task*> & tasks,
	              map<int, bool> & usd,
	              vector<TaskGraph> & graphs,
	              Processors & processors);

void setExcl(map<int, Task*> & tasks, 
	         Task * task, 
	         int depth);

void setExcl2(map<int, Task*> & tasks, Task * task);

void expandGraphs(vector<TaskGraph> & graphs, 
	              int & major_frame,
	              Processors & processors);

void copyGraph(vector<TaskGraph> & graphs,
               int & graphId,
               int & newGraphId,
               int & instantNum,
               Processors & processors);

void assignHigherPrioritySet(vector<TaskGraph> & graphs, 
	                         Processors & processors);

void setHp(vector<TaskGraph> & graphs,
           Task * task,
           Processors & processors);

void setProcessors(XMLNode *xmlNode, Processors & processors);

int findGCD(int a, int b);

int findLCM(vector<TaskGraph> & graphs);

void expandGraph(vector<TaskGraph> & graphs, 
	             int & graphId, 
                 int & expansionFactor,
                 Processors & processors);

void sortTasks(vector<TaskGraph> & graphs, vector<Task*> & sortedQueue);

bool checkExcl(Task * task1, 
               Task * task2, 
               const int & graphId,
               const int & simGraphId);

void computeTimeBounds(vector<TaskGraph> & graphs,
                       vector<Task*> & sortedQueue);

void minA (Task * t, bool & changed);

void maxA (Task * t, bool & changed);

void minS (Task * t, bool & changed);

void maxS (Task * t, bool & changed);

void minF (Task * t, bool & changed);

void maxF (Task * t, bool & changed);

bool checkPmtor(Task * task1, Task * task2);

void clearSetsPmtor(vector<TaskGraph> & graphs);

int getWCRT(vector<TaskGraph> & graphs, int targetTask);

void firstInitialization(vector<TaskGraph> & graphs, Processors & processors, vector<Task*> & sortedQueue);

bool computeTimeBoundsOfTask(vector<TaskGraph> & graphs, const int graphId, Processors & processors, 
	                        Task * const task, bool fstIter, bool & wasChange);

#endif // FUNCTIONS_H