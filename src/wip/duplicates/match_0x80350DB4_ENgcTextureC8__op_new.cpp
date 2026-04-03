struct ENgcTextureC8 {
    static void *operator new(unsigned int, void *p);
};
void *ENgcTextureC8::operator new(unsigned int, void *p) { return p; }
