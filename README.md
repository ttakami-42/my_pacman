# my_pacman
pacman using c++ &amp; ncurses.
<br>This game was created as a university assignment in the summer of _2021_, and has since been gradually improved. 
<br>I still occasionally add code to it.
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
![ss_pacman_menu](https://user-images.githubusercontent.com/67182687/222733784-ce4c5f86-e5b2-458d-9c29-3b83513479e6.png)
