/* QuickDataBehaviorConstants::QuickDataBehaviorConstants(void) - 0x8015A738 - 68 bytes */

struct IFFBehaviorConstants {
    char _data[0x1C];
    IFFBehaviorConstants(void);
};

struct QuickDataBehaviorConstants : public IFFBehaviorConstants {
    int m_field_01C;
    QuickDataBehaviorConstants(void);
};

extern void* __vt__QuickDataBehaviorConstants[];

QuickDataBehaviorConstants::QuickDataBehaviorConstants(void) : IFFBehaviorConstants() {
    m_field_01C = 0;
    *(void***)this = __vt__QuickDataBehaviorConstants;
}
