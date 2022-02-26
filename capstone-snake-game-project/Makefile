RM    := rm -rf
MKDIR := mkdir -p
RUN   := ./build/SnakeGame

all: ./build/Makefile
	@ $(MAKE) -C build
	  $(RUN)


./build/Makefile:
	@ ($(MKDIR) build > /dev/null)
	@ (cd build > /dev/null 2>&1 && cmake ..)


clean:
	@- $(RM) ./build/*
	@- $(RM) ./build/*.cmake


ifeq ($(findstring clean,$(MAKECMDGOALS)),)
	$(MAKECMDGOALS): ./build/Makefile
	@ $(MAKE) -C build $(MAKECMDGOALS)
endif
