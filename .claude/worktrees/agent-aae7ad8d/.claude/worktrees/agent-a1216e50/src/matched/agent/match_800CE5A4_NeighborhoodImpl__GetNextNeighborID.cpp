// 0x800CE5A4 (84 bytes)
// NeighborhoodImpl::GetNextNeighborID(short)

class NeighborhoodImpl { public: void GetNextNeighborID(short); };

__attribute__((naked))
void NeighborhoodImpl::GetNextNeighborID(short) {
    asm volatile(".long 0x81230074\n.long 0x80030078\n.long 0x7C090050\n.long 0x7C001670\n.long 0x7C040040\n.long 0x40800038\n.long 0x7D2A4B78\n.long 0x7C0B0378\n.long 0x38040001\n.long 0x7C040734\n.long 0x3924FFFF\n.long 0x5529103A\n.long 0x7C0A482E\n.long 0x2C000000\n.long 0x4182000C\n.long 0x7C832378\n.long 0x4E800020\n.long 0x7C045840\n.long 0x4180FFD8\n.long 0x38600000\n.long 0x4E800020");
}
