#pragma once
#include "Structure.h"

class CMemory
{
private:
	MemBlock* m_pMemory;	// Point to the start address of the memory area
	int m_anStack[MEM_NUM];	// It is used to implement the stack of LRU. 
public:
	bool LoadFile(const CString strFilepath);

	//int ReadPage(const int pageno, char* pStr, const int nMaxSize);
	//void UpdatePage();
	//void AddPage();
	//void WriteBack();
	//int GetPageNum();
	//MemBlock* GetMemInfo();

};

