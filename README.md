argparser for c++

```
g++ main.cpp -o main
```

Make sure the types are correct
```
int main(int argc, char *argv[]){
    ArgumentParser parser(argc, argv);
    std::string type = parser.add_argument<std::string>("-t", "hello");

    parser.parse_arguments();

    std::cout << type << std::endl;
    return 1;
}
```