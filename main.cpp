// SGPA and CGPA Code
// ********* MADE BY :- DEVANSH RAJORIA ***********

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> Ipair;

vector<pair<int,Ipair> > Calc_gradePoints(vector<pair<string,Ipair> > marks){
    
    vector<pair<int,Ipair> > cgpa;
    vector<pair<string,Ipair> >::iterator iter;
    int grade;
    
    for(iter = marks.begin();iter != marks.end();iter++){
        if(iter->first == "O"){
            grade = 10;
        }
        else if(iter->first == "A+"){
            grade = 9;
        }
        else if(iter->first == "A"){
            grade = 8;
        }
        else if(iter->first == "B+"){
            grade = 7;
        }
        else if(iter->first == "B"){
            grade = 6;
        }
        else if(iter->first == "C"){
            grade = 5;
        }
        else if(iter->first == "P"){
            grade = 4;
        }
        else if(iter->first == "F"){
            grade = 0;
        }
        
        cgpa.push_back({grade,{iter->second.first,iter->second.second}});
    }
    return cgpa;
}

float Calc_CGPA(vector<pair<string,Ipair> > marks){
    int credit_grade_sum = 0;
    int credit_sum = 0;
    float cgpa_sum = 0.0;
    
    vector<pair<int,Ipair> > cgpa = Calc_gradePoints(marks);
    
    vector<pair<int,Ipair> >::iterator it;
    for(it = cgpa.begin();it != cgpa.end();it++){
        printf("%d,(%d,%d)\n",it->first,it->second.first,it->second.second);
    }
    
    vector<pair<int,Ipair> >::iterator iter;
    for(iter = cgpa.begin();iter != cgpa.end();iter++){
        credit_grade_sum += (iter->second.second*iter->first);
        credit_sum += iter->second.second;
    }
    
    cgpa_sum = credit_grade_sum/(1.0*credit_sum);

    return cgpa_sum;
}

int main()
{   
    vector<pair<string,pair<int,int> > > marks;   // (grade,(marks,credits))
    
    // 3rd Semester
    
    marks.push_back({"O",{100,4}});  // Applied Maths-3
    marks.push_back({"A+",{83,4}});  // Analog Electronics-1
    marks.push_back({"A",{71,4}});  // STLD
    marks.push_back({"O",{95,4}});  // EIM
    marks.push_back({"A",{67,4}});  // Data Structures
    marks.push_back({"A+",{80,4}});  // Signals and Systems
    marks.push_back({"O",{94,1}});  // Analog Electronics Lab
    marks.push_back({"A+",{89,1}});  // STLD Lab
    marks.push_back({"O",{96,1}});  // EIM Lab
    marks.push_back({"O",{94,1}});  // Data Structures Lab
    marks.push_back({"A+",{84,1}});  // Signals and Systems Lab
    
    
    //4nd Semester
    /*
    marks.push_back({"O",{90,4}}); // Applied Maths-4
    marks.push_back({"A+",{80,3}}); // Computer Architecture
    marks.push_back({"B+",{57,4}}); // Analog Electronics-2
    marks.push_back({"A+",{79,4}}); // NAS
    marks.push_back({"O",{91,3}}); // EMFT
    marks.push_back({"O",{91,4}}); // Communication Systems
    marks.push_back({"O",{97,1}}); // NCC/NSS
    marks.push_back({"O",{97,1}}); // Applied Maths Lab
    marks.push_back({"O",{92,1}}); // Analog Electronics-2 Lab
    marks.push_back({"O",{96,1}}); // Communication Systems Lab
    marks.push_back({"A+",{85,1}}); // NAS Lab
    marks.push_back({"O",{93,1}}); // Computer Architecture Lab
    */
    
    float sgpa = Calc_CGPA(marks);
    
    printf("\nYour SGPA is : %f",sgpa);
    
    // Comment the 3rd Sem while getting your 4th sem and Vice Versa
    // To Calculate CGPA = (1st sem SGPA + 2nd Sem SGPA + .. + 4th Sem SGPA)/4
	printf("\n\n");
    return 0;
}
