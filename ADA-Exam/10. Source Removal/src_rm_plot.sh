#!/bin/bash

# Set variables
filename="Source removal Algorithm"
xrange="[0:11]"
yrange="[0:220]"
b_file="src_b.txt"
w_file="src_w.txt"

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
