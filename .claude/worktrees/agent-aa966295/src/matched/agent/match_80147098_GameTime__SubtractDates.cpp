// 0x80147098 (76 bytes)
// GameTime::SubtractDates(int, int, int, int, int, int)

class GameTime { public: void SubtractDates(int, int, int, int, int, int); };

__attribute__((naked))
void GameTime::SubtractDates(int, int, int, int, int, int) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xBF61000C\n.long 0x90010024\n.long 0x7CDB3378\n.long 0x7CFD3B78\n.long 0x7D1C4378\n.long 0x48000031\n.long 0x7C7E1B78\n.long 0x7FA4EB78\n.long 0x7F63DB78\n.long 0x7F85E378\n.long 0x4800001D\n.long 0x7C63F050\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBB61000C\n.long 0x38210020\n.long 0x4E800020");
}
