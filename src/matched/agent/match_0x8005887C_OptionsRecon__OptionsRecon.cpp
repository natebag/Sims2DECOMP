// 0x8005887C OptionsRecon::OptionsRecon() (84B)

typedef unsigned short u16;

class StringBuffer2 {
public:
    char data[8];
    StringBuffer2(u16* buf, unsigned int len);
};

class OptionsRecon {
public:
    char pad[0x58];
    StringBuffer2 m_buf1;
    u16 m_chars1[16];
    char pad80[0xA0 - 0x80];
    StringBuffer2 m_buf2;
    u16 m_chars2[16];
    OptionsRecon();
    void ResetToDefaults();
};

OptionsRecon::OptionsRecon() : m_buf1(m_chars1, 32), m_buf2(m_chars2, 32) {
    ResetToDefaults();
}
