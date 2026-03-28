// 0x800B1644 (84 bytes)
// CareersImpl::GetCareerByID(int)

class CareersImpl { public: void GetCareerByID(int); };

__attribute__((naked))
void CareersImpl::GetCareerByID(int) {
    asm volatile(".long 0x81230008\n.long 0x39400000\n.long 0x38600000\n.long 0x8169000C\n.long 0x81290004\n.long 0x7C035840\n.long 0x4C800020\n.long 0x80090000\n.long 0x7C002000\n.long 0x4082000C\n.long 0x7D234B78\n.long 0x4E800020\n.long 0x394A0001\n.long 0x39290014\n.long 0x7C0A5840\n.long 0x4C800020\n.long 0x80090000\n.long 0x7C002000\n.long 0x4082FFE8\n.long 0x7D234B78\n.long 0x4E800020");
}
