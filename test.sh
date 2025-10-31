rm -rf build && rm -rf install
cmake -S . -B build

# build shared library
cmake -DIS_LOG_SHARED=ON build

cmake --build build
cmake --install build --prefix ./install
