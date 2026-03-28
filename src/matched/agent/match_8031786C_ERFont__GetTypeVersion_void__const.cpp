struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERFont_tid = { 1, 2, 3, 4 };
class ERFont { public: unsigned short GetTypeVersion() const; };
unsigned short ERFont::GetTypeVersion() const { return s_ERFont_tid.version; }
