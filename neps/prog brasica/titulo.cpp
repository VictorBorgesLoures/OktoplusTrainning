#include <iostream>

using namespace std;

string title(string F){
    int space = 0;
    for (int i = 0; i < F.length(); i++)
    {
        if(F[i] == ' ')
            space=1;
        else
            if(space == 1) {
                if(F[i] >= 97)
                    F[i]-= 32;
                space = 0;
            } else {
                if(F[i] < 97) 
                    F[i] += 32;
            }
        if(i == 0 && space == 0)
            F[0]-= 32;
    }
    
    return F;
}

int main(){ 
	string F;

	F = "qualquer escrita asdasdas asd asdasdasdqe12 3123 1asda sdas aqui";

	cout << title(F) << "\n";
}