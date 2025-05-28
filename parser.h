#include "argument.h"

class ArgumentParser{
    public:

    ArgumentParser(int& argc, char* argv[]) : argc(argc), argv(argv) {}

    template<class ArgType>
    ArgType add_argument(const char* identifier, const ArgType& defaultValue){
        return CLArgument<ArgType>(identifier, argc, argv, defaultValue);
    }

    void parse_arguments() {
        
        if (argc != 1) {
            std::string msg = "Error: Duplicate or unrecognized arguments:\n";
            for (int i = 1; i < argc; i++) {
                msg += "arg " + std::to_string(i) + ": " + argv[i] + "\n";
            }
            throw std::runtime_error(msg);
        }
    }

    private:
    int& argc;
    char** argv;


};