# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

# Detect C and C++ compiler options
# if not gcc, default to clang-7

# COMPILER=$(notdir $(CC))
# ifeq ($(COMPILER), gcc)
#         USE_GCC = true
# endif

# ifeq ($(USE_GCC),)
#         CC = clang-7
#         COMPILER=clang
#         CXX = clang++-7
#         CXXCOMPILER=clang++
# endif

CC=cc
CXX=c++
COMPILER=gcc
CXXCOMPILER=g++

CFLAGS=$(shell pkg-config oeenclave-$(COMPILER) --cflags)
CXXFLAGS=$(shell pkg-config oeenclave-$(CXXCOMPILER) --cflags)
LDFLAGS=$(shell pkg-config oeenclave-$(CXXCOMPILER) --libs)

all:
	$(MAKE) build
	$(MAKE) keys
	$(MAKE) sign

build:
	@ echo "Compilers used: $(CC), $(CXX)"
	oeedger8r ../helloworld.edl --trusted

	$(CXX) -g -I/home/christophe/build_artifacts/eEVM/3rdparty -I/home/christophe/build_artifacts/eEVM  $(CXXFLAGS) -Wall -Werror -std=gnu++1z  -o enc.o -c /home/christophe/build_artifacts/eEVM/sample_enclaves/helloworld/enc/enc.cpp
	$(CC) -g -c $(CFLAGS) helloworld_t.c -o helloworld_t.o
	$(CXX) -o helloworldenc helloworld_t.o enc.o /home/christophe/build_artifacts/eEVM/sample_enclaves/helloworld/enc/libevm.a $(LDFLAGS) -static-libgcc -lgcc

sign:
	oesign sign helloworldenc helloworld.conf private.pem

clean:
	rm -f enc.o helloworldenc helloworldenc.signed private.pem public.pem helloworld_t.o helloworld_t.h helloworld_t.c helloworld_args.h

keys:
	openssl genrsa -out private.pem -3 3072
	openssl rsa -in private.pem -pubout -out public.pem
