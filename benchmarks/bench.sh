echo 'Flag: -O0'
make DEBUG=yes re > /dev/null
clang -I inc/ lib42.a benchmarks/memset-test.c && ./a.out
echo ''
echo 'Flag: -O2'
make PROD=yes re > /dev/null
clang -I inc/ lib42.a benchmarks/memset-test.c && ./a.out
