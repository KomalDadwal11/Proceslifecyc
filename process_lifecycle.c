#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Enumeration of process states
typedef enum { NEW, READY, RUNNING, WAITING, TERMINATED } ProcessState;

// Process structure
typedef struct {
    int pid;               // Process ID
    ProcessState state;    // Current state of the process
} Process;

// Function to simulate process creation
Process create_process(int pid) {
    Process p;
    p.pid = pid;
    p.state = NEW;
    return p;
}

// Function to simulate process transition to READY state
void make_ready(Process *p) {
    p->state = READY;
}

// Function to simulate process execution
void run_process(Process *p) {
    p->state = RUNNING;
    printf("Process %d is now running.\n", p->pid);
    sleep(1);  // Simulate process execution time
}

// Function to simulate process waiting
void wait_process(Process *p) {
    p->state = WAITING;
    printf("Process %d is now waiting.\n", p->pid);
    sleep(1);  // Simulate waiting time
}

// Function to terminate a process
void terminate_process(Process *p) {
    p->state = TERMINATED;
    printf("Process %d has terminated.\n", p->pid);
}

int main() {
    Process p1 = create_process(1);

    make_ready(&p1);
    run_process(&p1);
    wait_process(&p1);
    terminate_process(&p1);

    return 0;
}