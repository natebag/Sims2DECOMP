// FLAGS: -fno-elide-constructors
// 0x801F119C (88 bytes)
// INVTarget::ClearAllObjRelatedCheatStrings(void)

extern "C" void* memset(void* dst, int val, unsigned int size);

void INVTarget_ClearAllObjRelatedCheatStrings(char* self) {
    memset(self + 0x118B, 0, 0x800);
    memset(self + 0x198B, 0, 0x800);
    memset(self + 0x218B, 0, 0x800);
}
