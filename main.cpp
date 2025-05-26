// main.cpp
#include <iostream>
#include <thread>
#include <chrono>
#include "menu-ui.h"
#include "functions.h"
#include <windows.h>

// to enable the ansi colors in terminal
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

using namespace std;

void enableVirtualTerminal() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

int main() {
    enableVirtualTerminal();

    MusicPlayer player;
    int choice;
    string title, filepath;

    startUpAnimation(); // Startup Animation
    clearScreen();      // Clear screen after startup

    do {
        clearScreen();
        printMainMenu();  // Show main menu with all fancy colors and animations
        cin >> choice;
        cin.ignore(); // clear newline

        clearScreen();

        switch (choice) {
            case 1:
                printHeader();
                cout << CYAN << "🎶 Enter song title: " << RESET;
                getline(cin, title);
                cout << CYAN << "📁 Enter file path (e.g., C:\\\\Music\\\\song.wav): " << RESET;
                getline(cin, filepath);
                player.addSong(title, filepath);
                successMessage("✅ Song Added Successfully!");
                break;

            case 2:
                printHeader();
                player.playSong();
                showNowPlaying(player.current->title); // Display now playing song along with volume and buffering animations
                break;

            case 3:
                printHeader();
                player.nextSong();
                successMessage("⏭️ Next Song Played!");
                break;

            case 4:
                printHeader();
                player.previousSong();
                successMessage("⏮️ Previous Song Played!");
                break;

            case 5:
                printHeader();
                player.viewPlaylist();
                successMessage("📜 Playlist Displayed!");
                break;

            case 6:
                printHeader();
                player.autoplay();
                successMessage("🔁 Autoplaying All Songs!");
                break;

            case 7:
                goodbyeScreen();  // Goodbye screen with animation
                break;

            default:
                errorMessage("❌ Invalid choice. Please try again.");
        }

        if (choice != 7) {
            cout << CYAN << "\nPress Enter to return to the menu...";
            cin.get();
        }

    } while (choice != 7);

    shutdownAnimation();  // Cool Shutdown Animation

    return 0;
}
