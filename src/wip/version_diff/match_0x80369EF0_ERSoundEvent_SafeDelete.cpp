/* ERSoundEvent::SafeDelete(void) - 0x80369EF0 (64 bytes) */

struct ERSoundEvent {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERSoundEvent();
    static void SafeDelete(ERSoundEvent *p);
};

void ERSoundEvent::SafeDelete(ERSoundEvent *p)
{
    if (p) {
        delete p;
    }
}
