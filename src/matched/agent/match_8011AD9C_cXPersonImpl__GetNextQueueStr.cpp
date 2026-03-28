// 0x8011AD9C (104 bytes)
// cXPersonImpl::GetNextQueueStr(int)

class cXPersonImpl { public: void GetNextQueueStr(int); };

__attribute__((naked))
void cXPersonImpl::GetNextQueueStr(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030534\n.long 0x39200000\n.long 0x2C000000\n.long 0x41820008\n.long 0x39200001\n.long 0x39630130\n.long 0x7D244A14\n.long 0x806B02A8\n.long 0x3C00CCCC\n.long 0x6000CCCD\n.long 0x7C634A14\n.long 0x7C030016\n.long 0x5400E8FE\n.long 0x1C00000A\n.long 0x7C601850\n.long 0x1C630044\n.long 0x7C6B1A14\n.long 0x4BFA6AC5\n.long 0x4BF88585\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
