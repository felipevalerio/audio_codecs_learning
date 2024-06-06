TARGET=main
CXX=c++
LD=clang++
OBJS=main.cc

main:$(OBJS)
	$(LD) -o $(TARGET) $(OBJS)