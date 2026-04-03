// 0x803135ac (20 bytes) — VERIFIED MATCH
// FlashBigFile::FlashBigFile(void) — zeros two fields
struct FlashBigFile_C { int b; int a; FlashBigFile_C(); };
FlashBigFile_C::FlashBigFile_C() : b(0), a(0) {}
