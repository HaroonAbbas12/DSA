#include <iostream>
#include <string>
using namespace std;

struct Song
{
    string title;
    Song *prev;
    Song *next;
};

// Function to add a song to the end of the playlist
void addSongToEnd(Song **head, string newSong)
{
    Song *newNode = new Song();
    newNode->title = newSong;
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    Song *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Function to traverse the playlist forwards
void playForward(Song *node)
{
    if (node == NULL)
    {
        cout << "The playlist is empty." << endl;
        return;
    }

    cout << "Playing playlist forward:" << endl;
    while (node != NULL)
    {
        cout << node->title << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

// Function to traverse the playlist backwards
void playBackward(Song *node)
{
    if (node == NULL)
    {
        cout << "The playlist is empty." << endl;
        return;
    }

    while (node->next != NULL)
    {
        node = node->next;
    }

    cout << "Playing playlist backward:" << endl;
    while (node != NULL)
    {
        cout << node->title << " -> ";
        node = node->prev;
    }
    cout << "NULL" << endl;
}

// Function to delete a song from the playlist
void deleteSong(Song **head, string songTitle)
{
    if (*head == NULL)
    {
        cout << "The playlist is empty. Cannot delete." << endl;
        return;
    }

    Song *temp = *head;

    // Search for the song to delete
    while (temp != NULL && temp->title != songTitle)
    {
        temp = temp->next;
    }

    // Song not found
    if (temp == NULL)
    {
        cout << "Song not found in the playlist." << endl;
        return;
    }

    // If the song is the head (first song)
    if (*head == temp)
    {
        *head = temp->next;
    }

    // Change next only if the node to be deleted is NOT the last node
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    // Change prev only if the node to be deleted is NOT the first node
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    delete temp;
    cout << "Song '" << songTitle << "' deleted from the playlist." << endl;
}

// Main function to demonstrate the playlist functionality
int main()
{
    Song *playlist = NULL;

    // Add songs to the playlist
    addSongToEnd(&playlist, "Song 1");
    addSongToEnd(&playlist, "Song 2");
    addSongToEnd(&playlist, "Song 3");
    addSongToEnd(&playlist, "Song 4");

    // Play playlist forwards
    playForward(playlist);

    // Play playlist backwards
    playBackward(playlist);

    // Delete a song
    deleteSong(&playlist, "Song 2");

    // Play playlist forwards again after deletion
    playForward(playlist);

    return 0;
}
