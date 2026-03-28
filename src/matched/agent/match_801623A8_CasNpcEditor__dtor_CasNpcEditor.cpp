// 0x801623A8 (120 bytes)
// CasNpcEditor::~CasNpcEditor(void)

class CasNpcEditor { public: void ~CasNpcEditor(void); };

__attribute__((naked))
void CasNpcEditor::~CasNpcEditor(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x3D208046\n.long 0x809F0064\n.long 0x39295FC8\n.long 0x387F0064\n.long 0x913F0004\n.long 0x48170575\n.long 0x809F0060\n.long 0x387F0060\n.long 0x48170569\n.long 0x809F005C\n.long 0x387F005C\n.long 0x4817055D\n.long 0x3D208046\n.long 0x73C00001\n.long 0x39295F68\n.long 0x913F0004\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x4816EE19\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
