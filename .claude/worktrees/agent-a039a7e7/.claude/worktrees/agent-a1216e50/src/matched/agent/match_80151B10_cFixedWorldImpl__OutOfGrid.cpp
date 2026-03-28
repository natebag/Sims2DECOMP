// 0x80151B10 (72 bytes)
// cFixedWorldImpl::OutOfGrid(CTilePt &) const

class cFixedWorldImpl { public: void OutOfGrid(CTilePt &) const; };

__attribute__((naked))
void cFixedWorldImpl::OutOfGrid(CTilePt &) const {
    asm volatile(".long 0x88040000\n.long 0x7C090774\n.long 0x2C090000\n.long 0x4180002C\n.long 0x80030014\n.long 0x7C090000\n.long 0x40800020\n.long 0x88040001\n.long 0x7C040774\n.long 0x2C040000\n.long 0x41800010\n.long 0x80030018\n.long 0x7C040000\n.long 0x4180000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
