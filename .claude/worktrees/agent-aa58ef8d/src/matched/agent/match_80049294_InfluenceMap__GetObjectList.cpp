// 0x80049294 (76 bytes)
// InfluenceMap::GetObjectList(int, int)

class InfluenceMap { public: void GetObjectList(int, int); };

__attribute__((naked))
void InfluenceMap::GetObjectList(int, int) {
    asm volatile(".long 0x7C691B78\n.long 0x7C842379\n.long 0x41800024\n.long 0x2C050000\n.long 0x4180001C\n.long 0x80090000\n.long 0x7C040000\n.long 0x40800010\n.long 0x80690004\n.long 0x7C051800\n.long 0x4180000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x7C6419D6\n.long 0x80090008\n.long 0x7C632A14\n.long 0x54632036\n.long 0x7C630214\n.long 0x4E800020");
}
