#PHONY goal
.PHONY: all clean check_obj_dir

#PATH
TOPDIR =  $(shell pwd)
CPPUTEST_HOME := $(TOPDIR)/../tool/cpputest

#FLAGS
CPPFLAGS += -I$(CPPUTEST_HOME)/include
CPPFLAGS += -Iinclude
LD_LIBRARIES = -L $(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt -lncurses -lpthread
CPPFLAGS += -MMD -MP
ifdef GCOV
    CPPFLAGS +=  -fprofile-arcs -ftest-coverage 
    LD_LIBRARIES += -lgcov
endif

SOURCE:= $(wildcard src/*.cpp)
SOURCE_OBJ:= $(SOURCE:src/%.cpp=obj/src/%.o)

TESTS:= $(wildcard test/*.cpp)
TESTS_OBJ:= $(TESTS:test/%.cpp=obj/test/%.o)

INTEGRATION_TESTS:= $(wildcard it/*.cpp)
INTEGRATION_TESTS_OBJ:= $(INTEGRATION_TESTS:it/%.cpp=obj/it/%.o)

OBJS:= $(SOURCE_OBJ) $(INTEGRATION_TESTS_OBJ) $(TESTS_OBJ)

UT_TARGET:= obj/ut.exe

IT_TARGET:=obj/it.exe

all: check_obj_dir $(UT_TARGET)
ifdef GCOV
	./cov.sh $(UT_TARGET)
else
	$(UT_TARGET)
endif

clean:
	rm -rf obj
	rm *.info
	rm -rf gcov-html

it: check_obj_dir $(IT_TARGET)
	$(IT_TARGET)

$(UT_TARGET): $(SOURCE_OBJ) $(TESTS_OBJ)
	$(CXX) $(SOURCE_OBJ) $(TESTS_OBJ) $(LD_LIBRARIES) -o $@

$(IT_TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LD_LIBRARIES) -o $(IT_TARGET)

$(OBJS):obj/%.o:%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@
-include $(OBJS:.o=.d)
	

check_obj_dir:
	-@mkdir -p obj obj/src obj/test obj/it 2>/dev/null
