CC = gcc

APP = mycore
MODE = debug

CFLAGS = -D_POSIX_C_SOURCE -Wall -std=c99
DEBUG_CFLAGS = -g3 -O0
RELEASE_CFLAGS = -O2 -DNDEBUG

LDFLAGS = 

BUILD_DIRS = build/ bin/
