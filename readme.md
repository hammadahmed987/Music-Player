# 🎧 C++ Music Player (Terminal-Based)

Welcome to the C++ Music Player, a fully functional terminal-based music player written entirely in pure C++. Designed with dynamic struct-based DSA (Doubly Linked List), it delivers an interactive and animated playlist experience—all within your terminal window! 💻🎶

## ✨ Features

- 🎵 Add Songs: Dynamically add music to your playlist.

- 📄 View Playlist: Check the list of added songs anytime.

- ▶️ Play Current Song: Instantly play the selected track.

- ⏭️ Next Song: Move forward in your playlist and play.

- ⏮️ Previous Song: Go back and play the previous track.

- 🔁 Autoplay: Play all songs in sequence automatically.

- 🧠 Format Recognition: Supports .mp3, .mp4, .wav, etc.

- 🎨 Animated UI: Colorful, stylish terminal UI with cross-platform safety.

- 🧹 Memory-Safe: Destructor ensures clean memory release.

- ⚙️ DSA-based Design: Built purely with structs—no classes!

## 🧠 How It Works

Each song is stored as a Song struct containing:

- title

- filepath

- *next

- *prev

A doubly linked list manages the playlist using a head and current pointer. Songs are played using Windows ShellExecute to open media files with your default system player.

## 🔧 Requirements
- 💻 Windows OS (required for ShellExecute)

- 🌐 UTF-8 Encoding
- Run this in CMD to support special characters:

- chcp 65001

## 🛠️ Modern g++ Compiler
(MinGW / CodeBlocks / VSCode setups work great)

## 🎼 Media Files

Have your .mp3, .mp4, .wav files ready!

## 📁 Project Structure

music-player/
- ├── main.cpp         🎯 Entry point + menu logic
- ├── functions.h      🔧 Core functionalities (add/play/etc.)
- ├── menu-ui.h        🎨 Terminal UI (colors, layout)
- ├── README.md        📘 Project details (this file)

## 🚀 Steps to Run

### 1. 📦 Clone the Repository

- git clone https://github.com/your-username/music-player
- cd music-player

### 2. 🧪 Compile the Code

- g++ main.cpp -o main.exe

### 3. ▶️ Run the Music Player

- ./main.exe
  
### 4. 🎶 Start Adding Songs

- Example path format:

- C:\\Users\\YourName\\Music\\song1.mp3



Built with ❤️ using nothing but C++ and structs.

Enjoy the rhythm in your terminal! 🎼🖥️
