CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror

TARGET = taskforge

OBJS = main.o \
       EmergencyResponseSystem.o \
       ResponseContainer.o \
       ResponseTeam.o \
       Responder.o \
       Incident.o \
       EmergencyDecorator.o \
       PriorityDecorator.o \
       LogsDecorator.o \
       ResponderState.o \
       AvailabilityState.o \
       RespondingState.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

leak: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)