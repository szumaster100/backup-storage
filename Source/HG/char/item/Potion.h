// Potion.h: interface for the CPotion class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POTION_H__E18064C0_AF0D_11D3_9DC2_00001C7030A6__INCLUDED_)
#define AFX_POTION_H__E18064C0_AF0D_11D3_9DC2_00001C7030A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>

class CPotion  
{
public:
	CPotion();
	virtual ~CPotion();

	char  m_cName[21];
	short m_sArray[12];

	int   m_iSkillLimit, m_iDifficulty;

};

#endif // !defined(AFX_POTION_H__E18064C0_AF0D_11D3_9DC2_00001C7030A6__INCLUDED_)
