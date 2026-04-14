/* 0x803C4160 (12 bytes) - EDebugMenuItem::GetDescription(char *, int) */
class EDebugMenuItem { public: void GetDescription(char *buf, int len); };
void EDebugMenuItem::GetDescription(char *buf, int len) { *buf = 0; }
