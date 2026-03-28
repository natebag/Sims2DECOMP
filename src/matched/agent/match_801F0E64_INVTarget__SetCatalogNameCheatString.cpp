// 0x801F0E64 (100 bytes)
// INVTarget::SetCatalogNameCheatString(char *, int, unsigned wchar_t *)

class INVTarget { public: void SetCatalogNameCheatString(char *, int, unsigned wchar_t *); };

__attribute__((naked))
void INVTarget::SetCatalogNameCheatString(char *, int, unsigned wchar_t *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C9F2378\n.long 0x7CDD3379\n.long 0x4082000C\n.long 0x9BBF0000\n.long 0x48000030\n.long 0x3FC08040\n.long 0x7FE3FB78\n.long 0x3BDE9A8C\n.long 0x7FC4F378\n.long 0x48052A49\n.long 0x7FC3F378\n.long 0x48052AC5\n.long 0x7CBF1A14\n.long 0x3880FFFF\n.long 0x7FA3EB78\n.long 0x4BE19E35\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
