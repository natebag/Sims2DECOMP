// 0x80012A74 AwarenessManager::handleMemoryAwarenessAnimation(unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,7; beq 1f; cmplwi 4,7; bgt 0f; cmplwi 4,4; bgt 2f; cmplwi 4,1; bge 1f; b 2f; 0:; cmplwi 4,15; ble 2f; cmpwi 4,16; bne 2f; 1:; lwz 0,0x0(3); andi. 9,0,16; beq 2f; lwz 4,0x18(3); lwz 5,0x14(3); bl _s80012A74_0; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80012A74_0();
extern "C" void f_80012A74() {}
