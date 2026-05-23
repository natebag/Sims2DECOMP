// 0x801358B8 iResFile::GetResFileData(void) (8 B)
struct iResFile { char _pad[0x8]; unsigned m_resFileData; unsigned GetResFileData(); };
unsigned iResFile::GetResFileData() { return m_resFileData; }
