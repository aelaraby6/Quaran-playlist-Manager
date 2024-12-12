# Quran Audio Player

![UML](https://github.com/user-attachments/assets/68b3377a-1e35-4055-864d-abe21bc9cb84)


## Overview

Quran Audio Player is a cross-platform application that allows users to listen to the Quran. It supports audio playback for the entire Quran, leveraging the `irrKlang` audio library for high-quality sound. The app is designed to work on Windows, Linux, and macOS. The audio management is powered by a 2D linked list structure to handle the Surahs efficiently
, The Quran's Surahs are managed using a 2D linked list to provide efficient access and playback..

## Features

- **Cross-Platform Compatibility**: Works on Windows, Linux, and macOS.
- **Quran Audio**: Listen to the entire Quran, with seamless transitions between Surahs.
- **irrKlang Library**: Utilizes the `irrKlang` audio library for smooth audio playback.
- **Interactive Controls**:
- *b (Start Playing)*: Press b to begin playing the selected audio.
- *Left Arrow (←)*: Go to the previous audio in the playlist.
- *Right Arrow (→)*: Skip to the next audio in the playlist.
- *Up Arrow (↑)*: Pause the currently playing audio.
- *Down Arrow (↓)*: Resume the paused audio.
- *q (Stop)*: Stop the currently playing audio.
- *ESC (Exit)*: Exit the playlist player and return to the main menu.

## Requirements

- **irrKlang Library**: Required for audio playback. [irrKlang Official Website](https://www.ambiera.com/irrklang/)
- **C++ Development Environment**: Ensure your system is set up for C++ development.
- **Supported Platforms**: Windows, Linux, macOS.

## Installation & Setup

1. Clone or download the project files.
2. Install the `irrKlang` library and include it in your project.
3. Open the project in a C++ development environment (e.g., Visual Studio, Code::Blocks).
4. Build and run the application.
5. Use the **Up Arrow** to skip to the next Surah, and **Down Arrow** to go back to the previous Surah.

## How to Use

1. **Start the Application**: After running the application, it will automatically begin playing the Quran starting from the first Surah.
2. **Keyboard Navigation**:
   - **Up Arrow**: This key will skip to the next Surah in the Quran, allowing you to listen to the Quran in sequence.
   - **Down Arrow**: This key will move back to the previous Surah, so you can easily replay the last Surah.
3. **Surah Management**: The Surahs and their audio files are organized and managed using a **2D Linked List**. This structure helps in efficiently navigating and controlling the playback sequence, ensuring smooth transitions between Surahs.
   
4. **Audio Playback**: Once a Surah is selected, it will begin playing, and you can control the playback by using the arrow keys as described.
