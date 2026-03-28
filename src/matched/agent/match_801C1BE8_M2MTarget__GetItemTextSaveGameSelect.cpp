// 0x801C1BE8 (88 bytes)
// M2MTarget::GetItemTextSaveGameSelect(int, unsigned wchar_t *)

class M2MTarget { public: void GetItemTextSaveGameSelect(int, unsigned wchar_t *); };

__attribute__((naked))
void M2MTarget::GetItemTextSaveGameSelect(int, unsigned wchar_t *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x5484103A\n.long 0x3D20803F\n.long 0x38840138\n.long 0x7CBD2B78\n.long 0x7FC32214\n.long 0x3889DFA4\n.long 0x7FC3F378\n.long 0x4BEE024D\n.long 0x7FC3F378\n.long 0x4BEE1759\n.long 0x7C641B78\n.long 0x7FA3EB78\n.long 0x4BEE62A9\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
