#!/bin/bash

g++ -Wall -Wextra ../clm.cpp -o clm
./clm > data.csv
python3 plot.py
rm data.csv
rm clm
