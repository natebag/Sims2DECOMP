struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERShader_tid = { 1, 2, 3, 4 };
class ERShader { public: unsigned short GetReadVersion(); };
unsigned short ERShader::GetReadVersion() { return s_ERShader_tid.readVer; }
