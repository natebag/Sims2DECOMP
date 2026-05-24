// 0x800F46C0 ObjectModuleImpl::Destroy(void) (568 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 22,0x28(1); stw 0,0x54(1); mr 30,3; lwz 0,0x14(30); cmpwi 0,0; beq 9f; addi 9,30,8336; lwz 29,0x2090(30); lwz 0,0x4(9); mr 27,9; addi 25,30,8352; addi 28,1,8; cmpw 29,0; addi 26,30,8344; addi 23,1,32; addi 24,30,36; addi 22,1,24; beq 2f; 0:; lwz 3,0x0(29); cmpwi 3,0; beq 1f; lwz 31,0x4(3); mr 3,30; mr 4,31; bl _s800F46C0_0; cmpwi 31,0; beq 1f; lwz 3,0x0(31); li 4,3; lwz 9,0x18(3); lha 0,0x8(9); lwz 9,0xc(9); add 3,3,0; mtspr 8,9; blrl; 1:; lwz 0,0x4(27); addi 29,29,4; cmpw 29,0; bne 0b; 2:; mr 29,25; addi 27,25,60; 3:; lwz 3,0x0(29); addi 29,29,4; cmpwi 3,0; beq 4f; lwz 31,0x4(3); mr 3,30; mr 4,31; bl _s800F46C0_1; cmpwi 31,0; beq 4f; lwz 3,0x0(31); li 4,3; lwz 9,0x18(3); lha 0,0x8(9); lwz 9,0xc(9); add 3,3,0; mtspr 8,9; blrl; 4:; cmpw 29,27; ble 3b; li 0,0; addi 8,28,8; stw 0,0x8(1); stw 0,0x4(28); stw 0,0x4(8); lwz 0,0x2094(30); lwz 9,0x2090(30); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x2090(30); stw 10,0x2094(30); lwz 11,0x2098(30); lwz 0,0x4(8); stw 0,0x4(23); lwz 9,0x4(26); stw 11,0x8(28); stw 9,0x4(8); lwz 0,0x20(1); lwz 3,0x8(1); lwz 9,0x24(1); stw 0,0x2098(30); cmpwi 3,0; stw 9,0x4(26); beq 6f; lwz 0,0xc(28); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 5f; bl _s800F46C0_2; b 6f; 5:; bl _s800F46C0_3; 6:; mr 3,25; li 4,0; li 5,64; bl _s800F46C0_4; li 0,0; stw 0,0x8(1); addi 8,28,8; stw 0,0x4(28); stw 0,0x4(8); lwz 0,0x20(30); lwz 9,0x1c(30); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x1c(30); stw 10,0x20(30); lwz 11,0x24(30); lwz 0,0x4(8); stw 0,0x4(22); lwz 9,0x4(24); stw 11,0x8(28); stw 9,0x4(8); lwz 0,0x18(1); lwz 3,0x8(1); lwz 9,0x1c(1); stw 0,0x24(30); cmpwi 3,0; stw 9,0x4(24); beq 8f; lwz 0,0xc(28); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 7f; bl _s800F46C0_5; b 8f; 7:; bl _s800F46C0_6; 8:; li 0,0; stw 0,0x14(30); 9:; lwz 0,0x54(1); mtspr 8,0; lmw 22,0x28(1); addi 1,1,80"

extern "C" void _s800F46C0_0();
extern "C" void _s800F46C0_1();
extern "C" void _s800F46C0_2();
extern "C" void _s800F46C0_3();
extern "C" void _s800F46C0_4();
extern "C" void _s800F46C0_5();
extern "C" void _s800F46C0_6();

struct ObjectModuleImpl {
    void Destroy();
};

void ObjectModuleImpl::Destroy() {
}
