// 0x80047E54 EIFloor::IsRoomInFloor(unsigned (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x7c(3); cmpw 4,0; bne 1f; 0:; li 3,1; blr; 1:; lwz 0,0x80(3); li 9,0; cmpw 9,0; bge 3f; mr 11,0; addi 3,3,132; 2:; lhz 0,0x0(3); addi 3,3,2; cmpw 4,0; beq 0b; addi 9,9,1; cmpw 9,11; blt 2b; 3:; li 3,0"

struct EIFloor {
    void IsRoomInFloor();
};

void EIFloor::IsRoomInFloor() {
}
