#include <iostream>
#include <iomanip>

using namespace std;
void print_spaces(int val)
{
    for(int i = 0; i < 11-val; i++) cout<<"      ";
}
int main()
{
    print_spaces(1);cout<<""<<setw(18)<<setfill(' ')<<" ___\n";
    print_spaces(1);cout<<""<<setw(18)<<setfill(' ')<<"/   \\\n";
    print_spaces(1);cout<<""<<setw(17)<<setfill(' ')<<"|  "<<1<<"  |\n";
    print_spaces(1);cout<<"             \\___/\n";
    print_spaces(1);cout<<"             /   \\\n";
    print_spaces(1);cout<<"         /     \\\n";
    print_spaces(1);cout<<"     /       \\\n";


    print_spaces(2);cout<<"        ___\n";
    print_spaces(2);cout<<"       /   \\\n";
    print_spaces(2);cout<<"      |  "<<1<<"  |\n";
    print_spaces(2);cout<<"       \\___/\n";
    print_spaces(2);cout<<"       /   \\\n";
    print_spaces(2);cout<<"      /     \\\n";
    print_spaces(2);cout<<"     /       \\\n";

    cout<<endl;
    return 0;
}