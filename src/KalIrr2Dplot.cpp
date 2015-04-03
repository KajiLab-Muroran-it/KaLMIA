/**************************************************************/
/*                                                            */
/*     ================[ KaLMIA Library ]================     */
/*                                                            */
/*            Kaji-Lab Magnifier Integrated Assets            */
/*                                                            */
/*     ============== " Be Ambitious For " ==============     */
/*                                                            */
/*              Muroran Institute of Technology               */
/*      Electronic System Control Engineering Laboratory      */
/*                                                            */
/**************************************************************/

// KalIrr2Dplot.cpp
#include "KalIrr2Dplot.hpp"
#include<iostream>
namespace kalmia {
	using namespace irr;
	using core::vector2di;
	using video::SColor;
	using std::unique_ptr;
	using std::shared_ptr;
	using std::make_shared;

	vector2di MultVec2diF32 (const f32 coef, const vector2di& vec){
		return vector2di ((s32)(coef*vec.X), (s32)(coef*vec.Y));
	}


	//--------------------------------
	//    Spacing
	//--------------------------------

	KalIrrSpacing::KalIrrSpacing () 
		: KalIrrSpacing (0){}

	KalIrrSpacing::KalIrrSpacing (s32 unified) 
		: KalIrrSpacing (unified, unified){}

	KalIrrSpacing::KalIrrSpacing (s32 vertical, s32 horizontal) 
		: KalIrrSpacing (vertical, horizontal, vertical){}

	KalIrrSpacing::KalIrrSpacing (s32 top, s32 horizontal, s32 bottom) 
		: KalIrrSpacing (top, horizontal, horizontal, bottom){}

	KalIrrSpacing::KalIrrSpacing (s32 top, s32 right, s32 left, s32 bottom) 
		: upperLeft (left, top), lowerRight (right, bottom), i (top){}

	//--------------------------------
	//    PlotItem
	//--------------------------------

	KalIrrPlotItem::KalIrrPlotItem (IrrlichtDevice* device) 
		: driver (device->getVideoDriver ()), guiEnv (device->getGUIEnvironment ())
		, position (vector2di ())
		, scale(1.)
	{}

	void KalIrrPlotItem::SetScale (const f32 scale){
		this->scale = scale;
	}


	//--------------------------------
	//    PlotItemParental
	//--------------------------------

	KalIrrPlotItemParental::KalIrrPlotItemParental (IrrlichtDevice* device) 
		: KalIrrPlotItem (device)
		, margin (KalIrrSpacing ())
		, padding(KalIrrSpacing ())
	{}

	void KalIrrPlotItemParental::DrawChildren (const vector2di& offset, const f32 parentalScale) const{
		vector2di vec = offset + position + MultVec2diF32 (scale*parentalScale, margin.upperLeft + padding.upperLeft);
		for (int i = 0; i < children.size (); i++){
			children[i]->Draw (vec, parentalScale*scale);
		}
	}

	void KalIrrPlotItemParental::SetMargin (const KalIrrSpacing& margin){
		this->margin = margin;
	}

	void KalIrrPlotItemParental::SetPadding (const KalIrrSpacing& padding){
		this->padding = padding;
	}

	//--------------------------------
	//    PlotPane
	//--------------------------------

	KalIrrPlotPane::KalIrrPlotPane (IrrlichtDevice* device, const vector2di& dimension) 
		: KalIrrPlotItemParental (device)
		, dimension (dimension)
		, borderColor (SColor())
		, backgroundColor (SColor())
	{}

	void KalIrrPlotPane::AddItem (const shared_ptr<KalIrrPlotItem>& item){
		children.push_back (item);
	}



	void KalIrrPlotPane::SetPosition (const vector2di& position){
		this->position = position;
	}

	void KalIrrPlotPane::SetBorderColor (const SColor& borderColor){
		this->borderColor = borderColor;
	}

	void KalIrrPlotPane::SetBackgroundColor (const SColor& backgroundColor){
		this->backgroundColor = backgroundColor;
	}

	void KalIrrPlotPane::Draw (const vector2di& offset, const f32 parentalScale){
		// Draw itself
		vector2di v1 = position + MultVec2diF32 (scale*parentalScale, margin.upperLeft);
		vector2di v2 = position + MultVec2diF32 (scale*parentalScale, margin.upperLeft + dimension);
		irr::core::rect<s32> rect (offset + v1, offset + v2);

		driver->draw2DRectangle (backgroundColor, rect, nullptr);
		driver->draw2DRectangleOutline (rect, borderColor);

		// Draw items
		if (children.size () > 0){
			DrawChildren (offset, parentalScale);
		}
	}


	//--------------------------------
	//    ChartBase
	//--------------------------------

	KalIrrChartBase::KalIrrChartBase (IrrlichtDevice* device, const vector2di& dimension) 
		: KalIrrPlotItemParental (device)
		, graphArea(device, dimension){

	}

	void KalIrrChartBase::Draw (const vector2di& offset, const f32 parentalScale){
	}

	//--------------------------------
	//    LineChart
	//--------------------------------

	KalIrrLineChart::KalIrrLineChart (IrrlichtDevice* device, const vector2di& dimension) 
		: KalIrrChartBase (device, dimension){}
}