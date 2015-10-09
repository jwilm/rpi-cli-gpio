#include <cassert>
#include <cstdlib>
#include <cstring>

#include "options.h"

// Specifying char** in C++ is unpleasant with -Wwrite-strings
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

namespace test {
namespace options {

size_t argvlen(char *argv[]) {
    size_t i = 0;
    while (argv[i] != NULL)
        i++;

    return i;
}

void read_pin() {
    char *argv[] = {"gpio", "--pin", "17", NULL};
    gpio::Options opts(argvlen(argv), argv);

    assert(opts.reading());
    assert(!opts.writing());
    assert(opts.pin_number() == 17);
}

void read_pin_short() {
    char *argv[] = {"gpio", "-p", "17", NULL};
    gpio::Options opts(argvlen(argv), argv);

    assert(opts.reading());
    assert(!opts.writing());
    assert(opts.pin_number() == 17);
}

void write_pin() {
    char *argv[] = {"gpio", "--write", "--pin", "18", "--verbose", NULL};
    gpio::Options opts(argvlen(argv), argv);

    assert(!opts.reading());
    assert(opts.writing());
    assert(opts.pin_number() == 18);
    assert(opts.verbose());
}

void write_pin_short() {
    char *argv[] = {"gpio", "-w", "-p", "18", NULL};
    gpio::Options opts(argvlen(argv), argv);

    assert(!opts.reading());
    assert(opts.writing());
    assert(opts.pin_number() == 18);
}

}
}

#pragma GCC diagnostic pop

int main() {
    test::options::read_pin();
    test::options::read_pin_short();
    test::options::write_pin();
    test::options::write_pin_short();

    ::exit(EXIT_SUCCESS);
}
