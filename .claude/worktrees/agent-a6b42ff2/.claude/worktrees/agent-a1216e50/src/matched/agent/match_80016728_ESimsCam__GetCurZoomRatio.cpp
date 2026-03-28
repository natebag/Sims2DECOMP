// 0x80016728 (72 bytes)
// ESimsCam::GetCurZoomRatio(void)

class ESimsCam { public: void GetCurZoomRatio(void); };

__attribute__((naked))
void ESimsCam::GetCurZoomRatio(void) {
    asm volatile(".long 0x81230000\n.long 0x3D60803D\n.long 0xC1A30448\n.long 0xC1890028\n.long 0xC009002C\n.long 0xEDAD6028\n.long 0xC02BE300\n.long 0xEC006028\n.long 0xEDAD0024\n.long 0xFC0D0800\n.long 0x4D800020\n.long 0x3D20803D\n.long 0xFC206890\n.long 0xC009E304\n.long 0xFC0D0000\n.long 0x4C810020\n.long 0xFC200090\n.long 0x4E800020");
}
