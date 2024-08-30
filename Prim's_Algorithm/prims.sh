#!/bin/bash

# Set variables
filename="Prims's Algorithm"
xrange="[2:7]"
yrange="[2:36]"
a_file="primsgraph.txt"

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
plot "${a_file}" title "avg-case"
EOF

echo "Plot saved as ${filename}.png"
