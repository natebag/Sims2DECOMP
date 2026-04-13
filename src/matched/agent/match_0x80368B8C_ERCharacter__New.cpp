// 0x80368B8C ERCharacter::New (40b)
struct ERCharacter {
    char _pad[52];
    static void *operator new(unsigned int);
    ERCharacter(void);
};

ERCharacter *ERCharacter__New(void) {
    ERCharacter *p = new ERCharacter;
    return p;
}
