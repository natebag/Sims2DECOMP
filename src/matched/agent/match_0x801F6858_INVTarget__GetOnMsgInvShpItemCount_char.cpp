// 0x801F6858 INVTarget::GetOnMsgInvShpItemCount(char (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s801F6858_0; lwz 9,0x178(31); rlwinm 3,3,3,0,28; lwzx 11,9,3; add 9,9,3; lwz 0,0x4(9); cmpwi 11,9; mulli 3,0,12; beq 0f; blt 3f; cmpwi 11,10; beq 1f; cmpwi 11,11; beq 2f; b 3f; 0:; lwz 9,0x164(31); addi 10,3,-1; lwz 11,0x0(9); lwz 0,0x4(9); subf 0,11,0; srawi 0,0,3; subf 5,10,0; b 5f; 1:; lwz 9,0x168(31); lwz 11,0x0(9); lwz 0,0x4(9); subf 0,11,0; srawi 0,0,3; b 4f; 2:; lwz 9,0x16c(31); lwz 11,0x0(9); lwz 0,0x4(9); subf 0,11,0; srawi 0,0,3; b 4f; 3:; rlwinm 0,11,2,0,29; addi 9,31,320; lwzx 11,9,0; lwz 10,0x0(11); lwz 0,0x4(11); subf 0,10,0; srawi 0,0,2; 4:; subf 5,3,0; 5:; cmpwi 5,12; ble 6f; li 5,12; 6:; lis 4,-32704; mr 3,30; addi 4,4,-30836; crxor 6,6,6; bl _s801F6858_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801F6858_0();
extern "C" void _s801F6858_1();
extern "C" void f_801F6858() {}
