/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  pypilot Plugin
 * Author:   Sean D'Epagnier
 *
 ***************************************************************************
 *   Copyright (C) 2018 by Sean D'Epagnier                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 ***************************************************************************
 */

#include "pypilotUI.h"

class pypilot_pi;

class CalibrationDialog : public CalibrationDialogBase
{
public:
    CalibrationDialog( pypilot_pi &_pypilot_pi, wxWindow* parent);
    ~CalibrationDialog();

    void Receive(std::string name, Json::Value &value);
    std::list<std::string> &GetWatchlist();

private:
    void OnCalibrationLocked( wxCommandEvent& event );
    void OnAboutCalibrationLocked( wxCommandEvent& event );
    void OnClose( wxCommandEvent& event );
    void OnLevel( wxCommandEvent& event );
    void OnAboutLevel( wxCommandEvent& event );
    void OnHeadingOffset( wxSpinEvent& event );
    void OnAboutHeadingOffset( wxCommandEvent& event );

    void RudderCalCommand(const char *command);
    void OnRudderCentered( wxCommandEvent& event ) { RudderCalCommand("centered"); }
    void OnRudderResetCalibration( wxCommandEvent& event ) { RudderCalCommand("reset"); }
    void OnRudderStarboardRange( wxCommandEvent& event ) { RudderCalCommand("starboard range"); }
    void OnRudderPortRange( wxCommandEvent& event ) { RudderCalCommand("portboard range"); }
    void OnRudderRange( wxSpinEvent& event );
    void OnAboutRudderCalibration( wxCommandEvent& event );

    double m_pitch;

    pypilot_pi &m_pypilot_pi;
    wxDateTime m_lastOffsetTime;

};
