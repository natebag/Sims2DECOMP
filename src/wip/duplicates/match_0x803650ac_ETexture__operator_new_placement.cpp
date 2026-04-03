struct ETexture {
    void *operator new(unsigned int, void *p);
};
void *ETexture::operator new(unsigned int, void *p) { return p; }
