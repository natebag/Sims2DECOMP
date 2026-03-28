struct AptViewer3 {
    char pad[0x3A4];
    int m_allowCtrlReading;
};

int AptViewer_AllowControllerReading(AptViewer3* self, int allow) {
    int prev = self->m_allowCtrlReading;
    self->m_allowCtrlReading = allow;
    return prev;
}
