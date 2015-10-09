#pragma once

namespace gpio {
    class Options {
    public:
        Options(int argc, char *argv[]);

        bool reading() const { return _readPin; }
        bool writing() const { return !_readPin; }
        int pin_number() const { return _pin; }
        bool verbose() const { return _verbose; }

    private:
        bool _readPin = true;
        int _pin = 0;
        bool _verbose = false;

        void print_usage(int argc, char *argv[]) const;
    };
}
