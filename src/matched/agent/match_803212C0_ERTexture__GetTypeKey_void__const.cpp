struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERTexture_tid = { 1, 2, 3, 4 };
class ERTexture { public: int GetTypeKey() const; };
int ERTexture::GetTypeKey() const { return s_ERTexture_tid.key; }
