typedef void *ERShader;

void ERShaderRelease(ERShader shader);

struct InteractorVisualizer_S {
    ERShader m_shader0;
    ERShader m_shader1;

    void Shutdown();
};

void InteractorVisualizer_S::Shutdown() {
    ERShaderRelease(m_shader0);
    m_shader0 = 0;
    ERShaderRelease(m_shader1);
    m_shader1 = 0;
}
