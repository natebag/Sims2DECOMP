struct ERShader {
    ~ERShader();
    static void Destruct(ERShader* obj);
};

void ERShader::Destruct(ERShader* obj) {
    obj->~ERShader();
}
