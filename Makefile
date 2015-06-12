test:
	make build && ./runtests
build: 
	g++ main.cpp SoundexTest.cpp Soundex.cpp \
	-Igmock-1.6.0/include -Igmock-1.6.0/gtest/include \
	-Lgmock-1.6.0/build -lgmock \
	-Lgmock-1.6.0/gtest/build -lgtest \
	-lpthread -o runtests -std=c++98 
