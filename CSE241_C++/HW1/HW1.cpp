#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int MAX = 10; // MAX-SIZE
const int GAME_COUNT = 100; // game-count

bool uniqueSecretNum(char*,int);  //the function that checks the validity of numbers
char compare(char*); // the func that checks argv[1]
void mastermind(char*,int);// the function where the game is played and the hints are printed.
int digit(char*); // the func founds digit number
string randomSecretNumGenerator(int);//randomly generating unique number

int main(int argc, char** argv)
{
    if(argc != 3) //missing parameters
    {
        cout << "E0" << endl;
        exit(1);
    }

    srand(time(0));
  
    char chr = compare(argv[1]); // to determine whether the user will enter a number randomly or by himself

    int digitNum = digit(argv[2]); //keep the size of the second string
    
    if(chr == 'u') // if user entered secret num
    {
        if(!(uniqueSecretNum(argv[2],digitNum))) //the entered numbers are checked
        {   
            exit(1);
        }
        mastermind(argv[2],digitNum); // the information about the number and the number of digits entered for playing the game is sent to the function as a parameter
    }
    else if(chr == 'r') // if if you want to select a random unique number
    {
        if(!(uniqueSecretNum(argv[2],digitNum))) //the entered numbers are checked if entered numbers is wrong,print error and exit
        {
            cout << "E0" << endl;
            exit(1);
        }
        int randomDigit = atoi(argv[2]); //string to int
        if(randomDigit == 0 || randomDigit >= 10)// if the number of extra or missing digits is specified, print error and exit
        {
            cout << "E0" << endl;
            exit(1);
        }

        string randomSecretNumString = randomSecretNumGenerator(randomDigit); // create random unique number

        char randomSecretNum[randomDigit]; 

        for(int i = 0; i <= randomDigit; i++) // string to char array
        { 
            randomSecretNum[i] = randomSecretNumString[i];    
        }
        mastermind(randomSecretNum,randomDigit);
    }
    else //undefined parameters
    {
        cout << "E0" <<endl;
        exit(1);
    }
    return 0;
}

bool uniqueSecretNum(char* chrArr, int digitNum)
{
    
    for(int i = 0; i < digitNum; i++) //if it does not digit (0 <= N <= 9) in the input,return false
    {
        if(chrArr[i] < '0' || chrArr[i] > '9')
        {
            return false;
        }
        for(int j = i + 1; j < digitNum; j++) // if it is not unique number , return false and print error.
        {
            if(chrArr[i] == chrArr[j])
            {
                cout << "E0"<< endl;
                return false;
            }
        }
    }
    return true;
}
char compare(char* argv) // check argv[1], if input corretly return r and u (tips for using in the main func) 
{
    if(*argv == '-') 
    {
        if(*(argv+1) == 'r')
        {
            return 'r';
        }
        else if(*(argv+1) == 'u')
        {
            return 'u';
        }
        else
        {
            return 'e';
        }
    }
    else
    {
        return 'e';
    }
        
}
void mastermind(char* argv,int digitNum)
{
    char userSecretNum[MAX]; //a variable that holds the entered strings
    int gameCounter = 1; // game counter
    int userSecretNumDigit; // a variable that holds the number of digits of the entered number
    
    while(gameCounter < GAME_COUNT) // less than 100
    {
        int countExact = 0; // a variable that holds number of hint1
        int countMisplaced = 0;// a variable that holds number of hint1

        cin >> userSecretNum;

        userSecretNumDigit = digit(userSecretNum); // find size of entered number

        if(!(uniqueSecretNum(userSecretNum,userSecretNumDigit))) // if entered number is not unique number or it is wrong number, print error and exit
        {
            cout << "E2" << endl;
            exit(1);
        }
        if(userSecretNumDigit != digitNum)// if the number of digits of the entered number is missing or more
        {
            cout << "E1" << endl;
            exit(1);
        }
        
        
        for(int i = 0; i < digitNum; i++) //the count of digits of the proposed number that match in place of the secretnumber.
        {
            if(userSecretNum[i] == argv[i])
            {
                countExact++;
            }
            else
            {
                for(int j = 0; j < digitNum; j++)//the count of digits of the proposed number which do exist in the secretnumber but are not in place.
                {
                    if(userSecretNum[i] == argv[j])
                    {
                        countMisplaced++;
                    }
                }
            }
        }
        if(countExact == digitNum) // the user input perfectly matches with the secret number, print the FOUND and gamecounter
        {
            cout << "FOUND " << gameCounter << endl;
            exit(1);
        }
        cout <<  countExact << " " << countMisplaced << endl;
        gameCounter++;
    }
    cout << "FAILED" << endl; // the user failed, print failed
}
int digit(char* argv) //the function that finds the length of the entered string
{
    int count = 0; 
    while(argv[++count] != '\0')
    {
    }
    return count;
}
string randomSecretNumGenerator(int randomDigit)
{
    const char alphabet[MAX] = {'0','1','2','3','4','5','6','7','8','9'}; //the numbers to be used have been entered
    string randomSecretNum; 
    bool check = false; 

    while(!check) // the loop continues until the unique number is formed
    {
        randomSecretNum = "";
        for (int i = 0; i < randomDigit; i++) //string randomly adds an element from alphabet array to itself each time
        {     
                randomSecretNum = randomSecretNum + alphabet[rand() % (MAX-1)];
        }

        check = true;
        
        if(randomSecretNum[0] == '0') // if first elemnt is 0. it is wrong.
        {
            check = false;
        }

        for(int i = 0; i < randomDigit; i++) // if number is not unique 
        {   
            for(int j = i + 1; j < randomDigit; j++)
            {
    
                if(randomSecretNum[i] == randomSecretNum[j])
                {
                    check = false;
                }
            }
        }   
    }    
    return randomSecretNum;
}

