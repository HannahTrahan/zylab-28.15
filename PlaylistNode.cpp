#include "PlaylistNode.h"

PlaylistNode::PlaylistNode(string ID, string name, string artist, int length){
	this->uniqueID = ID;
	this->songName = name;
	this->artistName = artist;
	this->songLength = length;
	this->nextNodePtr = NULL;
}

string PlaylistNode::GetID(){
   return this->uniqueID;
}

string PlaylistNode::GetSongName(){
   return this->songName;
}

string PlaylistNode::GetArtistName(){
   return this->artistName;
}

int PlaylistNode::GetSongLength(){
   return this->songLength;
}

PlaylistNode* PlaylistNode::GetNext(){
	return this->nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
	PlaylistNode* tmpNext;
	tmpNext = this->nextNodePtr;
	this->nextNodePtr = nodePtr;
	nodePtr->nextNodePtr = tmpNext;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr){
   this->nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode(){
   cout << "Unique ID: " << this->uniqueID << endl;
   cout << "Song Name: " << this->songTitle << endl;
   cout << "Artist Name: " << this->songArtist << endl;
   cout << "Song Length (in seconds): " << this->songLength << endl;
}
