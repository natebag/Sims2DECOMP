// 0x80138854 (96 bytes)
// GetLightRoomID(unsigned short)

__attribute__((naked))
void GetLightRoomID(unsigned short) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x83EDAC20\n.long 0x7C7E1B78\n.long 0x7FC4F378\n.long 0x7FE3FB78\n.long 0x4BFFDDD1\n.long 0x7C631B79\n.long 0x41820020\n.long 0xA0830002\n.long 0x7FE3FB78\n.long 0x4BFFDDBD\n.long 0x7C631B79\n.long 0x4182000C\n.long 0xA0630000\n.long 0x48000008\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
