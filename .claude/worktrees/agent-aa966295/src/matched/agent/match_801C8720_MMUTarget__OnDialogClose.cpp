// 0x801C8720 (104 bytes)
// MMUTarget::OnDialogClose(int)

class MMUTarget { public: void OnDialogClose(int); };

__attribute__((naked))
void MMUTarget::OnDialogClose(int) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C9F2378\n.long 0x7C7D1B78\n.long 0x2C1F0001\n.long 0x40820038\n.long 0x3D208047\n.long 0x3BC00000\n.long 0x39295B84\n.long 0x93E90084\n.long 0x93C900F0\n.long 0x4BFFE871\n.long 0x3D208047\n.long 0x7FA3EB78\n.long 0x39295DCC\n.long 0x38800001\n.long 0x93C9044C\n.long 0x93E90448\n.long 0x4BFFFDE1\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
