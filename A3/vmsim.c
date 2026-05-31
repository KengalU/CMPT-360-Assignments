/* ID Header: 
 Student Name: Scott Weaver Kevin Usualele
 Student ID: 3144661 / 3103649
 Submission Date: TBD
 File: vsim.c
*/

#include "vmsim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

// usage
static void usage(const char *prog) {
    fprintf(stderr,
        "Usage:\n"
        "  %s --mode=bb  --base=N --limit=N --trace=FILE \n"
        "  %s --mode=seg --config=FILE --trace=FILE \n",
        prog, prog);
}

// CLI
bool parse_args(int argc, char **argv, sim_opts_t *o) 
{
    if (o) memset(o, 0, sizeof(*o));
    bool mode_set = false, base_set = false, limit_set = false, trace_set = false, config_set = false;
    char *value;

    for (int i = 1; i < argc; i++)
    {
        value = strchr(argv[i], '='); // find '=' in arg and point to value after it
        if (value != NULL) value++; // move pointer to value after '='
        else {fprintf(stderr, "Error: Malformed arguments: '%s'\n", argv[i]); return false;} // input not valid => ./vmsim --modebb --base1000

        if (strncmp(argv[i], "--mode=", 7) == 0)
        {
            if (strcmp(value, "bb") == 0) o->mode = MODE_BB;
            else if (strcmp(value, "seg") == 0) o->mode = MODE_SEG;
            else {fprintf(stderr, "Error: Invalid mode: '%s'\n", value); return false;}
            mode_set = true;
        }

        else if (strncmp(argv[i], "--base=", 7) == 0) {o->base = atol(value); base_set = true;}

        else if (strncmp(argv[i], "--limit=", 8) == 0) {o->limit = atol(value); limit_set = true;}

        else if (strncmp(argv[i], "--trace=", 8) == 0) {o->trace_path = value; trace_set = true;}

        else if (strncmp(argv[i], "--config=", 9) == 0) {o->config_path = value; config_set = true;}

        else{fprintf(stderr, "Error: Invalid argument: '%s'\n", argv[i]); return false;}
    }

    // Validate arg combos
    if (!mode_set) {fprintf(stderr, "Error: --mode is required\n"); return false;}
    if (!trace_set) {fprintf(stderr, "Error: --trace is required\n"); return false;}
    if (o->mode == MODE_BB && (!base_set || !limit_set))
    {
        fprintf(stderr, "Error: --base and --limit are required for bb mode\n");
        return false;
    }
    if (o->mode == MODE_SEG && !config_set)
    {
        fprintf(stderr, "Error: --config is required for seg mode\n");
        return false;
    }
    
    return true;
}

//bb
int run_bb(const sim_opts_t *o, stats_t *st) {
    (void)o; (void)st;
    echo_file(o);
    //fprintf(stderr, "TODO: run_bb()\n");
    return 0;
}

//seg
int run_seg(const sim_opts_t *o, stats_t *st) {
    (void)o; (void)st;
    echo_file(o);
    //fprintf(stderr, "TODO: run_seg()\n");
    return 0;
}

int echo_file(const sim_opts_t *o) {
    FILE *f = fopen(o->trace_path, "r");
    if (!f) { fprintf(stderr, "Error: Failed to open file '%s'\n", o->trace_path); return 1; }
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
    return 0;
}

//main()
int main(int argc, char **argv) {
    sim_opts_t opts;
    if (!parse_args(argc, argv, &opts)) { usage(argv[0]); return 1; }
    stats_t st = (stats_t){0};
    if (opts.mode == MODE_BB) return run_bb(&opts, &st);
    else return run_seg(&opts, &st);
}
