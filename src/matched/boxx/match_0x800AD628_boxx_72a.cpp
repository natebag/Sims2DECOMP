// FLAGS: -fno-elide-constructors
// 0x800AD628 boxx_72a (72b)

int boxx_lookup(void*);

int boxx_72a(void* self, int param, int* out) {
    if (param > 20) return 0;
    *out = boxx_lookup(self);
    return 1;
}
