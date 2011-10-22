// <license>
// Copyright (C) 2011 Andrea Interguglielmi, All rights reserved.
// This file is part of the coral repository downloaded from http://code.google.com/p/coral-repo.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// 
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
// 
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// </license>

#ifndef CORAL_GEOCUBENODE_H
#define CORAL_GEOCUBENODE_H

#include "../src/Node.h"
#include "../src/Numeric.h"
#include "../src/NumericAttribute.h"
#include "../src/GeoAttribute.h"

namespace coral{

class GeoCube: public Node{
public:
	GeoCube(const std::string &name, Node *parent);
	void update(Attribute *attribute);

private:
	void buildDepthForHeightFaces(int widthSubdivisions, int depthSubdivisions, int heightSubdivisions, int totalPoints, bool otherSide, std::vector<std::vector<int> > &faces);
	void assignFacePoints(int point0, int point1, int point2, int point3, bool clockWise, std::vector<int> &faceVertices);
	
	NumericAttribute *_width;
	NumericAttribute *_height;
	NumericAttribute *_depth;
	NumericAttribute *_widthSubdivisions;
	NumericAttribute *_heightSubdivisions;
	NumericAttribute *_depthSubdivisions;
	GeoAttribute *_out;
};

}

#endif
