//Hannah Trahan, github: https://github.com/HannahTrahan/zylab-28.15

#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   if(option == 'a'){
      PlaylistNode* lastNode = headNode->GetNext();
      while(lastNode!=0){
         lastNode = lastNode->GetNext();
      }
      cout << "ADD SONG" << endl;
      string title, id, artist;
      int length;
      cout << "Enter song's unique ID:" << endl;
      getline(cin, id);
      cout << "Enter song's name:" << endl;
      getline(cin, title);
      cout << "Enter artist's name:" << endl;
      getline(cin, artist);
      cout << "Enter song's length (in seconds):" << endl;
      cin >> length;
      lastNode->SetNext(new PlaylistNode(id, title, artist, length));
   }
   
   if(option == 'd'){
      string ID;
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      getline(cin, ID);
      PlaylistNode* currNode = headNode;
      while(currNode!=0){
         PlaylistNode* next = currNode->GetNext();
         if(next->GetID() == ID){
            currNode->SetNext(next->GetNext());
            cout << "'" << next->GetSongName() << "' removed." << endl;
         }
         currNode = next;
      }
   }
   
   if(option == 's'){
      string songArtist;
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name:" << endl;
      getline(cin, songArtist);
      PlaylistNode* currNode = headNode->GetNext();
      while(currNode!=0){
         if(currNode->GetArtistName() == songArtist){
            currNode->PrintPlaylistNode();
            cout << endl;
         }
         currNode = currNode->GetNext();
      }
   }
   
   if(option == 't'){
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      int sum = 0;
      PlaylistNode* currNode = headNode->GetNext();
      while(currNode!=0){
         sum += currNode->GetSongLength();
         currNode = currNode->GetNext();
      }
      cout << "Total time: " << sum << " seconds" << endl;
   }
   
   if(option == 'o'){
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      if(headNode->GetNext() == 0){
         cout << "Playlist is empty" << endl;
         return headNode;
      }
      PlaylistNode* curr = headNode->GetNext();
      int count = 1;
      while(curr != 0){
         cout << count << "." << endl;
         curr->PrintPlaylistNode();
         cout << endl;
         curr = curr->GetNext();
         count++;
      }
   }

   return headNode;
}

int main() {
   string title;
   char choice;
   PlaylistNode* headNode = new PlaylistNode();
   
   cout << "Enter playlist's title:" << endl;
   cout << endl;
   getline(cin, title);
   
   PrintMenu(title);
   cout << endl;
   cout << "Choose an option:" << endl;
   cin >> choice;
   
   while(choice != 'q'){
      ExecuteMenu(choice, title, headNode);
      PrintMenu(title);
      cout << endl;
      cout << "Choose an option:" << endl;
      cin >> choice;
   }
   
   return 0;
}

