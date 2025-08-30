# RTOS DSP Scheduler

A simple RTOS-style cooperative scheduler written in **C++17** on **Linux (Debian 12)** targeting Debian based systems, featuring:

- Task scheduling with configurable tick rate  
- Digital signal processing tasks (moving average filter)  
- FFT analysis using **FFTW3**  
- Unit tests using **GoogleTest**  

This project demonstrates embedded-style scheduling and DSP in a Linux environment, with an emphasis on practices common in aerospace, defense, and telecom software development.

---

# Building & Running

## Prerequisites
Make sure the following packages are installed on your system (Debian/Ubuntu):
```bash
sudo apt update
sudo apt install -y build-essential cmake libfftw3-dev libgtest-dev
```
## Building the GoogleTest libraries
```bash
cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp lib/*.a /usr/lib
```
## Building the main program
```bash
make
```
## Running tests
```
make test
```
## Project Structure
```
include/ # Header files
src/ # Source files
tests/ # Unit tests
Makefile # Build system
```
# Workflow
This repository adheres to a Git branching model:\
**main** - stable branch with workable code\
**dev** - integration branch for features that'll be merged\
**feature/*** - branches for individual tasks

Pull Requests (PRs) are used to merge the **feature** branches into **dev**. Once tested and stable, **dev** is merged into **main**.
# Prospective Additions
- Extend the logger task to write to logfile(s) rather than a console
- Add GitHub Actions CI/CD, to ensure auto-building and testing upon push/PR
- Add test coverage reporting
- Experiment with RTOS simulation like FreeRTOS/Zephyr
- Add extensions to signal processing (windowing, simulate sensor input, FIR/IIR filters)
- Integrate with Cloud/AWS (push system logs to S3 and process events with AWS Lambda)
- Simplify Docker build/run workflow

## Running with Docker

This project includes a Dockerfile for portability.  
You can build and run the project in a clean Debian 12 container without installing dependencies manually.

### Prerequisites
- Install [Docker Engine](https://docs.docker.com/engine/install/) (tested on Debian 12)

### Build the image
```bash
docker build -t rtos-dsp-scheduler .