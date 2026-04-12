// FLAGS: -fno-elide-constructors
// 0x800B0EB0 boxx_func (64b)

extern float g_boxx_floats[4];
int boxx_getval(void*);
void boxx_apply(void*, int val, float f);

void boxx_64(void* self) {
    int val = boxx_getval(self);
    boxx_apply(self, val, *(float*)g_boxx_floats);
}
