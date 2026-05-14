/*
 * Student Name: Kevin Usuanlele / Scott Weaver
 * Student ID:   3103649 / 3144661
 * Date:         May 13, 2026
 * File:         sched.c
 * Description:  Read a workload file that lists processes by process ID, arrival time,
 *               and required CPU burst and simulates execution on a single CPU printing
 *               both a timeline of execution and detailed scheduling metrics
 * Reference(s): strncmp() - https://www.w3schools.com/c/ref_string_strncmp.php
 */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sched.h"
#include "stdbool.h"

static void usage(const char* prog){
    /* one-line usage only (per spec) */
    fprintf(stderr, "Usage: %s --policy=FCFS|RR [--quantum=N] --in=FILE\n", prog);
}

/* TODO: strict CLI
   Required: --policy=FCFS|RR, --in=FILE
   Optional: --quantum=N (required iff RR; N>0)
   On error: print usage() and return non-zero.
*/
int parse_args(int argc, char** argv, sim_cfg_t* cfg, const char** in_path){
    (void)argc; (void)argv; (void)cfg; (void)in_path;
    bool quantum = false;
    char *value;

    // Check if the number of args is valid
    if (argc < 3 || argc > 4)
    {
        usage(argv[0]);
        return 1;
    }

    // Parse through args => ./sched --policy=FCFS --in=W1.txt
    for (int i = 1; i < argc; i++) // start at 1 to skip program name
    {
        value = strchr(argv[i], '='); // find '=' in arg and point to value after it
        if (value != NULL) // if '=' is found
        {
            value++; // move pointer to FCFS/RR or path
        }
        else // input not valid => ./sched --policyFCFS --inW1.txt
        {
            usage(argv[0]);
            return 1;
        }

        // Read policy value
        if (strncmp(argv[i], "--policy=", 9) == 0) // compare first 9 chars ("--policy=") with arg to check if it's policy arg
        {
            if (strcmp(value, "FCFS") == 0) cfg->policy = POL_FCFS;
            else if (strcmp(value, "RR" == 0)) cfg->policy = POL_RR;
            else usage(argv[0]); return 1;
        }

        // Read Path
        else if (strncmp(argv[i], "--in=", 5) == 0)
        {
            *in_path = value; // value now should point to path
        }

        // Read Quantum
        else if (strncmp(argv[i], "--quantum=", 10) == 0)
        {
            // Validate quantum value
            //
            //
            //

            cfg->quantum = NULL;
            quantum = true;
        }
        else
        {
            usage(argv[0]);
            return 1;
        }

        // Validate flag combos
        if (cfg->policy == POL_FCFS && quantum) usage(argv[0]); return 1;
        if (cfg->policy == POL_RR && !quantum) usage(argv[0]); return 1;
    }
    return 0;
}

/* TODO: read "PID ARRIVAL CPU_TIME", ignore lines starting with '#', validate:
   pid>=0, arrival>=0, cpu>0. Sort by (arrival, pid). Return 0 on success.
*/
int load_workload(const char* path, job_t** jobs, int* n){
    (void)path; (void)jobs; (void)n;
    fprintf(stderr, "TODO: load_workload() not implemented\n");
    return 1;
}

/* TODO: discrete-time CPU simulation with FIFO ready queue.
   FCFS: never preempt. RR: quantum countdown; when it hits 0 and job not finished, enqueue at tail.
   Track: first run (first time scheduled) and completion (t+1 on finish).
   Build timeline run[t]=pid or -1 (idle). After finishing:
     - ctx = count PID->PID changes (ignore idle)
     - TAT = completion-arrival; RESP = first run-arrival
   Print exactly:
     time: 0 1 2 ... T-1
     run : <pid or -> per tick
     Pk: first run=... completion=... TAT=... RESP=...
     System: ctx_switches=..., avgTAT=..., avgRESP=...
*/
int simulate(const job_t* jobs, int n, const sim_cfg_t* cfg, sim_metrics_t* out){
    (void)jobs; (void)n; (void)cfg; (void)out;
    fprintf(stderr, "TODO: simulate() not implemented\n");
    return 1;
}

int main(int argc, char** argv){
    sim_cfg_t cfg; const char* in_path=NULL;
    int pr = parse_args(argc, argv, &cfg, &in_path);
    if (pr != 0) return 1;

    job_t* jobs=NULL; int n=0;
    if (load_workload(in_path, &jobs, &n) != 0) return 2;

    sim_metrics_t m;
    if (simulate(jobs, n, &cfg, &m) != 0) { free(jobs); return 3; }

    free(jobs);
    return 0;
}

