// 0x80022684 EDummyFile::Read(void (8 B)
struct EDummyFile { unsigned Read(void*, unsigned); };
unsigned EDummyFile::Read(void* buf, unsigned count) { return count; }
