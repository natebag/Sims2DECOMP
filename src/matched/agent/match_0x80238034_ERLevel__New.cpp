void *ERLevel__New_alloc(unsigned int);
void *ERLevel__ctor(void *);

void *ERLevel__New(void) {
    void *p = ERLevel__New_alloc(0x2E460);
    return ERLevel__ctor(p);
}
