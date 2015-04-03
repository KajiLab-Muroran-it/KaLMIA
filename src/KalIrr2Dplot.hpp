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

// KalIrr2Dplot.hpp
#ifndef KALIRR2DPLOT_HPP
#define KALIRR2DPLOT_HPP

#include <memory>
#include <string>
#include <array>
#include <vector>
#include <Irrlicht.h>

namespace kalmia {
	irr::core::vector2di MultVec2diF32 (const irr::f32 coef, const irr::core::vector2di& vec);

	const class KalIrrSpacing {
	public:
		irr::core::vector2d<irr::s32> upperLeft, lowerRight;
		int i;

		KalIrrSpacing ();
		KalIrrSpacing (irr::s32 unified);
		KalIrrSpacing (irr::s32 vertical, irr::s32 horizontal);
		KalIrrSpacing (irr::s32 top, irr::s32 horizontal, irr::s32 bottom);
		KalIrrSpacing (irr::s32 top, irr::s32 right, irr::s32 left, irr::s32 bottom);

		virtual ~KalIrrSpacing () = default;
	};

	class KalIrrPlotItem {
	public:
		KalIrrPlotItem (irr::IrrlichtDevice* device);
		virtual ~KalIrrPlotItem () = default;

		void SetScale (irr::f32 scale = 1.);
		virtual void Draw (const irr::core::vector2di& offset = irr::core::vector2di (), const irr::f32 parentalScale = 1.) = 0;

	protected:
		irr::f32 scale;
		irr::core::vector2di position;
		irr::video::IVideoDriver* driver;
		irr::gui::IGUIEnvironment* guiEnv;
	};

	class KalIrrPlotItemParental : public KalIrrPlotItem{
	public:
		KalIrrPlotItemParental (irr::IrrlichtDevice* device);
		virtual ~KalIrrPlotItemParental () = default;

		void SetMargin (const KalIrrSpacing& margin = KalIrrSpacing ());
		void SetPadding (const KalIrrSpacing& padding = KalIrrSpacing ());

	protected:
		KalIrrSpacing margin;
		KalIrrSpacing padding;
		std::vector<std::shared_ptr<KalIrrPlotItem>> children;
		void DrawChildren (const irr::core::vector2di& offset, const irr::f32 parentalScale) const;
	};

	class KalIrrPlotPane : public KalIrrPlotItemParental {
	public:
		KalIrrPlotPane (irr::IrrlichtDevice* device, const irr::core::vector2di& dimension);
		virtual ~KalIrrPlotPane () = default;

		void AddItem (const std::shared_ptr<KalIrrPlotItem>& item);

		void Draw (const irr::core::vector2di& offset = irr::core::vector2di (), const irr::f32 parentalScale = 1.) override;

		void SetBorderColor (const irr::video::SColor& borderColor = irr::video::SColor(0x00000000));
		void SetBackgroundColor (const irr::video::SColor& backgroundColor = irr::video::SColor (0x00000000));

		void SetPosition (const irr::core::vector2di& = irr::core::vector2di());
		
		//void SetTitle (std::wstring);

	protected:
		irr::core::vector2di dimension;

		irr::video::SColor borderColor;
		irr::video::SColor backgroundColor;
		
		
	};

	class KalIrrChartBase : public KalIrrPlotItemParental{
	public:
		const class Axis {
		private:
			double min, max;
			// double tick;
		};

		class Series : public KalIrrPlotItem{
		public:
			void Draw (const irr::core::vector2di& offset = irr::core::vector2di (), const irr::f32 parentalScale = 1.);
		};


		KalIrrChartBase (irr::IrrlichtDevice* device, const irr::core::vector2di& dimension);
		virtual ~KalIrrChartBase () = default;

	private:
		KalIrrPlotPane graphArea;
		//Series defaultX;

	protected:
	public:
		void Draw (const irr::core::vector2di& offset = irr::core::vector2di (), const irr::f32 parentalScale = 1.) override;

		//virtual void AddSeries (const std::shared_ptr<Series>& series);
	};

	class KalIrrLineChart : public KalIrrChartBase {
	public:
		KalIrrLineChart (irr::IrrlichtDevice* device, const irr::core::vector2di& dimension);
		virtual ~KalIrrLineChart () = default;

	private:
		//Axis xAxis, yAxis;
	protected:

	public:


	};

}

//#include "KalIrr2Dplot.cpp"
#endif