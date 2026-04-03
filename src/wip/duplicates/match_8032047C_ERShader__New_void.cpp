typedef unsigned int size_t;

struct ERShader {
    char pad[108];
    void* operator new(size_t);
    ERShader();
    static ERShader* New();
};

ERShader* ERShader::New() {
    return new ERShader();
}
