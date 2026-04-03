struct ERTexture {
    static void *operator new(unsigned int, void *p);
};
void *ERTexture::operator new(unsigned int, void *p) { return p; }
