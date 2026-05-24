// 0x801376EC Room::Clear(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32706; li 0,0; lfs f0,-11420(9); addi 10,3,20; li 9,1; lwz 11,0x14(3); stw 0,0x94(3); stw 9,0x84(3); stfs f0,0x48(3); stw 0,0x34(3); stw 0,0x4c(3); stw 0,0x54(3); stw 0,0x58(3); stw 0,0x5c(3); stw 0,0x60(3); stw 0,0x64(3); stw 0,0x68(3); stw 0,0x6c(3); stw 0,0x70(3); stw 0,0x50(3); stw 0,0x74(3); stw 0,0x78(3); stfs f0,0x7c(3); stfs f0,0x80(3); stw 0,0x88(3); stw 0,0x8c(3); stw 0,0x9c(3); stw 0,0xa0(3); lwz 0,0x4(10); mr 9,11; cmpw 11,0; beq 1f; 0:; addi 9,9,12; cmpw 9,0; bne 0b; 1:; stw 11,0x4(10)"

struct Room {
    void Clear();
};

void Room::Clear() {
}
