if [ "$1" ]; then
    make all TARGET=$1
else
    rm a.out
fi
