// 0x801357D8 (120 bytes)
// iResFile::AddWithLanguage(Memory::HandleNode *, int, short, StringBuffer &, char, bool)

class iResFile { public: void AddWithLanguage(Memory::HandleNode *, int, short, StringBuffer &, char, bool); };

__attribute__((naked))
void iResFile::AddWithLanguage(Memory::HandleNode *, int, short, StringBuffer &, char, bool) {
    asm volatile(".long 0x9421FF90\n.long 0x7C0802A6\n.long 0xBF210054\n.long 0x90010074\n.long 0x3BC10008\n.long 0x7C7A1B78\n.long 0x7C9C2378\n.long 0x7CBB2B78\n.long 0x7D394B78\n.long 0x7CDD3378\n.long 0x389E0008\n.long 0x38A00040\n.long 0x7FC3F378\n.long 0x4BF70DA1\n.long 0x813A000C\n.long 0x7F84E378\n.long 0x7F65DB78\n.long 0x7FA6EB78\n.long 0xA86900F8\n.long 0x7FC7F378\n.long 0x800900FC\n.long 0x7F28CB78\n.long 0x7C7A1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x80010074\n.long 0x7C0803A6\n.long 0xBB210054\n.long 0x38210070\n.long 0x4E800020");
}
