#pragma once

#include <iostream>
#include <string>
#include <windows.h>  // this library hold the functions to PlaySound

using namespace std;

// Define the Song structure to hold song information
struct Song {
    string title;
    string filepath;
    Song* next;
    Song* prev;
};

// Define the MusicPlayer structure with function pointers for functionality
struct MusicPlayer {
    Song* head;
    Song* current;

    // Initialize MusicPlayer with head and current pointers
    MusicPlayer() {
        head = current = nullptr;
    }

    // Function to add a song to the playlist
    void addSong(const string& title, const string& filepath) {
        Song* newSong = new Song{title, filepath, nullptr, nullptr};
        if (!head) {
            head = current = newSong;
        } else {
            Song* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newSong;
            newSong->prev = temp;
        }
        cout << GREEN << "✔ Song '" << title << "' added successfully! 🎶\n" << RESET;
    }

    // Function to view the playlist
    void viewPlaylist() {
        if (!head) {
            cout << RED << "✖ Playlist is empty. No songs to show. 🎧\n" << RESET;
            return;
        }
        Song* temp = head;
        int index = 1;
        cout << CYAN << "🎧 Playlist:\n" << RESET;
        while (temp) {
            cout << index++ << ". " << temp->title << endl;
            temp = temp->next;
        }
    }

    // Function to play the current song
    void playSong() {
        if (!current) {
            cout << RED << "❌ No song to play. Please add songs first. 🎶\n" << RESET;
            return;
        }
        cout << GREEN << "▶ Now Playing: " << current->title << " 🎵\n";

        // Show file type to enhance user experience its is an extra feature to enhance CLI so dont need to understand
    string filepath = current->filepath;
    size_t pos = filepath.find_last_of('.');
    if (pos != string::npos) {
        string extension = filepath.substr(pos + 1);
        if (extension == "mp3" || extension == "wav" || extension == "aac" || extension == "m4a") {
            cout << CYAN << "🔊 Type: Audio File (" << extension << ")\n" << RESET;
        } else if (extension == "mp4" || extension == "avi" || extension == "mov" || extension == "mkv") {
            cout << CYAN << "🎬 Type: Video File (" << extension << ")\n" << RESET;
        } else {
            cout << CYAN << "📁 Type: Unknown (" << extension << ")\n" << RESET;
        }
    } else {
        cout << CYAN << "📁 Type: Unknown\n" << RESET;
    }

        // Play the sound using Windows API
        //  it is used to play the sound file on the terminal by taking the file path 
        ShellExecute(NULL, "open", current->filepath.c_str(), NULL, NULL, SW_SHOWNORMAL);
    }

    // Function to play the next song
    void nextSong() {
        if (current && current->next) {
            current = current->next;
            playSong();
        } else {
            cout << RED << "✖ No next song available. You're at the end of the playlist. ⏳\n" << RESET;
        }
    }

    // Function to play the previous song
    void previousSong() {
        if (current && current->prev) {
            current = current->prev;
            playSong();
        } else {
            cout << RED << "✖ No previous song available. You're at the beginning of the playlist. ⏪\n" << RESET;
        }
    }

    // Function to autoplay songs in the playlist
    void autoplay() {
        if (!current) {
            cout << RED << "✖ No songs to autoplay. 🎶\n" << RESET;
            return;
        }

        Song* temp = current;
        while (temp) {
            current = temp;
            playSong();
            cout << YELLOW << "Press Enter to play the next song... 🎧" << RESET;
            cin.get(); // wait for user input to continue
            temp = temp->next;
        }
        cout << YELLOW << "✔ Autoplay finished. 🎵\n" << RESET;
    }

    // Destructor to free the dynamically allocated memory
    ~MusicPlayer() {
        Song* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
