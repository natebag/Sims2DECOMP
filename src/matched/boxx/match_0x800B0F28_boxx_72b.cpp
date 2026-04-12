// FLAGS: -fno-elide-constructors
// 0x800B0F28 boxx_72b (72b)

extern float g_boxx_floats2[4];
int boxx_getval2(void*);
void boxx_apply2(void*, int, float);
void boxx_finalize(void*);

void boxx_72b(void* self) {
    int val = boxx_getval2(self);
    boxx_apply2(self, val, *(float*)g_boxx_floats2);
    boxx_finalize(self);
}
