#include "LsystemInterpreter.h"

float LsystemInterpreter::randomNr(float input, float range)
{

	//Return if no random range
	if (range == 0)
	{
		return input;
	}
	int _range = range * 10;
	// random nr between 0 and range -1
	float randomNumber = (rand() % (_range));
	std::cout << randomNumber << std::endl;
	
	randomNumber -= 0.5 * range;
	return input + (randomNumber/100);
}

LsystemInterpreter::LsystemInterpreter(std::string sentence_)
{
	this->sentence = sentence_;
	turtle = Matrix4D();
}

LsystemInterpreter::LsystemInterpreter()
{
	turtle = Matrix4D();
}

void LsystemInterpreter::setSentence(std::string sentence_)
{
	sentence = sentence_;
}

void LsystemInterpreter::moveForwardByDistance(float distance)
{
	Matrix4D temp = turtle;
	temp = turtle.translate(Vector4D(0, 0, -distance, 0));
	turtle = turtle * temp;
}

void LsystemInterpreter::rotateXbyAngle(float radians)
{
	turtle = turtle * turtle.RotationX(radians);
}

void LsystemInterpreter::rotateYbyAngle(float radians)
{
	turtle = turtle * turtle.RotationY(radians);
}

void LsystemInterpreter::rotateZbyAngle(float radians)
{
	turtle = turtle * turtle.RotationZ(radians);
}

void LsystemInterpreter::calculatePoints(int randrangeAngle, int branchRandRange)
{
	segmentList.clear();
	//Resets values before running function
	//Thickness of current segment
	thicknessFactor = 0;
	//Length of current segment
	//dist = 2.f;
	//handle to previously generated segment
	previous = -1;
	//handle to segment currently being generated
	current = 0;
	//Keeps track of branching
	branchLevelTracker = 0;
	//Keeps track of nr of segments in branch
	branchDepthTracker = 0;

	//Pitchin up turtle after resetting it
	turtle = Matrix4D();
	rotateXbyAngle(1.5708f);

	//List that saves states when branching off
	std::vector<int> branchingPoints;

	for (int i = 0; i < sentence.length(); i++)
	{

		if (!skipBranch)
		{
			//Forward
			if (sentence[i] == 'A')
			{
				//Create segment
				Segment newSeg = Segment();

				newSeg.thickness = thicknessFactor;
				//push start position
				newSeg.position0 = turtle.getPosition();
				//calculate random length and move halfway
				newSeg.length = randomNr(dist, randLength);

				rotateYbyAngle(randomNr(0, 0));
				moveForwardByDistance(newSeg.length / 2);
				//Push middle transform
				newSeg.transform = turtle;
				//move forward the rest of the way
				moveForwardByDistance(newSeg.length / 2);
				//push end point 
				newSeg.position1 = turtle.getPosition();
				
				addSegment(newSeg);
			}
			//turn right
			else if (sentence[i] == 'B')
			{
				Segment newSeg = Segment();
				//push start position
				newSeg.position0 = turtle.getPosition();
				rotateYbyAngle(randomNr(angleRad, randAngle));

				newSeg.length = randomNr(dist, randLength);
				moveForwardByDistance(newSeg.length / 2);
				newSeg.transform = turtle;
				moveForwardByDistance(newSeg.length / 2);

				//push end point and other data
				newSeg.position1 = turtle.getPosition();
				addSegment(newSeg);
			}
			//turn left
			else if (sentence[i] == 'C')
			{
				Segment newSeg = Segment();

				//push start position
				newSeg.position0 = turtle.getPosition();
				rotateYbyAngle(randomNr(-angleRad, randAngle));
				newSeg.length = randomNr(dist, randLength);
				moveForwardByDistance(newSeg.length / 2);
				newSeg.transform = turtle;
				moveForwardByDistance(newSeg.length / 2);
				//push end point and other data
				newSeg.position1 = turtle.getPosition();
				

				addSegment(newSeg);
			}
			//Pitch down
			else if (sentence[i] == 'D')
			{

				Segment newSeg = Segment();

				//push start position
				newSeg.position0 = turtle.getPosition();
				rotateXbyAngle(randomNr(-angleRad, randAngle));
				newSeg.length = randomNr(dist, randLength);
				moveForwardByDistance(newSeg.length / 2);
				newSeg.transform = turtle;
				moveForwardByDistance(newSeg.length / 2);
				//push end point and other data
				newSeg.position1 = turtle.getPosition();
			

				addSegment(newSeg);
			}
			//pitch up
			else if (sentence[i] == 'E')
			{
				Segment newSeg = Segment();

				//push start position
				newSeg.position0 = turtle.getPosition();
				rotateXbyAngle(randomNr(angleRad, randAngle));
				newSeg.length = randomNr(dist, randLength);
				moveForwardByDistance(newSeg.length / 2);
				newSeg.transform = turtle;
				moveForwardByDistance(newSeg.length / 2);
				//push end point and other data
				newSeg.position1 = turtle.getPosition();
			

				addSegment(newSeg);
			}
			//start branch
			else if (sentence[i] == '[')
			{
				if (segmentList[previous].branchDepth < 0) {
					//Atempt at making branching not occur on bottom of tree, doesn�t work well
					skipBranch = true;
				}
				else {
					branchingPoints.push_back(previous);
					segmentList[previous].branches.push_back(current);
					branchLevelTracker++;
				}
			}
		}
		//end branch
		 if (sentence[i] == ']')
		{
			//Stop skipping if skipping
			if (skipBranch) {
				skipBranch = false;
			}
			//Set current data to values from branching point
			else {
				//End of branch has leaf
				segmentList[previous].hasLeaf = true;

				//Get a ptr of segment at branching point
				Segment* previousSeg = &segmentList[branchingPoints.back()];

				//Store nr of children
				previousSeg->nrOfSuccessors += branchDepthTracker;
				previousSeg->nrOfSuccessors += segmentList[previous].nrOfSuccessors;

				//Reset branchdepth to where it was at branchingpoint
				branchDepthTracker = previousSeg->branchDepth;

				//Reset thickness to where it was at branchingpoint
				thicknessFactor = previousSeg->thickness;

				//Reset turtle position and move turtle forward to end of segment
				turtle = previousSeg->transform;
				moveForwardByDistance(previousSeg->length / 2);

				//Sets the previous handle to the branching point
				previous = branchingPoints.back();

				//Remove branching point
				branchingPoints.pop_back();

				//Drops the branchlevel
				branchLevelTracker--;
			}
		}
		 //Code that reduces segment length further up in the tree
		//dist -= dist / (segmentLengthReduction * 6 * segmentList[previous].thickness);
	}
	//thickness calculation that i made up myself
	float thickRange = 0.4 * sqrt(segmentList.size()) ;
	
	for (int segment = 0; segment < segmentList.size(); segment++) {
		segmentList[segment].thickness = (thickRange / ((2 + segmentList[segment].thickness) * 10 ));
	}


}

void LsystemInterpreter::addSegment(Segment s)
{
	thicknessFactor++;
	s.thickness = thicknessFactor;
	s.branchDepth = branchDepthTracker;
	s.branchingLevel = branchLevelTracker;
	s.predecessor = previous;
	previous = current;
	current++;
	segmentList.push_back(s);
	branchDepthTracker++;

}
