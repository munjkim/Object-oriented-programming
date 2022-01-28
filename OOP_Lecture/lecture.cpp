#pragma once
#include "lecture.h"

lecture::lecture() {
	m_pid = new int{ 0 };
	m_name = "error";
}
lecture::lecture(int id, string name) {
	m_pid = new int{ id };
	m_name = name;
}
string lecture::getName() {
	return m_name;
}
void lecture::setid(int id) {
	*m_pid = id;
}