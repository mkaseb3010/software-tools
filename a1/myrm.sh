#!/bin/bash

recycleDESTINATION=/eecs/home/mkaseb1/a1/recycle-bin
mkdir -p $recycleDESTINATION

if [ $# == "0" ]; then
        echo 'Error:no target specified'
        echo 'Usage:./myrm <files>'
fi

for file in "$@"
do
    if [ -f $file ]
        then	
        echo 'deleting' $file	
		filename=`basename $file`	
		if [ -f $recycleDESTINATION/$filename'copy'$override ]; then      
				 		 	override=`$override + 1`
				 		 else
				 			mv $file $recycleDESTINATION/$filename
				 	fi 		
			else			
				echo "Error: The File" $file "does not exist"
		fi
done