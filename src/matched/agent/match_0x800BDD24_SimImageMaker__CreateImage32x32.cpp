// 0x800BDD24 (84B) SimImageMaker::CreateImage32x32(void)
// map says (void) but asm uses r4, r5 — real sig has 2 extra args

void func_80133634(void* a, void* b, int c);
void func_803a46fc(void* a, int b, void* c, void* d);

struct SimImageMaker {
    void CreateImage32x32(void* arg1, void* arg2);
};

void SimImageMaker::CreateImage32x32(void* arg1, void* arg2) {
    func_80133634(arg1, (char*)this + 16, 1);
    func_803a46fc(this, *(int*)this, arg1, arg2);
}
