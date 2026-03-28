struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERTexture_tid = { 1, 2, 3, 4 };
class ERTexture { public: unsigned short GetReadVersion(); };
unsigned short ERTexture::GetReadVersion() { return s_ERTexture_tid.readVer; }
