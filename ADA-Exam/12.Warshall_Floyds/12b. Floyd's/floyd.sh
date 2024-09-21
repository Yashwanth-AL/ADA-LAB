#!/bin/bash

# Set variables
filename="Floyds Algorithm"
xrange="[0:13]"
yrange="[0:1100]"
b_file="floyd.txt"

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
plot "${b_file}" title "floyds algorithm"
EOF

echo "Plot saved as ${filename}.png"
