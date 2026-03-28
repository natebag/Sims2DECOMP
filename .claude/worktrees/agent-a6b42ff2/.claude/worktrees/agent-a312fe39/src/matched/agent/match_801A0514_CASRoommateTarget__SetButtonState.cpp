// 0x801A0514 (72 bytes)
// CASRoommateTarget::SetButtonState(void)

class CASRoommateTarget { public: void SetButtonState(void); };

__attribute__((naked))
void CASRoommateTarget::SetButtonState(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0x9001001C\n.long 0x38810008\n.long 0x48000039\n.long 0x38010008\n.long 0x3C60803F\n.long 0x90010010\n.long 0x3863D38C\n.long 0x38800000\n.long 0x38A00000\n.long 0x38C00001\n.long 0x38E10010\n.long 0x4BFD780D\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0x38210018\n.long 0x4E800020");
}
