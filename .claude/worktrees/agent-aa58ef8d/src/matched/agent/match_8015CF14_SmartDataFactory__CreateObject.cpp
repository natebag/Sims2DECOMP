// 0x8015CF14 (108 bytes)
// SmartDataFactory::CreateObject(unsigned int, unsigned int, void **)

class SmartDataFactory { public: void CreateObject(unsigned int, unsigned int, void **); };

__attribute__((naked))
void SmartDataFactory::CreateObject(unsigned int, unsigned int, void **) {
    asm volatile(".long 0x9421FFD8\n.long 0x7C0802A6\n.long 0xBF610014\n.long 0x9001002C\n.long 0x7C7D1B78\n.long 0x7C9B2378\n.long 0x83DD0000\n.long 0x7CA42B78\n.long 0x7CDC3378\n.long 0x38A00000\n.long 0xA81E0020\n.long 0x38610008\n.long 0x3BDE0020\n.long 0x7FBD0214\n.long 0x4BFFEBA9\n.long 0x801E0004\n.long 0x7FA3EB78\n.long 0x7F64DB78\n.long 0x7F86E378\n.long 0x38A10008\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001002C\n.long 0x7C0803A6\n.long 0xBB610014\n.long 0x38210028\n.long 0x4E800020");
}
