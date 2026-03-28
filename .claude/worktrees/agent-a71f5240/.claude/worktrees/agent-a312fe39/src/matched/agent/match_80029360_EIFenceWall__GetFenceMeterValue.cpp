// 0x80029360 (64 bytes)
// EIFenceWall::GetFenceMeterValue(void)

class EIFenceWall { public: void GetFenceMeterValue(void); };

__attribute__((naked))
void EIFenceWall::GetFenceMeterValue(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x800D8080\n.long 0x3D404330\n.long 0x3D20803D\n.long 0x6C008000\n.long 0xC8090CE8\n.long 0x9001000C\n.long 0x3D20803D\n.long 0xC1A90CF0\n.long 0x91410008\n.long 0xC8210008\n.long 0xFC210028\n.long 0xFC200818\n.long 0xEC216824\n.long 0x38210010\n.long 0x4E800020");
}
