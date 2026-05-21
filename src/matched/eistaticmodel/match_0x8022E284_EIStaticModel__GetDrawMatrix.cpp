// 0x8022E284 EIStaticModel::GetDrawMatrix(void) (8B)
struct EIStaticModel { char _pad[0x80]; char m_drawMatrix[1]; char* GetDrawMatrix(); };
char* EIStaticModel::GetDrawMatrix() { return m_drawMatrix; }
