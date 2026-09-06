CXX=g++ -std=c++11
CFLAGS=-I. -Wall -Werror
TARGET=taskforge
OBJS= .o 

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

leak:	
	valgrind --leak-check=full ./eventflow