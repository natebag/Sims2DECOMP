struct ENgcShader {
    static void *operator new(unsigned int, void *p);
};
void *ENgcShader::operator new(unsigned int, void *p) { return p; }
