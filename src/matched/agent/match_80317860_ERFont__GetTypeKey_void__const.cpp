struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERFont_tid = { 1, 2, 3, 4 };
class ERFont { public: int GetTypeKey() const; };
int ERFont::GetTypeKey() const { return s_ERFont_tid.key; }
