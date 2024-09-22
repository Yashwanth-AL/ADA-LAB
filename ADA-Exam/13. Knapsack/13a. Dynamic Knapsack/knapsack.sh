#!/bin/bash

# Set variables
filename="Knapsack problem"
xrange="[1:6]"
yrange="[1:50]"
b_file="knapsack.txt"

# Gnuplot commands
gnuplot << EOF
set terminal png
set output "${filename}.png"
set title "${filename}"
set xrange ${xrange}
set yrange ${yrange}
set xlabel "input-size"
set ylabel "op-count"
set style data linespoints
plot "${b_file}" title "output"
EOF

echo "Plot saved as ${filename}.png"
