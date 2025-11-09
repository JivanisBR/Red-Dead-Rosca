# Red Dead Rosca

![Capturar](https://github.com/user-attachments/assets/ad73add0-a686-4f96-8e52-2db6d473813a)

A 2D **Old West style duel game**, with support for **2 Players and 2 Game Modes**!
Developed as a **Final Course Project (TCC)**. The project was created **from scratch** in **C++** with the **Raylib** library, aiming to didactically demonstrate the implementation of basic game mechanics, such as movement, collision, game states, multiple modes, particle system, and a simple AI.

---

## Contents

* [About the Game](#about-the-game)
* [Features](#features)
* [Gameplay](#gameplay)
* [Controls](#controls)
* [How to Play (Executable)](#how-to-play)
* [How to Compile (For Developers)](#how-to-compile)
* [Autor](#autor)
* [Licence](#licence)

---

## About the Game

**Red Dead Rosca** is a 2D arena game that pits two cowboys against each other in a duel to the death. The game offers two distinct modes, testing both the players' quick reflexes and strategic thinking.

* **Bang Bang Mode:** A franetic action mode where players move freely around the arena, jumping and crouching to dodge bullets. Each player has a 6-bullet revolver and must reload after emptying the cylinder. The last one standing wins the round.

* **One Shot Mode:** A strategic simultaneous turn-based duel, inspired by the classic "Rock, Paper, Scissors". Each round, players secretly choose between Loading, Blocking, or Shooting. A shot beats a load, a block defends a shot, and a load has no effect against a block. The winner is the one who deceives and shoots the opponent at the right time.

The game was developed entirely in **C++** using the **Raylib** graphics library.

## Features

- **Two distinct game modes:** Real-time action and turn-based strategy.
- **1 or 2 Player Support:** Challenge a friend in local multiplayer or face an AI in solo mode.
- **Simple IA**: The solo mode opponent reacts to the player's movements, such as jumping and crouching to dodge shots.
- **Complex Physics**: Includes gravity, variable-height jump, procedural blood particles, knockback when hit, hats with their own physics, and death animations.
- **Complete Audio System:** Sound effects for shots, hits, deaths, menu navigation, and background music for atmosphere.
- **Developed from Scratch**: A practical demonstration of state management, rendering, collision detection, and input in C++.
  

## Controls

| Action | Player 1 | Player 2 |
| :--- | :---: | :---: |
| Move Left/Right | **A** / **D** | **J** / **L** |
| Jump | **W** | **I** |
| Crouch | **S** | **K** |
| Shoot | **Space** | **M** |
| Emote | **Q** | **O** |
| Pause | **P** | **P** |

## How to Play (Executable)

The easiest way to play is to download the pre-compiled version.

1.  Download the .zip file of the latest version.
2.  Extract the contents of the .zip file to a folder on your computer.
3.  Important: Make sure the RedDeadRosca.exe file is in the same folder as all the audio (.mp3) and image (.png) files.
4.  Run RedDeadRosca.exe to play!

## How to Compile (For Developers)

If you wish to compile the game from the source code, follow the steps below.

### Pre-requisites
* A C++ compiler (the project was developed with MinGW-w64 on Windows).
* The Raylib library configured for your compiler.

### Compilation Command

Open a terminal in the project folder and run the following command, replacing [path to raylib] with the directory where your Raylib library is located:

```bash
g++ RedDeadRosca1.cpp -o RedDeadRosca.exe -I"[caminho para a raylib]\include" -L"[caminho para a raylib]\lib" -lraylib -lopengl32 -lgdi32 -lwinmm
```
After compilation, move the assets (images, sounds, and the font) to the same folder as the generated executable.

## Autor

**[Giovani Giachini / Jivanis]**

## Licence
This project was made for study and is **open-source**, so feel free to download and modify it.
