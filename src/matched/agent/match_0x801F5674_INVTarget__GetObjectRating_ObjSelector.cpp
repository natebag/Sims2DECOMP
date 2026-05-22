// 0x801F5674 INVTarget::GetObjectRating(ObjSelector (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); li 0,0; mr 31,5; mr 29,6; stw 0,0x0(31); stw 0,0x0(29); mr. 30,4; beq 0f; mr 3,30; bl _s801F5674_0; mr. 30,3; bne 2f; 0:; li 3,0; b 4f; 1:; lwz 9,0x0(31); addi 9,9,1; stw 9,0x0(31); 2:; lwz 4,0x0(31); cmpwi 4,13; bgt 3f; mr 3,30; bl _s801F5674_1; cmpwi 3,0; stw 3,0x0(29); ble 1b; 3:; lwz 0,0x0(31); cmpwi 7,0,13; cror 31,30,28; mfcr 3; rlwinm 3,3,0,31,31; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801F5674_0();
extern "C" void _s801F5674_1();
extern "C" void f_801F5674() {}
