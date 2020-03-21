/* Author: Meha Gupta 
 * Date: 03 April 2019
 * Lab9 Assignment: Maintainence of Personal Music Library */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

//Declaration of Node structure//
typedef struct node {char *artist; 
char *songName;
char *genre;
struct node *next;
} Node;

//Declaration of functions used//
Node *insertNewSong(Node* head); //Inserts a new song in alphabetical order
Node *deleteASong(Node* head); //Deletes required song
void searchASong(Node* head); //Searches required song
void printMusicLibrary(Node* head); //Prints the music library
Node *deleteAllMusic(Node *head); //Deletes library and quits 
void inputStringFromUser(char *prompt, char *s, int arraySize); //asks and reads user input
void songNameDuplicate(char *songName); //checks if the song exists in the library
void songNameFound(char *songName); //prints message when a song is found after search
void songNameNotFound(char *songName); //prints message when a song is found
void songNameDeleted(char *songName); //prints message when a song is deleted
void artistFound(char *artist); //prints message when artist is found
void artistNotFound(char *artist); //prints message when artist is not found
void printMusicLibraryEmpty(void); //prints message when music library is empty
void printMusicLibraryTitle(void); //prints title for music library

const int MAX_LENGTH = 1024; //Maximum letters in input

int main(int argc, char **argv)
{
    char response; 
    char input[MAX_LENGTH+1]; //stores user input command
    Node *head=NULL;
    printf("Personal Music Library.\n\n");
    printf("Commands are I (insert), D (delete), S (search by song name), P (print), Q (quit).\n\n");
    do {
        inputStringFromUser("Command",input,MAX_LENGTH); //calling function to ask and read user input
        response=input[0]; //user input
        if (response=='I'){ //Inserting a new song
            head=insertNewSong(head);
        }
        else if (response=='D'){ //Deleting a particular song by calling appropriate function
            head=deleteASong(head);
        }
        else if (response=='S'){ //Searching a song by song name by calling appropriate function
            searchASong(head);
        }
        else if (response=='P'){ //Printing music library by calling appropriate function 
            printMusicLibrary(head);
        }
        else if (response=='Q'){ //Quitting and freeing allocated memory space by calling appropriate function
            head=deleteAllMusic(head);
        }
        else {
            printf("Invalid Command.\n"); 
        }
    }
    while (response!='Q');
	return 0;
}

//To insert new song
Node *insertNewSong(Node* head){
    bool isStringEqual=false; //keeps record of similar songs- starting with false to ensure entry into loop
    
    //Creating a new node
    Node *newNode=(Node *)malloc((MAX_LENGTH+1)*sizeof(Node));
    char *songsName=(char *)malloc((MAX_LENGTH+1)*sizeof(char));
    char *artistName=(char *)malloc((MAX_LENGTH+1)*sizeof(char));
    char *genreName=(char *)malloc((MAX_LENGTH+1)*sizeof(char));
    //assigning appropriate values by calling function to ask for user input
    inputStringFromUser("Song name",songsName,MAX_LENGTH);
    inputStringFromUser("Artist",artistName,MAX_LENGTH);
    inputStringFromUser("Genre",genreName,MAX_LENGTH);
    printf("\n");
    newNode->songName=songsName;
    newNode->artist=artistName;
    newNode->genre=genreName;
    newNode->next=NULL;
    
    //Inserting song at appropriate position (alphabetical order)
    if (head==NULL){ //When music library is empty, new song is inserted at the head
        return newNode;
    }
    else if (strcmp(head->songName,newNode->songName) > 0){ //When new song is to be entered before existing song at the head 
        newNode->next=head;
        head=newNode;
        return head;
    }
    else if (strcmp(head->songName,newNode->songName)==0){ //When entered song is same as existing song at the head
        songNameDuplicate(songsName);
        free(newNode->songName);
        free(newNode->artist);
        free(newNode->genre);
        free(newNode);
        return head;
    }
    else {
        Node *current=head;
        //Going through the entries of the music library- checking if entered song already exists or if it is to be placed before some entry
        while (!isStringEqual && current->next != NULL && (strcmp(current->next->songName,newNode->songName)<=0)){
            if (strcmp(current->next->songName,newNode->songName)==0){ //When entered song is the same as an existing one
                isStringEqual=true;
            }
            current=current->next;
        }
        if (isStringEqual){ //When entered song is the same as some existing song
        songNameDuplicate(songsName);
        free(newNode->songName);
        free(newNode->artist);
        free(newNode->genre);
        free(newNode);
        }
        else { //When entered song comes before a specific entry
        newNode->next=current->next;
        current->next=newNode;
        }
    }
        return head;
}

//To ask and reading user input
void inputStringFromUser(char *prompt, char *s, int arraySize) {
    int i = 0; 
    char c;
    printf("%s --> ", prompt) ; 
    while(i < arraySize && (c = getchar()) != '\n'){ //reading entered string until new line charactar is entered
            s[i++] = c; 
    }
    s[i] = '\0'; 
}

//To print message when entered song is same as an existing song
void songNameDuplicate(char *songName){
    printf("A song with the name '%s' is already in the music library.\n No new song entered.\n\n",songName);
}

//To delete a specific song
Node *deleteASong(Node *head){
        char songName[MAX_LENGTH];
        inputStringFromUser("\nEnter the name of the song to be deleted",songName,MAX_LENGTH); //getting user input
        if (head==NULL){ //If the music library is empty
            void printMusicLibraryEmpty();
            return head;
        }
        //Searching for the song using 'strcmp'
        else if(strcmp(head->songName,songName)==0){ //If entered song is same as the song at the head
            head=head->next;
            songNameDeleted(songName);
            free(head->songName);
            free(head->artist);
            free(head->genre);
            return head;
        }
        else {
            Node *current=head;
            //Going through the music library and searching for entered song
            while (current->next!=NULL && strcmp(current->next->songName,songName)!=0){ 
                current=current->next;
            }
            if (current->next==NULL){ //When song is not found
                songNameNotFound(songName);
            }
            else { //Deleting song when found
                current->next=current->next->next;
                songNameDeleted(songName);
                free(current->next->songName);
                free(current->next->artist);
                free(current->next->genre);
            }
            return head;
        }
}

//To print message when the music library is empty
void printMusicLibraryEmpty(void){
    printf("\nThe music library is empty.\n\n");
}

//To print message when a particular song is deleted
void songNameDeleted(char *songName){
    printf("\nDeleting a song with name '%s' from the music library.\n\n",songName);
}

//To print message when a particular song is not found in the list
void songNameNotFound(char *songName){
    printf("\nThe song name '%s' was not found in the music library.\n\n",songName);
}

//To search a song using 'strcmp'
void searchASong(Node *head){
    char songName[MAX_LENGTH+1];
    inputStringFromUser("\nEnter the name of the song to search for",songName,MAX_LENGTH);
    if (head==NULL){ //When library is emoty
        printMusicLibraryEmpty();
    }
    else {
        Node *current=head;
        //Going through the entire library and comparing each element with the entered song
        while(current!=NULL && (strcmp(current->songName,songName)!=0)){
            current=current->next;
        }
        if (current!=NULL){ //When entered song is found
            songNameFound(songName);
            printf("%s\n%s\n%s\n\n",current->songName,current->artist,current->genre);
        }
        else { //When entered song is not found
            songNameNotFound(songName);
        }
    }
}

//To print message when a song is found in music library
void songNameFound(char *songName){
    printf("\nThe song name '%s' was found in the music library.\n\n",songName);
}

//To print music library
void printMusicLibrary(Node *head){
    if (head==NULL){ //When library is empty
        printMusicLibraryEmpty();
    }
    //Going through library and printing each item from list
    else{
        printMusicLibraryTitle();
        Node *current=head;
        while (current!=NULL){
            printf("%s\n%s\n%s\n\n",current->songName,current->artist,current->genre);
            current=current->next;
        }
    }
}

//To delete library and quit application (using 'free')
Node *deleteAllMusic(Node  *head){
    while (head!=NULL){
        songNameDeleted(head->songName);
        free(head->songName);
        free(head->artist);
        free(head->genre);
        head=head->next;
    }
    if(head==NULL){
        printMusicLibraryEmpty();
    }
    return head;
}

//To print title of music library
void printMusicLibraryTitle(void){
    printf("\nMy Personal Music Library:\n\n");
}


