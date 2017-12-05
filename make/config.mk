COMMON_LIBRARY=-luuid -pthread -lrt -ldl 
COMMON_INCLUDE=-I../ -I/usr/include/brpc/
COMMON_MACRO=-D__LINUX
#COMMON_OPTION=-Wl,--no-as-needed
COMMON_CFLAGS=-g -std=c++11 -fPIC
COMMON_CXX=g++

PUBLIC_COMMON_LIBRARY=-lboost_filesystem -lboost_regex -lfr_public -lmysqlcppconn -lfr_sql -lbrpc

BUILD_LIBRARY_PATH=../../build/lib
BUILD_INCLUDE_PATH=../../build/include
BUILD_EXECUTE_PATH=../../build/bin
OUTPUT_LIB_PATH=/usr/local/lib64
OUTPUT_INCLUDE_PATH=/usr/local/include
OUTPUT_EXECUTE_PATH=/usr/local/bin
OUTPUT_TEMPORARY_PATH=../../out
OUTPUT_EXAMPLE_PATH=../../out

.PHONY: clean all install example

# 匹配规则
./${OUTPUT_TEMPORARY_PATH}/%.o : %.cpp
	-mkdir -p ./${OUTPUT_TEMPORARY_PATH}/$(dir $<)
	$(COMMON_CXX) $(COMMON_CFLAGS) $(COMMON_MACRO) -c $(COMMON_INCLUDE) $< -o $@

./${OUTPUT_TEMPORARY_PATH}/%.o : %.cc
	-mkdir -p ./${OUTPUT_TEMPORARY_PATH}/$(dir $<)
	$(COMMON_CXX) $(COMMON_CFLAGS) $(COMMON_MACRO) -c $(COMMON_INCLUDE) $< -o $@

./${OUTPUT_TEMPORARY_PATH}/%.o : %.c
	-mkdir -p ./${OUTPUT_TEMPORARY_PATH}/$(dir $<)
	$(COMMON_CXX) $(COMMON_CFLAGS) $(COMMON_MACRO) -c $(COMMON_INCLUDE) $< -o $@

