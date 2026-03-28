struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_EResource_tid = { 1, 2, 3, 4 };
class EResource { public: unsigned short GetReadVersion(); };
unsigned short EResource::GetReadVersion() { return s_EResource_tid.readVer; }
