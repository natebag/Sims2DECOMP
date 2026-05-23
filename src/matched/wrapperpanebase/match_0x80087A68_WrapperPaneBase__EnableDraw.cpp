struct WrapperPaneBase { char pad[4]; unsigned int m_flags; };
extern "C" void refreshDraw(WrapperPaneBase*);
void WrapperPaneBase_EnableDraw(WrapperPaneBase* self) {
    self->m_flags |= 1;
    refreshDraw(self);
}
