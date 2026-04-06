// FLAGS: -fno-elide-constructors
// 0x800AFF24 boxx_func_b (60b)
void boxx_f2b(void*);
void boxx_f3b(void*);

void boxx_60b(void* self) {
    boxx_f1b(self);
    boxx_f2b(self);
    boxx_f3b(self);
}
