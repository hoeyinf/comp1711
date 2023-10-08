#!/usr/bin/bash
for((counter=2;counter<11;counter++))do
    mkdir week$counter
    cd week$counter
    mkdir session1
    mkdir session2
    cd ..
done