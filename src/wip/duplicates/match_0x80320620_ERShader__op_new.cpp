struct ERShader {
    static void *operator new(unsigned int, void *p);
};
void *ERShader::operator new(unsigned int, void *p) { return p; }
