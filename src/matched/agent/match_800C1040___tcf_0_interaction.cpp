/* __tcf_0 (interaction.obj) - 40 bytes */

struct BString2 {
    int m_data[2];
    ~BString2(void);
};

static BString2 s_interactionString;

void __tcf_0(void) {
    s_interactionString.~BString2();
}
