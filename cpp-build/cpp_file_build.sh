MAKE_DIR=~/algorithm/cpp-build
PWD=`pwd`
cp $MAKE_DIR/Makefile $PWD
make

if [ $MAKE_DIR != $PWD ]; then
    rm $PWD/Makefile
fi