test:
	make build && ./runtests
build:
	g++ main.cpp -Igmock-1.7.0/include -Igmock-1.7.0/gtest/include -Lgmock-1.7.0/build -lgmock -lpthread -o runtests