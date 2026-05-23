// 0x80048344 EIFloor::operator (8 B)
struct EIFloor { unsigned operator=(unsigned); };
unsigned EIFloor::operator=(unsigned x) { return x; }
