#include "Border.h"

Border::Border(BorderPosition position, Rectangle borderRec) 
{
	this->position = position;
	this->borderRec = borderRec;
}

Border::~Border()
{

}

BorderPosition Border::GetBorderPosition()
{
	return position;
}

void Border::SetBorderPosition(BorderPosition position) 
{
	this->position = position;
}

Rectangle Border::GetBorderRec() 
{
	return borderRec;
}

void Border::SetBorderRec(Rectangle borderRec)
{
	this->borderRec = borderRec;
}

void Border::Draw()
{
	DrawRectangle(borderRec.x, borderRec.y, borderRec.width, borderRec.height, BROWN);
}
