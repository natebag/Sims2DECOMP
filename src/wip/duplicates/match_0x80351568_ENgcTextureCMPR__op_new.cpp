struct ENgcTextureCMPR {
    static void *operator new(unsigned int, void *p);
};
void *ENgcTextureCMPR::operator new(unsigned int, void *p) { return p; }
