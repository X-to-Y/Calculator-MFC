
// CalculatorDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
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


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_CStrResult(_T("0"))
	, m_CStrResultBin(_T(""))
	, m_CStrResultOct(_T(""))
	, m_CStrResultHex(_T(""))
	, m_History(_T(""))
	, IflagStart(true)
	, IflagPoint(true)
	, IflagY(false)
	, finalnum(0)
	, count(0)
	, ValueResult(0)
	, X(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_CStrResult);
	DDX_Text(pDX, IDC_EDIT2, m_CStrResultBin);
	DDX_Text(pDX, IDC_EDIT3, m_CStrResultOct);
	DDX_Text(pDX, IDC_EDIT4, m_CStrResultHex);
	DDX_Text(pDX, IDC_EDIT5, m_History);
	DDX_Control(pDX, IDC_Statext, m_static);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0, &CCalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_1, &CCalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CCalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CCalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CCalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CCalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CCalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CCalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CCalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CCalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_Point, &CCalculatorDlg::OnBnClickedPoint)
	ON_BN_CLICKED(IDC_Add, &CCalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_Sub, &CCalculatorDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_Mul, &CCalculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_Div, &CCalculatorDlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_Lbracket, &CCalculatorDlg::OnBnClickedLbracket)
	ON_BN_CLICKED(IDC_Rbracket, &CCalculatorDlg::OnBnClickedRbracket)
	ON_BN_CLICKED(IDC_BackSpace, &CCalculatorDlg::OnBnClickedBackspace)
	ON_BN_CLICKED(IDC_AllClear, &CCalculatorDlg::OnBnClickedAllclear)
	ON_BN_CLICKED(IDC_Equal, &CCalculatorDlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_Pi, &CCalculatorDlg::OnBnClickedPi)
	ON_BN_CLICKED(IDC_Sin, &CCalculatorDlg::OnBnClickedSin)
	ON_BN_CLICKED(IDC_Cos, &CCalculatorDlg::OnBnClickedCos)
	ON_BN_CLICKED(IDC_Tan, &CCalculatorDlg::OnBnClickedTan)
	ON_BN_CLICKED(IDC_Square, &CCalculatorDlg::OnBnClickedSquare)
	ON_BN_CLICKED(IDC_Cube, &CCalculatorDlg::OnBnClickedCube)
	ON_BN_CLICKED(IDC_Sqrt, &CCalculatorDlg::OnBnClickedSqrt)
	ON_BN_CLICKED(IDC_Cbrt, &CCalculatorDlg::OnBnClickedCbrt)
	ON_BN_CLICKED(IDC_Yroot, &CCalculatorDlg::OnBnClickedYroot)
	ON_BN_CLICKED(IDC_Ln, &CCalculatorDlg::OnBnClickedLn)
	ON_BN_CLICKED(IDC_Log10, &CCalculatorDlg::OnBnClickedLog10)
	ON_BN_CLICKED(IDC_Factorial, &CCalculatorDlg::OnBnClickedFactorial)
	ON_BN_CLICKED(IDC_BIN, &CCalculatorDlg::OnBnClickedBIN)
	ON_BN_CLICKED(IDC_OCT, &CCalculatorDlg::OnBnClickedOCT)
	ON_BN_CLICKED(IDC_HEX, &CCalculatorDlg::OnBnClickedHEX)
	ON_BN_CLICKED(IDC_EXIT, &CCalculatorDlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_Caret, &CCalculatorDlg::OnBnClickedCaret)
	ON_BN_CLICKED(IDC_E, &CCalculatorDlg::OnBnClickedE)
	ON_BN_CLICKED(IDC_Cot, &CCalculatorDlg::OnBnClickedCot)
	ON_BN_CLICKED(IDC_Epower, &CCalculatorDlg::OnBnClickedEpower)
	ON_BN_CLICKED(IDC_Power, &CCalculatorDlg::OnBnClickedPower)
	ON_BN_CLICKED(IDC_Reciprocal, &CCalculatorDlg::OnBnClickedReciprocal)
	ON_BN_CLICKED(IDC_Reverse, &CCalculatorDlg::OnBnClickedReverse)
	ON_BN_CLICKED(IDC_ONE, &CCalculatorDlg::OnBnClickedOne)
	ON_BN_CLICKED(IDC_CleanHisory, &CCalculatorDlg::OnBnClickedCleanhisory)
	ON_BN_CLICKED(IDC_About, &CCalculatorDlg::OnBnClickedAbout)
	ON_WM_CTLCOLOR()
	ON_WM_NCHITTEST()
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
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
	CString sPath = _T("C:\\Users\\XY\\source\\repos\\Calculator\\res\\BG1.jpg");//添加背景图片
	CImage img;
	img.Load(sPath);
	HBITMAP hbmp = img.Detach();
	CBitmap bmp;
	bmp.Attach(hbmp);
	m_bgBrush.CreatePatternBrush(&bmp);

	CRgn rgnTmp;//调整对话框大小以及边框弧度
	RECT rc;
	GetClientRect(&rc);
	rgnTmp.CreateRoundRectRgn(rc.left + 3, rc.top + 3, rc.right - rc.left - 3, rc.bottom - rc.top - 3, 6, 6);
	SetWindowRgn(rgnTmp, TRUE);

	SetClassLong(this->m_hWnd, GCL_STYLE, GetClassLong(this->m_hWnd, GCL_STYLE) | CS_DROPSHADOW); //增加对话框阴影

	m_FontCString.CreatePointFont(215, _T("微软雅黑"));//调整输入框字体大小
	GetDlgItem(IDC_EDIT1)->SetFont(&m_FontCString);

	m_FontStatext.CreatePointFont(230, _T("微软雅黑"));//调整静态文本字体大小(历史记录）
	GetDlgItem(IDC_Statext)->SetFont(&m_FontStatext);

	m_FontStaTitle.CreatePointFont(140, _T("微软雅黑")); //调整标题大小
	GetDlgItem(IDC_StaTitle)->SetFont(&m_FontStaTitle);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalculatorDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)
		m_CStrResult = _T("0");//当输入首个数字为0时，直接覆盖.避免追加
	else
	{
		if (m_CStrResult.GetAt(m_CStrResult.GetLength() - 1) == '/')
			MessageBox(_T("除数不能为0！！！"));
		else
			m_CStrResult += _T("0"); //当输入不是首个数字时，在末尾追加数字。
	}
	UpdateData(FALSE);  
}

void CCalculatorDlg::OnBnClicked1()  // 1 - 9构成相同
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true) 
		m_CStrResult = _T("1"); //当输入为首个数字不为0时，覆盖初值，变为相应数字。
	else
		m_CStrResult += _T("1"); //当输入不是首个数字时，在末尾追加。
	IflagStart = false;  //改变iflagstart的状态，使后续输入0的得到追加。
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)
		m_CStrResult = _T("2");
	else
		m_CStrResult += _T("2");
	IflagStart = false;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)
		m_CStrResult = _T("3");
	else
		m_CStrResult += _T("3");
	IflagStart = false;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)
		m_CStrResult = _T("4");
	else
		m_CStrResult += _T("4");
	IflagStart = false;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)
		m_CStrResult = _T("5");
	else
		m_CStrResult += _T("5");
	IflagStart = false;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)
		m_CStrResult = _T("6");
	else
		m_CStrResult += _T("6");
	IflagStart = false;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)
		m_CStrResult = _T("7");
	else
		m_CStrResult += _T("7");
	IflagStart = false;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)
		m_CStrResult = _T("8");
	else
		m_CStrResult += _T("8");
	IflagStart = false;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)
		m_CStrResult = _T("9");
	else 
		m_CStrResult += _T("9");
	IflagStart = false;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedE()//输入常数e （下同）
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)
		m_CStrResult = _T("2.718281828459045");
	else if (IflagPoint == true)
		m_CStrResult += _T("2.718281828459045");
	else
		MessageBox(_T("没有输入运算符！！！"));
	IflagStart = false;
	IflagPoint = false;//避免出现多个小数点
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedPi()//输入常数pi
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true && IflagPoint == true)
		m_CStrResult = _T("3.141592653589793");
	else if (IflagPoint == true)
		m_CStrResult += _T("3.141592653589793");
	else
		MessageBox(_T("没有输入运算符！！！"));
	IflagStart = false;
	IflagPoint = false;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedPoint()//输入小数点
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagPoint == true)
	{
		if (m_CStrResult.GetAt(m_CStrResult.GetLength() - 1) == '(' || 
			m_CStrResult.GetAt(m_CStrResult.GetLength() - 1) == '-' ||
			m_CStrResult.GetAt(m_CStrResult.GetLength() - 1) == '+' ||
			m_CStrResult.GetAt(m_CStrResult.GetLength() - 1) == 'x' ||
			m_CStrResult.GetAt(m_CStrResult.GetLength() - 1) == '/')
		{
			MessageBox(_T("小数点前无数字！！!\r\n(已自动纠正)"));
			m_CStrResult += _T("0.");
		}
		else
		{
			m_CStrResult += _T(".");
		}

	}
	IflagStart = false;
	IflagPoint = false;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedCaret()//次方符号输入
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_CStrResult += _T("^");
	IflagStart = false;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedAdd() //加号 同减号
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)//最开始时便输入+号时简化式子
		m_CStrResult = _T("");
	else
		m_CStrResult += _T("+");
	IflagStart = false;
	IflagPoint = true;//使得小数点可以重新在输入下一个数时生效
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedSub()//减号
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)// 简化式子
		m_CStrResult = _T("-");
	else
		m_CStrResult += _T("-");
	IflagStart = false;
	IflagPoint = true;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedMul()//乘号  同除号
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_CStrResult.GetAt(m_CStrResult.GetLength() - 1) == '.') //美化纠正输入的式子
	{ 
		m_CStrResult = m_CStrResult.Left(m_CStrResult.GetLength() - 1);
		m_CStrResult += _T("x");
	}
	else
		m_CStrResult += _T("x");
	IflagStart = false;
	IflagPoint = true;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedDiv()//除号
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_CStrResult.GetAt(m_CStrResult.GetLength() - 1) == '.')
	{
		m_CStrResult = m_CStrResult.Left(m_CStrResult.GetLength() - 1);
		m_CStrResult += _T("/");
	}
	else
		m_CStrResult += _T("/");
	IflagStart = false;
	IflagPoint = true;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedLbracket()//左括号
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (IflagStart == true)
		m_CStrResult = _T("(");
	else
	{
		/*i = m_CStrResult.GetAllocLength() - 1;
		if (m_CStrResult.GetAt(i) != '+' && m_CStrResult.GetAt(i) != '-' &&
			m_CStrResult.GetAt(i) != 'x' && m_CStrResult.GetAt(i) != '/' && 
			m_CStrResult.GetAt(i) != '(' && m_CStrResult.GetAt(i) != 'x(')
		{
			m_CStrResult += _T("x(");
			MessageBox(_T("输入不合法！！！") 已自动纠正);
		} 
		else*/
		m_CStrResult += _T("(");
	}
	IflagStart = false;
	IflagPoint = true;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedRbracket()//右括号
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int Lcount = 0, Rcount = 0, i, Leftcount = 0;
	if (IflagStart == true)
		MessageBox(_T("输入错误！！！"));
	else
	{
		for (i = 0; i < m_CStrResult.GetLength(); i++)//验证输入括号的匹配
		{
			if (m_CStrResult.GetAt(i) == '(')
				Lcount++;
			else if (m_CStrResult.GetAt(i) == ')')
				Rcount++;
		}
		if (Rcount >= Lcount)
			MessageBox(_T("存在括号不匹配的问题"));
		else if (Rcount < Lcount)
			m_CStrResult += _T(")");
	}
	IflagPoint = true;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedBackspace()//删除键
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString str = _T(""), temp = _T("");
	double value = 0;
	int i = m_CStrResult.GetLength() - 1;
	if (m_CStrResult.GetLength() > 1)  //使当字符串大于1时删除有效。
	{
		if (m_CStrResult.GetAt(i) == '.') //使得删除小数点后，再输入小数点的输入有效
		{
			m_CStrResult = m_CStrResult.Left(m_CStrResult.GetLength() - 1);
			IflagPoint = true;
		}
		else if (m_CStrResult.GetAt(i) == '+' || m_CStrResult.GetAt(i) == '-' ||
			m_CStrResult.GetAt(i) == 'x' || m_CStrResult.GetAt(i) == '/')  //主要解决删除运算符后继续输入小数点符合逻辑
		{
			m_CStrResult = m_CStrResult.Left(m_CStrResult.GetLength() - 1);
			for (i = m_CStrResult.GetLength() - 1; i >= 0; i--)
			{
				if (m_CStrResult.GetAt(i) == '+' || m_CStrResult.GetAt(i) == '-'
					|| m_CStrResult.GetAt(i) == 'x' || m_CStrResult.GetAt(i) == '/')
					break;
				temp += m_CStrResult.GetAt(i);
			}
			for (i = temp.GetLength() - 1; i >= 0; i--)
			{
				str += temp.GetAt(i);
			}
			value = _wtof(str);
			if (value != (int)value)
				IflagPoint = false;
		}
		else
			m_CStrResult = m_CStrResult.Left(m_CStrResult.GetLength() - 1);
	}
	else if (m_CStrResult.GetLength() == 1)//使当字删除最后一个数时，变为0.
	{ 
		m_CStrResult = _T("0");
		IflagStart = true;
		IflagPoint = true;
	}
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedAllclear()//清空键
{
	// TODO: 在此添加控件通知处理程序代码
	IflagStart = true;
	IflagPoint = true;
	IflagY = false;
	m_CStrResult = _T("0");
	m_CStrResultBin = _T("");
	m_CStrResultOct = _T("");
	m_CStrResultHex = _T("");
	UpdateData(FALSE);
}

void CCalculatorDlg::RemoveBracket(CString str, int postion)//转换最内层括号
{
	// TODO: 在此处添加实现代码.
	CString str1 = _T(""), str2 = _T(""), str3 = _T("");
	int i;
	for (i = 0; i < str.GetLength(); i++)
	{
		if (i == postion)
		{
			i++;
			for (; i < str.GetLength(); i++)
			{
				if (str.GetAt(i) == ')')
					break;
				else
					str2 += str.GetAt(i);
			}
			i++;
			for (; i < str.GetLength(); i++)
			{
				str3 += str.GetAt(i);
			}
			break;
		}
		str1 += str.GetAt(i);
	}
	CtoF(str2);
	FtoR();
	str2.Format(_T("%lf"), ValueResult);
	m_CStrResult = str1 + str2 + str3;
}

void CCalculatorDlg::CtoF(CString str) //CString 转为 算式 （formula）。
{
	// TODO: 在此处添加实现代码.
	int i = 0, j = 0;
	double doublevalue = 0, rate = 10;
	for (i = 0; i < 50;i++)
		value[i] = 0.0;
	for (i = 0; i < 25; i++)
		sign[i] = ' ';
	for (i = 0; i < str.GetLength(); i++)
	{
		if (isdigit(str.GetAt(i)))
		{
			if (rate == 10)
			{
				doublevalue = doublevalue * rate + (str.GetAt(i) - '0');
			}
			else
			{
				doublevalue = doublevalue + (str.GetAt(i)-'0') * rate;
				rate *= 0.1;
			}
		}
		else if (str.GetAt(i) == '.')
		{
			rate = 0.1;
		}
		else if (str.GetAt(i) == '+')
		{
			value[j] = doublevalue;
			j++;
			sign[j] = '+';
			j++;
			doublevalue = 0;
			rate = 10;
		}
		else if (str.GetAt(i) == '-')
		{
			value[j] = doublevalue;
			j++;
			sign[j] = '-';
			j++;
			doublevalue = 0;
			rate = 10;
		}
		else if (str.GetAt(i) == 'x')
		{
			value[j] = doublevalue;
			j++;
			sign[j] = '*';
			j++;
			doublevalue = 0;
			rate = 10;
		}
		else if (str.GetAt(i) == '/')
		{
			value[j] = doublevalue;
			j++;
			sign[j] = '/';
			j++;
			doublevalue = 0;
			rate = 10;
		}
		
	}
	count = j;
	value[j] = doublevalue;
}

void CCalculatorDlg::FtoR()//算式 计算出 结果；
{
	// TODO: 在此处添加实现代码.
	int i = 0, j = 0, k = 1, pre = 0;
	for (i = 0; i <= count; i++) //替换/为*
	{
		if (sign[i] == '/')
		{
			sign[i] = '*';
			value[i + 1] = 1 / value[i + 1];
		}
	}
	for (i = 0; i <= count; i++)// 计算乘法
	{
		if (sign[i] == '*')
		{
			if ((i - pre) == 2)//解决连乘
			{
				value[pre - k] = value[pre - k] * value[i + 1];
				k += 2;	
			}
			else
				value[i - 1] = value[i - 1] * value[i + 1];
			value[i + 1] = 0;
			sign[i] = ' ';
			pre = i;
		}
	}
	if (value[0] == 0)//解决首个数是负数的情况
	{
		j += 2;
		i = 1;
	}
	else
		i = 0;
	for (k = 1; i <= count; i++)//按顺序整理算式在数组中的位置。
	{
		if (value[i] != 0)
		{
			value[j] = value[i];
			j += 2;
		}
		if (sign[i] != ' ')
		{
			sign[k] = sign[i];
			k += 2;
		}
	}
	for (i = 1, ValueResult = value[0]; i <= k - 2; i++)//最后计算所有加减法
	{
		if (sign[i] == '+')
			ValueResult += value[i + 1];
		else if (sign[i] == '-')
			ValueResult -= value[i + 1];
	}
	
}

void CCalculatorDlg::CleanZero()//除去末尾多余的0和小数点。
{
	// TODO: 在此处添加实现代码.
	int i;

	for (i = m_CStrResult.GetLength() - 1; i > 0; i--)
	{
		if (m_CStrResult.Find(_T(".")) != -1)
		{
			if (m_CStrResult.GetAt(i) == '0' || m_CStrResult.GetAt(i) == '.')
				m_CStrResult = m_CStrResult.Left(m_CStrResult.GetLength() - 1);
			else
				break;
		}
		else
			break;
	}
}

void CCalculatorDlg::OnBnClickedEqual()//等号
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int i, j, pos[20] = { 0 }, count = 0, Lcount = 0, Rcount = 0;
	for (i = 0; i < m_CStrResult.GetLength(); i++)//补全右括号
	{
		if (m_CStrResult.GetAt(i) == '(')
			Lcount++;
		else if (m_CStrResult.GetAt(i) == ')')
			Rcount++;
	}
	for (i = Lcount - Rcount; i > 0; i--)
	{
		m_CStrResult += _T(")");
	}
	m_History += m_CStrResult + _T("\r\n");
	for (i = 0; i < m_CStrResult.GetLength(); i++)//找出括号组数
	{
		if (m_CStrResult.GetAt(i) == '(')
		{
			j = count;
			pos[j] = i;
			count++;
		}
	}
	for (i = 0; i < count; i++, j--)
	{
		RemoveBracket(m_CStrResult, pos[j]);
	}
	CtoF(m_CStrResult);
	FtoR();
	m_CStrResult.Format(_T("%lf"), ValueResult);
	CleanZero();
	m_History += _T("		       =") +  m_CStrResult + _T("\r\n");
	if (_wtof(m_CStrResult) == 0)		//解决计算出结果为0时的后续输入情况
	{
		IflagStart = true;
		IflagPoint = true;
	}
	else if (_wtof(m_CStrResult) != (int)(_wtof(m_CStrResult)))//解决计算结果为小数后的连续输入
		IflagPoint = false;
	UpdateData(FALSE);
	OnBnClickedOne();
}

void CCalculatorDlg::GetFinalNum()//得到最后一位操作数
{
	// TODO: 在此处添加实现代码.
	UpdateData(TRUE);
	int i;
	CString str = _T(""), temp = _T("");
	finalnum = 0;
	for (i = m_CStrResult.GetLength() - 1; i >= 0; i--)
	{
		if (m_CStrResult.GetAt(i) == '+' || m_CStrResult.GetAt(i) == '-'
			|| m_CStrResult.GetAt(i) == 'x' || m_CStrResult.GetAt(i) == '/'
			|| m_CStrResult.GetAt(i) == '@' || m_CStrResult.GetAt(i) == '(')
			break;
		temp += m_CStrResult.GetAt(i);
		m_CStrResult = m_CStrResult.Left(m_CStrResult.GetLength() - 1);
	}
	for (i = temp.GetLength() - 1; i >= 0; i--)
	{
		str += temp.GetAt(i);
	}
	finalnum = _wtof(str);
}

void CCalculatorDlg::OnBnClickedSin()//sin函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double result;
	CString str = _T("");
	GetFinalNum();
	result = sin(finalnum);
	if (result != (int)result)//解决当科学计算后的小数点逻辑问题
		IflagPoint = false;
	str.Format(_T("%lf"), result);
	m_CStrResult += str;
	if (_wtof(m_CStrResult) == 0)//解决科学计算仅存一个数结果为0的后续输入问题
	{
		IflagStart = true;
		IflagPoint = true;
	}
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedCos()//cos函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double result;
	CString str = _T("");
	GetFinalNum();
	result = cos(finalnum);
	if (result != (int)result)
		IflagPoint = false;
	str.Format(_T("%lf"), result);
	m_CStrResult += str;
	if (_wtof(m_CStrResult) == 0)
	{
		IflagStart = true;
		IflagPoint = true;
	}
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedTan()//tan函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double result;
	CString str = _T("");
	GetFinalNum();
	result = tan(finalnum);
	if (result != (int)result)
		IflagPoint = false;
	str.Format(_T("%lf"), result);
	m_CStrResult += str;
	if (_wtof(m_CStrResult) == 0)
	{
		IflagStart = true;
		IflagPoint = true;
	}
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedCot()//cot函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double result;
	CString str = _T("");
	GetFinalNum();
	result = 1 / tan(finalnum);
	if (result != (int)result)
		IflagPoint = false;
	str.Format(_T("%lf"), result);
	m_CStrResult += str;
	if (_wtof(m_CStrResult) == 0)
	{
		IflagStart = true;
		IflagPoint = true;
	}
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedSquare()//平方函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	GetFinalNum();
	double result;
	CString str = _T("");
	result = finalnum * finalnum;
	if (result != (int)result)
		IflagPoint = false;
	str.Format(_T("%lf"), result);
	m_CStrResult += str;
	if (_wtof(m_CStrResult) == 0)
	{
		IflagStart = true;
		IflagPoint = true;
	}
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedCube()//立方函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double result;
	CString str = _T("");
	GetFinalNum();
	result = finalnum * finalnum * finalnum;
	if (result != (int)result)
		IflagPoint = false;
	str.Format(_T("%f"), result);
	m_CStrResult += str;
	if (_wtof(m_CStrResult) == 0)
	{
		IflagStart = true;
		IflagPoint = true;
	}
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedPower()//X^y函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double m1, m2, result;
	CString str1 = _T(""), str2 = _T(""), str3 = _T("");
	int i;
	for (i = m_CStrResult.GetLength() - 1; i >= 0; i--)
	{
		if (m_CStrResult.GetAt(i) == '+' || m_CStrResult.GetAt(i) == '-' ||
			m_CStrResult.GetAt(i) == 'x' || m_CStrResult.GetAt(i) == '/')
			break;
		str3 += m_CStrResult.GetAt(i);
		m_CStrResult = m_CStrResult.Left(m_CStrResult.GetLength() - 1);
	}
	for ( i = str3.GetLength() - 1; i >= 0; i--)
	{
		if (str3.GetAt(i) == '^')
		{
			i--;
			for (; i >=0; i--)
			{
				str2 += str3.GetAt(i);
			}

		}
		else
			str1 += str3.GetAt(i);
	}
	m1 = _wtof(str1);
	m2 = _wtof(str2);
	result = pow(m1, m2);
	if (result != (int)result)
		IflagPoint = false;
	str3.Format(_T("%lf"), result);
	m_CStrResult += str3;
	if (_wtof(m_CStrResult) == 0)
	{
		IflagStart = true;
		IflagPoint = true;
	}
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedEpower()//e^x函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double result;
	CString str = _T("");
	GetFinalNum();
	result = pow(2.718281828459045, finalnum);
	if (result != (int)result)
		IflagPoint = false;
	str.Format(_T("%lf"), result);
	m_CStrResult += str;
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedSqrt()//开平方
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double result;
	CString str = _T("");
	GetFinalNum();
	result = sqrt(finalnum);
	if (result != (int)result)
		IflagPoint = false;
	str.Format(_T("%lf"), result);
	m_CStrResult += str;
	if (_wtof(m_CStrResult) == 0)
	{
		IflagStart = true;
		IflagPoint = true;
	}
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedCbrt()//开立方
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double result;
	CString str = _T("");
	GetFinalNum();
	result = cbrt(finalnum);
	if (result != (int)result)
		IflagPoint = false;
	str.Format(_T("%lf"), result);
	m_CStrResult += str;
	if (_wtof(m_CStrResult) == 0)
	{
		IflagStart = true;
		IflagPoint = true;
	}
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedYroot()//y√X函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int i;
	double Y = 0, result = 0;
	CString str = _T("");
	if (IflagY == false)
	{
		IflagY = true;
		GetFinalNum();
		X = finalnum;
		str.Format(_T("%lf"), X);
		m_CStrResult += _T("√") + str;
		CleanZero();
		m_CStrResult += _T("@");
	}
	else if (IflagY == true)
	{
		IflagY = false;
		GetFinalNum();
		Y = finalnum;
		result = pow(X, 1 / Y);
		if (result != (int)result)
			IflagPoint = false;
		str.Format(_T("%lf"), result);
		for (i = m_CStrResult.GetLength() - 1; i >= 0; i--)
		{
			if (m_CStrResult.GetAt(i) == '+' || m_CStrResult.GetAt(i) == '-'
				|| m_CStrResult.GetAt(i) == 'x' || m_CStrResult.GetAt(i) == '/' || m_CStrResult.GetAt(i) == '(')
				break;
			m_CStrResult = m_CStrResult.Left(m_CStrResult.GetLength() - 1);
		}
		m_CStrResult += str;
		if (_wtof(m_CStrResult) == 0)
		{
			IflagStart = true;
			IflagPoint = true;
		}
		CleanZero();
	}
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedLn()//ln函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double result;
	CString str = _T("");
	GetFinalNum();
	result = log(finalnum);
	if (result != (int)result)
		IflagPoint = false;
	str.Format(_T("%lf"), result);
	m_CStrResult += str;
	if (_wtof(m_CStrResult) == 0)
	{
		IflagStart = true;
		IflagPoint = true;
	}
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedLog10()//lg函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double result;
	CString str = _T("");
	GetFinalNum();
	result = log10(finalnum);
	if (result != (int)result)
		IflagPoint = false;
	str.Format(_T("%lf"), result);
	m_CStrResult += str;
	if (_wtof(m_CStrResult) == 0)
	{
		IflagStart = true;
		IflagPoint = true;
	}
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedFactorial()//阶乘函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString str = _T("");
	double result = 1, i , j, k ;
	GetFinalNum();
	k = m_CStrResult.GetLength();
	i = finalnum;
	j = (int)finalnum;
	if (i != j || i < 0)
	{
		MessageBox(_T("阶乘数不能为小数和负数！！！"));
		str.Format(_T("%lf"), finalnum);
		m_CStrResult += str;
	}
	else if (i == 0)
	{
		result = 1;
		m_CStrResult.Format(_T("%lf"), result);
	}
	else
	{
		for (; i > 0; i--)
			result *= i;
		str.Format(_T("%lf"), result);
		m_CStrResult += str;
	}
	CleanZero();
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedBIN()//转换为2进制函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_CStrResultBin = _T("");
	CleanZero();
	CString str = _T("");
	int zs[35], xs[20], zstemp, i, j;
	double xstemp;
	if (m_CStrResult.Find(_T(".")) != -1)
	{
		if (_wtof(m_CStrResult) < 0)
		{
			m_CStrResultBin += _T("-");
			zstemp = -_wtoi(m_CStrResult);
			xstemp = -(_wtof(m_CStrResult) + zstemp);
		}
		else
		{
			zstemp = _wtoi(m_CStrResult);
			xstemp = _wtof(m_CStrResult) - zstemp;
		}
		for (i = 0; i < 35; i++)
		{
			zs[i] = zstemp % 2;
			zstemp = zstemp / 2;
			if (zstemp == 0)
				break;
		}
		for (j = 0; j < 20; j++)
		{
			xs[j] = (int)(xstemp * 2);
			xstemp = (xstemp * 2) - (int)(xstemp * 2);
			if (xstemp == 0)
				break;
		}
		if (i == 35)//防止数组溢出
			i = i - 1;
		for (; i >= 0; i--)
		{
			str.Format(_T("%d"), zs[i]);
			m_CStrResultBin += str;
		}
		m_CStrResultBin += _T(" . ");
		if (j == 20) //防止数组溢出。
			j = j - 1;
		for (i = 0; i <= j; i++)
		{
			str.Format(_T("%d"), xs[i]);
			m_CStrResultBin += str;
		}
	}
	else
	{
		if (_wtof(m_CStrResult) < 0)
		{
			m_CStrResultBin += _T("-");
			zstemp = -_wtoi(m_CStrResult);
		}
		else
			zstemp = _wtoi(m_CStrResult);
		for (i = 0; i < 35; i++)
		{
			zs[i] = zstemp % 2;
			zstemp = zstemp / 2;
			if (zstemp == 0)
				break;
		}
		if (i == 35)
			i = i - 1;
		for (; i >= 0; i--)
		{
			str.Format(_T("%d"), zs[i]);
			m_CStrResultBin += str;
		}
	}
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedOCT()//转换为8进制函数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_CStrResultOct = _T("");
	CleanZero();
	CString str = _T("");
	int zs[20], xs[20], zstemp, i, j;
	double xstemp;
	if (m_CStrResult.Find(_T(".")) != -1)
	{
		if (_wtof(m_CStrResult) < 0)
		{
			m_CStrResultOct += _T("-");
			zstemp = -_wtoi(m_CStrResult);
			xstemp = -(_wtof(m_CStrResult) + zstemp);
		}
		else
		{
			zstemp = _wtoi(m_CStrResult);
			xstemp = _wtof(m_CStrResult) - zstemp;
		}
		for (i = 0; i < 20; i++)
		{
			zs[i] = zstemp % 8;
			zstemp = zstemp / 8;
			if (zstemp == 0)
				break;
		}
		for (j = 0; j < 20; j++)
		{
			xs[j] = (int)(xstemp * 8);
			xstemp = (xstemp * 8) - (int)(xstemp * 8);
			if (xstemp == 0)
				break;
		}
		if (i == 20)
			i = i - 1;
		for (; i >= 0; i--)
		{
			str.Format(_T("%d"), zs[i]);
			m_CStrResultOct += str;
		}
		m_CStrResultOct += _T(" . ");
		if (j == 20)
			j = j - 1;
		for (i = 0; i <= j; i++)
		{
			str.Format(_T("%d"), xs[i]);
			m_CStrResultOct += str;
		}
	}
	else
	{
		if (_wtof(m_CStrResult) < 0)
		{
			m_CStrResultOct += _T("-");
			zstemp = -_wtoi(m_CStrResult);
		}
		else
			zstemp = _wtoi(m_CStrResult);
		for (i = 0; i < 20; i++)
		{
			zs[i] = zstemp % 8;
			zstemp = zstemp / 8;
			if (zstemp == 0)
				break;
		}
		if (i == 20)
			i = i - 1;
		for (; i >= 0; i--)
		{
			str.Format(_T("%d"), zs[i]);
			m_CStrResultOct += str;
		}
	}
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedHEX()//转换为16进制
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_CStrResultHex = _T("");
	CleanZero();
	CString str = _T("");
	int zs[20], xs[20], zstemp, i, j;
	double xstemp;
	if (m_CStrResult.Find(_T(".")) != -1)
	{
		if (_wtof(m_CStrResult) < 0)
		{
			m_CStrResultHex += _T("-");
			zstemp = -_wtoi(m_CStrResult);
			xstemp = -(_wtof(m_CStrResult) + zstemp);
		}
		else
		{
			zstemp = _wtoi(m_CStrResult);
			xstemp = _wtof(m_CStrResult) - zstemp;
		}
		for (i = 0; i < 20; i++)
		{
			zs[i] = zstemp % 16;
			zstemp = zstemp / 16;
			if (zstemp == 0)
				break;
		}
		for (j = 0; j < 20; j++)
		{
			xs[j] = (int)(xstemp * 16);
			xstemp = (xstemp * 16) - (int)(xstemp * 16);
			if (xstemp == 0)
				break;
		}
		if (i == 20)
			i = i - 1;
		for (; i >= 0; i--)
		{
			switch (zs[i])
			{
				case 10: 
					m_CStrResultHex += _T("A");
					break;
				case 11:
					m_CStrResultHex += _T("B");
					break;
				case 12:
					m_CStrResultHex += _T("C");
					break;
				case 13:
					m_CStrResultHex += _T("D");
					break;
				case 14:
					m_CStrResultHex += _T("E");
					break;
				case 15:
					m_CStrResultHex += _T("F");
					break;
				default:
					str.Format(_T("%d"), zs[i]);
					m_CStrResultHex += str;
			}
		}
		m_CStrResultHex += _T(" . ");
		if (j == 20)
			j = j - 1;
		for (i = 0; i <= j; i++)
		{
			switch (xs[i])
			{
				case 10: 
					m_CStrResultHex += _T("A");
					break;
				case 11:
					m_CStrResultHex += _T("B");
					break;
				case 12:
					m_CStrResultHex += _T("C");
					break;
				case 13:
					m_CStrResultHex += _T("D");
					break;
				case 14:
					m_CStrResultHex += _T("E");
					break;
				case 15:
					m_CStrResultHex += _T("F");
					break;
				default:
					str.Format(_T("%d"), xs[i]);
					m_CStrResultHex += str;
			}
		}
	}
	else
	{
		if (_wtof(m_CStrResult) < 0)
		{
			m_CStrResultHex += _T("-");
			zstemp = -_wtoi(m_CStrResult);
		}
		else
			zstemp = _wtoi(m_CStrResult);
		for (i = 0; i < 20; i++)
		{
			zs[i] = zstemp % 16;
			zstemp = zstemp / 16;
			if (zstemp == 0)
				break;
		}
		if (i == 20)
			i = i - 1;
		for (; i >= 0; i--)
		{
			switch (zs[i])
			{
			case 10:
				m_CStrResultHex += _T("A");
				break;
			case 11:
				m_CStrResultHex += _T("B");
				break;
			case 12:
				m_CStrResultHex += _T("C");
				break;
			case 13:
				m_CStrResultHex += _T("D");
				break;
			case 14:
				m_CStrResultHex += _T("E");
				break;
			case 15:
				m_CStrResultHex += _T("F");
				break;
			default:
				str.Format(_T("%d"), zs[i]);
				m_CStrResultHex += str;
			}
		}
	}
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedOne()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedBIN();
	OnBnClickedOCT();
	OnBnClickedHEX();
}

void CCalculatorDlg::OnBnClickedReciprocal()//将操作数转换为倒数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double result;
	CString str = _T("");
	GetFinalNum();
	if (finalnum == 0)
		MessageBox(_T("除数不能为0!!!"));
	else
		result = 1 / finalnum;
	if (result != (int)result)
		IflagPoint = false;
	str.Format(_T("%lf"), result);
	m_CStrResult += str;
	CleanZero();
	UpdateData(FALSE);
}


void CCalculatorDlg::OnBnClickedReverse()//将操作数转换为相反数
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int i;
	double result;
	CString str = _T(""), temp = _T(""), strend = _T("(");
	for (i = m_CStrResult.GetLength() - 1; i >= 0; i--)
	{
		if (m_CStrResult.GetAt(i) == '+' || m_CStrResult.GetAt(i) == '-'
			|| m_CStrResult.GetAt(i) == 'x' || m_CStrResult.GetAt(i) == '/' || m_CStrResult.GetAt(i) == '(')
			break;
		temp += m_CStrResult.GetAt(i);
		m_CStrResult = m_CStrResult.Left(m_CStrResult.GetLength() - 1);
	}
	for (i = temp.GetLength() - 1; i >= 0; i--)
	{
		str += temp.GetAt(i);
	}
	result = -(_wtof(str));
	str.Format(_T("%lf"), result);
	for (i = str.GetLength() - 1; i > 0; i--)
	{
		if (str.Find(_T(".")) != -1)
		{
			if (str.GetAt(i) == '0' || str.GetAt(i) == '.')
				str = str.Left(str.GetLength() - 1);
			else
				break;
		}
		else
			break;
	}
	for (i = 0; i < str.GetLength(); i++)
	{
		strend += str.GetAt(i);
	}
	strend += _T(")");
	m_CStrResult += strend;
	UpdateData(FALSE);
}

LRESULT CCalculatorDlg::OnNcHitTest(CPoint point)//解决窗口拖动
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	LRESULT ret = CDialogEx::OnNcHitTest(point);
	return (ret == HTCLIENT) ? HTCAPTION : ret;
}


void CCalculatorDlg::OnBnClickedExit()//退出按钮
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}


HBRUSH CCalculatorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if (pWnd == this)   // 添加背景图片
	{
		return m_bgBrush;
	}

	if (IDC_Statext == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框，静态文本美化 ， 历史记录
	{
		pDC->SetTextColor(RGB(105, 145, 136));//设置文本颜色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景为黑色
		hbr = CreateSolidBrush(RGB(255, 255, 255));//控件的背景色为黑色
	}
	if (IDC_StaTitle == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框，静态文本美化 ， 标题
	{
		pDC->SetTextColor(RGB(255, 255, 255));//设置文本颜色为白色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(105, 145, 136));//设置文本背景为黑色
		hbr = CreateSolidBrush(RGB(105, 145, 136));//控件的背景色为黑色
	}
	return hbr;
}


void CCalculatorDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)//button按钮背景色调整
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	ASSERT(lpDrawItemStruct->CtlType == ODT_BUTTON);

	CString strText;
	((CButton *)GetDlgItem(nIDCtl))->GetWindowText(strText);

	SetBkMode(lpDrawItemStruct->hDC, TRANSPARENT);
	{
		CBrush brush(RGB(247, 247, 247));
		dc.FillRect(&(lpDrawItemStruct->rcItem), &brush);
		DrawText(lpDrawItemStruct->hDC, strText, strText.GetLength(),
			&lpDrawItemStruct->rcItem, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
		SetBkMode(lpDrawItemStruct->hDC, TRANSPARENT);
	}
	dc.Detach();
}

void CCalculatorDlg::OnBnClickedCleanhisory()//清空历史记录
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_History = _T("");
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedAbout()//关于按钮弹窗
{
	// TODO: 在此添加控件通知处理程序代码
	CAboutDlg abtDlg;
	abtDlg.DoModal();
}