#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "square.h"
#include "cells.h"
#include "hardrods.h"
#include "histogram.h"
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <vector>
#include <array>
using namespace std;

#ifndef MC_H
#define MC_H

class MC
{
    private:
    	//data members;
        std::vector<HR> VRodlist; // the list storage the Vertical Rods;
        std::vector<HR> HRodlist; // the list storage the Horizantal Rods;
    	int r,c;
    	int length;
    	long int step;
    	double z,bepsilon; 
    	double nh,nv,dh,dv,ah,av;
        

    public:
    	MC(long int ST, int LEN,int C, int R, double Z,double E); //E stands for betaepsilon!

    	// ********* Getters********//
        vector<HR> getVRodlist();
        vector<HR> getHRodlist();
    	double getTho() const;
        double getNh() const;
        double getNv() const;
        // ******** Setters ******//
        // void setRodlist(std::vector<HR> RodL);

    	// ******** Other Functianality *******//
        void Add(Cells &s,double &prob,double &aaccp);
        void Del(Cells &s,double &prob,double &daccp, double &size);
    	void MCRUN(); 
        void Zvs_();

    	void plot(const vector<HR>& VRodlist, const vector<HR>& HRodlist);

};

#endif /* MC_H */