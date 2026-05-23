// 0x8002268C EDummyFile::Write(void (8 B)
struct EDummyFile { unsigned Write(const void*, unsigned); };
unsigned EDummyFile::Write(const void* buf, unsigned count) { return count; }
