#include "iostream"
#include <string>

using namespace std;

class PlaylistNode{
private:
   string uniqueID;
   string songName;
   string artistName;
   int songLength;
   PlaylistNode* nextNodePtr;
   
public:
   PlaylistNode() {
		uniqueID = "none";
		songName = "none";
		artistName = "none";
		songLength = 0;
		nextNodePtr = 0;
	}
	
	PlaylistNode(string ID, string name, string artist, int length);
	
	string GetID();
	
	string GetSongName();
	
	string GetArtistName();
	
	int GetSongLength();
	
	PlaylistNode* GetNext();
	
	void InsertAfter(PlaylistNode* nodePtr);
	
	void SetNext(PlaylistNode* nodePtr);
	
	void PrintPlaylistNode();
};
