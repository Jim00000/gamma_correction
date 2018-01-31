# gamma_correction

This project implements gamma correction using C++ with OpenMP and CUDA is alternative option

## Download and Build

```
$ git clone https://github.com/Jim00000/gamma_correction.git
$ cd gamma_correction
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Release .. # or use cmake-gui
$ make
```

## Test

After building this project, go to build/test/ folder

```
$ ctest
```

and you will get one gif animation merging multiple images

## Demo

![gif](.imgs/animated.gif)

## License

BSD 3-Clause License