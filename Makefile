CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

OBJS = main.o ascii.o systeminfo.o

apexfetch: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) apexfetch
