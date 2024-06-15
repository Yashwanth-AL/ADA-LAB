#!/bin/bash

# Set variables
filename="Linear-Search"
xrange="[0:700]"
yrange="[-50:800]"
b_file="l_b.txt"
w_file="l_w.txt"
a_file="l_a.txt"

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
