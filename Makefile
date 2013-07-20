CPPUTEST_HOME := /home/topcoder/alus_excerise/CppUTest
CPPFLAGS += -I$(CPPUTEST_HOME)/include
CPPFLAGS += -Iinclude
LD_LIBRARIES = -L $(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt -lncurses -lpthread

SOURCE:= $(wildcard src/*.cpp)
SOURCE_OBJ:= $(SOURCE:src/%.cpp=obj/%.o)

TESTS:= $(wildcard test/*.cpp)
TESTS_OBJ:= $(TESTS:test/%.cpp=obj/%.o)

INTEGRATION_TESTS:= $(wildcard it/*.cpp)
INTEGRATION_TESTS_OBJ:= $(INTEGRATION_TESTS:it/%.cpp=obj/%.o)

UT_OBJ:= $(SOURCE_OBJ) $(TESTS_OBJ)

IT_OBJ:= $(SOURCE_OBJ) $(INTEGRATION_TESTS_OBJ) $(TESTS_OBJ)

UT_TARGET:= obj/ut.exe

IT_TARGET:=obj/it.exe

all: $(UT_TARGET)
	$(UT_TARGET)

clean:
	rm $(UT_OBJ) $(UT_TARGET) $(IT_OBJ)  $(IT_TARGET)

it: $(IT_TARGET)
	$(IT_TARGET)

$(UT_TARGET): $(UT_OBJ)
	$(CXX) $(UT_OBJ) $(LD_LIBRARIES) -o $(UT_TARGET)

$(IT_TARGET): $(IT_OBJ)
	$(CXX) $(IT_OBJ) $(LD_LIBRARIES) -o $(IT_TARGET)

$(SOURCE_OBJ):obj/%.o:src/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(TESTS_OBJ):obj/%.o:test/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(INTEGRATION_TESTS_OBJ):obj/%.o:it/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@
