objects=w-w

CPPFLAGS=-lpthread

all: $(objects)

$(objects): % : %.cpp
	g++ $(CPPFLAGS) $< -o $@

clean:
	rm -rf *out *log
