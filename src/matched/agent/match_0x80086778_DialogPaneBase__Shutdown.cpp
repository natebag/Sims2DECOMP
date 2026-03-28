struct WrapperPaneBase {
    void Shutdown(void);
};

struct DialogPaneBase : public WrapperPaneBase {
    void Shutdown(void);
};

void DialogPaneBase::Shutdown(void) {
    WrapperPaneBase::Shutdown();
}
