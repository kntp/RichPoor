CPP = g++
CPPUTEST_DIR = /home/knaka/Projects/cpputest-3.4
LIBS = -lCppUTest
LIBDIR = $(CPPUTEST_DIR)/lib
CXXFLAGS = -I$(CPPUTEST_DIR)/include
APPOBJS = CardTest.o Card.o
TESTOBJS = AllTests.o CardTest.o Card.o
TARGET = MyApp
TEST_TARGET = MyTest

all: check

app: $(TARGET)

check: $(TEST_TARGET)
	./$(TEST_TARGET)

MyApp: $(APPOBJS)
	$(CPP) -o $(TARGET) $(APPOBJS)

$(TEST_TARGET): $(TESTOBJS)
	$(CPP) -o $(TEST_TARGET) -L$(LIBDIR) $(TESTOBJS) $(LIBS)

clean:
	@rm -f *.o *~ $(TARGET) $(TEST_TARGET)
