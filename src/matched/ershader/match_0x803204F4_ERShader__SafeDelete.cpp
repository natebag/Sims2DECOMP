// 0x803204F4 ERShader::SafeDelete (64B)

struct ERShader {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERShader();
    void SafeDelete();
};

void ERShader::SafeDelete() {
    if (this != 0) {
        delete this;
    }
}
