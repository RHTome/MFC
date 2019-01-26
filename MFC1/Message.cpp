#include <afxwin.h>
#include "resource.h"

class MyFrame : public CFrameWnd
{
private:
	CMenu *FMenu;					//�˵�ָ�룬ָ��˵�����
public:
	MyFrame()
	{
		Create(NULL, "Hello MFC");//�����Ӵ�
		FMenu = new CMenu;			//����һ���˵�����
		FMenu->LoadMenu(IDR_MENU1);	//���ó�Ա��������˵���Դ
		SetMenu(FMenu);				//���˲˵������趨�����ڶ���
	}
	~MyFrame() { delete FMenu; }
	afx_msg void OnExit()
	{
		MessageBox("Exit1");
		DestroyWindow();
	}
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point)
	{
		SetCapture();//�趨Ŀǰִ���е��Ӵ������ȡ������Ϣ����Ȩ,���ۻ����Ƿ����Ӵ�֮�ϡ�
	}
	afx_msg void OnMouseMove(UINT nFlags, CPoint point)
	{
		if (this == GetCapture()) //GetCapture()���ص�ǰȡ�û�����Ϣ����Ȩ���Ӵ��ľ��
		{
			CClientDC aDC(this);
			aDC.SetPixel(point, RGB(255, 0, 0));
		}
	}
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point)
	{
		ReleaseCapture();//�ͷŻ�����Ϣ����Ȩ
	}
	DECLARE_MESSAGE_MAP();			//����MyFrame����һ��ѶϢӳ���
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
	BOOL InitInstance()							//�ض���̳���CWinApp��InitInstance()
	{
		CFrameWnd *Frame = new MyFrame();		//����CFrameWnd������Ӵ���������Ҳ���Խд��ڶ���
		m_pMainWnd = Frame;
		Frame->ShowWindow(SW_SHOW);				//��ʾ�Ӵ�������
		//��������������ʾ
		return true;
	}
};
MyApp a_app;