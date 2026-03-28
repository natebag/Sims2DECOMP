// 0x8005892C (96 bytes)
// OptionsRecon::ResetToDefaults(void)

class OptionsRecon { public: void ResetToDefaults(void); };

__attribute__((naked))
void OptionsRecon::ResetToDefaults(void) {
    asm volatile(".long 0x38000000\n.long 0x3960000A\n.long 0x39200001\n.long 0x3940FFFF\n.long 0x90030024\n.long 0x9963001E\n.long 0x99430054\n.long 0x91230014\n.long 0x91230000\n.long 0x91230004\n.long 0x91230008\n.long 0x9003000C\n.long 0x90030010\n.long 0x9963001C\n.long 0x9963001D\n.long 0x99630028\n.long 0x99630029\n.long 0x9803001F\n.long 0x98030020\n.long 0x900300E8\n.long 0x900300EC\n.long 0x900300F0\n.long 0x90030018\n.long 0x4E800020");
}
