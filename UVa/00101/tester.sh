#!/bin/bash
EXE=ans
Input=TestFiles/Input/
Output=TestFiles/Output/

TESTBREAK="================================================"

DIFFPROG=$(command -v colordiff)
if [ "$DIFFPROG" == "" ];	then
	DIFFPROG=diff
fi

for f in {1..5};
do
		echo "$TESTBREAK"
		./$EXE < $Input$f > temp
		echo "TEST: $f"
		EXP=$Output$f
		DIFF=$(diff temp $EXP)
		LLE=$(wc -L $EXP | awk '{print $1}')
		LLA=$(wc -L temp | awk '{print $1}')
		COL=$LLA
		if [ $LLE -gt $LLA ]; then
			COL=$LLE
		fi
		COLSIZE=$COL
		if [ $COLSIZE -gt 80 ]; then
			COLSIZE="`tput cols`"
			COL=$(expr $COLSIZE / 2)
		elif [ $COLSIZE -lt 12 ]; then
			COLSIZE=24
			COL=12
		else
			COLSIZE=$(expr $COL \* 2)
		fi
		pad=$(printf '%0.1s' "-"{1..80})

		if [ "$DIFF" != "" ]; then
			printf 'EXPECTED:'
			printf '%*.*s' 0 $((COL - 12 )) "$pad"
			printf 'ACTUAL:\n'
			$DIFFPROG -yW "$COLSIZE" $EXP temp --suppress-common-lines
			rm -f temp
			echo "$TESTBREAK"
			break
		else
			echo "Passed"
		fi
		rm -f temp
		echo "$TESTBREAK"
done
