RM    := rm -rf
MKDIR := mkdir -p
RUN   := ./build/SnakeGame

.PHONY: all build run

all: build run

build:
	@ ($(MKDIR) build > /dev/null)
	@ cmake -B build
	@ cmake --build ./build/

run:
	$(RUN)

debug:
	@ cmake -S . -B debug -DCMAKE_BUILD_TYPE=Debug
	@ cmake --build debug

clean:
	@- $(RM) ./build/*
	@- $(RM) ./build/*.cmake


ifeq ($(findstring clean,$(MAKECMDGOALS)),)
	$(MAKECMDGOALS): ./build/Makefile
	@ $(MAKE) -C build $(MAKECMDGOALS)
endif
