// 0x80190574 (116 bytes)
// SerializeUIGameData::AllocateLoadBuffers(void)

class SerializeUIGameData { public: void AllocateLoadBuffers(void); };

__attribute__((naked))
void SerializeUIGameData::AllocateLoadBuffers(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x3D208043\n.long 0x3B800000\n.long 0x3BC96C10\n.long 0x3BE00000\n.long 0x3BA00004\n.long 0x7C1FF02E\n.long 0x2C000000\n.long 0x41820014\n.long 0x4813F95D\n.long 0x7C9FF02E\n.long 0x481407CD\n.long 0x7F9FF12E\n.long 0x4813F94D\n.long 0x38800400\n.long 0x38A00000\n.long 0x481404E5\n.long 0x7C7FF12E\n.long 0x37BDFFFF\n.long 0x3BFF0004\n.long 0x4082FFC8\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
