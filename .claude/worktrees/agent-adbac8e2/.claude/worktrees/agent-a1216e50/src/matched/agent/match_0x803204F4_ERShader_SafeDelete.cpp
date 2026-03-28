/* ERShader::SafeDelete(void) - 0x803204F4 (64 bytes) */

struct ERShader {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERShader();
    static void SafeDelete(ERShader *p);
};

void ERShader::SafeDelete(ERShader *p)
{
    if (p) {
        delete p;
    }
}
