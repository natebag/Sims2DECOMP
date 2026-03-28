void SetIntVar(char*, int);

struct GetVar_SliderStep {
    char pad[0x0C];
    int value;
    void Handler(char* msg);
};

void GetVar_SliderStep::Handler(char* msg) {
    SetIntVar(msg, value);
}
