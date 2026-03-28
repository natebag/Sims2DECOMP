// 0x801997C0 (72 bytes)
// CASSelectionTarget::ConvertGridStringToOptionArrayIdx(char *)

class CASSelectionTarget { public: void ConvertGridStringToOptionArrayIdx(char *); };

__attribute__((naked))
void CASSelectionTarget::ConvertGridStringToOptionArrayIdx(char *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x8BC40000\n.long 0x7C7D1B78\n.long 0x38640001\n.long 0x7FDE0774\n.long 0x48145471\n.long 0x7C651B78\n.long 0x7FC4F378\n.long 0x7FA3EB78\n.long 0x48000681\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
