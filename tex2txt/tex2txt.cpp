#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int LINESIZE=1000;

int main()
{
    ifstream fpath("path.txt");
    char line[LINESIZE];
    fpath.getline(line,LINESIZE);
    ifstream fin(line);
    fpath.getline(line,LINESIZE);
    string outpathStr(line);
    cout<<"Directory:\n\n  "<<outpathStr<<"\n\nwill be deleted in the process.\n\n\nPress ENTER to continue.\n";
    cin.get();
    system((string("rd /s /q \"")+outpathStr+string("\"")).c_str());
    system((string("md \"")+outpathStr+string("\"")).c_str());
    ofstream fout;
    string str,filename;
    bool flag=0;
    while(fin.getline(line,LINESIZE))
    {
        str=string(line);
        if(str.find("subsection")!=string::npos)
        {
            int l=str.find("{"),r=str.find("}");
            filename=str.substr(l+1,r-l-1);
        }
        else if(str.find("\\begin{lstlisting}")!=string::npos)
        {
            fout.open(outpathStr+"\\"+filename+".txt");
            flag=1;
        }
        else if(str.find("\\end{lstlisting}")!=string::npos)
        {
            fout.close();
            flag=0;
        }
        else if(flag) fout<<str<<endl;
    }
    return 0;
}
