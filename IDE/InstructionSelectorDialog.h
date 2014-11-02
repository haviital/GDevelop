/*
 * GDevelop IDE
 * Copyright 2008-2014 Florian Rival (Florian.Rival@gmail.com). All rights reserved.
 * This project is released under the GNU General Public License.
 */

#ifndef INSTRUCTIONSELECTORDIALOG_H
#define INSTRUCTIONSELECTORDIALOG_H

#include <wx/treectrl.h>
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/hyperlink.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/srchctrl.h>
#include <wx/checkbox.h>
#include <wx/imaglist.h>
#include <wx/bmpbuttn.h>
#include "GDCore/Events/Expression.h"
namespace gd { class Layout; }
namespace gd { class Project; }
namespace gd { class InstructionMetadata; }

#include <string>
#include <vector>

using namespace std;

class InstructionSelectorDialog: public wxDialog
{
public:

	InstructionSelectorDialog(wxWindow* parent, gd::Project & game_, gd::Layout & scene_, bool chooseAction);
	virtual ~InstructionSelectorDialog();
	void RefreshList();
	void RefreshFromInstruction();

    gd::Project & game;
    gd::Layout & scene;

    std::string instructionType; ///< The type of the selected instruction
    vector < gd::Expression > Param; ///< The value of the parameters
    bool isInverted; ///< True if the condition is inverted

	wxButton* OkBt;
	wxSearchCtrl* searchCtrl;
	wxStaticBitmap* ActionImg;
	wxNotebook* Notebook1;
	wxStaticText* instructionNameTxt;
	wxStaticBitmap* StaticBitmap1;
	wxFlexGridSizer* GridSizer1;
	wxPanel* Panel1;
	wxCheckBox* invertedCheck;
	wxHyperlinkCtrl* HyperlinkCtrl1;
	wxStaticLine* StaticLine2;
	wxButton* moreBt;
	wxButton* CancelBt;
	wxStaticLine* StaticLine1;
	wxNotebook* objectsListsNotebook;
	wxSearchCtrl* objectsSearchCtrl;
	wxStaticText* instructionDescriptionTxt;
	wxCheckBox* objSortCheck;
	wxTreeCtrl* instructionsTree;

protected:

	static const long ID_TREECTRL1;
	static const long ID_NOTEBOOK2;
	static const long ID_TEXTCTRL2;
	static const long ID_PANEL1;
	static const long ID_TEXTCTRL1;
	static const long ID_STATICBITMAP1;
	static const long ID_STATICTEXT1;
	static const long ID_STATICTEXT2;
	static const long ID_STATICLINE1;
	static const long ID_STATICLINE2;
	static const long ID_BUTTON4;
	static const long ID_CHECKBOX2;
	static const long ID_STATICBITMAP2;
	static const long ID_HYPERLINKCTRL1;
	static const long ID_BUTTON1;
	static const long ID_BUTTON2;
	static const long ID_TEXTARRAY;
	static const long ID_EDITARRAY;
	static const long ID_BUTTONARRAY;
	static const long ID_CHECKBOX1;
	static const long ID_CHECKARRAY;

private:

	vector < wxCheckBox * > ParaFac;
	vector < wxPanel * > ParaSpacer1;
	vector < wxStaticText * > ParaText;
	vector < wxPanel * > ParaSpacer2;
	vector < wxBitmapButton * > ParaBmpBt;
	vector < wxTextCtrl * > ParaEdit;

	void OnOkBtClick(wxCommandEvent& event);
	void OnCancelBtClick(wxCommandEvent& event);
	void OnHelpBtClick(wxCommandEvent& event);
	void OninstructionsTreeSelectionChanged(wxTreeEvent& event);
	void OnmoreBtClick(wxCommandEvent& event);
	void OnsearchCtrlText(wxCommandEvent& event);
	void OninstructionsTreeItemActivated(wxTreeEvent& event);
	void OnobjectinstructionsTreeItemActivated(wxTreeEvent& event);
	void RefreshObjectsLists();
	void OnParameterBtClick(wxCommandEvent& event);
    void OnOptionalCheckboxClick(wxCommandEvent& event);
    bool MatchSearchCriteria(std::string search, const gd::InstructionMetadata & instrMetadata);

    void SelectInstruction(const std::string &type);
	wxTreeItemId GetGroupItem(wxTreeCtrl * treeCtrl, wxTreeItemId parent, std::string groupStr, bool insertIfNotExist = true);

	const bool editingAction; ///< True if an action is being edited, false if it's a condition.
	wxImageList * imageList;
	std::string selectedObject;

	DECLARE_EVENT_TABLE()
};

#endif
