//------------------------------------------------------------------------------
// exampleapp.cc
// (C) 2015-2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "exampleapp.h"
#include <cstring>
#include "imgui.h"

#define STRING_BUFFER_SIZE 8192

using namespace Display;
namespace Example
{
ImGuiExampleApp::ImGuiExampleApp() 
{}

ImGuiExampleApp::~ImGuiExampleApp()
{}

bool ImGuiExampleApp::Open()
{
	App::Open();
	this->window = new Display::Window;
	window->SetKeyPressFunction([this](int32, int32, int32, int32)
	{
		this->window->Close();
	});

	if (this->window->Open())
	{
		srand((unsigned)time(0));
		// set background color
		glClearColor(0.f, 0.f, 0.f, 0.0f);

		//Initial rules for L-system
		{

			LsystemRule rule1('A', "A[A[A]]A[A]");
			LsystemRule rule2('B', "A[A[A]]A[A]");
			LsystemRule rule3('C', "A[A[A]]A[A]");
			LsystemRule rule4('D', "A[A[A]]A[A]");
			LsystemRule rule5('E', "A[A[A]]A[A]");

			LsystemRule rule6('A', "AA[A[A]]A[A]");
			LsystemRule rule7('B', "AA[A[A]]A[A]");
			LsystemRule rule8('C', "AA[A[A]]A[A]");
			LsystemRule rule9('D', "AA[A[A]]A[A]");
			LsystemRule rule10('E', "AA[A[A]]A[A]");


			lista.push_back(rule1);
			lista.push_back(rule2);
			lista.push_back(rule3);
			lista.push_back(rule4);
			lista.push_back(rule5);
			lista.push_back(rule1);
			lista.push_back(rule2);
			lista.push_back(rule3);
			lista.push_back(rule4);
			lista.push_back(rule5);
			lista.push_back(rule1);
			lista.push_back(rule2);
			lista.push_back(rule3);
			lista.push_back(rule4);
			lista.push_back(rule5);


			LsystemRule simple1('A', "A[B][D]A[C][E]");
			LsystemRule simple2('B', "ABA");
			LsystemRule simple3('C', "ACA");
			LsystemRule simple4('D', "ADA");
			LsystemRule simple5('E', "AEA");

			lista2.push_back(simple1);
			lista2.push_back(simple2);
			lista2.push_back(simple3);
			lista2.push_back(simple4);
			lista2.push_back(simple5);

			//commented out stuff that has been used when testing 
			{


				//Makes nice random trees 
				/*
				LsystemPart ad('A', "A[BC]");
				LsystemPart da('B', "A[EE][C]A");
				LsystemPart ed('C', "AB[D]");
				LsystemPart dab('D', "A[EE][C]A");
				LsystemPart edb('E', "AB[D]");
				*/

				/*
				LsystemPart ad('A', "AB[B][C]");
				LsystemPart da('B', "A[A]");
				LsystemPart ed('C', "[D][A]");
				LsystemPart dab('D', "A[A]");
				LsystemPart edb('E', "AA[B]");
				*/
				//lista.push_back(aa);
				//lista.push_back(dd);
				//lista.push_back(ee);
				//lista.push_back(ddd);
				//lista.push_back(eee);
				//Spara
				//	LsystemPart simple1('A', "A[B][D]A");
				//	LsystemPart simple2('B', "BA");
				//LsystemPart simple3('C', "CA");a
				//LsystemPart simple4('D', "DA");
				//	LsystemPart simple5('E', "EA");
				//{ { "A", "A[B]A[C]" }, { "B", "BA" }, { "C", "CA" } };

			}

		}

		//skicka in statiska regler
		treeGenerator.setRules(lista2);

		treeGenerator.setN(2);
		//Generates the segments
		treeGenerator.buildTree(treeGenerator.getN(), 0, 0);
		Gnode = new GraphicsNode();
		
		//Setting up resources for the tree graphicsnode
		Gnode->pointerSetup();

		Gnode->setupAndGenerateTree(treeGenerator.lSysInt.segmentList, shadedSmooth);
		//Making resources
		LeafNode.pointerSetup();
		//Setting up resources for the leaf graphicsnodes
		LeafNode.setup("resources/obj/TestOBJ.obj", "resources/textures/shrek.jpg");

		//Setup light
		Light.position.setXYZW(0.0f, 3.0f, 12.f, 1);
		Light.color.setXYZW(1.0f, 1.0f, 1.0f, 1);

		//Generates leaf graphics nodes  
		treeGenerator.setupLeafNodes(LeafList, LeafNode);
	
		// set ui rendering function
		this->window->SetUiRender([this]()
		{
			this->RenderUI();
		});

		return true;
	}
	return false;
}
//------------------------------------------------------------------------------
void
ImGuiExampleApp::Run()
{
	
	//Cam
	Camera myCam;
	myCam.view = myCam.view * myCam.view.translate(Vector4D(0,0 , -30, 0));

	//For rotations
	float angle = 0.05;
	//variables for input 
	bool mbOnePressed = false;
	bool mbTwoPressed = false;
	//mousepositions
	float mouseX;
	float mouseY;
	//change in mousepositions
	float mouseDx;
	float mouseDy;

	while (this->window->IsOpen())
	{
		//Chunky input stuff
		//In here we check what key is pressed and sets a bool to true if pressed and to false when released
		window->SetMousePressFunction([this, &angle, &myCam, &mbOnePressed, &mbTwoPressed](int key, int action, int mod)
			{
				switch (key)
				{
				case 0://mb1 

					switch (action)
					{
					case 0://mb1 
						mbOnePressed = false;
						break;
					case 1://mb2
						mbOnePressed = true;
						break;
					}
					break;

				case 1://mb2

					switch (action)
					{
					case 0://mb1 
						mbTwoPressed = false;
						break;
					case 1://mb2
						mbTwoPressed = true;
						break;
					}
					break;
				}
			});
		//Calls movement functions based on key pressed
		window->SetKeyPressFunction([this,  &angle, &myCam](int key, int, int action, int mod)
		{
			if (action == 1 || action == 2)
			{
				//cout << key << endl;
				switch (key)
				{
				case 49://1
					Light.intensity = Light.intensity + 0.01;
					break;		
				case 50://2
					Light.intensity = Light.intensity - 0.01;
					break;
				case 51://3
					myCam.moveDown();
					break;
				case 81://q
					myCam.moveDown();
					break;
				case 87://w
					myCam.moveForward();
					break;
				case 69://e
					myCam.moveUp();
					break;
				case 82://-
					Light.position.setZ(Light.position.getZ() + 0.5);
					//Gnode.transform = Gnode.transform.translate(Vector4D(0, 0, -0.5f, 1)) * Gnode.transform;
					break;
				case 65://a
					myCam.moveLeft();
					break;
				case 83://s
					myCam.moveBack();
					break;
				case 68://d
					myCam.moveRight();
					break;
				case 70://f
					//Gnode.transform = Gnode.transform.translate(Vector4D(0, 0, 0.50, 1)) * Gnode.transform;
					Light.position.setZ(Light.position.getZ() - 0.5);
					break;
				case 263://left
					//Gnode.transform =/* Gnode.transform **/ Gnode.transform.translate(Vector4D(-0.5, 0, 0, 1)) * Gnode.transform;
					Light.position.setX(Light.position.getX() - 0.5);
					break;
				case 265://up
					//Gnode.transform = /*Gnode.transform **/ Gnode.transform.translate(Vector4D(0, 0.5, 0, 1)) * Gnode.transform;
					Light.position.setY(Light.position.getY() + 0.5);
					break;
				case 262://right
					//Gnode.transform = /*Gnode.transform **/ Gnode.transform.translate(Vector4D(0.5, 0, 0, 1)) * Gnode.transform;
					Light.position.setX(Light.position.getX() + 0.5);
					break;
				case 264://down
					//Gnode.transform = Gnode.transform.translate(Vector4D(0, -0.5, 0, 1)) * Gnode.transform;
					Light.position.setY(Light.position.getY() - 0.5);
					break;
				case 256:
					this->window->Close();
					return;
				}
			}
		});
		//In here we check how much the mouse is moving while left or right is pressed, if movement (dx and/or dy) 
		//is above a treshold we either rotate cube or cam
		window->SetMouseMoveFunction([this, angle, &myCam, &mouseX, &mouseY, &mouseDx, &mouseDy, &mbOnePressed, &mbTwoPressed](float x, float y)mutable {

			if (mbOnePressed > 0) {
				mouseDx = mouseX - x;
				mouseDy = mouseY - y;
				mouseX = x;
				mouseY = y;
				float sensitivity = 0.25;
				angle = angle * sensitivity;

				int deltaTreshold = 2;
				if (mouseDx > deltaTreshold) {
					if (mouseDy < -deltaTreshold) {
						myCam.rotateView(angle, -angle);
					}
					else if (mouseDy > deltaTreshold)
					{
						myCam.rotateView(angle, angle);
					}
					else {
						myCam.rotateView(angle, 0);
					}
				}
				else if (mouseDx < -deltaTreshold)
				{
					if (mouseDy < -deltaTreshold) {

						myCam.rotateView(-angle, -angle);
					}
					else if (mouseDy > deltaTreshold)
					{
						myCam.rotateView(-angle, angle);
					}
					else {
						myCam.rotateView(-angle, 0);
					}
				}
				else {
					if (mouseDy < -deltaTreshold) {

						myCam.rotateView(.0f, -angle);
					}
					else if (mouseDy > deltaTreshold)
					{
						myCam.rotateView(.0f, angle);
					}
				}
			}
			if (mbTwoPressed > 0) {
				mouseDx = mouseX - x;
				mouseDy = mouseY - y;
				mouseX = x;
				mouseY = y;
				int deltaTreshold = 2;
				//disabled diagonal rotation of the model because it was disgusting but it works 
				if (mouseDx > deltaTreshold) {
					if (mouseDy < -deltaTreshold) {

						//Gnode.transform = Gnode.transform.RotationY(-angle) * Gnode.transform.RotationX(angle) * Gnode.transform;

					}
					else if (mouseDy > deltaTreshold)
					{

						//Gnode.transform = Gnode.transform.RotationY(-angle) * Gnode.transform.RotationX(-angle) * Gnode.transform;
					}
					else {

						Gnode->transform = Gnode->transform.RotationY(-angle) * Gnode->transform;
					}
				}
				else if (mouseDx < -deltaTreshold)
				{
					if (mouseDy < -deltaTreshold) {
						//Gnode.transform = Gnode.transform.RotationY(angle) * Gnode.transform.RotationX(angle) * Gnode.transform;
					}
					else if (mouseDy > deltaTreshold)
					{
						//Gnode.transform = Gnode.transform.RotationY(angle) * Gnode.transform.RotationX(-angle) * Gnode.transform;
					}
					else {

						Gnode->transform = Gnode->transform.RotationY(angle) * Gnode->transform;
					}
				}
				else {
					if (mouseDy < -deltaTreshold) {
						Gnode->transform = Gnode->transform.RotationX(angle) * Gnode->transform;
					}
					else if (mouseDy > deltaTreshold)
					{
						Gnode->transform = Gnode->transform.RotationX(-angle) * Gnode->transform;
					}
				}
			}

			});
		//Depthcheck stuff
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT);

		this->window->Update();
		Gnode->ShaderO->UseProgram();
		//Sending stuff to shaders
		Gnode->ShaderO->ModMat4fv("view", myCam.view);
		Gnode->ShaderO->ModMat4fv("projection", myCam.projection.transpose());
		Gnode->ShaderO->ModVec3f("cam_pos", Vector4D(myCam.view.get(3), myCam.view.get(7), myCam.view.get(11), 1.0));

		Light.sendValuesToUniform(*Gnode->getShaderO());

		//draw 
		Gnode->draw();

		//Swap to leaf shader resoruce
		LeafNode.ShaderO->UseProgram();
		LeafNode.ShaderO->ModMat4fv("view", myCam.view);
		LeafNode.ShaderO->ModMat4fv("projection", myCam.projection.transpose());
		LeafNode.ShaderO->ModVec3f("cam_pos", Vector4D(myCam.view.get(3), myCam.view.get(7), myCam.view.get(11), 1.0));
		Light.sendValuesToUniform(*LeafNode.getShaderO());
		//Draws if drawLeaf is toggled on
		if (drawLeaf) {
			for (int i = 0; i < LeafList.size(); i++) {
				LeafList[i].draw();
			}
		}

		// transfer new frame to window
		this->window->SwapBuffers();
	}
}
//------------------------------------------------------------------------------
void ImGuiExampleApp::RenderUI()
{
	if (this->window->IsOpen())
	{
		bool show = true;
		// create a new window
		ImGui::Begin("Tree UI", &show, ImGuiWindowFlags_NoSavedSettings);
	
		ImGui::Text("Value of N         ");
		ImGui::SameLine();
		if (ImGui::Button("AddN"))
		{
			// if pressed we compile the shaders
			treeGenerator.setN(treeGenerator.getN() + 1);

		}
		ImGui::SameLine();
		if (ImGui::Button("SubN"))
		{
			// if pressed we compile the shaders
			treeGenerator.setN(treeGenerator.getN() - 1);

		}

		ImGui::Text("Value of Length    ");
		ImGui::SameLine();
		if (ImGui::Button("Add Length"))
		{
			// if pressed we compile the shaders
			//treeGenerator.setN(treeGenerator.getN() + 1);
			treeGenerator.lSysInt.setDist(treeGenerator.lSysInt.getDist() + LengthStep);


		}
		ImGui::SameLine();
		if (ImGui::Button("Sub Length"))
		{
			// if pressed we compile the shaders
			//treeGenerator.setN(treeGenerator.getN() - 1);
			treeGenerator.lSysInt.setDist(treeGenerator.lSysInt.getDist() - LengthStep);

		}		
		ImGui::Text("Random range Length");
		ImGui::SameLine();
		if (ImGui::Button("Add"))
		{
			// if pressed we compile the shaders
			//treeGenerator.setN(treeGenerator.getN() + 1);		
			treeGenerator.lSysInt.setLengthRandRange(treeGenerator.lSysInt.getLengthRandRange() + randomStep);

		}
		ImGui::SameLine();
		if (ImGui::Button("Sub"))
		{
			// if pressed we compile the shaders
			treeGenerator.lSysInt.setLengthRandRange(treeGenerator.lSysInt.getLengthRandRange() - randomStep);

		}


		ImGui::Text("Value of Angle     ");
		ImGui::SameLine();
		if (ImGui::Button("Add Degrees"))
		{
			// if pressed we compile the shaders
			treeGenerator.lSysInt.setAngle(treeGenerator.lSysInt.getAngle() + AngleStep);

		}
		ImGui::SameLine();
		if (ImGui::Button("Sub Degrees"))
		{
			// if pressed we compile the shaders
			treeGenerator.lSysInt.setAngle(treeGenerator.lSysInt.getAngle() - AngleStep);

		}
		ImGui::Text("Random range Angle ");
		ImGui::SameLine();
		if (ImGui::Button("Add rand angle"))
		{
			// if pressed we compile the shaders
			//treeGenerator.setN(treeGenerator.getN() + 1);		
			treeGenerator.lSysInt.setAngleRandRange(treeGenerator.lSysInt.getAngleRandRange() + randomStep);

		}
		ImGui::SameLine();
		if (ImGui::Button("Sub rand angle"))
		{
			// if pressed we compile the shaders
			treeGenerator.lSysInt.setAngleRandRange(treeGenerator.lSysInt.getAngleRandRange() - randomStep);

		}

		// apply button
		if (ImGui::Button("Apply"))
		{
			
			if (*generateProductions)
			{
				treeGenerator.setRules( treeGenerator.generateProductions(lista));
				std::cout << *generateProductions << std::endl; 
			}
			if (treeGenerator.getN() > 0){

				rebuildModel();
	
			std::cout << treeGenerator.lSysInt.segmentList.size() << std::endl;
			}
			std::cout << treeGenerator.getN() << std::endl;
		}

		if (ImGui::Button("Toggle leaves"))
		{
			
			if (drawLeaf) { drawLeaf = false; }
			else { drawLeaf = true; }

		}
		
		ImGui::Checkbox("Generate productions", generateProductions);
		ImGui::Checkbox("Shaded smooth", shadedSmooth);

		if (ImGui::Button("Export model"))
		{
			// if pressed we compile the shaders
			std::cout << "I do nothing, lel" << std::endl;

		}

		// close window
		ImGui::End();
	}
}

void ImGuiExampleApp::rebuildModel() {

	Gnode = new GraphicsNode();
	treeGenerator.buildTree(treeGenerator.getN(), 0, 0);
	Gnode->pointerSetup();

	Gnode->setupAndGenerateTree(treeGenerator.lSysInt.segmentList, *shadedSmooth);

	treeGenerator.setupLeafNodes(LeafList, LeafNode);
}

} // namespace Example






