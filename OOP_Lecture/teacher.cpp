#include "teacher.h"
teacher::teacher() {
	m_pId = new int(0);
	m_name = "Alice";
}
teacher::teacher(int id, string name) {
	m_pId = new int(id);
	m_name = name;
}
string teacher::GetName() {
	return m_name;
}
void teacher::SetID(int id) {
	*(this->m_pId) = id;
}