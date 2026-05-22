// 0x80218AD8 InteractorModule::InteractorVisualizer::AddModelToResourceSet(InteractorModule::Interactor (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr 7,3; addi 12,1,8; addi 6,7,8; lwz 3,0x8(7); lwz 0,0x4(6); stw 4,0x8(1); subf 0,3,0; srawi. 10,0,7; ble 3f; 0:; srawi 11,10,1; rlwinm 9,11,7,0,24; lwzx 0,3,9; add 8,3,9; cmplw 0,4; blt 1f; mr 10,11; b 2f; 1:; subf 9,11,10; addi 3,8,128; addi 10,9,-1; 2:; cmpwi 10,0; bgt 0b; 3:; lwz 11,0x4(6); cmpw 3,11; beq 4f; lwz 9,0x0(12); lwz 0,0x0(3); cmplw 9,0; bge 4f; mr 3,11; 4:; lwz 0,0xc(7); cmpw 3,0; beq 5f; addi 3,3,4; mr 4,5; bl _s80218AD8_0; b 6f; 5:; li 3,0; 6:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80218AD8_0();
extern "C" void f_80218AD8() {}
