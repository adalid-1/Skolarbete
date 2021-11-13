//------------------------------------------------------------------------------
/**
	Application class used for example application.
	
	(C) 2015 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "render/window.h"
#include "2d/2dapp.h"
#include "Shape.h"
#include <vector>
#include "Circle.h"
using namespace std;

namespace Example
{
class AssignmentApp : public App2D::BaseApp
{
public:
	static AssignmentApp& GetInstance()
	{
		static AssignmentApp instance;
		return instance;
	}

	/// destructor
	~AssignmentApp();

	/// initialize, create shapes etc
	void Setup();

	/// update app, draw lines etc
	void Update();

	//Do something 
	void KeyEvent(int key, int action, int modifier);

	/// line drawing function
	static void DrawLine(const LineData & line);

private:
	/// constructor hidden because it is a singleton
	AssignmentApp();
	/// also hidden because of the singleton
	AssignmentApp(AssignmentApp const &);
	/// also hidden because of the singleton
	void operator=(AssignmentApp const &);

	vector<Shape*> former; 
	int formerSize;
	
	 Display::Window* window;

	 Matrix2D_v2 TestMatrix2D;
	 Vector2D_v2 tempVector;
	 Circle* breakball;
	 void setupShapes(int nr);
};

//------------------------------------------------------------------------------
/**
*/
inline void 
AssignmentApp::DrawLine( const LineData & line )
{
	AssignmentApp::GetInstance().AddLine(line);
}

} // namespace Example