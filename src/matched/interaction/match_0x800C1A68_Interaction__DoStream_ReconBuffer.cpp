// 0x800C1A68 Interaction::DoStream(ReconBuffer (524 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; mr 30,4; lwz 0,0x4(31); addi 4,1,8; mr 3,30; li 5,1; stw 0,0x8(1); lwz 29,-21484(13); bl _s800C1A68_0; lwz 0,0x8(1); mr 3,30; addi 4,31,56; li 5,1; stw 0,0x4(31); bl _s800C1A68_1; lwz 11,0x8(31); cmpwi 11,0; beq 0f; lwz 9,0x4(11); lha 3,0x308(9); lwz 0,0x30c(9); add 3,11,3; mtspr 8,0; blrl; stw 3,0xc(1); b 1f; 0:; stw 11,0xc(1); 1:; lwz 11,0xc(31); cmpwi 11,0; beq 2f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; stw 3,0x10(1); b 3f; 2:; stw 11,0x10(1); 3:; lwz 11,0x10(31); cmpwi 11,0; beq 4f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; stw 3,0x14(1); b 5f; 4:; stw 11,0x14(1); 5:; lwz 9,0x0(29); addi 5,1,12; mr 4,30; lwz 0,0x1e4(9); lha 3,0x1e0(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x0(29); addi 5,1,16; mr 4,30; lwz 0,0x1dc(9); lha 3,0x1d8(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x0(29); mr 4,30; addi 5,1,20; lwz 0,0x1dc(9); lha 3,0x1d8(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0xc(1); li 0,0; cmpwi 9,0; beq 6f; lwz 0,0x4(9); 6:; lwz 9,0x10(1); li 11,0; stw 0,0x8(31); cmpwi 9,0; beq 7f; lwz 11,0x4(9); 7:; lwz 9,0x14(1); li 0,0; stw 11,0xc(31); cmpwi 9,0; beq 8f; lwz 0,0x4(9); 8:; stw 0,0x10(31); mr 3,30; addi 4,31,20; li 5,1; bl _s800C1A68_2; mr 3,30; addi 4,31,24; li 5,4; bl _s800C1A68_3; mr 3,30; addi 4,31,40; li 5,1; bl _s800C1A68_4; mr 3,30; addi 4,31,44; li 5,1; bl _s800C1A68_5; mr 3,30; addi 4,31,48; li 5,1; bl _s800C1A68_6; mr 3,30; addi 4,31,60; li 5,1; bl _s800C1A68_7; lwz 3,0x38(31); lwz 0,-32024(13); cmpw 3,0; ble 9f; stw 3,-32024(13); 9:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"

extern "C" void _s800C1A68_0();
extern "C" void _s800C1A68_1();
extern "C" void _s800C1A68_2();
extern "C" void _s800C1A68_3();
extern "C" void _s800C1A68_4();
extern "C" void _s800C1A68_5();
extern "C" void _s800C1A68_6();
extern "C" void _s800C1A68_7();

struct Interaction {
    void DoStream_ReconBuffer();
};

void Interaction::DoStream_ReconBuffer() {
}
