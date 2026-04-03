struct ENgcTexture {
    static void *operator new(unsigned int, void *p);
};
void *ENgcTexture::operator new(unsigned int, void *p) { return p; }
