#!/bin/bash

assert(){
    expected="$1"
    input="$2"

    ./rvcc "$input" > tmp.s || exit
    riscv64-unknown-linux-gnu-gcc -static tmp.s -o tmp
    qemu-riscv64 -L $RISCV/sysroot/ tmp

    actual="$?"
    if [ "$actual" = "$expected" ]; then
        echo "$input => $actual"
    else
        echo "$input => $expected expected, but got $actual"
        exit 1
    fi

}

assert 0 0
assert 45 45

echo OK