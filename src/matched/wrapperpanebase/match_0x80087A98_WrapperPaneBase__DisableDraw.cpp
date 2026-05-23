struct WrapperPaneBase { char pad[4]; unsigned int m_flags; };
extern "C" void refreshHide(WrapperPaneBase*);
void WrapperPaneBase_DisableDraw(WrapperPaneBase* self) {
    self->m_flags &= ~1u;
    refreshHide(self);
}
