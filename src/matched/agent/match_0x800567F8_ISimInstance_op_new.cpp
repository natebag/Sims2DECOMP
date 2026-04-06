// MATCH: 0x800567F8 ISimInstance::op_new (8 bytes)
// Raw: 7C 83 23 78 4E 80 00 20

extern "C" void* ISimInstance_op_new(unsigned int, void* ptr) {
    return ptr;
}
