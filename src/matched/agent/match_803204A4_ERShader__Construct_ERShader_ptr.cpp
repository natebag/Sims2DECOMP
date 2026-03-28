typedef unsigned int size_t;
void* operator new(size_t, void*);

struct ERShader {
    char pad[108];
    ERShader();
    static void Construct(ERShader* obj);
};

void ERShader::Construct(ERShader* obj) {
    new (obj) ERShader();
}
