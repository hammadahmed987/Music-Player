# 🎵 C++ Music Player (Terminal-Based)

Welcome to **C++ Music Player**, a sleek and interactive command-line application built using **pure C++**, leveraging **struct-based DSA (Doubly Linked List)**. Designed to simulate a music player, it supports **MP3, MP4, WAV, and more** with a cool animated UI — all running inside your terminal! 😎🎶

---

## ✨ Features

- 🎶 Add songs to your playlist dynamically
- 📃 View a playlist
- ▶️ Play the current song
- ⏭️ Move and Play the next song
- ⏮️ Play the previous song
- 🔁 Autoplay all songs in sequence
- 🧠 File type recognition (audio/video)
- 🖥️ Stylish, colorful terminal UI (cross-platform safe)
- ♻️ Clean memory management with destructor
- ⚙️ Powered by **Doubly Linked List** (no class, just `struct`!)

---

## 🛠️ How It Works

- Every song is stored as a `struct Song` node with:
- `title`, `filepath`, `next`, and `prev`
- The app tracks a `head` and `current` pointer for the playlist.
- On selecting a song, it opens the file using windows API (ShellExecute)

---

### 🔧 Requirements:

- chcp 65001  -> Run in the terminal to set the code page to UTF-8.
- Windows OS (required for `ShellExecute`)
- Updated version of g++ compiler (MinGW / CodeBlocks / VSCode setup)
- Some media files like(MP3, MP4, WAV)

---

### 📁 Project Structure

```bash
music-player/
├── main.cpp         # Entry point with menu logic
├── functions.h      # Core functionalities (add/play/next/etc.)
├── menu-ui.h        # UI elements (colors, header, menu)
├── README.md        # You’re reading it 🙂
```

---

### 🛠 Steps to Run

1. **Clone the Repository**
```bash
git clone https://github.com/fahadkhan008/Music-Player
cd Music-Player
g++ main.cpp -o main.exe                # compile the file
./main.exe                              # run the project
C:\\Users\\YourName\\Music\\song1.mp3   # path format like that



