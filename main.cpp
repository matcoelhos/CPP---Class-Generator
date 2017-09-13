#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

void createCPP(string name)
{
    stringstream n;
    n << name << ".cpp";
    
    ofstream file;
    file.open(n.str());
    
    file << "#include \"" << name << ".h" << "\"" << endl << endl;
    file << name << "::" << name << "()" << endl << "{}" << endl << endl;
    file << name << "::" << "~" << name << "()" << endl << "{}" << endl;
    
    file.close();
    
}

void createH(string name)
{
    stringstream n;
    n << name << ".h";
    
    string s = name;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    
    ofstream file;
    file.open(n.str());
    
    file << "#ifndef " << s << "_H_INCLUDED" << endl;
    file << "#define " << s << "_H_INCLUDED" << endl << endl;
    file << "#include <iostream>" << endl << endl;  
    
    file << "using namespace std;" << endl << endl;
    
    file << "class " << name << endl << "{" << endl;
    file << "public: " << endl;
    
    file << "\t//constructor" << endl;
    file << "\t" << name << "();" << endl;
    file << "\t//destructor" << endl;
    file << "\t~" << name << "();" << endl << endl;
    
    file << "private:" << endl;
    file << "" << endl;
    file << "}" << endl;
    
    file << "#endif //" << s << "_H_INCLUDED";
    file.close();
}

int main(int argc, char* argv[])
{
    createCPP(argv[1]);
    createH(argv[1]);
}