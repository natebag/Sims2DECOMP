// 0x80369E78 ERSoundEvent::New (40b)
struct ERSoundEvent {
    char _pad[52];
    static void *operator new(unsigned int);
    ERSoundEvent(void);
};

ERSoundEvent *ERSoundEvent__New(void) {
    ERSoundEvent *p = new ERSoundEvent;
    return p;
}
