// 0x8007E5E8 DlgWrapper::GetDialogPane(void) (8 B)
struct DlgWrapper { char _pad[0xac]; unsigned m_dialogPane; unsigned GetDialogPane(); };
unsigned DlgWrapper::GetDialogPane() { return m_dialogPane; }
