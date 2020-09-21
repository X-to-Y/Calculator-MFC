
// CalculatorDlg.h: 头文件
//

#pragma once


// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
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
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedPoint();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedLbracket();
	afx_msg void OnBnClickedRbracket();
	afx_msg void OnBnClickedBackspace();
	afx_msg void OnBnClickedAllclear();
	afx_msg void OnBnClickedEqual();
	afx_msg void OnBnClickedPi();
	afx_msg void OnBnClickedSin();
	afx_msg void OnBnClickedCos();
	afx_msg void OnBnClickedTan();
	afx_msg void OnBnClickedSquare();
	afx_msg void OnBnClickedCube();
	afx_msg void OnBnClickedSqrt();
	afx_msg void OnBnClickedCbrt();
	afx_msg void OnBnClickedYroot();
	afx_msg void OnBnClickedLn();
	afx_msg void OnBnClickedLog10();
	afx_msg void OnBnClickedFactorial();
	afx_msg void OnBnClickedBIN();
	afx_msg void OnBnClickedOCT();
	afx_msg void OnBnClickedHEX();
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedCaret();
	afx_msg void OnBnClickedE();
	afx_msg void OnBnClickedCot();
	afx_msg void OnBnClickedEpower();
	afx_msg void OnBnClickedPower();
	afx_msg void OnBnClickedReciprocal();
	afx_msg void OnBnClickedReverse();
	afx_msg void OnBnClickedOne();
	afx_msg void OnBnClickedCleanhisory();
	afx_msg void OnBnClickedAbout();
	void RemoveBracket(CString str, int postion);
	void CtoF(CString str);
	void FtoR();
	void CleanZero();
	void GetFinalNum();

private:
	CFont m_FontCString;
	CFont m_FontStatext;
	CFont m_FontStaTitle;
	CString m_CStrResult;
	CString m_CStrResultBin;
	CString m_CStrResultOct;
	CString m_CStrResultHex;
	CString m_History;
	CStatic m_static;
	CStatic m_statitle;
	CBrush m_bgBrush;
	bool IflagStart;
	bool IflagPoint;
	double value[50];
	char sign[25];
	int count;
	double ValueResult;
	double finalnum;
	bool IflagY;
	double X;
	
};
