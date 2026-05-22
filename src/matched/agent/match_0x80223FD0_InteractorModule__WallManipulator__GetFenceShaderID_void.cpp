// 0x80223FD0 InteractorModule::WallManipulator::GetFenceShaderID(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc4(3); andi. 9,0,256; beq 0f; lwz 9,0xd8(3); lwz 3,0x0(9); blr; 0:; li 3,0"
extern "C" int f_80223FD0() {}
