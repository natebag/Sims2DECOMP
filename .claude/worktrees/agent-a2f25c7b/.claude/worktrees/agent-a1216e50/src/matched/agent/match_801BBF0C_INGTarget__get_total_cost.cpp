// 0x801BBF0C (96 bytes)
// INGTarget::get_total_cost(unsigned int *) const

class INGTarget { public: void get_total_cost(unsigned int *) const; };

__attribute__((naked))
void INGTarget::get_total_cost(unsigned int *) const {
    asm volatile(".long 0x38000004\n.long 0x386301E0\n.long 0x7C0903A6\n.long 0x39400000\n.long 0x39000000\n.long 0x2C030000\n.long 0x4182002C\n.long 0x81630004\n.long 0x2C0B0000\n.long 0x41820020\n.long 0x81230000\n.long 0x2C090000\n.long 0x41820014\n.long 0xA8090002\n.long 0x394A0001\n.long 0x7C0059D6\n.long 0x7D080214\n.long 0x38630008\n.long 0x4200FFCC\n.long 0x2C040000\n.long 0x41820008\n.long 0x91440000\n.long 0x7D034378\n.long 0x4E800020");
}
