struct ERAnim {
    static void *operator new(unsigned int, void *p);
};
void *ERAnim::operator new(unsigned int, void *p) { return p; }
