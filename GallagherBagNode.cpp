//Jeremiah Gallagher
//C++ Spring 2017
//Monday 5:30-8:00pm
//Bag:
//This program gets a text file from the user, builds a linked-list
//from all of the words, alphabetizes them, and then outputs the list with
//the number of times each word was found in the text file.
//Referenced: http://math.hws.edu/eck/cs225/ for
//help with the solution.

#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


struct BagNode {
   string dataValue;
   int dataCount;
   BagNode *next;
};

void buildList(istream &fin, BagNode* &sortList);
void insert(BagNode* &myList, string dataValue);
void makeLower(string &str);
string inputData(istream & fin);
void printWordList(ostream &out, BagNode *list);
void printWordList( BagNode * list);

int main() {

   string inputFile, outputFile;
   ifstream fin;
   BagNode * wordsList;

   cout << "Welcome to the Bag Program. Please enter a filename containing" << endl;
   cout << "space deliniated text." << endl;

   getline(cin, inputFile);

   fin.open(inputFile.c_str());
   if (!fin) {
      cout << "That is not a valid file name" << inputFile << endl;
      exit(1);
   }
   wordsList = NULL;
   buildList(fin,wordsList);


   // Output list to user specified file. If no file, output to console
   ofstream out;

   cout << "What is the name of the output file? ";
   getline(cin, outputFile);

   out.open(outputFile.c_str());
   printWordList(out,wordsList);
   cout << "The results were written to file " << outputFile << endl;

   if (!out) {
	   cout << "No file name was entered" << endl;
	   printWordList(wordsList);
   }

   return 0;
}

//Read a  sequence of letters from an input stream.
//Any non-letter characters are skipped .
string inputData(istream &fin) {
   string dataValue;
   char ch;
   while (fin && !isalpha(fin.peek())) {
      fin.get(ch);
   }
   dataValue = "";
   while (fin && isalpha(fin.peek())) {
      fin.get(ch);
      dataValue += ch;
   }
   return dataValue;
}

// Print the data from the sorted linked list to output file.
void printWordList(ostream &out, BagNode * list) {
   while (list) {
	   if(list->dataCount == 1){
		   out << "     " << list->dataValue << endl;
	   }
       else{
		   out << "     " << list->dataValue << " (" << list->dataCount << ") " << endl;
	   }
      list = list->next;
   }
}
//Print the data from the sorted linked list to console.
void printWordList( BagNode * list) {
   while (list) {
	   if(list->dataCount == 1){
		   cout << "     " << list->dataValue << endl;
	   }
		else{
			cout << "     " << list->dataValue << " (" << list->dataCount << ") " << endl;;
		}
      list = list->next;
   }
}

//make all words lowercase
void makeLower(string &str) {
   int top = str.length();
   for (int i = 0; i < top; i++)
      str[i] = tolower(str[i]);
}

//insert a new word into linked list.  If word already exists, add to dataCount.
void insert(BagNode* &myList, string dataValue) {
   if (myList == NULL || dataValue < myList->dataValue) { //if list is empty or word belongs at front of list alphabetically
      BagNode *newNode = new BagNode;
      newNode->dataValue = dataValue;
      newNode->dataCount = 1;
      newNode->next = myList;
      myList = newNode;
   }
   else { // word belongs inside list, but not at front
      BagNode *current = myList->next;
      BagNode *previous = myList;
      while (current != NULL && dataValue > current->dataValue) {
         previous = current;
         current = current->next;
      }
      if (current != NULL && dataValue == current->dataValue) {// word already exists, so add to counter
         current->dataCount++;
      }
      else { // Insert a new node between previous and current
         BagNode *newNode = new BagNode;
         newNode->dataValue = dataValue;
         newNode->dataCount = 1;
         newNode->next = current;
         previous->next = newNode;
      }
   }
}

// Read all  "words" from  input stream.  All words converted
//to lower case,  add the words to a binary sort sortList.
void buildList(istream &fin, BagNode* &sortList) {
   string dataValue;
   dataValue = inputData(fin);
   while (dataValue != "") {
      makeLower(dataValue);
      insert(sortList,dataValue);
      dataValue = inputData(fin);
   }
}
