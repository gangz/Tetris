CPPUTEST_HOME := /home/topcoder/alus_excerise/CppUTest
CPPFLAGS += -I$(CPPUTEST_HOME)/include
CPPFLAGS += -Iinclude
LD_LIBRARIES = -L $(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

SOURCE:= $(wildcard src/*.cpp)
SOURCE_OBJ:= $(SOURCE:src/%.cpp=obj/%.o)

TESTS:= $(wildcard test/*.cpp)
TESTS_OBJ:= $(TESTS:test/%.cpp=obj/%.o)

OBJ:= $(SOURCE_OBJ) $(TESTS_OBJ)
TARGET:= obj/ut.exe

all: $(TARGET)
	$(TARGET)

clean:
	rm $(OBJ) $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) $(LD_LIBRARIES) -o $(TARGET)

$(SOURCE_OBJ):obj/%.o:src/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(TESTS_OBJ):obj/%.o:test/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@
