# my_pacman
pacman using c++ &amp; ncurses.
This game was created as a university assignment in the summer of _2021_, and has since been gradually improved. I still occasionally add code to it.
Initially, it was a simple program that started the game when executed.
Instead of release notes, here are the features that have been added so far:

* Menu screen.
* Pause and resume functionality.
* Optimization of enemy characters.
* Invincibility item.

> **Warning**
> <br>By the way, Those sentences above is written by ChatGPT. Is it enough???

## What is Nucurses?
Ncurses (or Ncursesw) is a library for managing screens, keystrokes, cursors, etc. in CUI.

## Usage

Install ncurses.
* Linux (include WSL)
  ```sh
  sudo apt install ncurses-dev
  ```
* Mac
  ```sh
  brew install ncurses
  ```

Build.
```sh
make
```
Run.
```sh
./pacman
```
> **Note**
> <br>I tested this program on my WSL2-Windows11 PC and M1-MacbookAir. Any probrems!

## Screenshots
![ss_pacman_menu](https://user-images.githubusercontent.com/67182687/222732313-3e32bdb0-4c35-49e8-92a5-aa74d960f25f.png)
