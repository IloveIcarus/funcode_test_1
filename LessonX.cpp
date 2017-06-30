/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonX.h"
////////////////////////////////////////////////////////////////////////////////
//
//
CGameMain		g_GameMain;	

//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
CGameMain::CGameMain()
{
	m_iGameState			=	1;
	p1=new CSprite("person1");
	p2=new CSprite("person2");
	p1->SetSpriteMass(1);
	p1->SetSpriteConstantForceY( 8);
	fl=0;
	fr=0;
	fu=0;
}
//==============================================================================
//
// ��������
CGameMain::~CGameMain()
{
}

//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬. 
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void CGameMain::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// ��ʼ����Ϸ�������һ���������
	case 1:
		{
			GameInit();
			SetGameState(2); // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
		}
		break;

		// ��Ϸ�����У����������Ϸ�߼�
	case 2:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;

		// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void CGameMain::GameInit()
{
	p2->SetSpriteVisible(false);
}
//=============================================================================
//
// ÿ����Ϸ������
void CGameMain::GameRun( float fDeltaTime )
{
}
//=============================================================================
//
// ������Ϸ����
void CGameMain::GameEnd()
{
}
void		CGameMain::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
	if(KEY_LEFT==iKey)
		fl=-8;
	if(KEY_RIGHT==iKey)
		fr=8;
	if(KEY_UP==iKey)
		fu=-8;
	if(fl+fr<0)
	{
		p1->SetSpriteFlipX(true);
		p2->SetSpriteFlipX(true);
		p1->SetSpriteVisible(false);
		p2->SetSpriteVisible(true);
	}else if(fl+fr>0)
	{
		p1->SetSpriteFlipX(false);
		p2->SetSpriteFlipX(false);
		p1->SetSpriteVisible(false);
		p2->SetSpriteVisible(true);
	}else if(fl+fr==0)
	{
		p1->SetSpriteVisible(true);
		p2->SetSpriteVisible(false);
	}
	p1->SetSpriteLinearVelocity(fl+fr,fu);
}
void CGameMain::OnKeyUp( const int iKey )
{
	if(KEY_LEFT==iKey)
		fl=-0;
	if(KEY_RIGHT==iKey)
		fr=0;
	if(KEY_UP==iKey)
		fu=0;
	if(fl+fr<0)
	{
		p1->SetSpriteFlipX(true);
		p1->SetSpriteVisible(false);
		p2->SetSpriteVisible(true);
	}else if(fl+fr>0)
	{
		p1->SetSpriteFlipX(false);
		p1->SetSpriteVisible(false);
		p2->SetSpriteVisible(true);
	}else if(fl+fr==0)
	{
		p1->SetSpriteVisible(true);
		p2->SetSpriteVisible(false);
	}
	p1->SetSpriteLinearVelocity(fl+fr,fu);
}