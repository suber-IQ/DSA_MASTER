#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Song {
public:
    string title;
    string artist;
    int duration;

    Song(string t, string a, int d) {
        title = t;
        artist = a;
        duration = d;
    }
};

class MusicPlayer {
private:
    stack<Song> history; // history of songs played

public:
    void play(Song s) {
        cout << "Playing " << s.title << " by " << s.artist << " (" << s.duration << "s)" << endl;
        history.push(s);
    }

    void undo() {
        if (history.empty()) {
            cout << "Cannot undo, history is empty" << endl;
            return;
        }
        Song lastSong = history.top();
        cout << "Undoing " << lastSong.title << " by " << lastSong.artist << " (" << lastSong.duration << "s)" << endl;
        history.pop();
    }
};

int main() {
    Song s1("Bohemian Rhapsody", "Queen", 355);
    Song s2("Stairway to Heaven", "Led Zeppelin", 482);
    Song s3("Hotel California", "Eagles", 391);

    MusicPlayer player;

    player.play(s1);
    player.play(s2);
    player.play(s3);

    player.undo();
    player.undo();
    player.undo();
    player.undo(); // should print "Cannot undo, history is empty"

    return 0;
}
