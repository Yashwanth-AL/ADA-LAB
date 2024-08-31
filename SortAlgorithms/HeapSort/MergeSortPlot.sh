#!/bin/bash

# Set variables
filename="Heap-Sort"
xrange="[0:1100]"
yrange="[0:18000]"
b_file="heap_b.txt"
w_file="heap_w.txt"
a_file="heap_a.txt"

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
plot "${b_file}" title "best-case", "${w_file}" title "worst-case", "${a_file}" title "avg-case"
EOF

echo "Plot saved as ${filename}.png"
