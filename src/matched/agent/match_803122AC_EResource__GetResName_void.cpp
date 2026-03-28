static char s_resName[16] = "EResource";
class EResource { public: char *GetResName(); };
char *EResource::GetResName() { return s_resName; }
