struct ENgcTextureRGBA8 {
    static void *operator new(unsigned int, void *p);
};
void *ENgcTextureRGBA8::operator new(unsigned int, void *p) { return p; }
