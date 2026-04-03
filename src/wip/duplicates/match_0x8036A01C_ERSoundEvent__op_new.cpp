struct ERSoundEvent {
    static void *operator new(unsigned int, void *p);
};
void *ERSoundEvent::operator new(unsigned int, void *p) { return p; }
