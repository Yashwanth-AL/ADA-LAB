#!/bin/bash

# Set variables
filename="String-Matching"
xrange="[-50:1200]"
yrange="[-10000:300000]"
b_file="sm_b.txt"
w_file="sm_w.txt"
a_file="sm_a.txt"

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
