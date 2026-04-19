// 0x801C6FA4 (32B) MMUTarget::OnRightKeyPressed(char *, char *)

struct MMUTarget_R {
    void IncrementChoice(char*, char*);
    void OnRightKeyPressed(char* a, char* b);
};

void MMUTarget_R::OnRightKeyPressed(char* a, char* b) {
    IncrementChoice(a, b);
}
