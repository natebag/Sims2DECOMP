// 0x80146F10 (104 bytes)
// TileWalls::First(void) const

class TileWalls { public: void First(void) const; };

__attribute__((naked))
void TileWalls::First(void) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x801E0000\n.long 0x2C000000\n.long 0x41820034\n.long 0x3BE00001\n.long 0x48000008\n.long 0x57FF083C\n.long 0x7FC3F378\n.long 0x7FE4FB78\n.long 0x4BFFFA55\n.long 0x2C030000\n.long 0x4182FFEC\n.long 0x7FE3FB78\n.long 0x4BFFF8E9\n.long 0x7FE3FB78\n.long 0x48000008\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
