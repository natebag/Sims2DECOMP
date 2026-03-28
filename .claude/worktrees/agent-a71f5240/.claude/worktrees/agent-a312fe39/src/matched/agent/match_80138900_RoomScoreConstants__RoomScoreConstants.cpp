// 0x80138900 (64 bytes)
// RoomScoreConstants::RoomScoreConstants(void)

class RoomScoreConstants { public: void RoomScoreConstants(void); };

__attribute__((naked))
void RoomScoreConstants::RoomScoreConstants(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38800003\n.long 0x4BFB3751\n.long 0x3D208046\n.long 0x7FC3F378\n.long 0x392944E0\n.long 0x913E0000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
