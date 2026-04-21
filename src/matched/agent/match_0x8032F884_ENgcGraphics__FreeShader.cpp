// 0x8032F884 (64B) ENgcGraphics::FreeShader(EShader *)
// MI vcall: non-virtual 240B base, vtable at offset 240, slot 1 = Release(int).

class EShaderData {
protected:
    char pad[240];
};

class EShader : public EShaderData {
public:
    virtual void Release(int flags) = 0;
};

class ENgcGraphics {
public:
    void FreeShader(EShader* s);
};

void ENgcGraphics::FreeShader(EShader* s) {
    if (!s) return;
    s->Release(3);
}
