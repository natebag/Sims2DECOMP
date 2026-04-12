// FLAGS: -fno-elide-constructors
// 0x800AEADC boxx_func (48b)

extern void boxx_target(void*, unsigned char, int, void*, void*);

void boxx_func(void* self, char* obj, void* p3) {
    boxx_target(self, *(unsigned char*)(obj + 20), 0, p3, obj);
}
