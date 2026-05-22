// 0x803354FC ENgcMovie::GetNextFrame(void) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; bl _s803354FC_0; cmpwi 3,6; bgt 0f; cmpwi 3,4; bge 1f; cmpwi 3,0; beq 5f; cmpwi 3,2; beq 5f; b 4f; 0:; cmpwi 3,8; beq 5f; cmpwi 3,11; bne 4f; 1:; lwz 11,-26348(13); cmpwi 11,0; bne 8f; lis 9,-32691; lbz 0,0x39e4(9); cmpwi 0,2; bne 2f; li 0,1; mr 3,31; stw 0,-26344(13); bl _s803354FC_1; b 3f; 2:; stw 11,-26344(13); 3:; li 0,1; stw 0,-26348(13); b 5f; 4:; lwz 0,-26348(13); cmpwi 0,0; beq 6f; lwz 9,-26344(13); li 0,0; stw 0,-26348(13); cmpwi 9,0; beq 5f; mr 3,31; bl _s803354FC_2; 5:; lwz 0,-26348(13); cmpwi 0,0; bne 8f; 6:; lwz 4,0x24(31); mr 3,31; lwz 5,0x18(31); lwz 6,0x1c(31); lwz 7,0x28(31); lwz 8,0x2c(31); bl _s803354FC_3; cmpwi 3,0; stw 3,0x10(31); blt 7f; li 30,1; 7:; mr 3,31; bl _s803354FC_4; 8:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803354FC_0();
extern "C" void _s803354FC_1();
extern "C" void _s803354FC_2();
extern "C" void _s803354FC_3();
extern "C" void _s803354FC_4();
extern "C" void f_803354FC() {}
