struct ERSampledata {
    static void *operator new(unsigned int, void *p);
};
void *ERSampledata::operator new(unsigned int, void *p) { return p; }
