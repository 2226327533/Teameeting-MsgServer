// AvcLogTestDlg.h : ͷ�ļ�
//

#pragma once


// CAvcLogTestDlg �Ի���
class CAvcLogTestDlg : public CDialog
{
// ����
public:
	CAvcLogTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_AVCLOGTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
protected:
	virtual BOOL DestroyWindow();
public:
	
	afx_msg void OnBnClickedBtnOk();
};
