#include <iostream>

using namespace std;


int main()
{
    char buf[4096] = "wmic PATH Win32_VideoController";
    while (true) {
        std::string result = "";
        FILE* pipe = _popen(buf, "r");
        if (!pipe) throw std::runtime_error("popen() failed!");
        try {
            while (fgets(buf, sizeof buf, pipe) != NULL) {
                result += buf;
            }
        }
        catch (...) {
            _pclose(pipe);
            throw;
        }
        _pclose(pipe);
        string search = result.c_str();
        std::string aranacak = "VMware SVGA 3D";
        size_t found = search.find(aranacak);
        if (found != string::npos)
        {
            cout << "VM Detected!!!" << endl;
            break;
        }
        else {
            cout << "VM Not Detected" << endl;
            break;
        }
    }



    system("pause");
    return 0;

}