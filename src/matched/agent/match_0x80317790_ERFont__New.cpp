// 0x80317790 ERFont::New (40b)
struct ERFont {
    char _pad[108];
    static void *operator new(unsigned int);
    ERFont(void);
};

ERFont *ERFont__New(void) {
    ERFont *p = new ERFont;
    return p;
}
