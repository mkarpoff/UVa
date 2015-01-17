#!/bin/bash
EXE=
TESTFILES=
for f in $TESTFILES
do
		echo "================================================"
		echo $f
		./$EXE < $f;
		echo "================================================"
done
