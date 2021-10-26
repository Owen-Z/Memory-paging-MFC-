
// Memory_PaginationDlg.h: 头文件
//

#pragma once


// CMemoryPaginationDlg 对话框
class CMemoryPaginationDlg : public CDialogEx
{
// 构造
public:
	CMemoryPaginationDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEMORY_PAGINATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CComboBox m_cbPageNum;	// Control of the page number of the map Widnow
	CString m_strContent;	// Multi-line edit control that displays the file content in the map window.
	CString m_strMemory;	// Edit control that display the memory page number in the map window
};
