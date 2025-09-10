CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

SRC = main.cpp ascii.cpp systeminfo.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = apexfetch

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
