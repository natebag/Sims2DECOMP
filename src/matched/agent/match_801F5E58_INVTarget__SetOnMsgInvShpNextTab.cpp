// 0x801F5E58 (104 bytes)
// INVTarget::SetOnMsgInvShpNextTab(char *)

class INVTarget { public: void SetOnMsgInvShpNextTab(char *); };

__attribute__((naked))
void INVTarget::SetOnMsgInvShpNextTab(char *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6A1B78\n.long 0x392A0178\n.long 0x810A0178\n.long 0x80090004\n.long 0x7C080050\n.long 0x540BE8FF\n.long 0x41820034\n.long 0x38000000\n.long 0x896A3250\n.long 0x980A3251\n.long 0x396B0001\n.long 0x81290004\n.long 0x7D284850\n.long 0x7D291E70\n.long 0x7C0B4B96\n.long 0x7C0049D6\n.long 0x7D605850\n.long 0x996A3250\n.long 0x480001E9\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
