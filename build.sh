#!/bin/bash
g++ main.cpp Game.cpp Snake.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
./main
