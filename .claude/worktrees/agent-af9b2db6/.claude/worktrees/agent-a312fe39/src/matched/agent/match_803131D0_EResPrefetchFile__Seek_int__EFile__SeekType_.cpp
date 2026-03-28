// 0x803131D0 (108 bytes)
// EResPrefetchFile::Seek(int, EFile::SeekType)

class EFile { public: typedef int SeekType; };
class EResPrefetchFile { public: void Seek(int, EFile::SeekType); };

__attribute__((naked))
void EResPrefetchFile::Seek(int, EFile::SeekType) {
    asm volatile(".long 0x2C050000\n.long 0x40820018\n.long 0x80030040\n.long 0x7C832378\n.long 0x7C040000\n.long 0x4D820020\n.long 0x4E800020\n.long 0x81430030\n.long 0x81230034\n.long 0x80030038\n.long 0x7D6A2214\n.long 0x7D290214\n.long 0x7C0B4840\n.long 0x41800020\n.long 0x7C095000\n.long 0x4082000C\n.long 0x80030040\n.long 0x48000018\n.long 0x80030040\n.long 0x91230030\n.long 0x4800000C\n.long 0x80030040\n.long 0x91630030\n.long 0x7C002214\n.long 0x90030040\n.long 0x80630040\n.long 0x4E800020");
}
