struct ENgcRendCommand {
    int m_type;
    int m_pad[2];
};

class ENgcRenderer {
public:
    void Flush(ENgcRendCommand*);
    void Flush();
};

void ENgcRenderer::Flush() {
    ENgcRendCommand cmd;
    cmd.m_type = 5;
    Flush(&cmd);
}
