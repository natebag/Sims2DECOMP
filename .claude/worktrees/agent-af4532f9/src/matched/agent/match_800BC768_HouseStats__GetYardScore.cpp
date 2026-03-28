// 0x800BC768 (80 bytes)
// HouseStats::GetYardScore(void)

class HouseStats { public: void GetYardScore(void); };

__attribute__((naked))
void HouseStats::GetYardScore(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x816DAC20\n.long 0x3D20803E\n.long 0xC00DA114\n.long 0xC1AB002C\n.long 0xC1899E08\n.long 0xEC0D0032\n.long 0xFC006000\n.long 0x40800008\n.long 0xFC006090\n.long 0x3D20803E\n.long 0xC1A99E0C\n.long 0xFC006800\n.long 0x40810008\n.long 0xFC006890\n.long 0xFDA0001E\n.long 0xD9A10008\n.long 0x8061000C\n.long 0x38210010\n.long 0x4E800020");
}
