struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERFlash_tid = { 1, 2, 3, 4 };
class ERFlash { public: unsigned short GetReadVersion(); };
unsigned short ERFlash::GetReadVersion() { return s_ERFlash_tid.readVer; }
