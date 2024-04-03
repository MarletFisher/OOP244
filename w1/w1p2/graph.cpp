#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "graph.h"

using namespace std;

namespace seneca {

    const int GRAPH_WIDTH = 65;
    void getSamples(int samples[], int noOfSamples) {
        int i;
        for (i = 0; i < noOfSamples; i++) {
            line(28);
            cout << "\\ " << (i + 1) << "/";
            printInt(noOfSamples, 2);
            cout << ":                    /";
            goBack(20);
            samples[i] = getInt(1, 1000000);
        }
    }

    void printBar(int val, int max) {
        int i;
        int barlength = GRAPH_WIDTH * val / max; // 65 * 100 / 97
        cout << "| ";
        for (i = 0; i < barlength; i++) {
            cout << "*";
        }
        cout << " ";
        printInt(val, (GRAPH_WIDTH + 6 - barlength)); // formula, 65 + 6 - numberOfStars
        cout << "|" << endl;
    }

    void printGraph(int samples[], int noOfSamples, const char* label, int* bracket) {
        int max = findMax(samples, noOfSamples);

        labelLine(GRAPH_WIDTH + 14, label); // 65 + 14, "students' marks distribution" 
        //labelLine(GRAPH_WIDTH + 10, label);
        for (int i = 0; i < noOfSamples; i++) {
            printf("%-3d ", bracket[i]);
            printBar(samples[i], max); // 100, 90, 80..., 97
        }
        //line(GRAPH_WIDTH + 10);
        line(GRAPH_WIDTH + 14);
    }

    int findMax(int samples[], int noOfSamples) {
        int max = samples[0]; 
        int i;
        for (i = 1; i < noOfSamples; i++) {
            if (max < samples[i]) max = samples[i];
        }
        return max < GRAPH_WIDTH ? GRAPH_WIDTH : max; // 97 for group1.csv
    }
}
