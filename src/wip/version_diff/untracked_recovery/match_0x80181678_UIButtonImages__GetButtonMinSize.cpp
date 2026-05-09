// MATCH: 0x80181678 UIButtonImages::GetButtonMinSize(int) | Size: 40 bytes
// FLAGS: -O2 -g0

struct ButtonSizeTable {
    float sizes[64];
};

extern ButtonSizeTable* g_buttonSizeTable;
extern float g_defaultButtonMinSize __attribute__((section(".data")));

struct UIButtonImages {
    static float GetButtonMinSize(int button);
};

float UIButtonImages::GetButtonMinSize(int button) {
    ButtonSizeTable* table = g_buttonSizeTable;
    if (!table) return g_defaultButtonMinSize;
    return table->sizes[button + 28];
}
