// 0x801E9308 (72 bytes)
// GetVar_EYE_settingSliderVal::Handler(char *)

class GetVar_EYE_settingSliderVal { public: void Handler(char *); };

__attribute__((naked))
void GetVar_EYE_settingSliderVal::Handler(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x8003000C\n.long 0x7C9E2378\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x3C808040\n.long 0x7FC3F378\n.long 0x388487A0\n.long 0x4CC63242\n.long 0x480F5551\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
