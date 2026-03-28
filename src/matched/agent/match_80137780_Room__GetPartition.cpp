// 0x80137780 (88 bytes)
// Room::GetPartition(void)

class Room { public: void GetPartition(void); };

__attribute__((naked))
void Room::GetPartition(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x3BE30024\n.long 0x81630024\n.long 0x813F0004\n.long 0x3C00CCCC\n.long 0x6000CCCD\n.long 0x7D2B4850\n.long 0x7D2901D6\n.long 0x5520F0BF\n.long 0x40820010\n.long 0xA0630000\n.long 0x7FE4FB78\n.long 0x4801E115\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
