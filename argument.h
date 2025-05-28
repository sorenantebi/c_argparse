#include <iostream>
#include <sstream>

template<class DstType, class SrcType>
inline DstType LexicalCast(const SrcType& src){
    DstType dst;
    std::stringstream ss(src);
    ss >> dst;
    return dst;
}



template<class ArgType>
ArgType CLArgument(const char *test_arg_short, const char *test_arg, int& argc, char *argv[], const ArgType& defaultValue){
    ArgType foundval = defaultValue;
    for (int n = 0; n < argc -1; ++n){
        if((strcmp(test_arg, argv[n]) == 0 || strcmp(test_arg_short, argv[n]) ==0) && strcmp("", argv[n]) != 0){
            const char *p = argv[n + 1];
            try{
                foundval = LexicalCast<ArgType>(p);
            }
            catch(...){}

            argc -= 2;
            for (; n < argc; ++n)
                argv[n] = argv[n+2];
        }
    }
    return foundval;
}


template<class ArgType>
ArgType CLArgument(const char* testarg, int& argc, char* argv[], const ArgType& defaultValue){
    return CLArgument("", testarg, argc, argv, defaultValue);
}
