
//Lab Purpose: Virus Spread Simulation Using Recursion and Iteration

#include<iomanip> // libary 
#include<cmath>
#include<iostream> // libary 

using namespace std;
int newInfectionsRecursive(int n);//funtion protype
int totalInfectedRecursive(int n);//funtion protype
int totalInfectedIterative(int n);//funtion protype



int main(){

int n; // varible of day
int total_infected_recusive ;// total varible for recursive
int total_infected_iterative; // total varible for iterative

char choice;
cout << "Virus Spread Simulation\n"; // title
cout << std::setfill('-') << std::setw(61) << "" << std::endl;// ----- lines
do{
    cout<<"Enter the number of days (n>=1): "; // prompting the user
    cin>> n;
    int total_infected_recusive = totalInfectedRecursive(n);// SAVING THE TOTAL 
    int total_infected_iterative = totalInfectedIterative(n); //SAVING THE TOTAL
    if(n>=1){ // if statemnet to check and out the results
    cout<< "Recursive Approach: Total infected individuals on " << n << " Days: " << total_infected_recusive << endl; // output the number to user
    cout<< "Iterative Approach: Total infected individuals on " << n << " Days: " << total_infected_iterative << endl; // output the number to user
    }
    std::cout << "Do you want simulate again? (y/n): "; // asking the user if they want to simulate again
    std::cin >> choice; // saving the choice 
    std::cout << std::endl;
}while(choice == 'y'|| choice == 'Y'); // if its y start again
if (choice == 'n' || 'N'){
    // if the choice is n the program ends
    std::cout << "Simulation ended. Stay safe!\n";
    std::cout << std::setfill('-') << std::setw(61) << "" << std::endl; // formating
}

return 0;
};

int newInfectionsRecursive(int n){ // code for recursive
    if(n==1){ // base case
        return 1;
    }else if(n==2){ //second base case
        return 2;
    }else{
        return newInfectionsRecursive(n - 1) + 2 * newInfectionsRecursive(n - 2); // math for the new infected
    };

};
int totalInfectedRecursive(int n){ // code for recursive total
    if(n==1){ //base case
        return 1;
    }else if(n ==2){ // second base
        return 3;
    }else{
        return totalInfectedRecursive(n - 1) + newInfectionsRecursive(n); // aadds the total
    };
};
int totalInfectedIterative(int n){ // iterative code
    int prev1 = 1 ;// I(1) // varbels for the iterative
    int prev2 = 2 ; // I(2) // bases cases
    int total = 3 ; // T(2) = 3 // total
    int currentNewInfections = 0; // total new infected
    if(n==1){ //base case
        return 1;
    }else if(n==2){ //base case
        return 3;
    }else{
        for(int i = 2; i<n; i++){ // loop to calculate the total
            currentNewInfections = prev2 + 2 * prev1; // math for the new infected
            total += currentNewInfections; //adding it to total
            prev1 = prev2; // moving the varibles 
            prev2 = currentNewInfections; // moving the varibles
        }
    };
return total;
};
