struct ERCharacter {
    static void *operator new(unsigned int, void *p);
};
void *ERCharacter::operator new(unsigned int, void *p) { return p; }
