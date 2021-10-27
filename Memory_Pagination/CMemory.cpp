#include "pch.h"
#include "CMemory.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool CMemory::LoadFile(const CString strFilepath) {
    std::string filePath = CT2A(strFilepath);
    //filePath = std::string((LPCTSTR)strFilepath);
    std::ifstream infile;
    infile.open(filePath.data());   //���ļ����������ļ���������
    assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ��������

    std::ifstream in(filePath);
    std::string contents((std::istreambuf_iterator<char>(in)),
        std::istreambuf_iterator<char>());
    for (int i = 0; i < 16; i++) {
        m_pMemory[i] = (MemBlock*)malloc(sizeof(MemBlock));
        m_pMemory[i]->no = i;
        std::ifstream in(strFilepath);
        std::string contents((std::istreambuf_iterator<char>(in)),
            std::istreambuf_iterator<char>());
        contents.substr(PAGE_SIZE * i, PAGE_SIZE).copy(m_pMemory[i]->content, 4096);
        
    }
    m_pMemory[1]->no;
	return true;
}