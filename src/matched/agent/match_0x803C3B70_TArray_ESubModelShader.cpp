// 0x803C3B70 TArray<ESubModelShader, (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 27,4; addi 29,5,-1; cmpwi 5,0; beq 2f; 0:; mr 30,27; mr 31,28; lwz 0,0x0(30); addi 4,30,20; addi 3,31,20; addi 27,30,112; stw 0,0x0(31); addi 28,31,112; lwz 0,0x4(30); stw 0,0x4(31); lwz 9,0x8(30); stw 9,0x8(31); lwz 0,0xc(30); stw 0,0xc(31); lwz 9,0x10(30); stw 9,0x10(31); bl _s803C3B70_0; lwz 0,0x20(30); addi 3,31,44; addi 4,30,44; stw 0,0x20(31); lfs f0,0x24(30); stfs f0,0x24(31); lwz 0,0x28(30); stw 0,0x28(31); bl _s803C3B70_1; li 0,12; addi 5,29,-1; mtspr 9,0; addi 11,31,56; addi 9,30,56; 1:; lwz 0,0x0(9); addi 9,9,4; stw 0,0x0(11); addi 11,11,4; bdnz 1b; lwz 9,0x68(30); mr 29,5; cmpwi 29,-1; stw 9,0x68(31); lwz 0,0x6c(30); stw 0,0x6c(31); bne 0b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s803C3B70_0();
extern "C" void _s803C3B70_1();
extern "C" void f_803C3B70() {}
