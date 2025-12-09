// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> W(N);
        int p1 = 0;
        int p2 = 0;
        
        int K = 0;
        int K1 = 0;
        
	    for (int i = 0; i < N; ++i) // per ogni round fa le verifiche. il ciclo intero è una partita
		{
			// prende in input un round
            cin >> W[i];
            
            
            // assegnamento punti del round
            if(W[i] == 1)
			{ 
				p1++;
			} 
			else
			{
				p2++;
			}
			
			
			// verifica se uno dei due ha vinto un game in base ai punti totali
			if((p1 >= 4 && (p1 - p2) >= 2) || (p2 >= 4 && (p2 - p1) >= 2))
			{
				K++; // se uno ha vinto lo salva in K 
				p1 = 0;
				p2 = 0;
			}
		}
		
		K1 = K;
		K = 0;
		
		for (int j = 0; j < N; ++j) // ripete tot partite per ogni N caratteri dentro W 
		{
			//cout << j << endl;
			W.erase(W.begin(), W.begin() + 1);
			/*cout << "---------" << endl;
			for(int num : W){
				cout << num << endl; 
			}
			cout << "---------" << endl; 
			*/
			
			K = 0;
			
			for (int i = 0; i < N; ++i) // per ogni round fa le verifiche. il ciclo intero è una partita
			{
	      
	            // assegnamento punti del round
	            if(W[i] == 1)
				{ 
					p1++;
				} 
				else
				{
					p2++;
				}
				
				
				// verifica se uno dei due ha vinto un game in base ai punti totali
				if((p1 >= 4 && (p1 - p2) >= 2) || (p2 >= 4 && (p2 - p1) >= 2))
				{
					K++; // se uno ha vinto lo salva in K 
					p1 = 0;
					p2 = 0;
				}
				
		 	}
			K1 = max(K1, K);
			p1 = 0;
			p2 = 0;
		}
		
        cout << K1 << endl;
    }

    return 0;
}
