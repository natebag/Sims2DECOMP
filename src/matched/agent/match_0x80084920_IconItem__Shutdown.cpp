struct IconItem {
    void ReleaseShader(void);
    void Shutdown(void);
};

void IconItem::Shutdown(void) {
    ReleaseShader();
}
