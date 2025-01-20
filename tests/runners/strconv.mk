# SPDX-License-Identifier: MIT

COMPONENT_NAME = strconv

SRC_FILES = \
	../src/strconv.c \

TEST_SRC_FILES = \
	src/strconv_test.cpp \
	src/test_all.cpp \

INCLUDE_DIRS = \
	$(CPPUTEST_HOME)/include \
	../include \

MOCKS_SRC_DIRS =
CPPUTEST_CPPFLAGS = -DOCPP_DEBUG=printf -DOCPP_ERROR=printf -DOCPP_INFO=printf \
		    -include stdio.h

include runners/MakefileRunner
