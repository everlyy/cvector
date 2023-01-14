#! /bin/bash

set -xe

gcc -o vector main.c -Wall -Wextra -Werror -ggdb
./vector
