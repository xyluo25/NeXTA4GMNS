// TLiteView.h : interface of the CTLiteView class
//
//  Portions Copyright 2010 Xuesong Zhou (xzhou99@gmail.com)

//   If you help write or modify the code, please also list your names here.
//   The reason of having Copyright info here is to ensure all the modified version, as a whole, under the GPL 
//   and further prevent a violation of the GPL.

// More about "How to use GNU licenses for your own software"
// http://www.gnu.org/licenses/gpl-howto.html


//    This file is part of NeXTA Version 0.9.12022020 (Open-source).

//    NEXTA is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    NEXTA is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with NEXTA.  If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include <afxstr.h>
#include <atlimage.h>
#include <comdef.h>

enum tool
   { move_tool, 
   select_link_tool, 
   select_feature_tool, 
   backgroundimage_tool,
   create_1waylink_tool,
   create_2waylinks_tool, 
   create_node_tool, 
   subarea_tool,
   move_node_tool,
   };

enum link_text_display_mode
   {
   link_display_none = 0, 
   link_display_street_name, 
   link_display_link_id,
   link_display_from_id_to_id,
   link_display_length_,
   link_display_speed_limit_,
   link_display_number_of_lanes,
   link_display_lane_capacity_per_hour,
   link_display_link_capacity_per_hour,
   link_display_free_flow_travel_time, 
   link_display_link_type_in_text,
   link_display_link_type_in_number,
   link_display_macro_node_id,
   link_display_main_node_id,
   link_display_mvmt_text_id,
   link_display_timing_cycle_length,
   link_display_timing_green_time,
   link_display_total_link_volume,
   link_display_hourly_link_volume,
   link_display_hourly_lane_volume,
   link_display_avg_speed,
   link_display_avg_travel_time,
   link_display_VOC_ratio,
   link_display_time_dependent_link_volume,
   link_display_time_dependent_lane_volume,
   link_display_time_dependent_density,
   link_display_time_dependent_speed_mph,
   link_display_time_dependent_queue_length,
   link_display_additional_field1,
   link_display_additional_field2,
   link_display_additional_field3,
   link_display_additional_field4,
   link_display_additional_field5,

   link_display_separator_3,

	   link_display_agent_type_code,

     link_display_LevelOfService,
  link_display_total_delay,

	link_display_avg_waiting_time_on_loading_buffer,

	link_display_time_dependent_congestion_duration,
	link_display_time_dependent_congestion_start_time,

};

enum node_display_mode
   { node_display_none = 0, 
   node_display_node_number, 
   node_display_zone_number, 
   node_display_intersection_name,
   node_display_main_node_id,
   node_display_control_type,
   node_display_additional_field1,
   node_display_additional_field2,
   node_display_additional_field3,
	node_display_additional_field4,
	node_display_additional_field5
};

enum GPS_display_mode
   { GPS_display_none = 0, 
     GPS_display_Agent_id, 
     GPS_display_timestamp_in_min, 
     GPS_display_timegap_in_min, 
     GPS_display_speed,
     GPS_display_all 
};

enum link_display_mode
   { link_display_mode_line, link_display_mode_band };

// ARROWSTRUCT
//
// Defines the attributes of an arrow.
// source: http://www.codeproject.com/Articles/3274/Drawing-Arrows
typedef struct tARROWSTRUCT 
{
	int nWidth;		// width (in pixels) of the full base of the arrowhead
	float fTheta;	// angle (in radians) at the arrow tip between the two
					//  sides of the arrowhead
	bool bFill;		// flag indicating whether or not the arrowhead should be
					//  filled
} ARROWSTRUCT;

/////////////////
/// reference: http://www.codeproject.com/Articles/25237/Bezier-Curves-Made-Simple
///
/// 

   class BezierCurve
    {
		private :
		double FactorialLookup[33];

	public:	
        BezierCurve()
        {
            FactorialLookup[0] = 1.0;
            FactorialLookup[1] = 1.0;
            FactorialLookup[2] = 2.0;
            FactorialLookup[3] = 6.0;
            FactorialLookup[4] = 24.0;
            FactorialLookup[5] = 120.0;
            FactorialLookup[6] = 720.0;
            FactorialLookup[7] = 5040.0;
            FactorialLookup[8] = 40320.0;
            FactorialLookup[9] = 362880.0;
            FactorialLookup[10] = 3628800.0;
            FactorialLookup[11] = 39916800.0;
            FactorialLookup[12] = 479001600.0;
            FactorialLookup[13] = 6227020800.0;
            FactorialLookup[14] = 87178291200.0;
            FactorialLookup[15] = 1307674368000.0;
            FactorialLookup[16] = 20922789888000.0;
            FactorialLookup[17] = 355687428096000.0;
            FactorialLookup[18] = 6402373705728000.0;
            FactorialLookup[19] = 121645100408832000.0;
            FactorialLookup[20] = 2432902008176640000.0;
            FactorialLookup[21] = 51090942171709440000.0;
            FactorialLookup[22] = 1124000727777607680000.0;
            FactorialLookup[23] = 25852016738884976640000.0;
            FactorialLookup[24] = 620448401733239439360000.0;
            FactorialLookup[25] = 15511210043330985984000000.0;
            FactorialLookup[26] = 403291461126605635584000000.0;
            FactorialLookup[27] = 10888869450418352160768000000.0;
            FactorialLookup[28] = 304888344611713860501504000000.0;
            FactorialLookup[29] = 8841761993739701954543616000000.0;
            FactorialLookup[30] = 265252859812191058636308480000000.0;
            FactorialLookup[31] = 8222838654177922817725562880000000.0;
            FactorialLookup[32] = 263130836933693530167218012160000000.0;
        }

        // just check if n is appropriate, then return the result
        double factorial(int n)
        {
            if ( n >=0 && n < 32)
	            return FactorialLookup[n]; /* returns the value n! as a SUMORealing point number */
			else return 1;
        }


        double Ni(int n, int i)
        {
            double ni;
            double a1 = factorial(n);
            double a2 = factorial(i);
            double a3 = factorial(n - i);
            ni =  a1/ (a2 * a3);
            return ni;
        }

        // Calculate Bernstein basis
        double Bernstein(int n, int i, double t)
        {
            double basis;
            double ti; /* t^i */
            double tni; /* (1 - t)^i */

            /* Prevent problems with pow */

            if (t == 0.0 && i == 0) 
                ti = 1.0; 
            else 
                ti = pow(t, i);

            if (n == i && t == 1.0) 
                tni = 1.0; 
            else 
                tni = pow((1 - t), (n - i));

            //Bernstein basis
            basis = Ni(n, i) * ti * tni; 
            return basis;
        }

		void Bezier2D(std::vector<GDPoint> ShapePoints, std::vector<GDPoint> &NewShapePoints)
        {
			std::vector<double> b;
			int cpts = 100;
			double p[200]; // 400 is approximating points

			int i;
			for(i =0; i< ShapePoints.size(); i++)
			{
				b.push_back(ShapePoints[i].x);
				b.push_back(ShapePoints[i].y);
			}
            int npts = b.size() / 2;
            int icount, jcount;
            double step, t;

            // Calculate points on curve

            icount = 0;
            t = 0;
            step = (double)1.0 / (cpts - 1);

            for (int i1 = 0; i1 != cpts; i1++)
            { 
                if ((1.0 - t) < 5e-6) 
                    t = 1.0;

                jcount = 0;
                p[icount] = 0.0;
                p[icount + 1] = 0.0;
                for (int i = 0; i != npts; i++)
                {
                    double basis = Bernstein(npts - 1, i, t);
                    p[icount] += basis * b[jcount];
                    p[icount + 1] += basis * b[jcount + 1];
                    jcount = jcount +2;
                }

                icount += 2;
                t += step;
            }

			// send approimating point back
			for(i= 0 ; i< cpts; i++)
			{
				GDPoint pt;
				pt.x = p[2*i];
				pt.y = p[2*i+1];
				NewShapePoints.push_back(pt);
			}
			

		}

    };


struct IncomingLinkAngle
{ public:
	DTALink* pLink; 
	int Angle;
};



class CTLiteView : public CView
{
protected: // create from serialization only
	CTLiteView();
	DECLARE_DYNCREATE(CTLiteView)

// Attributes
public:

	CString m_PathNodeSequence;
	bool m_bShowTop10ODOnly;
	bool m_bShowTop20ODOnly;
	bool m_bShowTop50ODOnly;
	bool m_bShowTop100ODOnly;


	bool m_bUpdateLinkAttributeBasedOnType;
	bool bShowAgentsWithIncompleteTrips;
	
		int m_msStatus;

		void CreateDefaultJunction();

	BezierCurve m_BezierCurve;

	link_display_mode m_link_display_mode;

void SetStatusText(CString text) const
{
   GetParentFrame()->SetMessageText(text);
}

bool RectIsInsideScreen(CRect rect, CRect screen_bounds)
{
      if( screen_bounds.top <= rect.top 
		  && screen_bounds.bottom >= rect.bottom 
		  && screen_bounds.left <= rect.left 
		  && screen_bounds.right >= rect.right)
		  return true;  // rect is entirely contained in screen_bounds

		CRect intersect_rect;
	  intersect_rect.IntersectRect (screen_bounds,rect);

	 return !intersect_rect.IsRectEmpty();
}
	bool isCreatingSubarea, isFinishSubarea;
	
	int m_SelectFromNodeID; 
	int m_SelectToNodeID; 

	bool m_bHighlightSubareaLinks;
	bool m_bHighlightSubareaBoundaryLinks;

	bool m_bShowODDemandVolume;
	bool m_bShowConnector;
	bool m_bHighlightActivityLocation;

	bool m_bShowTransit;
	bool m_bShowAVISensor;
	
	bool m_bShowSensorDecription;
	bool m_bShowSensorMatchedLink;
	LPPOINT m_subarea_points;
	// Create a polygonal region
    HRGN m_polygonal_region;

	CTLiteDoc* GetDocument() const;
	tool m_ToolMode; 
	bool m_bNetworkCooridinateHints;
	double m_GridResolutionX;
	double m_GridResolutionY;
	CPoint m_last_cpoint;
	CPoint m_last_left_down_point;
	bool m_bMoveDisplay;

	bool m_bMoveImage;
	bool m_bMoveSensorMap;
	bool m_bMoveNetwork;
	bool m_bShowGrid;
	bool m_bShowLinkArrow;
	bool m_bShowNode;
	

	node_display_mode m_ShowNodeTextMode;
	GPS_display_mode m_ShowGPSTextMode;

	link_text_display_mode m_ShowLinkTextMode;

	double 	m_MovmentTextSize;
	double 	m_LinkTextSize;
	int m_NodeDisplayBoundarySize; 

	bool m_bShowAgentID;
	bool m_bShowSelectedAgentOnly;
	bool m_bShowImage;
	bool m_bShowLinkType;

	int m_AgentSize;

   virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
   virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);


	void FitNetworkToScreen();
	void DrawObjects(CDC* pDC);
	void DrawBitmap(CDC *pDC, CPoint point,UINT nIDResource );
	void DrawTemporalLink(CPoint start_point, CPoint end_point);


	CPoint m_TempLinkStartPoint, m_TempLinkEndPoint;
	CPoint m_TempZoneStartPoint, m_TempZoneEndPoint;

	CPoint m_FirstSubareaPoints;

	bool bFindCloseSubareaPoint(CPoint pt)
	{
		if(GetDocument()->m_SubareaShapePoints.size()>0)
		{
			double value = (pt.x - m_FirstSubareaPoints.x)*(pt.x - m_FirstSubareaPoints.x) + (pt.y - m_FirstSubareaPoints.y)*(pt.y -m_FirstSubareaPoints.y);
		double distance = sqrt(value);
			if(distance < 10) 
				return true;

		}

		return false;
	}

	bool m_bMouseDownFlag;

	CPoint m_ScreenOrigin;
	GDPoint m_Origin;
	double m_Resolution;

	int m_OriginOnBottomFlag;

	int m_ViewID;

	void FollowGlobalViewParameters(int CurrentViewID)
	{
/*		if(GetDocument()->m_bSetView && m_ViewID!=CurrentViewID)
		{
		 GetDocument()->m_Doc_Origin = m_Origin;
		 GetDocument()->m_Doc_Resolution = m_Resolution;
		}
		 
*/
	}
	void SetGlobalViewParameters();


	void MoveNode(int NodeNo, CPoint point)
	{

		CTLiteDoc* pDoc = GetDocument();

		DTANode * pNode = pDoc->m_NodeNoMap[NodeNo];
		

		// update node's position

		pNode->pt = SPtoNP(point);

		// update all connected links' distance 

		for (std::list<DTALink*>::iterator iLink = pDoc->m_LinkSet.begin(); iLink != pDoc->m_LinkSet.end(); iLink++)
		{

			bool bConnected = false;
			if((*iLink)->m_FromNodeNo == pNode->m_NodeNo )
			{
				(*iLink)->m_FromPoint = pNode->pt;
				bConnected = true;
			}

			if((*iLink)->m_ToNodeNo == pNode->m_NodeNo )
			{
				(*iLink)->m_ToPoint = pNode->pt;
				bConnected = true;

			}

			if(bConnected)
			{
				if(pDoc->m_LongLatFlag)  // bLongLatFlag is user input,  m_LongLatFlag is the system input from the project file 
					(*iLink)->m_Length   =  g_CalculateP2PDistanceInMeterFromLatitudeLongitude((*iLink)->m_FromPoint , (*iLink)->m_ToPoint);
				else 
					(*iLink)->m_Length   = (*iLink)->DefaultDistance()/max(0.0000001,pDoc->m_UnitDistance);

				(*iLink)->UpdateShapePointsBasedOnEndPoints(pDoc->m_UnitDistance*pDoc->m_LaneWidthInMeter);  // 20 feet per lane)
			}
		}
	}

	char* m_NodeTypeFaceName;

    CPoint NPtoSP(GDPoint net_point) // convert network coordinate to screen coordinate
	{
		CPoint pt;
		pt.x = int((net_point.x-m_Origin.x)*m_Resolution+ m_ScreenOrigin.x+0.5);
		pt.y = int((net_point.y-m_Origin.y)*m_OriginOnBottomFlag*m_Resolution + m_ScreenOrigin.y+0.5);
		return pt;
	}

    GDPoint SPtoNP(CPoint screen_point)
	{
		GDPoint pt;
		pt.x = (screen_point.x-m_ScreenOrigin.x)/m_Resolution+m_Origin.x;
		pt.y = (screen_point.y-m_ScreenOrigin.y)/(m_OriginOnBottomFlag*m_Resolution)+m_Origin.y;
	
		return pt;
	}

	int FindClosestNode(CPoint point, float Min_distance);
	int FindClosestZone(CPoint point, float Min_distance);

	CPoint m_CurrentMousePoint;
	

// Operations
public:

	bool m_ShowAllPaths;

	void CopyLinkSetInSubarea();
		
	
	CPoint FromPoint, ToPoint; // avoid creating variables multiple times in drawing links
	GDPoint fromp, top;
	CPoint m_arrow_pts[3];
	CPoint m_BandPoint[2000];  // maximum 1000 feature points
	int m_LinkTextFontSize;
	int m_NodeTextFontSize;

	void DrawNode(CDC *pDC, DTANode* pNode, CPoint point, int node_size,TEXTMETRIC tm);


	

	void DrawLinkAsLine(DTALink* pLink, CDC* pDC);
	void DrawLinkAsStraightLine(DTALink* pLink, CDC* pDC);

	bool DrawLinkAsBand(DTALink* pLink, CDC* pDC, bool bObservationFlag);
	bool DrawLinkAsStraightBand(DTALink* pLink, CDC* pDC, bool bObservationFlag);
	
void ArrowTo(HDC hDC, int x, int y, ARROWSTRUCT *pA) 
{

	POINT ptTo = {x, y};

	ArrowTo(hDC, &ptTo, pA);
}

void DrawMovementLink(CDC* pDC,GDPoint pt_from, GDPoint pt_to,int NumberOfLanes, double theta, int lane_width);
void DrawNodeMovements(CDC* pDC, DTANode* pNode, CRect PlotRect);


// ArrowTo()
//
void ArrowTo(HDC hDC, const POINT *lpTo, ARROWSTRUCT *pA) 
{

	POINT pFrom;
	POINT pBase;
	POINT aptPoly[3];
	float vecLine[2];
	float vecLeft[2];
	float fLength;
	float th;
	float ta;

	// get from point
	MoveToEx(hDC, 0, 0, &pFrom);

	// set to point
	aptPoly[0].x = lpTo->x;
	aptPoly[0].y = lpTo->y;

	// build the line vector
	vecLine[0] = (float) aptPoly[0].x - pFrom.x;
	vecLine[1] = (float) aptPoly[0].y - pFrom.y;

	// build the arrow base vector - normal to the line
	vecLeft[0] = -vecLine[1];
	vecLeft[1] = vecLine[0];

	// setup length parameters
	fLength = (float) sqrt(vecLine[0] * vecLine[0] + vecLine[1] * vecLine[1]);
	th = pA->nWidth / (2.0f * fLength);
	ta = pA->nWidth / (2.0f * (tanf(pA->fTheta) / 2.0f) * fLength);

	// find the base of the arrow
	pBase.x = (int) (aptPoly[0].x + -ta * vecLine[0]);
	pBase.y = (int) (aptPoly[0].y + -ta * vecLine[1]);

	// build the points on the sides of the arrow
	aptPoly[1].x = (int) (pBase.x + th * vecLeft[0]);
	aptPoly[1].y = (int) (pBase.y + th * vecLeft[1]);
	aptPoly[2].x = (int) (pBase.x + -th * vecLeft[0]);
	aptPoly[2].y = (int) (pBase.y + -th * vecLeft[1]);

	MoveToEx(hDC, pFrom.x, pFrom.y, NULL);

	// draw we're fillin'...
	if(pA->bFill) {
		LineTo(hDC, aptPoly[0].x, aptPoly[0].y);
		Polygon(hDC, aptPoly, 3);
	}

	// ... or even jes chillin'...
	else {
		LineTo(hDC, pBase.x, pBase.y);
		LineTo(hDC, aptPoly[1].x, aptPoly[1].y);
		LineTo(hDC, aptPoly[0].x, aptPoly[0].y);
		LineTo(hDC, aptPoly[2].x, aptPoly[2].y);
		LineTo(hDC, pBase.x, pBase.y);
		MoveToEx(hDC, aptPoly[0].x, aptPoly[0].y, NULL);
	}
}


int m_DislayedAgentType;
bool m_DislayReferenceLineNo;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:

// Implementation
public:
	virtual ~CTLiteView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	void OnClickLink(UINT nFlags, CPoint point);
protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnViewZoomin();
	afx_msg void OnViewZoomout();
	afx_msg void OnViewShownetwork();
	afx_msg void OnViewMove();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnUpdateViewMove(CCmdUI *pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnViewSelect();
	afx_msg void OnUpdateViewSelect(CCmdUI *pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNodeOrigin();
	afx_msg void OnNodeDestination();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSearchFindlink();
	afx_msg void OnViewBackgroundimage();
	afx_msg void OnUpdateViewBackgroundimage(CCmdUI *pCmdUI);
	afx_msg void OnViewShowlinktype();
	afx_msg void OnUpdateViewShowlinktype(CCmdUI *pCmdUI);
	afx_msg void OnShowShownode();
	afx_msg void OnUpdateShowShownode(CCmdUI *pCmdUI);
	afx_msg void OnShowShowallpaths();
	afx_msg void OnUpdateShowShowallpaths(CCmdUI *pCmdUI);
	afx_msg void OnShowShowNodeID();
	afx_msg void OnUpdateShowShowNodeID(CCmdUI *pCmdUI);
	afx_msg void OnEditCreate1waylink();
	afx_msg void OnEditCreate2waylinks();
	afx_msg void OnUpdateEditCreate1waylink(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditCreate2waylinks(CCmdUI *pCmdUI);
	afx_msg void OnShowGrid();
	afx_msg void OnUpdateShowGrid(CCmdUI *pCmdUI);
	afx_msg void OnShowLinkarrow();
	afx_msg void OnUpdateShowLinkarrow(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMoeAgent(CCmdUI *pCmdUI);
	afx_msg void OnViewTextlabel();
	afx_msg void OnUpdateViewTextlabel(CCmdUI *pCmdUI);
	afx_msg void OnLinkDelete();
	afx_msg void OnUpdateEditDeleteselectedlink(CCmdUI *pCmdUI);
	afx_msg void OnLinkEditlink();
	afx_msg void OnEditCreatenode();
	afx_msg void OnUpdateEditCreatenode(CCmdUI *pCmdUI);
	afx_msg void OnEditDeleteselectednode();
	afx_msg void OnEditSelectnode();
	afx_msg void OnViewSelectNode();
	afx_msg void OnUpdateViewSelectNode(CCmdUI *pCmdUI);
	afx_msg void OnEditDeletelinksoutsidesubarea();
	afx_msg void OnEditMovenetworkcoordinates();
	afx_msg void OnUpdateEditMovenetworkcoordinates(CCmdUI *pCmdUI);
	afx_msg void OnBnClickedFindNode();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnViewIncreasenodesize();
	afx_msg void OnViewDecreatenodesize();
	afx_msg void OnViewDisplaylanewidth();
	afx_msg void OnNodeCheckconnectivityfromhere();
	afx_msg void OnNodeDirectiontohereandreliabilityanalysis();
	afx_msg void OnLinkIncreasebandwidth();
	afx_msg void OnLinkDecreasebandwidth();
	afx_msg void OnLinkSwichtolineBandwidthMode();
	afx_msg void OnNodeMovementproperties();
	afx_msg void OnLinkLinedisplaymode();
	afx_msg void OnUpdateLinkLinedisplaymode(CCmdUI *pCmdUI);
	afx_msg void OnUpdateViewZoneboundary(CCmdUI *pCmdUI);
	afx_msg void OnViewShowConnector();
	afx_msg void OnUpdateViewShowConnector(CCmdUI *pCmdUI);
	afx_msg void OnViewHighlightcentroidsandactivitylocations();
	afx_msg void OnUpdateViewHighlightcentroidsandactivitylocations(CCmdUI *pCmdUI);
	afx_msg void OnViewBackgroundcolor();
	afx_msg void OnMoeOddemand();
	afx_msg void OnUpdateMoeOddemand(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLinkIncreasebandwidth(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLinkDecreasebandwidth(CCmdUI *pCmdUI);
	afx_msg void OnAgentAgentnumber();
	afx_msg void OnUpdateAgentAgentnumber(CCmdUI *pCmdUI);
	afx_msg void OnAgentShowselectedAgentonly();
	afx_msg void OnUpdateAgentShowselectedAgentonly(CCmdUI *pCmdUI);
	afx_msg void OnNodeAddintermediatedestinationhere();
	afx_msg void OnNodeRemoveallintermediatedestination();
	afx_msg void OnLinkAvoidusingthislinkinrouting();
	afx_msg void OnBnClickedButtonConfiguration();
	afx_msg void OnNodeNodeproperties();
	afx_msg void OnNodeAvoidthisnode();
	afx_msg void OnNodeRemovenodeavoidanceconstraint();
	afx_msg void OnEditMovenode();
	afx_msg void OnUpdateEditMovenode(CCmdUI *pCmdUI);

	afx_msg void OnZoneHighlightassociatedacititylocations();
	afx_msg void OnUpdateZoneHighlightassociatedacititylocations(CCmdUI *pCmdUI);
	afx_msg void OnZoneCreatezone();
	afx_msg void OnEditCreatezone();
	afx_msg void OnUpdateEditCreatezone(CCmdUI *pCmdUI);
	afx_msg void OnSubareaHighlightlinksinsidesubarea();
	afx_msg void OnUpdateSubareaHighlightlinksinsidesubarea(CCmdUI *pCmdUI);
	afx_msg void OnSubareaHighlightlinksacosssubarea();
	afx_msg void OnUpdateSubareaHighlightlinksacosssubarea(CCmdUI *pCmdUI);
	afx_msg void OnOdmatrixViewtop50odpairsonly();
	afx_msg void OnUpdateOdmatrixViewtop50odpairsonly(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTransitShowtransitaccessibility(CCmdUI *pCmdUI);
	afx_msg void OnMovementHighlightprohibitedmovements();
	afx_msg void OnUpdateMovementHighlightprohibitedmovements(CCmdUI *pCmdUI);
		afx_msg void OnUpdateTransitShowtransitlinksonly(CCmdUI *pCmdUI);
	afx_msg void OnFilePrint();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnFilePrintSetup();
	afx_msg void OnAgentdataShowcompletetrajectory();
	afx_msg void OnUpdateAgentdataShowcompletetrajectory(CCmdUI *pCmdUI);
	afx_msg void OnAgentdataShow();
	afx_msg void OnUpdateAgentdataShow(CCmdUI *pCmdUI);
	afx_msg void OnGridUnlock();
	afx_msg void OnUpdateGridUnlock(CCmdUI *pCmdUI);

	afx_msg void OnBnClickedButtonSearch();
	afx_msg void OnNodeZoneDisplay();
	afx_msg void OnToolsSubarea();
	afx_msg void OnUpdateToolsSubarea(CCmdUI* pCmdUI);
	afx_msg void OnCreatesubareaWritesubareafile();
};

extern std::list<CTLiteView*>	g_ViewList;


#ifndef _DEBUG  // debug version in TLiteView.cpp
inline CTLiteDoc* CTLiteView::GetDocument() const
   { return reinterpret_cast<CTLiteDoc*>(m_pDocument); }
#endif

