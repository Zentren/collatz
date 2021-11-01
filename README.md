# Longest Collatz sequence

The attached applications find the starting number below a given limit that has
the longest Collatz sequence.

## Build

There are two applications:
1. `space/` contains an implementation optimized for space, simplicity and
    readability.
2. `time/` contains an implementation optimized for speed, trading off some
    space.

You can build the above using CMake or the provided Bash script after changing
directory into the application of interest and following the instructions below:
```bash
cd space/
```
or
```bash
cd time/
```

### Using CMake
```bash
mkdir -p dist
cd dist/
cmake ..
make
```

### Using the provided Bash script

```bash
./build
cd dist/
```

## Running

If you followed the provided build steps, you should be in the `dist/` directory
of the application you would like to use. There should be two executables:
1. `app` - which is run with an upper limit as its first command line argument
    and will print out the first element in the longest Collatz sequence less
    than or equal to that upper limit, e.g.
    ```bash
    $ ./app 30
    The longest Collatz sequence starting <= 30 starts at 27.
    ```
2. `test` - which if run will print out unit test results. Pass `-d` command
    line argument to see test case timings. The speed-optimized solution is
    about an order of magnitude faster than the space one on my machine.

## Notes

- _CMake_ is the preferred build toolchain; the Bash script is brittle and
    assumes that _GCC_ is the compiler being used. However, you may use the bash
    script to understand how to compile the application and tests if you
    encounter any issues building.
- _doctest_ is a header-only unit testing framework for _C++_ which has been
    used to check correctness of the solutions and runtime difference between
    solutions. Its source is included and the the project may be found at
    https://github.com/onqtam/doctest.