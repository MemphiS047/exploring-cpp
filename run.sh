# Condition for compiling only main.cpp
if [ $1 == "simple" ] 
then
    echo "Compiling only main... (simple mode)"
    g++ -std=c++11 -o main main.cpp
    ./main
    exit 0
fi
make
./main