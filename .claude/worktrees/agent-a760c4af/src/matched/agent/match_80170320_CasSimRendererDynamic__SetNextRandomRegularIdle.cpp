// 0x80170320 (116 bytes)
// CasSimRendererDynamic::SetNextRandomRegularIdle(void)

class CasSimRendererDynamic { public: void SetNextRandomRegularIdle(void); };

__attribute__((naked))
void CasSimRendererDynamic::SetNextRandomRegularIdle(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38600064\n.long 0x4BF3620D\n.long 0x2C03000E\n.long 0x41810010\n.long 0x813E0224\n.long 0x83E90004\n.long 0x48000024\n.long 0x3803FFF1\n.long 0x2800000E\n.long 0x41810010\n.long 0x813E0224\n.long 0x83E90008\n.long 0x4800000C\n.long 0x813E0224\n.long 0x83E90000\n.long 0x7FC3F378\n.long 0x7FE4FB78\n.long 0x4BFFF111\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
