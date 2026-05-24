// 0x800253AC EHouse::CleanUpRoomLights(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x28(31); cmpwi 0,0; beq 4f; lwz 0,0x2c(31); li 29,1; cmpw 29,0; bge 2f; li 30,4; 0:; lwz 9,0x28(31); lwzx 4,30,9; cmpwi 4,0; beq 1f; lwz 3,0x1c(31); bl _s800253AC_0; lwz 9,0x28(31); lwzx 11,30,9; cmpwi 11,0; beq 1f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x2c(31); addi 29,29,1; addi 30,30,4; cmpw 29,0; blt 0b; 2:; lwz 3,0x28(31); cmpwi 3,0; beq 3f; bl _s800253AC_1; 3:; li 0,0; stw 0,0x28(31); 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800253AC_0();
extern "C" void _s800253AC_1();

struct EHouse {
    void CleanUpRoomLights();
};

void EHouse::CleanUpRoomLights() {
}
