// 0x800AC5A8 Behavior::GetConstants(short, (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,0x0(3); mr 30,4; mr 31,5; lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; lwz 11,-21508(13); mr 4,3; lwz 9,0x0(11); lha 3,0x198(9); lwz 0,0x19c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,30; bl _s800AC5A8_0; mr 11,3; stw 11,0x0(31); cmpwi 11,0; beq 0f; lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x0(31); li 3,1; cmpwi 0,0; bne 1f; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800AC5A8_0();

struct Behavior {
    void GetConstants();
};

void Behavior::GetConstants() {
}
