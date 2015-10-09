#include <getopt.h>

#include <cassert>
#include <cstdlib>
#include <iostream>

#include "options.h"

using std::cerr; using std::endl;

namespace gpio {

Options::Options(int argc, char *argv[]) {
    int opt, index;

    static struct option long_options[] {
        {"pin",     required_argument, 0, 'p'},
        {"write",   no_argument,       0, 'w'},
        {"verbose", no_argument,       0, 'v'},
        {0, 0, 0, 0}
    };

    // Reset global optind which specifies where to start parsing
    optind = 1;

    while ((opt = ::getopt_long(argc, argv, "p:wv", long_options, &index))) {
        if (opt == -1)
            break;

        switch (opt) {
            case 'p':
                _pin = ::atoi(optarg);
                break;
            case 'w':
                _readPin = false;
                break;
            case 'v':
                _verbose = true;
                break;
            default:
                print_usage(argc, argv);
                ::exit(EXIT_FAILURE);
        }
    }
}

void Options::print_usage(int argc, char *argv[]) const {
    cerr << "Usage: " << argv[0] << " --pin <pin> [--write]" << endl;
}

}
