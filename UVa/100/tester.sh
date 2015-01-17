#!/bin/bash
EXE=ans
TESTFILES=TestFiles/*
for f in $TESTFILES
do
		echo "================================================"
		echo $f
		./$EXE < $f;
		echo "================================================"
done
