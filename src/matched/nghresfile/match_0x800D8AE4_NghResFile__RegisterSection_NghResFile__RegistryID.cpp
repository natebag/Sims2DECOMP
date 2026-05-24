// 0x800D8AE4 NghResFile::RegisterSection(NghResFile::RegistryID, (556 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 26,0x20(1); stw 0,0x3c(1); lwz 0,0x14(3); lwz 9,0x10(3); cmplw 9,0; bge 1f; mr 11,0; 0:; lwz 0,0x0(9); cmpw 0,4; beq 15f; addi 9,9,16; cmplw 9,11; blt 0b; 1:; stw 4,0x8(1); addi 31,1,8; stw 5,0x4(31); addi 29,3,16; stw 6,0x8(31); stw 7,0xc(31); lwz 9,0x4(29); lwz 0,0xc(29); cmpw 9,0; beq 2f; lwz 0,0x8(1); stw 7,0xc(9); stw 0,0x0(9); stw 5,0x4(9); stw 6,0x8(9); lwz 9,0x4(29); addi 9,9,16; stw 9,0x4(29); b 18f; 2:; lwz 0,0x10(3); mr 28,9; li 9,1; addi 11,1,28; subf 0,0,28; stw 9,0x1c(1); srawi 3,0,4; addi 9,1,24; stw 3,0x18(1); cmplwi 3,1; bge 3f; mr 9,11; 3:; lwz 0,0x0(9); add. 0,3,0; beq 5f; rlwinm 0,0,4,0,27; mr 27,0; cmplwi 0,128; ble 4f; mr 3,27; bl _s800D8AE4_0; b 6f; 4:; mr 3,27; bl _s800D8AE4_1; b 6f; 5:; li 3,0; li 27,0; 6:; mr 30,3; lwz 8,0x0(29); mr 26,30; mr 3,26; cmpw 8,28; beq 8f; 7:; lwz 0,0x0(8); lwz 9,0x4(8); lwz 11,0x8(8); lwz 10,0xc(8); stw 0,0x0(3); addi 8,8,16; stw 9,0x4(3); cmpw 8,28; stw 11,0x8(3); stw 10,0xc(3); addi 3,3,16; bne 7b; 8:; lwz 0,0x1c(1); mr 30,3; cmpwi 0,1; bne 9f; lwz 10,0xc(31); lwz 0,0x0(31); lwz 9,0x4(31); lwz 11,0x8(31); stw 0,0x0(30); stw 9,0x4(30); stw 11,0x8(30); stw 10,0xc(30); addi 30,30,16; b 12f; 9:; mr. 9,0; mr 3,30; mtspr 9,9; beq 11f; 10:; lwz 0,0x0(31); lwz 9,0x4(31); lwz 11,0x8(31); lwz 10,0xc(31); stw 0,0x0(3); stw 9,0x4(3); stw 11,0x8(3); stw 10,0xc(3); addi 3,3,16; bdnz 10b; 11:; mr 30,3; 12:; lwz 9,0x0(29); lwz 11,0x4(29); mr 3,9; lwz 0,0xc(29); cmpw 9,11; beq 14f; 13:; addi 9,9,16; cmpw 9,11; bne 13b; 14:; subf 0,3,0; cmpwi 3,0; srawi 0,0,4; beq 17f; rlwinm 4,0,4,0,27; cmplwi 4,128; ble 16f; bl _s800D8AE4_2; b 17f; 15:; li 3,0; b 19f; 16:; bl _s800D8AE4_3; 17:; add 0,27,26; stw 26,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 18:; li 3,1; 19:; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x20(1); addi 1,1,56"

extern "C" void _s800D8AE4_0();
extern "C" void _s800D8AE4_1();
extern "C" void _s800D8AE4_2();
extern "C" void _s800D8AE4_3();

struct NghResFile {
    void RegisterSection_NghResFile__RegistryID();
};

void NghResFile::RegisterSection_NghResFile__RegistryID() {
}
