#!/bin/bash

# Set variables
filename="MergeSort"
xrange="[1:1100]"
yrange="[1:10000]"
b_file="m_b.txt"
w_file="m_w.txt"
a_file="m_a.txt"

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
plot "${b_file}" title "best-case", "${w_file}" title "worst-case", "${a_file}" title "average-case"
EOF

echo "Plot saved as ${filename}.png"
