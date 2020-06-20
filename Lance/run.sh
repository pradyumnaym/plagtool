#!/bin/bash

make clean
make
./myapp $1
stcleanup $1
