#include"student.h"

student::student() {
	m_pid = new int(404);
	m_name = "Alice";
}
student::student(int id, string name) {
	m_pid = new int(id);
	m_name = name;
}
string student::getname() {
	return m_name;
}
void student::setid(int id) {
	*m_pid = id;
}
