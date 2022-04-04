    #include <iostream> 
    #include <cstdlib> 
    #include <ctime> 
    using namespace std; 
    int main() 
    { 
    	int arr[] = { 1, 4, 5 }; 
        int cont1 = 0;
        int cont2 = 0;
        int cont3 = 0;
        int cont4 = 0;
        int cont5 = 0;
    	int random; 
    	for (int i = 0; i < 5; i++) 
    	{ 
    		random = rand()%2; 

    		cout << random << " "; 
    	} 
    } 
    // int n = rand()%10;
    // if (n > 5){

    // }
    // std::cout<<n<<std::endl;
    // return 0;int n = 0;
