#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <ctime>

#include "classes.h" 
#include "functions.h"


int main(int argc, char **argv)
{

    clock_t time;
    time = clock();

    XMLError eResult;
    vector<TaskGraph> graphs;
    map<int,Task*> tasks;
    vector<Task*> sortedQueue;
    Processors processors;
    XMLDocument xmlDocument;

    eResult = xmlDocument.LoadFile(argv[1]); // load XML file
    XMLCheckResult(eResult);

    int targetTask = strtol(argv[2], 0, 10);

//// XML parsing//////////////////////////////////////////
    XMLNode * xmlNode = xmlDocument.FirstChildElement(); // root tag
    if (xmlNode == nullptr) return XML_ERROR_FILE_READ_ERROR;

    map<int, bool> usd;
    setTasks(xmlNode, tasks, usd, processors);
    setLinks(xmlNode, tasks);
    tasks[targetTask]->_isTarget = true;


    setInfoTasks(tasks, usd, graphs, processors);

    int major_frame = tasks[targetTask]->_major_frame;
    expandGraphs(graphs, major_frame, processors);
    sortTasks(graphs, sortedQueue);
    assignHigherPrioritySet(graphs, processors);
    computeTimeBounds(graphs, sortedQueue);
    int WCRT = getWCRT(graphs, targetTask);

    time = clock() - time;

    ofstream fout("output.txt", ios::app);

    fout << endl << endl;
    fout << "WCRT = " << WCRT << endl;
    fout << "Period = " << tasks[targetTask]->_period << endl;
    fout << "Task num = " << targetTask << endl;
    fout << "Time = " << static_cast<float>(time)/CLOCKS_PER_SEC << endl;
    fout.close();

    printf("\n\n");
    printf("WCRT = %d\n", WCRT);
    printf("Period = %d\n", tasks[targetTask]->_period);
    printf("Task num = %d\n", targetTask);
    printf("Time = %f\n", static_cast<float>(time)/CLOCKS_PER_SEC);

    /*
    for (const auto & q : sortedQueue)
    {
        q->outInfo();
        cout << endl;
    }
    cout << endl << endl;
    */
    /*
    for (const auto & p : graphs) 
    { 
        p.outInfo();
    }
    printf("\n/////////////////////////////\n");
    processors.outInfo();
    */


    return 0;
}
