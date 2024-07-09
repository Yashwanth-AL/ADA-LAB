#!/bin/bash

# Set variables
filename="BFS - Matrix"
xrange="[0:120]"
yrange="[0:120]"
b_file="bfs_b.txt"
w_file="bfs_w.txt"

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
plot "${b_file}" title "best-case", "${w_file}" title "worst-case"
EOF

echo "Plot saved as ${filename}.png"
