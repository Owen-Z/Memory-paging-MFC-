﻿
// Memory_PaginationDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Memory_Pagination.h"
#include "Memory_PaginationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMemoryPaginationDlg 对话框



CMemoryPaginationDlg::CMemoryPaginationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEMORY_PAGINATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemoryPaginationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_cbPageNum);
	DDX_Control(pDX, IDC_EDIT1, pageNum);
	DDX_Control(pDX, IDC_EDIT2, text);
}

BEGIN_MESSAGE_MAP(CMemoryPaginationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CMemoryPaginationDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CMemoryPaginationDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMemoryPaginationDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMemoryPaginationDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMemoryPaginationDlg 消息处理程序

BOOL CMemoryPaginationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMemoryPaginationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMemoryPaginationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMemoryPaginationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// Click button read
void CMemoryPaginationDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}


// Click button save 
void CMemoryPaginationDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


// Click button read a page
void CMemoryPaginationDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}


// Click button open file
void CMemoryPaginationDlg::OnBnClickedButton3()
{
	CFileDialog dlg(TRUE); // TRUE is to tell the dialog is used as an open CFileDialog.
	if (dlg.DoModal() == IDOK)
	{
		// get the full path name of the selected file.
		CString fullPathName = dlg.GetPathName(); 
		cMemory = new CMemory();

		if (cMemory->LoadFile(fullPathName)) {
			int a = cMemory->m_pMemory[1]->no;
			text.SetWindowTextW(_T("DD"));
		}
		// Start to read file

	}
	
}
