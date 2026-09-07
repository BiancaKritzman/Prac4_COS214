# TaskForge Emergency Response System

## Build

Build the Docker image:

```bash
docker build -t taskforge .
```

## Run

Run the program:

```bash
docker run --rm taskforge
```

## GDB and Valgrind

Open the Docker container:

```bash
docker run -it --rm taskforge bash
```

Run GDB:

```bash
make gdb
```

Run Valgrind:

```bash
make valgrind
```