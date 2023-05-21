#include <iostream>
#include <sstream>
using namespace std;

void print_board(int board[10][10] ){
    cout<<'\n';
    cout<<"Current status of the board"<<"\n";
    cout<<"-------------------------"<<'\n';
    for (int row=1; row<=9 ; row++){
        cout<<"| ";
        for (int col=1; col<=9; col++){
            if (board[row][col] == 0){
                cout<<"."<<" ";
            }
            else{
                cout<<board[row][col]<<" ";
            }
            if (col%3 == 0){
                cout<<"| ";
            }
        }
        cout<<'\n';
        if (row%3 == 0){
            cout<<"-------------------------";
            cout<<'\n';

        }
    }
}

string suffix (int n){
    if (n == 1){
        return "st";
    }
    else if (n == 2){
        return "nd";
    }
    else if (n == 3){
        return "rd";
    }
    else{
        return "th";
    }
}

void solve(int board[10][10]){

}
int main(){
    int board[10][10];
    string edit;
    int rowNum;

    for (int row=1; row<=9; row++){
        string input;
        cout<<"Please input the "<<row<<suffix(row)<<" row, seperate each number with space, for empty box please input the number zero (0)"<<'\n';
        getline(cin, input);
        istringstream iss(input);
            
        for (int col=1; col<=9; col++){
            if (!(iss >> board[row][col])) {
                cout << "Invalid input. Please try again." <<'\n';
            }
            // board[row][col] = 0;
        }
    }
    
    print_board(board);
    cout<<"Do you want to make changes with the board? [y/n]"<<'\n';
    cin >> edit;

    while (edit == "y" || edit == "Y"){
        cout<<"Which row would you like to edit?"<<'\n';
        cin >> rowNum;

        string nums;
        cout<<"Please input the "<<rowNum<<suffix(rowNum)<<" row, seperate each number with space, for empty box please input the number zero (0)"<<'\n';
        cin.ignore();
        getline(cin, nums);
        istringstream iss(nums);

        for (int col=1; col<=9; col++){
            if (!(iss >> board[rowNum][col])) {
                cout << "Invalid input. Please try again." <<'\n';
            }
        }
        print_board(board);
        cout<<"Do you want to make other changes with the board? [y/n]"<<'\n';
        cin >> edit;
    }
    cout<<"Solving the sudoku please wait..."<<'\n';


}