CC = g++
CFLAGS = --std=c++11
LDFLAGS = --std=c++11


HEADERS = */*.h *.h
SOURCES = */*.cpp *.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = frontend

all: clean $(EXECUTABLE)

$(EXECUTABLE): $(OBJECT)
	$(CC) $(LDFLAGS) -o $@ $(SOURCES)

run: 
	./$(EXECUTABLE)

run-files:
	./$(EXECUTABLE) ../../tests/frontend/test_users.txt ../../tests/frontend/test_items.txt ./_TRANSACTIONS.txt

%.o: %.cpp $(HEADERS)
	$(CC) -c $(CFLAGS) $<

.PHONY: clean

clean:
	rm -rf $(OBJECT) $(EXECUTABLE)
