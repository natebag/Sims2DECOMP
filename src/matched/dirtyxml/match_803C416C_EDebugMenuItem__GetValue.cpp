/* 0x803C416C (12 bytes) - EDebugMenuItem::GetValue(char *) */
class EDebugMenuItem { public: void GetValue(char *buf); };
void EDebugMenuItem::GetValue(char *buf) { *buf = 0; }
