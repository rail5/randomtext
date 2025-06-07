all:
	g++ -O2 -s -o randomtext main.cpp

clean:
	rm -f randomtext
.PHONY: all clean
