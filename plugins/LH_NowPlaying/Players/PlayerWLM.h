/*
  Copyright (C) 2011 Birunthan Mohanathas (www.poiru.net)

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef __PLAYERWLM_H__
#define __PLAYERWLM_H__

#include "Player.h"
#include <QTime>
#include <QString>

class CPlayerWLM : public CPlayer
{
public:
	virtual ~CPlayerWLM();

	static CPlayer* Create();

	virtual void UpdateData();

	virtual void Pause() { return Play(); }
	virtual void Play();
	virtual void Stop();
	virtual void Next();
	virtual void Previous();

    virtual QString GetPlayer()    { if(m_State==PLAYER_STOPPED) return ""; else return m_PlayerName; }

    static const QString WLMPlayerName() { return "MSN Compatible"; }
protected:
	CPlayerWLM();

private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void SendKeyInput(WORD key);

	static CPlayer* c_Player;

	HWND m_Window;
};

#endif
