#include <iostream>

using namespace std;

bool eh_primo(int x){
	int divisoresQtd = 0;
    for (int i = x; i > 0; i--)
    {
        if(x%i == 0) {
            divisoresQtd++;
        }
        if(divisoresQtd > 2)
            break;
    }

    if(divisoresQtd == 2)
        return true;
    return false;

}

int main(){
	int x;

	cin>>x;

	if(eh_primo(x)){
		cout << "S" << "\n";
	}else{
		cout << "N" << "\n";
	}
}