#/bin/bash
EXE=ans
TESTFILES=test_files/*
for f in $TESTFILES
do
		echo "================================================"
		echo $f;
		./$EXE < $f;
		echo "================================================"
done
