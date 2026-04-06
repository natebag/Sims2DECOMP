// FLAGS: -fno-elide-constructors
// 0x800AFEE8 boxx_func_a (60b)
void boxx_f2a(void*);
void boxx_f3a(void*);

void boxx_60a(void* self) {
    boxx_f1a(self);
    boxx_f2a(self);
    boxx_f3a(self);
}
