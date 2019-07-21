
Folder_A="./data"  

echo 'clear .out'
rm -rf $Folder_A/*.out

for file_a in ${Folder_A}/*
do  
    filein=`basename $file_a`
    filein=$Folder_A/$filein
    echo $filein
    # cat $filein

    fileout=`basename $file_a  .in`
    fileout=$Folder_A/$fileout.out
    echo $fileout

    # : > $fileout
    ./a.out < $filein > $fileout
done

# for file in `ls ./data`
# do
#     echo $file
# done