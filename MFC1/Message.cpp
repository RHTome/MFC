#include <afxwin.h>
#include "resource.h"

class MyFrame : public CFrameWnd
{
private:
	CMenu *FMenu;					//菜单指针，指向菜单对象
public:
	MyFrame()
	{
		Create(NULL, "Hello MFC");//建立视窗
		FMenu = new CMenu;			//定义一个菜单对象
		FMenu->LoadMenu(IDR_MENU1);	//调用成员函数载入菜单资源
		SetMenu(FMenu);				//将此菜单对象设定给窗口对象
	}
	~MyFrame() { delete FMenu; }
	afx_msg void OnExit()
	{
		MessageBox("Exit1");
		DestroyWindow();
	}
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point)
	{
		SetCapture();//设定目前执行中的视窗程序获取滑鼠信息接收权,无论滑鼠是否在视窗之上。
	}
	afx_msg void OnMouseMove(UINT nFlags, CPoint point)
	{
		if (this == GetCapture()) //GetCapture()返回当前取得滑鼠信息接收权的视窗的句柄
		{
			CClientDC aDC(this);
			aDC.SetPixel(point, RGB(255, 0, 0));
		}
	}
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point)
	{
		ReleaseCapture();//释放滑鼠信息接收权
	}
	DECLARE_MESSAGE_MAP();			//声明MyFrame类有一个讯息映射表
};
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	ON_COMMAND(IDM_Exit1, OnExit)
	ON_COMMAND(ID_APP_EXIT, OnExit)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()
class MyApp : public CWinApp
{
public:
	BOOL InitInstance()							//重定义继承自CWinApp的InitInstance()
	{
		CFrameWnd *Frame = new MyFrame();		//利用CFrameWnd类产生视窗框架物件，也可以叫窗口对象
		m_pMainWnd = Frame;
		Frame->ShowWindow(SW_SHOW);				//显示视窗框架物件
		//产生→建立→显示
		return true;
	}
};
MyApp a_app;