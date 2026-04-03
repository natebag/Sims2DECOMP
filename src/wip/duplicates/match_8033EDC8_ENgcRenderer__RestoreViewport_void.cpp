class SomeViewport {
public:
    void Restore();
};

class ENgcRenderer {
    char pad[1240];
    SomeViewport* m_pViewport;
public:
    void RestoreViewport();
};

void ENgcRenderer::RestoreViewport() {
    m_pViewport->Restore();
}
