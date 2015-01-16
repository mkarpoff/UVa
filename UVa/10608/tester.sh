#!/bin/bash
EXE=ans
TESTFILES=test_files/*
for f in $TESTFILES
do
		echo "================================================"
		./$EXE < $f;
		echo "================================================"
done
