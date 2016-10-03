/*
 *  Librarian for KiCad, a free EDA CAD application.
 *  This file contains the code for the main frame, which is almost all of the
 *  user-interface code.
 *
 *  Copyright (C) 2013-2016 CompuPhase
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may not
 *  use this file except in compliance with the License. You may obtain a copy
 *  of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 *  License for the specific language governing permissions and limitations
 *  under the License.
 *
 *  $Id: libmngr_frame.h 5580 2016-10-03 09:21:56Z thiadmer $
 */
#ifndef __libmngr_frame__
#define __libmngr_frame__

/**
@file
Subclass of libmngr_frame_base, which is generated by wxFormBuilder.
*/

#include "libmngr_gui_base.h"
#include "libraryfunctions.h"
#include "cxffont.h"
#include <wx/timer.h>
#if !defined NO_3DMODEL
    #include <wx/glcanvas.h>
    #include <cybergarage/x3d/CyberX3D.h>
#endif

/** Implementing libmngr_frame_base */
class libmngrFrame : public AppFrame
{
public:
    /** Constructor */
    explicit libmngrFrame(wxWindow* parent);

protected:
    virtual void OnCloseApp(wxCloseEvent& event);
    virtual void OnNewLibrary(wxCommandEvent& event);
    virtual void OnRenameLibrary(wxCommandEvent& event);
    virtual void OnNewFootprint(wxCommandEvent& event);
    virtual void OnNewSymbol(wxCommandEvent& event);
    virtual void OnFootprintReport(wxCommandEvent& event);
    virtual void OnSymbolReport(wxCommandEvent& event);
    virtual void OnQuit(wxCommandEvent& event);
    virtual void OnFootprintMode(wxCommandEvent& event);
    virtual void OnSymbolMode(wxCommandEvent& event);
    virtual void OnSearchPaths(wxCommandEvent& event);
    virtual void OnRemoteLink(wxCommandEvent& event);
    virtual void OnReportSettings(wxCommandEvent& event);
    virtual void OnUIOptions(wxCommandEvent& event);
    virtual void OnTemplateOptions(wxCommandEvent& event);
    virtual void OnCompareMode(wxCommandEvent& event);
    virtual void OnDetailsPanel(wxCommandEvent& event);
    virtual void OnSyncMode(wxCommandEvent& event);
    virtual void OnFilterToggle(wxCommandEvent& event);
    virtual void OnHelp(wxCommandEvent& event);
    virtual void OnAbout(wxCommandEvent& event);
    virtual void OnMovePart(wxCommandEvent& event);
    virtual void OnCopyPart(wxCommandEvent& event);
    virtual void OnDeletePart(wxCommandEvent& event);
    virtual void OnRenamePart(wxCommandEvent& event);
    virtual void OnDuplicatePart(wxCommandEvent& event);
    virtual void OnLeftLibSelect(wxCommandEvent& event);
    virtual void OnRightLibSelect(wxCommandEvent& event);
    virtual void OnLeftModSelect(wxListEvent& event);
    virtual void OnRightModSelect(wxListEvent& event);
    virtual void OnZoomIn(wxCommandEvent& event);
    virtual void OnZoomOut(wxCommandEvent& event);
    virtual void On3DView(wxCommandEvent& event);
    virtual void OnShowMeasurements(wxCommandEvent& event);
    virtual void OnShowDetails(wxCommandEvent& event);
    virtual void OnShowLabels(wxCommandEvent& event);
    virtual void OnShowLeftFootprint(wxCommandEvent& event);
    virtual void OnShowRightFootprint(wxCommandEvent& event);
    virtual void OnShowLeftDetails(wxCommandEvent& event);
    virtual void OnShowRightDetails(wxCommandEvent& event);
    virtual void OnDetailsPanelUnsplit(wxSplitterEvent& event);
    virtual void OnViewStartDrag(wxMouseEvent& event);
    virtual void OnViewDrag(wxMouseEvent& event);
    virtual void OnViewCentre(wxMouseEvent& event);
    virtual void OnPaintViewport(wxPaintEvent& event);
    virtual void OnSizeViewport(wxSizeEvent& event);
    virtual void OnStatusBarDblClk(wxMouseEvent& event);
    virtual void OnPasteGeneral(wxCommandEvent& event);

    virtual void OnTextFieldChange(wxCommandEvent& event);
    virtual void OnChoiceFieldChange(wxCommandEvent& event);
    virtual void OnEnterTextInfo(wxCommandEvent& event);
    virtual void OnKillFocusTextInfo(wxFocusEvent& event);
    virtual void ChangeTextInfo(wxControl* ctrl);

          bool RearrangePinNames(int direction);
          void OnPinNameChanged(wxGridEvent& event);
          void OnPinNameRearrange(wxKeyEvent& event);
          void OnPinRightClick(wxGridEvent& event);
          void OnSwapPins(wxCommandEvent& event);
          void OnPastePinList(wxCommandEvent& event);
          void OnSetPinType(wxCommandEvent& event);

    virtual void OnEnterPadCount(wxCommandEvent& event);
    virtual void OnKillFocusPadCount(wxFocusEvent& event);
          void ChangePadCount(wxControl* ctrl);
    virtual void OnEnterPadInfo(wxCommandEvent& event);
    virtual void OnKillFocusPadInfo(wxFocusEvent& event);
          void ChangePadInfo(wxControl* ctrl);
    virtual void OnEnterPitchInfo(wxCommandEvent& event);
    virtual void OnKillFocusPitchInfo(wxFocusEvent& event);
          void ChangePitch(wxControl* ctrl);
    virtual void OnEnterSpanInfo(wxCommandEvent& event);
    virtual void OnKillFocusSpanInfo(wxFocusEvent& event);
          void ChangeSpan(wxControl* ctrl);
    virtual void OnEnterBodyInfo(wxCommandEvent& event);
    virtual void OnKillFocusBodyInfo(wxFocusEvent& event);
          void ChangeBodyInfo(wxControl* ctrl);
    virtual void OnEnterLabelField(wxCommandEvent& event);
    virtual void OnKillFocusLabelField(wxFocusEvent& event);
    virtual void OnLabelShowHide(wxCommandEvent& event);
          void ChangeLabelInfo(wxControl* ctrl);
    virtual void OnEnterShapeHeight(wxCommandEvent& event);
    virtual void OnKillFocusShapeHeight(wxFocusEvent& event);
          void ChangeShape(wxControl* ctrl);
    virtual void OnSavePart(wxCommandEvent& event);
    virtual void OnRevertPart(wxCommandEvent& event);

private:
    bool GetSelectedLibrary(wxString* library, int* side);
    bool GetReportNameList(wxString* reportfile, wxString* library, wxArrayString* namelist);

    void DrawSymbols(wxGraphicsContext *gc, int midx, int midy, const int transp[]);
    void DrawFootprints(wxGraphicsContext *gc, int midx, int midy, const int transp[]);
    void DrawModels(float xangle, float yangle);
    void DrawDimension(wxGraphicsContext *gc, int midx, int midy, int orientation, int stack,
                       double value, const CoordPair pins[2], const CoordSize& bbox);
    void UpdateBoundingBox(CoordSize* bbox, double x, double y);
    void UpdateBoundingBox(CoordSize* bbox, double x, double y, double width, double height) {
        UpdateBoundingBox(bbox, x, y);
        UpdateBoundingBox(bbox, x + width, y + height);
    }
    void ResizeModelViewport();

    wxString ExportSymbolBitmap(const wxString& modname);
    wxString ExportFootprintBitmap(const wxString& modname);

    bool CheckTemplateVar(const wxString& varname);
    bool SetVarDefaults(RPNexpression *rpn, const wxString& templatename,
                        const wxString& name, const wxString& description,
                        const wxString& prefix=wxEmptyString, bool silent=false);
    bool SetVarsFromFields(RPNexpression *rpn, bool SymbolMode);
    void SetVarsFromTemplate(RPNexpression *rpn, const wxString& templatename, bool SymbolMode);
    bool RebuildTemplate();

    bool ValidateFilename(wxString* name);

    void DrawStrokeText(wxGraphicsContext *gc, float x, float y, const wxString& text);

    void ToggleMode(bool symbolmode);
    void ToggleDetailsPanel(bool onoff);
    void EnableButtons(int side);
    wxString GetSelection(wxListCtrl* list, wxChoice* choice=0, wxString* library=0, wxString* author=0);
    bool RemoveSelection(wxListCtrl* list, int* index);

    void SyncScroll(int side);
    int CompareNames(const wxString& name1, const wxString& name2);
    long GetListPosition(const wxString &name, const wxListCtrl* list);
    void CollectLibraries(const wxString &path, wxArrayString* list);
    void CollectAllLibraries(bool eraselists=true);

    wxString GetPinSectionName(int side, int index);
    void WarnNoRepository(wxChoice* choice);
    void HandleLibrarySelect(wxChoice* choice, wxListCtrl* list, int side);
    void SynchronizeLibraries(wxListCtrl* list1, wxListCtrl* list2);
    void CollectSymbols(const wxString &path, wxListCtrl* list, const wxString& filter);
    void CollectFootprints(const wxString &path, wxListCtrl* list, const wxString& filter);
    void LoadPart(int index, wxListCtrl* list, wxChoice* choice, int fp);
    void UpdateDetails(int fp);

    bool SavePart(int index, wxListCtrl* list);
    bool CheckSavePart();

    #define IDM_TIMER 900
    wxTimer* m_Timer;
    void OnTimer(wxTimerEvent& event);

    wxTextCtrl* m_editFilter;
    bool FilterChanged;
    void OnFilterChange(wxCommandEvent& event);
    void OnFilterEnter(wxCommandEvent& event);

private:
    wxArrayString PartData[2];  /* max. 2 footprints or symbols may be loaded at any time */
    FootprintInfo Footprint[2]; /* dimensions, pad information and others (footprints) */
    BodyInfo BodySize[2];       /* body size (footprints & symbols) */
    LabelInfo LabelData[2];     /* reference and value labels (footprints & symbols) */
    PinInfo* PinData[2];        /* pin names and directions (symbols) */
    PinSection CustomPinSections[2][2];
    int PinDataCount[2];        /* number of entries in PinData (symbols) */
    bool FromRepository[2];     /* is the footprint/symbol from the repository? */
    int SelectedPartLeft;       /* current index in the symbol/module lists, -1 if there is no selection */
    int SelectedPartRight;
    bool FieldEdited;           /* was the field edited/changed? */
    bool PartEdited;            /* was the active footprint changed? */
    bool PinNamesEdited;        /* were any pin names edited? */

    double Scale;               /* scale used in the viewport (footprints, symbols & models) */
    double ScaleNormal;         /* svaed value for footprints and symbols (not models) */
    bool SymbolMode;            /* show schematic symbols instead of footprints */
    bool CompareMode;
    bool SyncMode;
    bool ShowLabels;
    bool ShowMeasurements;
    bool DrawCentreCross;
    long FontSizeLegend;
    long DimensionOffset;
    bool ShowPinNumbers;
    bool ShowFullPaths;
    bool CopyVRML;
    bool DontRebuildTemplate;
    bool ConfirmOverwrite;
    bool ConfirmDelete;
    wxColour clrFootprintMode;
    wxColour clrSchematicMode;
    wxColour clr3DModelMode;

    bool ModelMode;
    #if !defined NO_3DMODEL
        CyberX3D::SceneGraph sceneGraph;
        wxGLCanvas *glCanvas;
        wxGLContext *glContext;
        bool Update3DModel(const wxArrayString& module);
    #endif

    long OffsetX, OffsetY;      /* offset from centre (when dragging) */
    long DragOrgX, DragOrgY;

    CXFFont VFont;              /* a vector/plotter font */
};

#endif // __libmngr_frame__