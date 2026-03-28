struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERTexture_tid = { 1, 2, 3, 4 };
class ERTexture { public: int GetTypeName() const; };
int ERTexture::GetTypeName() const { return s_ERTexture_tid.name; }
