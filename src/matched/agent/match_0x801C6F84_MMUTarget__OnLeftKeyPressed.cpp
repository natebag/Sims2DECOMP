// 0x801C6F84 (32B) MMUTarget::OnLeftKeyPressed(char *, char *)

struct MMUTarget_L {
    void DecrementChoice(char*, char*);
    void OnLeftKeyPressed(char* a, char* b);
};

void MMUTarget_L::OnLeftKeyPressed(char* a, char* b) {
    DecrementChoice(a, b);
}
