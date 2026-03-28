void SetPtrVar(char*, void*);

struct GetVar_GetCount {
    char pad[0x0C];
    int count;
    void Handler(char* msg);
};

void GetVar_GetCount::Handler(char* msg) {
    SetPtrVar(msg, &count);
}
