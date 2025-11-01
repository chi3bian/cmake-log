
test:
	rm -rf build && rm -rf install
	cmake -S . -B build
	cmake -DIS_LOG_SHARED=ON build
	cmake --build build
	cmake --install build --prefix ./install