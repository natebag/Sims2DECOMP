// MATCH: 0x80048344 EIFloor::op_new (8 bytes)
// Raw: 7C 83 23 78 4E 80 00 20

extern "C" void* EIFloor_op_new(unsigned int, void* ptr) {
    return ptr;
}
