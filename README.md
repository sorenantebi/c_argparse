argparser for c++

```
g++ main.cpp -o main
```

Make sure the types are correct
```
int main(int argc, char *argv[]){
    ArgumentParser parser(argc, argv);
    std::string name = parser.add_argument<std::string>("-flag", "defaultValue");

    parser.parse_arguments();

    std::cout << name << std::endl;
    return 1;
}
```