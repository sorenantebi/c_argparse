#include "parser.h"

int main(int argc, char *argv[]){
    ArgumentParser parser(argc, argv);
    std::string type = parser.add_argument<std::string>("-t", "hello");

    parser.parse_arguments();

    std::cout << type << std::endl;
    return 1;
}