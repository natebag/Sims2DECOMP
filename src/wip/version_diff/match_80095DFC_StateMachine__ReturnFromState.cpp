struct SM { char p[0x88]; int m_returning; int m_result; void ReturnFromState(int v); };
void SM::ReturnFromState(int v) { m_result = v; m_returning = 1; }
