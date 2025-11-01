.PHONY: test remove config build install
test: remove config build install 
build:
	cmake --build build

remove:
	rm -rf build && rm -rf install

config:
	cmake -S . -B build
	cmake -S . -B build -DIS_LOG_SHARED=ON

install:
	cmake --install build --prefix ./install
