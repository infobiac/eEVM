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
# endif

CC=cc
CXX=c++
COMPILER=gcc
CXXCOMPILER=g++


CFLAGS=$(shell pkg-config oehost-$(COMPILER) --cflags)
CXXFLAGS=$(shell pkg-config oehost-$(CXXCOMPILER) --cflags)
LDFLAGS=$(shell pkg-config oehost-$(CXXCOMPILER) --libs)

build:
	@ echo "Compilers used: $(CC), $(CXX)"
	oeedger8r ../helloworld.edl --untrusted
	$(CXX) -g -I/home/christophe/build_artifacts/eEVM/3rdparty -I/home/christophe/build_artifacts/eEVM $(CXXFLAGS) -Wall -Werror -std=gnu++1z  -o host.o -c /home/christophe/build_artifacts/eEVM/sample_enclaves/helloworld/host/host.cpp
	$(CC) -g -c $(CFLAGS) helloworld_u.c
	$(CXX) -o helloworldhost helloworld_u.o host.o /home/christophe/build_artifacts/eEVM/sample_enclaves/helloworld/enc/libevm.a $(LDFLAGS) -static-libgcc -lgcc

clean:
	rm -f helloworldhost host.o helloworld_u.o helloworld_u.c helloworld_u.h helloworld_args.h
