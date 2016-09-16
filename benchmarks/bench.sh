echo 'Mode DEBUG'
make DEBUG=yes re > /dev/null
clang -I inc/ lib42.a benchmarks/memset-test.c && ./a.out
echo 'Mode PROD'
make PROD=yes re > /dev/null
clang -I inc/ lib42.a benchmarks/memset-test.c && ./a.out
