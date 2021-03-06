#include "CRatVector0.h"

CRatVector0 operator+(const CRatVector0& left, const CRatVector& right) {
	CRatVector0 a(std::max(left.vecsize, CRatVector0(right).vecsize));
	std::copy(left.data, left.data + left.vecsize, a.data);
	a += right;
	return a;
}

CRatVector0 operator-(const CRatVector0& left, const CRatVector& right) {
	CRatVector0 a(std::max(left.vecsize, CRatVector0(right).vecsize));
	std::copy(left.data, left.data + left.vecsize, a.data);
	a -= right;
	return a;
}

void CRatVector0::setFilename(const char* FileName) {
	this->FileName = new char[strlen(FileName) + 1];
	memcpy(this->FileName, FileName, strlen(FileName));
	this->FileName[strlen(FileName)] = '\0';
}

const char* CRatVector0::getFilename() const {
	return this->FileName;
}

int CRatVector0::output(const char* FileName) {
	if (FileName == nullptr) {
		std::cout << "Error occured while working with file!" << std::endl;
		return 1;
	}
	std::ofstream out(FileName, std::ios::app);
	for (int i = 0; i < vecsize; i++) {
		if (data[i].div < 0) {
			out << "-" << std::endl << -data[i].div << std::endl;
		}
		else {
			out << data[i].div << std::endl;
		}
		out << "/" << std::endl << data[i].den << std::endl;
	}
	out << std::endl;
	out.close();
	return 0;
}
