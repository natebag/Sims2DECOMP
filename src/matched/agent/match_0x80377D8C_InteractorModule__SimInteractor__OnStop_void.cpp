// 0x80377D8C InteractorModule::SimInteractor::OnStop(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_80377E2C" lines="bl _s80377D8C_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0; blr; li 0,4; lis 3,-32690; mtspr 9,0; addi 3,3,-3232; li 5,0; li 4,0; lwz 6,0x0(3); b 2f; 0:; addi 5,5,1; cmplwi 5,64; ble 1f; li 3,0; blr; 1:; lwz 6,0x0(6); 2:; cmplwi 6,0; bne 0b; lwzu 6,0x4(3); b 5f; 3:; addi 5,5,1; cmplwi 5,64; ble 4f; li 3,0; blr; 4:; lwz 6,0x0(6); 5:; cmplwi 6,0; bne 3b; lwzu 6,0x4(3); addi 4,4,1"
extern "C" void _s80377D8C_0();
extern "C" void f_80377E2C();
extern "C" void f_80377D8C() {}
