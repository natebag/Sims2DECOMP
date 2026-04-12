// 0x8032047C ERShader::New (40b)
struct ERShader {
    char _pad[108];
    static void *operator new(unsigned int);
    ERShader(void);
};

ERShader *ERShader__New(void) {
    ERShader *p = new ERShader;
    return p;
}
