.PHONY: configure build test

configure:
	cmake -S . -B build

build:
	cmake --build build

test: build
	cmake --build build
	ctest --test-dir build --output-on-failure
