// 0x80175228 (108 bytes)
// CasSimState::SetSimName(unsigned wchar_t *, unsigned wchar_t *)

class CasSimState { public: void SetSimName(unsigned wchar_t *, unsigned wchar_t *); };

__attribute__((naked))
void CasSimState::SetSimName(unsigned wchar_t *, unsigned wchar_t *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7F1B78\n.long 0x7CBD2B78\n.long 0x7C9E2379\n.long 0x4182001C\n.long 0x387F000C\n.long 0x7FC4F378\n.long 0x38A00020\n.long 0x4BF32CAD\n.long 0x38000000\n.long 0xB01F004A\n.long 0x2C1D0000\n.long 0x4182001C\n.long 0x7FC4F378\n.long 0x387F000C\n.long 0x38A00020\n.long 0x4BF32C8D\n.long 0x38000000\n.long 0xB01F004A\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
