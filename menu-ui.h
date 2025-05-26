#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// Color Codes
string RESET = "\033[0m";
string RED = "\033[31m";
string GREEN = "\033[32m";
string YELLOW = "\033[33m";
string BLUE = "\033[34m";
string MAGENTA = "\033[35m";
string CYAN = "\033[36m";
string WHITE = "\033[37m";
string BOLD = "\033[1m";

// Clear screen function
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Sleep for milliseconds
void wait(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

// Loading animation...
void loadingAnimation(string message = "Loading")
{
    cout << CYAN << "\n"
         << message;
    for (int i = 0; i < 3; ++i)
    {
        cout << ".";
        cout.flush();
        wait(400);
    }
    cout << RESET << endl;
}

// Animated Startup Logo
void startUpAnimation()
{
    clearScreen();
    string logo[] = {
        "███╗   ███╗███████╗██╗      ██████╗  ██████╗  ██╗ ███████╗ ██╗   ██╗",
        "████╗ ████║██╔════╝██║     ██╔═══██╗ ██╔══██╗ ██║ ██╔════╝ ╚██╗ ██╔╝",
        "██╔████╔██║█████╗  ██║     ██║   ██║ ██║  ██║ ██║ █████╗    ╚████╔╝ ",
        "██║╚██╔╝██║██╔══╝  ██║     ██║   ██║ ██║  ██║ ██║ ██╔══╝     ╚██╔╝  ",
        "██║ ╚═╝ ██║███████╗███████╗╚██████╔╝ ██████╔╝ ██║ ██║         ██║   ",
        "╚═╝     ╚═╝╚══════╝╚══════╝ ╚═════╝  ╚═════╝  ╚═╝ ╚═╝         ╚═╝   ",
        "                🎶 MELODIFY MUSIC PLAYER 🎶           "};

    cout << BOLD << MAGENTA;
    for (auto &line : logo)
    {
        cout << line << endl;
        wait(150); // Smooth line by line animation
    }
    cout << RESET;
    wait(500);
    loadingAnimation("Booting Up");
}

// Fancy Header
void printHeader()
{
    cout << BOLD << BLUE;
    cout << "\n============================================================\n";
    cout << "               🎵 WELCOME TO MELODY PRO PLAYER 🎵\n";
    cout << "============================================================\n";
    cout << RESET;
}

// Main Menu
void printMainMenu()
{
    printHeader();
    cout << BOLD << WHITE;
    cout << "\nSelect an Option:\n";
    cout << CYAN;
    cout << "------------------------------------------------------------\n";
    cout << " 1. ➕ Add New Song\n";
    cout << " 2. ▶️  Play Current Song\n";
    cout << " 3. ⏭️  Play Next Song\n";
    cout << " 4. ⏮️  Play Previous Song\n";
    cout << " 5. 📜 Show All Songs\n";
    cout << " 6. 🔁 Auto Play All Songs\n";
    cout << " 7. ❌ Exit\n";
    cout << "------------------------------------------------------------\n";
    cout << RESET;
    cout << BOLD << "Enter your choice: " << RESET;
}

// Fake Buffering Animation before playing song
void bufferingAnimation(string message = "Buffering")
{
    cout << YELLOW << "\n"
         << message << ": [";
    cout.flush();

    for (int i = 0; i <= 20; ++i)
    {
        cout << "█";
        cout.flush();
        wait(100); // slow loading effect
    }
    cout << "] Done!\n"
         << RESET;
    wait(500);
}

// Music Wave Animation (dancing bars)
void musicWaveAnimation(int seconds = 5)
{
    cout << CYAN << "\nMusic Waves: \n"
         << RESET;
    srand(time(0)); // random waves

    for (int i = 0; i < seconds * 5; ++i)
    {
        int bars = rand() % 20 + 1;
        for (int j = 0; j < bars; ++j)
            cout << "|";
        cout << "\n";
        cout.flush();
        wait(150); // fast wave feeling
    }
}

// Now Playing screen with Volume Animation
void showNowPlaying(string songName)
{
    bufferingAnimation(); // <-- add before playing

    cout << GREEN;
    cout << "\n==============================================\n";
    cout << "          Now Playing: 🎶 " << songName << " 🎶\n";
    cout << "==============================================\n";
    cout << RESET;

    // Fake Volume Bar
    cout << CYAN << "\nVolume: ";
    for (int i = 0; i <= 20; ++i)
    {
        cout << "|";
        cout.flush();
        wait(80);
    }
    cout << RESET << endl;

    // Music Waves Animation
    musicWaveAnimation(5); // 5 seconds
}

// Success message
void successMessage(string msg)
{
    cout << GREEN << "\n✅ " << msg << "\n"
         << RESET;
}

// Error message
void errorMessage(string msg)
{
    cout << RED << "\n❌ " << msg << "\n"
         << RESET;
}

// Info message
void infoMessage(string msg)
{
    cout << CYAN << "\nℹ️  " << msg << "\n"
         << RESET;
}

// Goodbye screen
void goodbyeScreen()
{
    cout << YELLOW << "\n👋 Thank you for using Melody Player! Goodbye!\n"
         << RESET;
}

// Cool Shutdown Animation
void shutdownAnimation()
{
    clearScreen();
    cout << BOLD << RED;
    cout << "\nShutting down Melody Player";
    cout.flush();
    for (int i = 0; i < 5; ++i)
    {
        cout << ".";
        cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    cout << "\n\n"
         << BOLD << YELLOW;
    cout << "Goodbye! See you soon! 🎶\n";
    cout << RESET;
    wait(1000);
}
