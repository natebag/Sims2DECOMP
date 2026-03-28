struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERShader_tid = { 1, 2, 3, 4 };
class ERShader { public: int GetTypeName() const; };
int ERShader::GetTypeName() const { return s_ERShader_tid.name; }
