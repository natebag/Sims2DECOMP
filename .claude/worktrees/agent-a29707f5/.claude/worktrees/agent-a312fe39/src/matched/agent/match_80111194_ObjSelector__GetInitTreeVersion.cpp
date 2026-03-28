// 0x80111194 (104 bytes)
// ObjSelector::GetInitTreeVersion(void)

class ObjSelector { public: void GetInitTreeVersion(void); };

__attribute__((naked))
void ObjSelector::GetInitTreeVersion(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F0074\n.long 0x2C00FFFF\n.long 0x40820034\n.long 0x480001F9\n.long 0x81230000\n.long 0x38800000\n.long 0xA8090070\n.long 0x81290074\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x7C641B78\n.long 0x807F000C\n.long 0x4BF9AB55\n.long 0x907F0074\n.long 0x807F0074\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
