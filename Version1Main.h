/***************************************************************
 * Name:      Version1Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2019-03-26
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef VERSION1MAIN_H
#define VERSION1MAIN_H

//(*Headers(Version1Frame)
#include <wx/gauge.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "./imports/Cell.h"
#include "./imports/Util.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <wx/time.h>
#include <wx/timer.h>
#include <time.h>
#include <stdlib.h>
#include <wx/msgdlg.h>
#include <wx/dcbuffer.h>


class Version1Frame: public wxFrame
{
    public:


        Version1Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Version1Frame();

    private:
        Cell **** array_of_cells;
        int population_size;
        int x_dim,y_dim,z_dim;
        bool initRun = false;
        bool done = false;
        bool runClicked = false;
        wxTimer m_timer;
        //(*Handlers(Version1Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnRunClick(wxCommandEvent& event);
        void OnColumnSliderUpdated(wxScrollEvent& event);
        void OnColumnText(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnRowSliderUpdated(wxScrollEvent& event);
        void OnRowText(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnStopClick(wxCommandEvent& event);
        void OnSlider3CmdScroll(wxScrollEvent& event);
        void OnPopulationText(wxCommandEvent& event);
        void OnSlider1CmdScroll1(wxScrollEvent& event);
        void OnSlider3CmdScroll1(wxScrollEvent& event);
        void OnPopulationSliderUpdated(wxScrollEvent& event);
        void OnPopulationSlider(wxScrollEvent& event);
        void GaugeProgress();
        //*)

        //(*Identifiers(Version1Frame)
        static const long ID_PANEL1;
        static const long ID_SLIDER1;
        static const long ID_TEXTCTRL1;
        static const long ID_SLIDER2;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_SLIDER3;
        static const long ID_GAUGE1;
        static const long ID_PANEL2;
        static const long ID_PANEL3;
        static const long ID_BUTTON1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Version1Frame)
        wxTextCtrl* TextCtrl3;
        wxPanel* Panel1;
        wxSlider* Slider3;
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxButton* Button2;
        wxStaticText* StaticText1;
        wxPanel* Panel2;
        wxStaticText* StaticText3;
        wxPanel* Panel3;
        wxTextCtrl* TextCtrl1;
        wxSlider* Slider2;
        wxStaticText* StaticText2;
        wxSlider* Slider1;
        wxGauge* Gauge1;
        wxTextCtrl* TextCtrl2;
        //*)

        void OnIdle(void);
        void tick(void);

        void animate(void);
        void render(int x, int y);
        void cell_modify(void);

        void OnTimer(wxTimerEvent& event);

       // void movement()

        DECLARE_EVENT_TABLE()
};

#endif // VERSION1MAIN_H
