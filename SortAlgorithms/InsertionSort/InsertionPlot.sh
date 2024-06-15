#!/bin/bash

# Set variables
filename="Insertion-Sort"
xrange="[0:40000]"
yrange="[-50000000:500000000]"
b_file="i_b.txt"
w_file="i_w.txt"
a_file="i_a.txt"

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
