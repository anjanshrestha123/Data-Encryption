/* 
	Written by Anjan Shrestha, March 2017
	Copyright (C) - All Rights Reserved
 */

#include<iostream>
#include<string.h>    // for using string library
#include<sstream>
#include<fstream>        //for using input and output file
#include<cstdlib>
#include <unistd.h>

using namespace std;       //for using cout

//function prototyping
void encryptFile(char file[50],int key);
void decryptFile(char file[50],int key);
void exitSoftware();
int stringToInt(string key);

int main()        //main function
{
     cout << "\n***********************************\n"          //welcome message
          << "***********************************\n"
          << "************WELCOME****************\n"
          << "**************TO*******************\n"
          << "*************FILE******************\n"
          << "*******ENCRYPTER/DECRYPTER*********\n"
          << "***********************************\n"
          << "***********************************\n"
          << "********************Designed-By****\n"
          << "********************Anjan Shrestha*\n"
          << "***********************************\n\n";

    //declaring variables
     char *passWord;
     int newKey=0,count=0;
     char choice;
     string key;    
     char fileName[50];
     FILE *filePointer;

     do{                        // loop for software
     cout << "Enter the password to access this software (Type quit to exit): ";
     passWord = getpass("");                 //to hide the users input
     if(strcmp(passWord,"quit")==0 )          //if statement for exitting
        {
              exitSoftware();
              return 0; 
        }
     else if(strcmp(passWord,"hacker")!=0 && count !=5)       //making password as "hacker " and maximum attempt to 5
       {
          cout << "\n***********************************\n"
                 << "***********ACCESS DENIED***********\n"
                 << "**********Invalid Password*********\n";
             printf("************Attempt %i*************\n",count+1);
           cout  << "*************Try Again*************\n"
                 << "***********************************\n\n";
        }

     count++;
     if (count == 5 && strcmp(passWord,"hacker")!=0)
       {
          cout << "\n**************************************************\n"
                 << "***********Reached Maximum Attempt--5*************\n"
                 << "***Thank you for using File Encrypter/Decrypter***\n"
                <<  "**********Designed by Anjan Shrestha**************\n"
                <<  "*******************Bye****************************\n"
                <<  "**************************************************\n\n";
            return 0;
        }

     }while(strcmp(passWord,"hacker")!=0);

     cout << "\n***********************************\n"
          << "***********ACCESS GRANTED**********\n"
          << "***********************************\n\n";

     while(1){
       cout << "\n*******************************************\n"
            <<"***********Enter 1 for Encryption**********\n"
            <<"***********Enter 2 for Decryption**********\n"
            <<"**************Enter 3 to exit**************\n"
            <<"*******************************************\n\n";

       cout << "What do you want to do? ";
       cin>> choice;

       if(choice=='1')                 //if choice is encryption
       {
          cout << "\n*************************************\n"
               << "**************Encryption*************\n"
               << "*************************************\n\n";
         cout << "Enter Key for the encryption: ";
         cin >> key;
         newKey = stringToInt(key);        //converting key to int

         cout << "Name of the file that you want to encrypt: ";
         cin >> fileName;
  
         if(filePointer = fopen(fileName, "r"))           //reading from input file
            {
               fclose(filePointer);
               encryptFile(fileName,newKey);              //calling encryption function
            }
         else 
           {
          cout << "\n***************************************\n"
               << "***********FILE NOT FOUND**************\n"
               << "*************Try Again*****************\n"       
               << "***************************************\n\n";            
           }

       }
 
       else if(choice=='2')                //if choice is decryption
       {
          cout << "\n*************************************\n"
               << "**************Decryption*************\n"
               << "*************************************\n\n";
         cout << "Enter Key for the decryption: \n";
         cin >> key;
         newKey = stringToInt(key);           //converting key to int

         cout << "Name of the file that you want to decrypt: ";
         cin >> fileName;

         if(filePointer = fopen(fileName, "r"))
            {
               fclose(filePointer);
               decryptFile(fileName,newKey);          //calling decryption function
            }
         else 
           {
          cout << "\n***************************************\n"
               << "***********FILE NOT FOUND**************\n"
               << "*************Try Again*****************\n"       
               << "***************************************\n\n";            
           }
       }
    
       else if (choice=='3')                     //if choice is exit
       {
              exitSoftware();                   //calling exit function
              return 0; 
       }
       else {                                     //if invalid choice
          cout << "\n*************************************\n"
               <<   "************Invalid Choice***********\n"
               <<   "***************Try Again*************\n"
               <<   "*************************************\n\n";
            }
    }                         //for while loop of encrpyt/decrypt prompt
}

void encryptFile(char file[50],int key)  // encryption function
{
    char charInput[10000] = "";
    char c;
    ifstream InputData(file);            //reading from the non-encrpyted file

    int i=0;
    while(!InputData.eof())             //reading input file
       {          
          InputData.get(c);
          charInput[i] = c + key;           //adding key to character
          i++;
       }
   InputData.close();

   ofstream InputDataNew(file);  
   InputDataNew << charInput;            //outputting to the file
   InputDataNew.close();

          cout << "\n*************************************\n"
               << "********Encryption Succeeded*********\n"
               << "************File saved in************\n";
           printf("************%s****************\n",file);
           cout << "*************************************\n\n";
}

void decryptFile(char file[50],int key)           //decryption function
{
    char charInput[10000] = "";
    char c;
    ifstream InputData(file);            //reading from the non-encrpyted file

    int i=0;
    while(!InputData.eof()) 
       {          
          InputData.get(c);
          charInput[i] = c - key;            //subtractin key from input character
          i++;
       }
   InputData.close();

   ofstream InputDataNew(file);  
   InputDataNew << charInput;              //outputting into the file
   InputDataNew.close();  

          cout << "\n*************************************\n"
               << "********Decryption Succeeded*********\n"
               << "************File saved in************\n";
           printf("************%s****************\n",file);
           cout << "*************************************\n\n";
}

void exitSoftware()            // to exit the program
{
           cout << "\n**************************************************\n"
            <<"***Thank you for using File Encrypter/Decrypter***\n"
            <<"**********Designed by Anjan Shrestha**************\n"
            <<"*******************Bye****************************\n"
            <<"**************************************************\n\n";

}

int stringToInt(string key)         //function to convert key to int value
{
  char newKey[50] = "";
  int newValue=0;
  strcpy(newKey, key.c_str());
  for (int i=0; i<50;i++)
     {
         newValue = newValue + newKey[i];         //adding newValue to newkey value
     }
  return newValue;               //returning newValue 
 
}